#include <stdio.h>
#include "syncqueue.h"


struct Arguments
{
    HANDLE startEvent;
    SyncQueue* queueP;
    int count;
    int ID;
};
CRITICAL_SECTION cs;

DWORD WINAPI producer (LPVOID arg)
{
    Arguments args = *((Arguments*) arg);
    // wait for a signal to start work;	 
	// 
    SyncQueue queue = *args.queueP; 
    WaitForSingleObject (args.startEvent,INFINITE);
	ResetEvent (args.startEvent);
    //perform the following actions cyclically 
	//(the number of cycles is set in the parameter):
    for (int i=0;i<args.count;i++)
    {
         //add to the ring queue an integer 
		 //equal to its ordinal number;
	     EnterCriticalSection(&cs);
         queue.insert(args.ID);

         //print to the console the message: 
		 //"Number produced: N", 
		 //where N is the number of the number, enqueued.
         printf ("%d is produced\n", args.ID);
		 LeaveCriticalSection(&cs);

         Sleep (7);
    }	
    SetEvent (args.startEvent);
	ExitThread(0);
}

DWORD WINAPI consumer (LPVOID arg)
{
    Arguments args = *((Arguments*) arg);
    SyncQueue queue = *args.queueP;
    // wait for a signal to start work;
    WaitForSingleObject (args.startEvent,INFINITE);
	ResetEvent (args.startEvent);
    //cyclically retrieve integers from the ring queue at 7ms intervals
    //(the number of cycles is set in the parameter);
    for (int i=0;i<args.count;i++)
    {
		EnterCriticalSection(&cs);
        printf ("\t%d is consumed\n", queue.remove());
        //when extracting a number from the ring queue, 
		//print the message to the console:
        //"\ tNumber N consumed", 
		//where N is the number of the number 
		//retrieved from the queue
		LeaveCriticalSection(&cs);
        Sleep (7);
		
    }
    SetEvent (args.startEvent);
	ExitThread(0);
}

int main(int argc, char *argv[])
{

	InitializeCriticalSection(&cs);
    //create a circular queue object, 
	//the queue size is entered by the user with
    //keyboard;
    int queueSz = 0;
    printf ("Queue size: ");
    scanf("%d",&queueSz);
    SyncQueue queue = SyncQueue (queueSz);

    //input from the keyboard the number of producer 
	//threads and the number of consumer threads, 
	//which it should start;
    int prodCount = 0;
    int consCount = 0;

    printf ("Producer count: ");
    scanf ("%d",&prodCount);
    printf ("Consumer count: ");
    scanf ("%d",&consCount);

    int* prodPortions  = new int [prodCount];
    int* consPortions  = new int [consCount];

    //request for each of the producer 
	//and cosumer streams the number of integers,
    //which these threads should respectively 
	//produce and consume;
    for (int i=0;i<prodCount;i++)
    {
        printf ("Produser %d items to produce: ", i+1);
        scanf ("%d",&prodPortions[i]);
    }

    for (int i=0;i<consCount;i++)
    {
        printf ("Consumer %d items to consume: ", i+1);
        scanf ("%d",&consPortions[i]);
    }

    //create the required number of producer threads, 
	//pass it to each thread ordinal and number 
	//of integers it should produce;
    HANDLE* hProducers = new HANDLE [prodCount];
    DWORD* prodID = new DWORD [prodCount];
    Arguments* prodArgs = new Arguments [prodCount];
    HANDLE* endItAll = new HANDLE [prodCount+consCount];
    for (int i=0;i<prodCount;i++)
    {
        prodArgs[i].count = prodPortions[i];
        prodArgs[i].queueP = &queue;
        prodArgs[i].startEvent = CreateEvent (NULL,TRUE,FALSE,NULL);
        endItAll[i] = prodArgs[i].startEvent;
        prodArgs[i].ID = i+1;
        if (!prodArgs[i].startEvent)
        {
            printf ("Error on creating startEvent for producer %d\n", i+1);
            return 200;
        }
        hProducers[i] = (HANDLE) CreateThread (NULL,0, producer, (void*) &prodArgs[i], 0, &prodID[i]);
        if (hProducers[i]==NULL)
        {
            printf ("Can't start producer thread %d\n",i+1);
            return 100;
        }
    }


    //create the required number of consumer threads, pass to each thread
    //the number of integers it should consume;

    HANDLE* hConsumers = new HANDLE [consCount];
    DWORD* consID = new DWORD [consCount];
    Arguments* consArgs = new Arguments[consCount];
	
    for (int i=0;i<consCount;i++)
    {
        consArgs[i].count = consPortions[i];
        consArgs[i].queueP = &queue;
        consArgs[i].startEvent = CreateEvent (NULL,TRUE,FALSE,NULL);
        endItAll[prodCount+i]=consArgs[i].startEvent;
        consArgs[i].ID = i+1;
        if (!consArgs[i].startEvent)
        {
            printf ("Error on creating startEvent for consumer %d\n", i+1);
            return 200;
        }
        hConsumers[i] = (HANDLE) CreateThread (NULL,0,consumer, (void*) &consArgs[i],0 ,&consID[i]);
        if (hProducers[i]==NULL)
        {
            printf ("Can't start consumer thread %d\n",i+1);
            return 100;
        }
    }

    //send a signal to start the producer 
	//and consumer threads;
	Sleep (100);
    for (int i=0;i<consCount+prodCount;i++)
    {
        SetEvent(endItAll[i]);
    }

    //terminate its work after all producer 
	//and consumer threads have finished.
	
    WaitForMultipleObjects (prodCount+consCount, endItAll, TRUE, INFINITE);	

	for (int i=0;i<consCount;i++)
	{
		CloseHandle (hConsumers[i]);
	}
	for (int i=0;i<prodCount;i++)
	{
		CloseHandle (hProducers[i]);
	}
	for (int i=0;i<prodCount+consCount;i++)
	{
		CloseHandle(endItAll[i]);
	}
    delete[] prodPortions;
    delete[] consPortions;

    delete [] hProducers;
    delete [] prodID;
    delete [] prodArgs;

    delete [] endItAll;

    delete [] hConsumers;
    delete [] consID;
    delete [] consArgs;
    return 0;
}



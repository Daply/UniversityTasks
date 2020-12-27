#include <iostream>
#include <windows.h>
#include <cstdio>
#include <time.h>
using namespace std;


struct MarkerArgs
{
    int id;
    int arrSize;
    int* arrP;
    HANDLE startEvent;
    HANDLE stoppedEvent;
    HANDLE resumeEvent;
    HANDLE killEvent;

};

DWORD WINAPI marker (LPVOID argument)
{
	// start after main stream signal
    MarkerArgs args = *((MarkerArgs*)argument);
    printf ("Thread #%d waiting for start signal\n",args.id);
    WaitForSingleObject (args.startEvent,INFINITE);
    //Initialize the generation of a sequence of random numbers. For this
    //use the srand function, to which you can pass your own
    //serial number.
    //srand (time(NULL));
    srand (args.id); //does not generate new sequences

    //Work cyclically, performing the following actions on each cycle:
    while (true)
    {
        //Generate a random number using the rand function.
        //Divide this number modulo by the dimension of the array.
        int randomNum = rand()%args.arrSize;
        printf("[THREAD %d] just generated %d\n",args.id,randomNum);

        //If the element of the array whose index is equal to the result of division is zero, then
        //do the following:
        if (args.arrP[randomNum]==0)
        {

            Sleep (5);

            //Input your ordinal number into the element whose index is calculated.
            args.arrP[randomNum]=args.id;

            Sleep(5);
            //Continue loop execution 3.
        }
        else
        {
            //Display your serial number on the console.
            //Print to the console the index of the array element, 
			//which is impossible mark.
            printf ("[THREAD %d]  STOPED at %d\n",args.id,randomNum);

            //Give a signal to the main thread that it cannot continue its work.
            SetEvent (args.stoppedEvent);

            //Wait for a response signal to continue or end work 
			//from the main thread
            HANDLE* events = new HANDLE [2];
            events[0] = args.resumeEvent;
            events[1] = args.killEvent;

            //If a signal to shutdown is received, then do the following:
            if (WaitForMultipleObjects (2,events,FALSE, INFINITE)-WAIT_OBJECT_0 == 1)
            {
                //Fill all the elements that he marked with zeros in the array.
                //To finish work.
                printf ("%d received KILL_SIGNAL...\n",args.id);
                for (int i=0;i<args.arrSize;i++)
                {
                    if (args.arrP[i]==args.id)
                    {
                        args.arrP[i]=0;
                    }
                }
                SetEvent(args.stoppedEvent);
                ExitThread(0);
            }
            //If a signal is received to continue work, 
			//then continue the execution of the cycle
            printf ("Thread %d resumed...\n",args.id);
            ResetEvent (args.stoppedEvent);
        }
    }


}


int main ()
{
    //Grab memory for an array of integers, 
	//the dimension of which is entered from the console.
    int arrSz = 0;
    printf ("Set array size: ");
    scanf("%d",&arrSz);
    int* array = new int [arrSz];

    //Initialize array elements to zeros.
    for (int i=0;i<arrSz;i++)
    {
        array[i]=0;
    }

    //Request the number of marker streams to run.
    int markerCount = 0;
    printf("Set amount of instances of \'maker\': ");
    scanf("%d",&markerCount);

    //Run the specified number of instances 
	//of the marker stream. 
	//As a parameter to each instance of the marker stream, 
	//pass its sequence number at startup.

    HANDLE* hThreads = new HANDLE [markerCount]; //stream descriptor array
    DWORD* threadIDs = new DWORD [markerCount]; //stream idetificators array
    HANDLE* stopedEvents = new HANDLE [markerCount]; // an array of event descriptors indicating 
	                                                 // that the thread has reached a dead end

    bool* killMask = new bool [markerCount]; // killed thread mask
    for (int i=0;i<markerCount;i++) killMask[i] = false; // all streams are alive

    MarkerArgs* args = new MarkerArgs [markerCount];

    for (int i=0;i<markerCount;i++)
    {
        //Argument initialization
        args[i].id = i+1;
        args[i].arrP = array;
        args[i].arrSize = arrSz;
       // stopedEvents[i] = CreateEvent (NULL,FALSE,FALSE,NULL);
       // startEvents[i] = CreateEvent (NULL,FALSE,FALSE,NULL);
        args[i].stoppedEvent =  CreateEvent (NULL,FALSE,FALSE,NULL);
        stopedEvents[i] = args[i].stoppedEvent;
        args[i].startEvent =  CreateEvent (NULL,FALSE,FALSE,NULL);
        args[i].resumeEvent = CreateEvent (NULL,FALSE,FALSE,NULL);
        args[i].killEvent = CreateEvent (NULL,FALSE,FALSE,NULL);


        printf ("Creating thread %d    ",i+1);
        hThreads[i] = CreateThread(NULL, 0, marker, &args[i], 0, &threadIDs[i]);
        if (hThreads[i]==NULL)
        {
            printf ("\n[ERR] Error on creation thread #%d",i+1);
        }
        else
        {
            printf ("[OK]\n");
        }
    }

    //Give a signal to start all streams marker.
    for (int i=0;i<markerCount;i++)
    {
        printf ("Starting thread %d...\n",i+1);
        SetEvent (args[i].startEvent);
    }
    int threadCount = markerCount;
    while (threadCount!=0)
    {

        //Wait until all marker streams give 
		//signals that they cant continue my work.
        printf ("Waiting for threads ...\n");
        for (int i=0;i<markerCount;i++)
        {
            if (killMask[i])
            {
                SetEvent(stopedEvents[i]);
            }

        }
        WaitForMultipleObjects (markerCount,stopedEvents,TRUE, INFINITE);
        for (int i =0;i<markerCount;i++)
        {
            if (!killMask[i])
            {
                ResetEvent(args[i].stoppedEvent);
            }
            stopedEvents[i] = args[i].stoppedEvent;
        }


        // array printing
        for (int i=0;i<arrSz;i++)
        {
            printf ("%3d ",array[i]);
        }
        printf ("\n");


        //Request from the console the sequence 
		//number of the marker stream to be served
        //signal to complete its work.
        printf ("Witch of  threads do you want to kill [");
        for (int i=0;i<markerCount;i++)
        {
            if (!killMask[i]) printf (" %d ",i+1);
        }
        printf ("]: ");
        int kill = 0;
        scanf ("%d",&kill);


        printf ("Sending  killEvent to %d thread...\n",kill);
        SetEvent(args[kill-1].killEvent);


        //Wait for the completion of the work of the marker stream, 
		//to which the signal was sent to shutdown
        WaitForSingleObject (args[kill-1].stoppedEvent,INFINITE);

        // array printing
        for (int i=0;i<arrSz;i++)
        {
            printf ("%3d ",array[i]);
        }
        printf ("\n");

        //Send a signal to continue work 
		//for the remaining streams marker.
        for (int i=0;i<markerCount;i++)
        {
            if (i!=kill-1)
            {
                SetEvent(args[i].resumeEvent);
            }
            else
            {
                CloseHandle (hThreads[i]);
                threadCount--;
                killMask[kill-1]=true;
                SetEvent (args[kill-1].stoppedEvent);
            }
        }
    }



    //free memory
    delete[] array;
    delete[]hThreads;
    delete[] args;
    delete [] stopedEvents;


    return 0;
}

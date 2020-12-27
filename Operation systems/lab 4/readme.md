## Topic: “Semaphores. Developing Thread-Safe Classes ”.

A task.<br>
Write a class to control concurrent thread access to a ring queue.
Implementation requirements:<br>
1. Class interface for concurrent thread access control to the ring queue:
```
class SyncQueue
{
public:
// constructor
SyncQueue (int nSize); // nSize - queue size
// destructor
~ SyncQueue ();
// functions for accessing the queue
void Insert (int nElement); // add an item to the tail of the queue
int Remove (); // remove the head element of the queue
};
```
2. A ring queue is implemented by an array, whose elements are of type int. The size a circular queue is specified in the constructor.
3. If the thread calls the Insert method, and the ring queue is full, then the method Insert should put this thread in a waiting state until it is removed from the ring queue of at least one element by another thread.
4. If the thread calls the Remove method, and the ring queue is empty, then the Remove should put this thread in a waiting state before writing to the ring queue, at least one new element by another thread.
Additional requirements:
To test the SyncQueue class, write a program for the console process that consists of a main thread and several consumer and producer threads.<br>
The main thread should do the following:<br>
create a circular queue object, the queue size is entered by the user with keyboards;<br>
enter from the keyboard the number of producer threads and the number of consumer threads, which he should run;<br>
request for each of the producer and cosumer streams the number of integers, which these flows must respectively produce and consume;<br>
create the required number of producer threads, pass it to each thread the ordinal number and the number of integers that it must produce;<br>
create the required number of consumer threads, pass to each thread the number of integers that he should consume;<br>
send a signal to start the producer and consumer threads;<br>
terminate its work after all producer and consumer threads have finished.<br>
The producer thread should do the following:<br>
wait for a signal to start work;<br>
perform the following actions cyclically (the number of cycles is set in the parameter):<br>
o add to the ring queue an integer equal to its ordinal number;<br>
o output to the console the message: "Number produced: N", where N is the number of the number, placed in the queue.<br>
o sleep 7 ms.<br>
The consumer thread should do the following:<br>
wait for a signal to start work;<br>
cyclically retrieve integers from the ring queue at 7ms intervals (the number of cycles is set in the parameter);<br>
when extracting a number from the ring queue, print the message to the console:<br>
"\ tNumber N consumed", where N is the number of the number retrieved from the queue.<br>

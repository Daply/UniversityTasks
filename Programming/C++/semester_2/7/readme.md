
## STL. Consecutive containers

To solve the problem, use a sequential container STL List, the X denotes the string type.<br>

Messages of the following structure are received from the input terminals of the network:
                      terminal code X (2)
                      message code X (3)
                      priority X (1)
                      information part X (40)
on the basis of which the queue of input messages is built in the order of their arrival.
Service discipline:
Either the message with the highest priority or the longest message is selected from the queue. Provides the ability to timely select all items from the queue.
Program menu:
1. Putting an item into the input queue.
2. Change of service discipline.
3. Display all items in the queue.
4. Fetching the next item from the queue.
5. Termination of the program.
When fetching, the element of the queue must be removed from it, and the memory occupied by it must be freed. The item selected from the queue is displayed.
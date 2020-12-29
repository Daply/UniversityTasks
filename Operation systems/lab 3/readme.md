## Topic: "Synchronization of threads using critical sections and events. Processing dead ends ".

Write a program for a console process, which consists of a main thread and multiple instances of the stream marker.<br>
The main thread should do the following:<br>
1. Grab memory for an array of integers, the dimension of which is entered from the console.
2. Initialize array elements with zeros.
3. Request the number of marker streams to run.
4. Run the specified number of instances of the marker stream. As a parameter to each instance of the marker stream, pass its sequence number in the run.
5. Give a signal to start work of all marker streams.
6. Perform the following actions in the loop:<br>
6.1. Wait until all marker streams give impossible signals continue their work.<br>
6.2. Print the contents of the array to the console.<br>
6.3. Request from the console the sequence number of the marker stream to be served signal to complete its work.<br>
6.4. Give the stream marker, the number of which was obtained in paragraph 6.3, a signal to completion of work.<br>
6.5. Wait for the completion of the work of the marker stream, to which the signal was sent to completion of work in clause 6.4.<br>
6.6. Print the contents of the array to the console.<br>
6.7. Send a signal to continue work for the remaining streams marker.<br>
7. Finish your work after the completion of all marker streams.

The marker stream should do the following:<br>
1. Start work on a signal from the main thread.
2. Initialize the generation of a sequence of random numbers. For this use the srand function, to which pass your own serial number.
3. Work cyclically, performing the following actions on each cycle:<br>
3.1. Generate a random number using the rand function.<br>
3.2. Divide this number modulo the dimension of the array.<br>
3.3. If the element of the array whose index is equal to the result of division is zero, then do the following:<br>
3.3.1. Sleep for 5 milliseconds.<br>
3.3.2. Enter your ordinal number into the element whose index is calculated.<br>
3.3.3. Sleep for 5 milliseconds.<br>
3.3.4. Continue loop execution 3.<br>
3.4. Otherwise:<br>
3.4.1. Print the following information to the console:<br>
-- your serial number;<br>
-- the number of marked items;<br>
-- the index of the array element that cannot be marked.<br>
3.4.2. Give a signal to the main thread that it cannot continue its work.<br>
3.4.3. Wait for a response signal to continue or terminate work from the thread main.<br>
4. If a signal to shutdown is received, then do the following:<br>
4.1. Fill all the elements that he marked with zeros in the array.<br>
4.2. To finish work.<br>
5. If a signal is received to continue work, then continue the execution of the cycle from point 3.

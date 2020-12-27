## Topic: "Data exchange via anonymous channels".

Task:<br>
write a program to control access of parallel processes to a file by anonymous channel.<br>
Formulation of the problem.<br>
1. Develop a server process that performs the following actions.
1.1. Creates a binary file whose entries have the following structure:<br>
```
struct student
{
int num; // student number
char name [10]; // student name
double grade; // average mark
};
```
<br>
The file name and student data are entered from the console.<br>
1.2. Outputs the generated file to the console.
1.3. Starts Client processes that access the file over an anonymous channel.<br>
The number of client processes is entered from the console.<br>
1.4. Serves requests from client processes as follows:<br>
- if the client process requests modification of a file record, then access to this file record is blocked for other client processes until the client completes the modification of the record;
- if the client process requests to read a file record, then access to this record for others client processes:<br>
- not blocked if they also request read access to data;<br>
- blocked if they request write access.<br>
1.5. After all client processes are finished, outputs the modified file to the console.
1.6. On command from the console, it ends its work.
2. Develop a Client process that performs the following actions:
2.1. Loops:<br>
2.1.1. Asks the console to perform one of the following operations:<br>
- modification of the file record;<br>
- reading a record;<br>
- exit from the cycle;<br>
2.1.2. After entering the required data, it performs this operation.<br>
2.2. Access to the file records is carried out by the key, which is the student's record number.
2.3. When a record is modified, the client process performs the following actions:<br>
2.3.1. Requests a recording key;<br>
2.3.2. Sends a request to the server;<br>
2.3.3. Outputs the record received from the server to the console;<br>
2.3.4. Requests new field values;<br>
2.3.5. On command from the console, sends the changed record to the server;<br>
2.3.6. On command from the console, terminates write access.<br>
2.4. When reading a record, the client process performs the following actions:<br>
2.3.1. Requests a recording key;<br>
2.3.2. Sends a request to the server;<br>
2.3.3. Outputs the record received from the server to the console;<br>
2.3.4. On command from the console, terminates write access.<br>
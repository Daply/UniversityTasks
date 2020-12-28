## Topic: "Process creation".
A task. Write a console program Main and two utilities Creator and Reporter, which perform the following actions.<br>
The Creator utility creates a binary file, the name of which is obtained through the command line.<br>
1. The number of file entries is entered from the console.
2. File entries are entered from the console and have the following structure:
```
 struct order
 {
 char name [10]; // product name
 int amount; // number of product units
 double price; // unit cost
 };
```
The Reporter utility creates a text file that contains a product report, description which are stored in a binary file created by Creator.<br>
1. The utility receives the following data via the command line:
1.1. Source binary file name.
1.2. The name of the report file.
1.3. The minimum number of product units.
1.4. The minimum total cost of the item.
2. The report includes data on the quantity and total cost of only those goods the number or total cost of which is less than the one specified on the command line.
3. The report contains the following lines:
3.1. Title: Report on the file "source binary file name".
3.2. Lines: product name, number of product units, total product value.
4. The total cost of the goods is calculated using the formula: amount * price.
The Main program does the following:<br>
1. Requests the name of the generated binary file from the console.
2. Runs the Creator utility, which passes the name through the command line the file being created.
3. Waits for the Creator utility to complete.
4. Dumps the contents of the created binary file to the console.
5. Asks from the console:<br>
a. The name of the report file.<br>
b. The minimum number of product units.<br>
c. The minimum total cost of the item.
6. Launches the Reporter utility, which transmits via the command line:<br>
a. Source binary file name.<br>
b. The name of the report file.<br>
c. The minimum number of product units.<br>
d. The minimum total cost of the item.<br>
7. Waits for the Reporter utility to finish.
8. Prints the report to the console.
9. Completes its work.
Note. To wait for the Creator and Reporter processes to terminate<br>
```
use function:
 DWORD WaitForSingleObject (
 HANDLE hHandle, // object handle
 DWORD dwMilliseconds // wait interval in milliseconds
 );
```
where the second parameter is set to INFINITE, for example<br>
```
 WaitForSingleObject (hCreator, INFINITE);
```
Here hCreator is a handle to the Creator process.<br>

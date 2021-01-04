## Lab #1
Develop a Java Console Application.<br>
The function is presented as its own Taylor series.<br>
![integral](https://github.com/Daply/university-assignments/blob/master/Programming/Java/pictures_for_readme/Lab1.PNG)<br>
Calculate the approximate value of the sum of this infinite series.<br>
Finish the calculations when the next term is less than the given number ε (Epsilon) in absolute value.<br>
The form of this number is determined by the following condition: ε = 10-k, where k is a natural number.<br>
Compare the obtained result with the value calculated using standard functions.<br>
Enter the values x and k from the console.<br>
The result should be displayed with five digits after the decimal point.<br>

## Lab #2
Tasks for laboratory work number 2 by arrays.<br>
You can perform any task you like more, but it is desirable that each other does not have Copy-Paste.<br>
Enter data into the program from the console, but if it is more convenient for someone to enter from a file - please, this is only a plus. To read from a file you can use<br>
```
a) BufferedReader br = new BufferedReader (new FileReader (...));
b) Scanner sc = new Scanner (new FileInputStream (...));
```

Subtraction of 2 large numbers:<br>
write a program that finds the difference of 2 large numbers: <br>
ie. represent the number as an array (0 is the ones place, 1 is the tens place, etc.) and find the difference between these 2 numbers.<br>
<b>NOTE:</b> you can also enter not very long numbers, the very essence of solving the problem is important, but if you want to try with large numbers, then there is an example at the end of the document.<br>

Example:<br>
```
try {
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
String line = br.readLine();
int[] number = new int[line.length()];
int j = 0;
for (int i = line.length() - 1; i >= 0; i--) {
    char sym = line.charAt(i);
    if (sym >= '0' && sym <= '9') {
        number[j++] = Integer.parseInt(String.valueOf(sym));
    }
}
number = Arrays.copyOf(number, j);
} catch (IOException e) {
            System.out.println("IOException occurred");
            e.printStackTrace();
}
```

## Lab #3
Tasks for laboratory work number 3 on matrices.<br>
You can perform any task you like more, but it is desirable that each other does not have Copy-Paste.<br>
Enter data into the program from the console, but if it is more convenient for someone to enter from a file - please, this is only a plus. To read from a file you can use<br>
```
a) BufferedReader br = new BufferedReader (new FileReader (...));
b) Scanner sc = new Scanner (new FileInputStream (...));
```

## Lab #4 Strings

In the given line-sentence with the standard set of delimiter characters replace all word groups in one scan between words (group - three or more adjacent words),<br>
containing exactly two English letters for the second word in the group, deleting the rest of the words.<br>
Sort the remaining words in ascending order of the number of English letters in words.

## Lab #5 Classes

Create classes, the specifications of which are given below.<br>
Set immutable attributes. Ensure that the id attribute values ​​are unique.<br>
Define a constructor, necessary logical blocks, getType () methods for all attributes, setType () for mutable attributes, override toString () methods to represent information about an object in symbolic form, equals () to compare two objects for equality by some criterion.<br>
Provide necessary exceptions. Use the Enum class to specify a list of values ​​for some attribute. Define an additional class in which an array of objects is created, methods for selecting data in accordance with the specified criterion and methods that order the elements in the array of objects in accordance with the specified criterion are implemented.<br>
Use comparators to order objects in the specified order.<br>
In the parent program, create an array of objects from at least five elements. Fill this array with elements of the appropriate class.<br>
To call methods implemented on the basis of an array of objects, create a menu.<br>
Additionally, test the equals () method for two objects.<br>
<br>
<b>Computer:</b> id, Manufacturer, Processor type (single-core, dual-core, etc., defined through the Enum class), Hard drive size, Year of release, RAM volume.

## Lab #6

Create classes, the specifications of which are given below.<br>
Set immutable attributes. Ensure that the id attribute values ​​are unique.<br>
Define a constructor, necessary logical blocks, getType () methods for all attributes, setType () for mutable attributes, override toString () methods to represent information about an object in symbolic form, equals () to compare two objects for equality by some criterion.<br>
Provide necessary exceptions. Use the Enum class to specify a list of values ​​for some attribute. Define an additional class in which an array of objects is created, methods for selecting data in accordance with the specified criterion and methods that order the elements in the array of objects in accordance with the specified criterion are implemented.<br>
Use comparators to order objects in the specified order.<br>
In the parent program, create an array of objects from at least five elements. Fill this array with elements of the appropriate class.<br>
To call methods implemented on the basis of an array of objects, create a menu.<br>
Additionally, test the equals () method for two objects.<br>
<br>
<b>Computer:</b> id, Manufacturer, Processor type (single-core, dual-core, etc., defined through the Enum class), Hard drive size, Year of release, RAM volume.<br>
<b>Laptop (extends Computer):</b> Battery, Time of work, Size, Weight.

## Lab #7-8

## Task 1

The next tasks require you to create an abstract class in which you declare methods that are common to its two subclasses.<br>
Create subclasses to add specific properties and methods. Override some of the methods. Override toString () method.<br>
Test the methods of both subclasses in the parent program.<br>
Create an array containing objects of both subclasses and execute the methods declared in the abstract class.<br>
<br>
Abstract class - AbstractRobot.
Subclasses - FirstRobot, SecondRobot.

## Task 2

The next tasks require you to create an interface in which you declare methods that are common to two different classes.<br>
Create these classes, add specific properties and methods to them. Override methods declared in the interface. Override toString () method.<br>
Test the methods of both classes in the parent program.<br>
Create an array containing objects of both classes and execute methods declared in the interface.<br>
<br>
Interface – FirstGrRobotInterface, SecondGrRobotInterface. 
Classes – FirstRobot, SecondRobot (FirstGrRobotInterface) and ThirdRobot, FourthRobot (SecondGrRobotInterface).

## Lab #9

Develop a Java Console Application using classes created in lab6.<br>
Implement:<br> 
The possibility to list all computers.<br>
The possibility to list computers by specified type of processor.<br>
The possibility to list computers by specified hard drive volume interval.<br>
The possibility to list computers by specified name of manufacturer.<br>
The possibility to list computers in descending order of RAM volume.<br>
The possibility to list computers alphabetically by manufacturer.<br>
The possibility to serialize an deserialize.

## Final work

Develop a console application that "encrypts information". The application works as follows:<br>
a) a string is entered from the console, which can contain any symbols: letters, numbers, symbols of arithmetic operations, etc. (except characters \ r, \ n, \ 0)<br>
b) from the entered string, get all the numbers and return an array of these numbers (by a number we mean a sequence of digits and the symbol '.', which can be considered as one number in the 10th system)<br>
c) an array of numbers is passed to some function, which, based on these numbers, calculates the value of a given function, and enters the result of the calculations into the array. It is guaranteed that the function has the bijection property<br>
d) the array of function results must be sorted in descending order<br>
e) re-sort the original array so that x [i] = f (y [i]). Those. in the original place, rearrange the elements so that the value of the function from the element in place with index i is a number, which in the results array is also in place with index i<br>
f) compose a permutation (change) matrix of the indices of the elements of the original array (if it doesn't work, then just a matrix with 1 on the side diagonal)<br>
g) one more row is introduced, the length of which is not less than the rank (dimension) of the matrix (everything superfluous can be discarded)<br>
h) this row must be "multiplied" by the transposed matrix on the right (Ax), i.e. rearrange characters in the string in accordance with the transformation specified by the matrix<br>
i) output the transformed line<br>
<b>POINTS</b> (so far something like this):<br>
a) output of the entered line - 1b<br>
b) splitting and outputting the resulting array - 2b<br>
c) calculate the result of calculating the function - 1b<br>
d) sort descending - 1b<br>
e) sort the original array accordingly - 2b<br>
f) compose and display the permutation matrix - 2b<br>
g) input of the second line and the correct number of words in it - 1b<br>

<b>Input string:</b><br>
<p>
Tz`RD[=61.0F?(sr{G>S45.34v?%)>u65.88"@ynUcik@21.0C#?)$NK!\&L11.0qr%:bq=#G31.75Mbu@g%38.05c=+ZS{/+C28.0jZ&r$"ogGn*OH97.0t>xi64.79;tE"yShP[42.57pAFcY2.71P\yg+27.0{%oEi@_i]OJs30.0U_)RIlsk2.41o?!@C&*\TT7.22C`+zCE^#20.41Xt 58.0%fMVD-^NSSC29.0
</p>
<br>

<b>Function:</b><br>
(-x - 5)^3 - (-x + 5)^2 - 5;
<br>

<b>String to decode:</b><br>
obsndod !k egoRaiog

<br>

<br>
<b>For testing:</b><br>
To make a second string use strings of 19 symbols and cipher it according these symbols numbers:<br>

 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19<br>
16 14 18  6  4 11 12  8 19 17 13  2  7 10  1  3  5 15  9<br>

<b>For example:</b><br>
Living free in life<br>
becomes<br>
lnfgie feiii eLvn r


## Studying practice
[<b>Studying practice task</b>](https://github.com/Daply/university-assignments/blob/master/Programming/Java/Studying%20Practice/readme.md)




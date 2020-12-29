
## Abstract classes.


<b>Exercise 1.</b>
<br>
Develop classes of triangles, the hierarchy of which is shown in Figure 1.
<br>
<table>
<tbody>
<tr>
<td>
<p>Abstract triangle</p>
</td>
<td>
</td>
<td>
</td>
<td>
</td>
<td>
</td>
</tr>
<tr>
<td>
<p>|</p>
</td>
<td>
</td>
<td>
</td>
<td>
</td>
<td>
</td>
</tr>
<tr>
<td>
<p>+ - - - - - - - - - -</p>
</td>
<td>
<p>+ - Isosceles triangle</p>
</td>
<td>
<p>- - - - - - - - - - - - - - - - -</p>
</td>
<td>
<p>- - - - - - - - - - - -</p>
</td>	
<td>
<p>+</p>
</td>
</tr>
<tr>
<td>
<p>|</p>
</td>
<td>
<p>|</p>
</td>
<td>
</td>
<td>
</td>
<td>
<p>|</p>
</td>
</tr>	
<tr>
<td>
<p>|</p>
</td>
<td>
<p>+ - Equilateral triangle</p>
</td>
<td>
</td>
<td>
</td>
<td>
<p>|</p>
</td>
</tr>
<tr>
<td>
<p>|</p>
</td>
<td>
</td>
<td>
</td>
<td>
</td>
<td>
<p>|</p>
</td>
</tr>
<tr>
<td>
<p>+ - - - - - - - - - -</p>
</td>
<td>
<p>- - - - - - - - - - - - - - - -</p>
</td>
<td>
<p>+ - Rectangular triangle</p>
</td>
<td>
<p>- - - - - - - - - - - -</p>
</td>
<td>
<p>+</p>
</td>
</tr>
<tr>
<td>
</td>
<td>
</td>
<td>
</td>
<td>
</td>
<td>
<p>|</p>
</td>
</tr>
<tr>
<td>
</td>
<td>
</td>
<td>
</td>
<td>
</td>
<td>
<p>+ - Rectangular isosceles triangle</p>
</td>
</tr>
</tbody>
</table>
									 
The base hierarchy class AbstractTriangle has the following interface:

```
class Triangle
{
virtual ~ Triangle () {}
virtual double perimeter () const = 0; // calculate the perimeter
virtual double area () const = 0; // calculate area
};
```

To check the performance of classes, write a test program in which objects of all classes in the hierarchy are created and all methods of the classes are called.<br>
Create a special testing function test (), the parameter of which is a reference to the base class of the AbstractTriangle hierarchy, test its operation on all created objects.<br>
Create an array of pointers to the base class of the AbstractTriangle hierarchy, place objects of the created classes into it, and calculate the perimeter and area for each of the objects.<br>
<br>
Comment.
<br>
Note that for this task you need to implement multiple inheritance. <br>

<br>
<b>Task 2.</b>

Implement an abstract container class AbstractContainer containing the following functions:<br>
• virtual destructor;<br>
• checking whether the container is empty or not; (is_Empty)<br>
• checking whether the container is full or not; (is_Full)<br>
<br>
Based on this abstract container class, implement two abstract container classes: AbstractStack and AbstractQueue, containing the following functions:<br>
• adding an item to a container; (push for stack and ins for queue)<br>
• removing items from the container. (pop for stack and del for queue)<br>
<br>
On the basis of the AbstractStack abstract class, create two descendants, namely the ArrayStack (stack on an array) and ListStack (stack on a list) classes, and on the basis of the AbstractQueue class also create two descendants, namely the ArrayRingQueue (ring queue on an array) and ListRingQueue (circular queue on the list).<br>
In each of these classes, define a constructor, destructor, functions for inserting and removing an element, and functions for checking the container for emptyness and overflow of the container.<br>
In the main () test function, define objects of all types, fill each of the containers with five elements of the integer type, and then output the elements from the containers.<br>
<br>
Create a test1 () function that performs the specified actions for an object of the abstract class AbstractStack. As a parameter of this function test1 (), specify a reference or a pointer to an object of the abstract class AbstractStack. Use this function for ArrayStack and ListStack objects.<br>
Create a test2 () function that performs the specified actions for an object of the abstract class AbstractQueue. As a parameter of this function test2 (), specify a reference or a pointer to an object of the abstract class AbstractQueue. Use this function for ArrayRingQueue and ListRingQueue objects.<br>
<br>
Create an array of pointers to an object of the AbstractStack class, put container objects of the ArrayStack and ListStack classes into this array, and perform the operations of adding and removing elements for each of the containers in a loop.<br>
Create an array of pointers to an object of the AbstractQueue class, put container objects of the ArrayRingQueue and ListRingQueue classes into this array, and perform the operations of adding and removing elements for each of the containers in a loop.<br>
<br>
Create an abstract iterator class AbstractIterator, on the basis of which to create iterators for each of the classes: ArrayStackIterator, ListStackIterator, ArrayRingQueueIterator, ListRingQueueIterator. Test the generated iterators.<br>
<br>

Comment:
<br>
An example iterator interface for the ArrayQueue class (queue on array) that loops through the queue in one direction.

```
class ArrayQueueIterator
{
  const ArrayQueue & a; // reference to the queue on the array
  int pos; // current position of the iterator
  ArrayQueueIterator (); // default constructor
public:
  ArrayQueueIterator (const ArrayQueue & a);
  bool in_range () const; // check for range
  void reset_begin (); // reset the iterator to the head of the queue
  int & operator * () const; // display the element at the iterator position
  void operator ++ (); // move the iterator forward one position
};
```

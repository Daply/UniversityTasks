
## Inheritance.

1. Create an ArrayQueue class describing a queue on an integer array. The queue interface is shown below.

class ArrayQueue // queue on the array
{
  int capacity; // queue capacity
int * p; // pointer to array
int head; // index of the first occupied element
int tail; // index of the first unoccupied element
ArrayQueue (); // default constructor
public:
ArrayQueue (const int & capacity); // constructor with parameters
ArrayQueue (const ArrayQueue & q); // copy constructor
~ ArrayQueue (); // queue destructor
void ins (const int & n); // add an item to the queue
int del (); // remove an item from the queue
bool is_empty () const; // is the queue empty?
bool is_full () const; // is the queue full?
void print (ostream & out) const; // view the items in the queue
};

2. On the basis of the ArrayQueue class, create a class inheriting from ArrayDeque - a deque on an array (dek). The standard interface of the ArrayDeque class is shown below.

class ArrayDeque // deque is a deque on an array
{
  int capacity; // deck capacity
  int * p; // pointer to array
  int head; // index of the first occupied element
  int tail; // index of the first unoccupied element
 ArrayDeque (); // default constructor
public:
  ArrayDeque (const int & capacity); // constructor with parameters
  ArrayDeque (const ArrayDeque & d); // copy constructor
  ~ ArrayDeque (); // deque destructor
  void ins_head (const int & n); // include the element in the head of the deck
  void ins_tail (const int & n); // include an element in the tail of the deck
  int del_head (); // exclude the element from the head of the deck
  int del_tail (); // exclude an item from the tail of the deck
  bool is_empty (); // is the deck empty?
  bool is_full (); // dec full?
  void print (ostream & out) const; // view the deck items
};

3. For the ArrayQueue class, create an iterator that loops through the queue in one direction. The iterator interface is shown below.

class ArrayQueueIterator
{
  const ArrayQueue & a; // reference to the queue on the array
  int pos; // current position of the iterator
  ArrayQueueIterator ();
public:
  ArrayQueueIterator (const ArrayQueue & a);
  bool in_range () const; // check for range
  void reset_begin (); // reset the iterator to the head of the queue
  int & operator * () const; // display the element at the iterator position
  void operator ++ (); // move the iterator forward one position
};

4. Based on the ArrayQueueIterator for an array queue (ArrayQueue), implement an ArrayDequeIterator for an array deque (ArrayDeque). Additionally enable the following methods:
 Dump the iterator to the end of the queue.
 Advance the iterator one position back.

To check the performance of the classes, write a test program in which all the methods of the created classes are called.
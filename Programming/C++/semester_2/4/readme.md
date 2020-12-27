
## Laboratory work No. 4

1. Implement the EVEN class describing even numbers, which has the following interface:

```
class Even
{
  int n;
public:
  // constructor
  Even (); // default
  Even (const int & _n); // copy throw (Non_Even)
  // assignment operators
  Even & operator + = (const Even & e);
  Even & operator - = (const Even & e);
  Even & operator * = (const Even & e);
  // unary + and -
  friend Even operator- (const Even & e);
  friend Even operator + (const Even & e);
  // binary comparison operators
  friend bool operator <(const Even & e1, const Even & e2);
  friend bool operator> (const Even & e1, const Even & e2);
  friend bool operator == (const Even & e1, const Even & e2);
  friend bool operator! = (const Even & e1, const Even & e2);
  friend bool operator <= (const Even & e1, const Even & e2);
  friend bool operator> = (const Even & e1, const Even & e2);
  // binary arithmetic operators
  friend Even operator + (const Even & e1, const Even & e2);
  friend Even operator- (const Even & e1, const Even & e2);
  friend Even operator * (const Even & e1, const Even & e2);
  // binary I / O operators
  friend istream & operator >> (istream & in, Even & e); // throw (Non_Even)
  friend ostream & operator << (ostream & out, const Even & e);
};
```

To test the functionality of a class, write a test program in which all the methods of the class are called. Create an array of class objects and execute any two methods.

2. Develop the SECTION_PLANE class to describe the segments located on the integer plane. Class objects have the following attributes:
• coordinates of the start and end points of the segment.
Implement:
• default constructor;
• a constructor that sets field values; check the correctness of setting the coordinates of the start and end points of the segment, provide for the generation of the Non_Section exception if this condition is violated;
• copy constructor;
• input-output of class objects into a stream using overloaded operators << and >> for this purpose; when entering, check for the correctness of specifying the coordinates of the start and end points of the segment; provide for the generation of a Non_Section exception if this condition is violated;
• assignment of one object to another using the overloaded operator = for this purpose;
• obtaining the value of the length of a segment using the overloaded unary operator & for this purpose;
• getting the coordinates of the specified point using the overloaded indexing operator [] for this purpose;
• increasing or decreasing the values ​​of coordinates of the starting or ending points of the segment by one using the overloaded operators ++ (increment) and -- (decrement);
• obtaining a new segment, symmetric to the given segment relative to the center of the coordinate system, using the overloaded operator ~ for this purpose;
• comparison of two objects of a class using for these purposes comparison operators (==,! =) Overloaded as friendly functions; two objects are considered equal to each other if they completely coincide;
• comparison of the lengths of two segments using overloaded operators <, <=,>,> = for this purpose;

To test the functionality of a class, write a test program in which all the methods of the class are called. Create an array of class objects and execute any two methods.

3. Create a class, the specification of which is given below.<br>
Ensure that the unique numeric identifier attribute values ​​are unique.<br>
Define a constructor with parameters, provide necessary exceptions.<br>
Define methods get_AttributeName () for all attributes, set_AttributeName () for variable attributes, override operators >>, << for input and output of information about an object.
Define a static method get_count () to display the number of objects created.<br>
In the parent program, create an array of pointers to objects of at least five elements.<br>
Fill this array with elements of the appropriate class.<br>
Implement methods for selecting data in accordance with the specified criterion and methods that order the elements in an array of objects in accordance with the specified rule.<br>
It is advisable to use qsort to order objects in the specified order.<br>
Additionally, test the static method of the get_count () class. Execution of actions in the head program is realized through the menu.<br>

Class Painting: unique numeric identifier (id), paintitng name, name of the artist, year of creation, estimated value, genre (landscape, portrait, etc., defined via enum).
Create an array of objects. Output:
a) a list of all paintings;
b) a list of paintings by the specified artist.
c) a list of paintings above a given value;
d) a list of paintings for a given year of writing of the specified genre;
e) a list of paintings in descending order of value;
f) a list of paintings in alphabetical order of titles.
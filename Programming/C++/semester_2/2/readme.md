
## Classes

Implement the STUDENT class, which has the following interface:

```
class Student
{
  char name[10];  	// student name
  int  num;      	// course number
  double grade;   	// average grade
public:
  // constructors
  Student();      // default constructor
  Student (const char* name, const int& num, const double& grade);	// constructor with parameters
  	
  // functions for data input-output into an object of type Student
  void output (ostream& out) const;
  Student& input (istream& in, ostream & out);

  // function that transfers a student to the next course if his average grade is greater than or equal to 4
  Student& changeNum(istream& in);
  	
  // functions that implement obtaining and setting a new value of the average score
  double getGrade() const {return grade;};
  Student& setGrade(const double& grade);
	
  // function of comparing the average scores of two students for equality 
  friend bool equal_grade (const Student & r1, const Student & r2);
};
```

To check the functionality of the STUDENT class, write a test program in which all the methods of the class are called.
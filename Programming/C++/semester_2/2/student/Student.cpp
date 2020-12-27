#include "Student.h"

Student::Student(const char* name, const int& num, const double& grade)
{
	strcpy(this->name, name);
	this->num = num;
	this->grade = grade;
}
//Student::Student(const Student& r)
//{
//	strcpy(name, r.name);
//    num = r.num;
//	grade = r.grade;
//}
void Student:: output(ostream& out) const
{
	out << "Name = " << name << endl;
	out << "Number = " << num << endl;
	out << "Grade = " << grade << endl;
}
Student& Student:: input(istream &in, ostream &out)
{
out<<"Input students parameteres: "<<endl;
in>>name>>num>>grade;
return *this;
}
Student& Student::changeNum(istream& in)
{
  in>>num;
   return Student (name,num,grade);
}
Student& Student::setGrade(const double& grade)
 {
  this->grade = grade;
    return *this;
 }
bool equal_grade (const Student & r1, const Student & r2)
 {
	 return r1.grade == r2.grade;
 }
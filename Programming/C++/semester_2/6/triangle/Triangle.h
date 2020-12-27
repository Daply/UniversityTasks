#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<iostream>
#include <math.h>

using namespace std;

struct Not_Rectangular{};

class Triangle
{
public:
	virtual ~Triangle(){}
	virtual double perimetr() const = 0; // calculate the perimeter
	virtual double area() const = 0; // calculate area
};

class Isosceles_triangle: public Triangle
{
    double side1;
    double side12;
    double side3;

public:
    Isosceles_triangle (const double & side1,const double & side3):side1(side1),side12(side1),side3(side3){};

	double perimetr() const
    {
        return side1+side12+side3;
    }

	double area() const
    {
        double p = perimetr()/2;
        return sqrt(p*(p-side1)*(p-side12)*(p-side3));
    }
};

class Equilateral_triangle: virtual public Isosceles_triangle
{
    double side1;
    double side2;
    double side3;

public:
	Equilateral_triangle (const double & side1):Isosceles_triangle(side1, side3),side2(side2){};

	double perimetr() const
    {
        return side1+side2+side3;
    }

	double area() const
    {
        double p = perimetr()/2;
        return sqrt(p*(p-side1)*(p-side2)*(p-side3));
    }
};

class Rectangular_triangle: public Triangle
{
    double side1;
    double side2;
    double side3;

public:
	Rectangular_triangle(const double & side1,const double & side2,const double & side3):side1(side1),side2(side2),side3(side3)
	{
	    if (side3 > side1 && side3 > side2)
        {
            if (sqrt(side1*side1 + side2*side2) != side3)
            {
                throw Not_Rectangular();
            }
        }
        else if (side2 > side1 && side2 > side3)
        {
            if (sqrt(side1*side1 + side3*side3) != side2)
            {
                throw Not_Rectangular();
            }
        }
        else if (side1 > side2 && side1 > side3)
        {
            if (sqrt(side3*side3 + side2*side2) != side1)
            {
                throw Not_Rectangular();
            }
        }
	};

	double perimetr() const
    {
        return side1+side2+side3;
    }

	double area() const
    {
        double p = perimetr()/2;
        return sqrt(p*(p-side1)*(p-side2)*(p-side3));
    }
};

class Rectangular_isosceles_triangle: virtual public Rectangular_triangle, virtual public Isosceles_triangle
{
    double side1;
    double side12;
    double side3;

public:
	Rectangular_isosceles_triangle(const double & side1,const double & side3):Isosceles_triangle(side1, side3),Rectangular_triangle(side1,side12,side3){};

	double perimetr() const
    {
        return side1+side12+side3;
    }

	double area() const
    {
        double p = perimetr()/2;
        return sqrt(p*(p-side1)*(p-side12)*(p-side3));
    }
};

#endif // TRIANGLE_H

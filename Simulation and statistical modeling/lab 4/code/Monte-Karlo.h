#pragma once
#include <iostream>
#include <string>
#include <boost\multiprecision\cpp_int.hpp>
#include <boost\multiprecision\cpp_int\multiply.hpp>

using namespace std;
using namespace boost::multiprecision;

class Monte_Carlo
{
public:

	Monte_Carlo() {};

	~Monte_Carlo()
	{
		cout << "Memory has been cleaned." << endl;
	}


	double func_1(double x_);
	double countIntegral_1(double * seq);
	double func_2(double x_);
	double countIntegral_2(double * seq);
	double quadr_gauss(int integr);
	double countIndepRandVals(int integr);
	
	double fi_inverseCDFNormal(double alpha);

	void solvingSLAU(double * seq);

};
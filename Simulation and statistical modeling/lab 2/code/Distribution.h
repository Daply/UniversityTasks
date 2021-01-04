#pragma once
#include <iostream>
#include <string>
#include <boost\multiprecision\cpp_int.hpp>
#include <boost\multiprecision\cpp_int\multiply.hpp>

using namespace std;
using namespace boost::multiprecision;

class Distribution
{
public:
	//for bernulli, binomial, negative binomial distribution
	double probability = 0.6;	
	//for discrete
	double a = 0;
	double b = 24;
	int mod = 24;
	//for pousson
	int lambda = 3;

	//for delta
	double Eps = 0.05;

	Distribution() {};

	~Distribution()
	{
		cout << "Memory has been cleaned." << endl;
	}

	int * Bernulli(double * sequence, int num);
	int * Discrete(double * sequence, int num);
	int * Binomial(double * sequence, int n);
	int * negativeBinomial(double * sequence, int n);
	int * Geometric(double * sequence, int num);
	int * Pouasson(double * sequence, int n);

	void confidenceInterval(int * sequence, int num, double alpha);
	double average(int * sequence, int num);
	double fi_inverseCDFNormal(double alpha);
	double inverseCDFHisquare(double k);

	double HiSquareCriteria(int * seq, int num, string dist, double k);
	double CDF(double x, string dist);
	cpp_int factorial(int n);
	cpp_int binom(int n, int k);
	double delta(string dist);
	int hipotez(double delta, double hi);

};
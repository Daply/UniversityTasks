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

	Distribution() {};

	~Distribution()
	{
		cout << "Memory has been cleaned." << endl;
	}

	double * Uniform(double * sequence, int num, double a, double b);
	double * normalDist(double * sequence, int num, int m, double mu, double sigma);
	double * lognormalDist(double * sequence, int num, int m, double mu, double sigma);
	double * exponentialDist(double * sequence, int num, double lambda);
	double * Veibull_GnedenkoDist(double * sequence, int num, double lambda, double alpha);
	double * gammaDist(double * sequence, int num, double alpha, double beta);
	double * CauchyDist(double * sequence, int num, double gamma, double coef);
	double * Logistic(double * sequence, int num, double a, double b);
	double * ChiSquareDist(double * sequence, int num, int m, int k);
	double * Student(double * sequence, int num, int m, int Sm);


	double HiSquareCriteria(double * seq, int num, string dist, double k);
	double KolmogorovCriteria(double * seq, int num, string dist);
	double CDF(double x, string dist);
	double Normal(double x);
	double middle(double * seq, int num);
	double variance(double * seq, int num);
	cpp_int factorial(int n);
	cpp_int binom(int n, int k);
	int hipotez(double delta, double hi);

};
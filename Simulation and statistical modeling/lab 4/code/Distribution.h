#pragma once
#include <iostream>
#include <string>

using namespace std;

class Distribution
{
public:

	Distribution() {};

	~Distribution()
	{
		cout << "Memory has been cleaned." << endl;
	}

	double * Uniform(double * sequence, int num, double a, double b);
	double * exponentialDist(double * sequence, int num, double lambda);

};
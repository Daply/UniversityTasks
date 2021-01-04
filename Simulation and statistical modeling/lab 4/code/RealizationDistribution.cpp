#include "Distribution.h";
#include "Math.h";
#include <iostream>;
#include <iomanip>

using namespace std;

double * Distribution::Uniform(double * sequence, int num, double a, double b) {
	double * seq = new double[num];
	double sum = 0;
	for (int i = 0; i < num; i++)
	{
		if (sequence[i] < a)
			seq[i] = 0;
		if(sequence[i] >= a && sequence[i] < b)
			seq[i] = sequence[i] * (b-a) + a;
		if (sequence[i] >= b)
			seq[i] = 1;
	}
	return seq;
}

double * Distribution::exponentialDist(double * sequence, int num, double lambda)
{
	double * seq = new double[num];
	for (int i = 0; i < num; i++)
	{
		//seq[i] = -(log(sequence[i]) / lambda);
		seq[i] = -(log(1 - sequence[i]) / lambda);
	}
	return seq;
}


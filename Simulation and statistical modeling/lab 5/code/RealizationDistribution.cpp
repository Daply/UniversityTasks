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
			seq[i] = sequence[i] * (b-a) + a;
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
		//seq[i] = -(log(sequence[i]) / lambda);
	/*	if (seq[i] < 0.04)
			seq[i] += 0.06;*/
	}
	return seq;
}

int * Distribution::Pouasson(double * sequence, int n, double lambda)  //works right!!!
{
	int num = n;
	double e = exp(-lambda);
	int j = 0, k = 0;
	int* seq = new int[num];
	double prod = sequence[0];
	for (int i = 0; i < num; i++)
	{
		while (prod >= e)
		{
			k++;
			prod *= sequence[j + k];
		}
		seq[i] = k;
		j += (k+1);
		prod = sequence[j];
		k = 0;
	}
	return seq;
};

int* Distribution::Bernulli(double * sequence, int num, double probability)   //works right!!!
{
	int * seq = new int[num];

	for (int i = 0; i < num; i++)
		if (sequence[i] <= probability)
			seq[i] = 1;
		else
			seq[i] = 0;
	return seq;
};
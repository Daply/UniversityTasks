#include "Distribution.h";
#include "Math.h";
#include <stdio.h>;
#include <stdlib.h>;
#include <iostream>;
#include <iomanip>
#include <string>
#include <boost\multiprecision\cpp_int.hpp>
#include <boost\multiprecision\cpp_int\multiply.hpp>

using namespace std;
using namespace boost::multiprecision;

int* Distribution::Bernulli(double * sequence, int num)   //works right!!!
{
	int * seq = new int[num];

	for (int i = 0; i < num; i++)
		if (sequence[i] <= probability)
			seq[i] = 1;
		else
			seq[i] = 0;
	return seq;
};

int * Distribution::Discrete(double * sequence, int num)   //works right!!!
{
	int * seq = new int[num];
	for (int i = 0; i < num; i++)
		seq[i] = sequence[i] * (mod+1);
	return seq;
};

int* Distribution::Binomial(double * sequence, int n)   //works right!!!
{
	int * seq = new int[n];
	int num = mod*n;
	int count = 0;
	for (int i = 0; i < num; i += mod)
	{
		count = 0;
		for (int j = 0; j < mod; j++)
		{
			if (sequence[i + j] < probability)
				count++;
		}
		seq[i/mod] = count;
	}
	return seq;
};

int* Distribution::negativeBinomial(double * sequence, int n)   //works right!!!
{
	int * seq = new int[n];
	int sum = 0;
	int num = n*mod;
	for (int i = 0; i < num; i += mod)
	{
		sum = 0;
		for (int j = 0; j < mod; j++)
		{
				sum += log(sequence[i+j]) / log(1 - probability);
		}
		seq[i/mod] = sum;
	}
	return seq;
};

int * Distribution::Geometric(double * sequence, int num)   //works right!!!
{ 
	int * seq = new int[num];
	for (int i = 0; i < num; i++)
		seq[i] = log(sequence[i])/log(1-probability);
	return seq;
};

int * Distribution::Pouasson(double * sequence, int n)  //works right!!!
{
	int num = n * 50;
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

////////////////////////////Hi Square Criteria Realization///////////////////////////////////

int comp(const int *a, const int *b)
{
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else return 0;
};

double Distribution::HiSquareCriteria(int * seq, int num, string dist, double k)
{
	int position = 0;
	int n = 0;
	double * sortedSeq = new double[num];
	qsort(seq, num, sizeof(int), (int(*) (const void *, const void *)) comp);
	for (int i = 0; i < num; i++)
		sortedSeq[i] = (double)seq[i];
	double X0 = sortedSeq[0];
	double Xn = sortedSeq[num-1];
	double Xright, Xleft = 0;
	double X2 = 0;
	double h = (Xn-X0) / (k-1);
	Xright = X0 + h/2;
	double pi = CDF(Xright,dist);
	int f = 0;
	for(int i = 0; i < k-1; i++)
	{
		while (sortedSeq[position] < Xright)
		{
			n++; 
			position++;
		}
		if(pi != 0)
		X2 += pow((n - num*pi),2)/(num*pi);
		n = 0;
		Xleft = Xright;
		Xright += h;
		pi = CDF(Xright, dist) - CDF(Xleft, dist);
	}	
	Xleft = Xn - h/2;
	pi = 1 - CDF(Xleft, dist);
    position = num-1;
		while (sortedSeq[position] > Xleft)
		{
			n++;
			position--;
		}
		X2 += pow((n - num*pi),2) / (num*pi);
	return X2;
};

double Distribution::delta(string dist)
{
	double result = 0;
	if (dist.compare("Bernulli") == 0)
		result = 3.841458820694125;
	if (dist.compare("Discrete") == 0)
		result = 36.415028501807306;
	if (dist.compare("Binomial") == 0)
		result = 30.143527205646155;
	if (dist.compare("Negative binomial") == 0)
		result = 56.94238714682409;
	if (dist.compare("Geometric") == 0)
		result = 21.026069817483062;
	if (dist.compare("Pousson") == 0)
		result = 18.307038053275143;
	return result;
};

int Distribution::hipotez(double delta, double hi)
{
	if (delta > hi)
		return 0;
	else
		return 1;
};

double Distribution::CDF(double x, string dist)
{
	double result = 0;
	if (dist.compare("Bernulli") == 0)                      ///WORKS RIGHT!!!
	{
		if (x < 0)
			result = 0;
		if (x >= 0 || x < 1)
			result = 1 - probability;
		if (x >= 1)
			result = 1;
	}
	if (dist.compare("Discrete") == 0)						///WORKS RIGHT!!!
	{
		result = (x - a) / b;
	}
	if (dist.compare("Binomial") == 0)                       ///WORKS RIGHT!!!
	{
		double number;
		cpp_int bin;
		for (int i = 0; i <= x; i++)
		{
			bin = binom(mod, i);
			number = bin.convert_to<double>();
			result += number*pow(probability, i)*pow(1 - probability, mod - i);
		}
	}
	if (dist.compare("Negative binomial") == 0)              ///WORKS RIGHT!!!
	{
		double number;
		cpp_int bin;
		for (int i = 0; i <= x; i++)
		{
			bin = binom(mod + i - 1, i);
			number = bin.convert_to<double>();
			result += number*pow(probability, mod)*pow(1 - probability, i);
		}
	}
	if (dist.compare("Geometric") == 0)                      ///WORKS RIGHT!!!
	{
		int x_ = x;
		result = 1 - pow((1 - probability), (x_+1));
	}
	if (dist.compare("Pousson") == 0)                        ///WORKS RIGHT!!!
	{
		double number;
		cpp_int fact;
		for (int i = 0; i <= x; i++)
		{
			fact = factorial(i);
			number = fact.convert_to<double>();
			result += (pow(lambda, i)*exp(-lambda)) / number;
		}
	}
	return result;
};

cpp_int Distribution::factorial(int n)
{
	cpp_int res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
};

cpp_int Distribution::binom(int n, int k)
{
	cpp_int result, f = 1, f2;
	if (k <= n)
	{
		result = factorial(n) / (factorial(k)*factorial(n - k));
	}
	else
		result = 1;
	return result;
};

//////////////////////////Confidence interval///////////////////////////////

double Distribution::fi_inverseCDFNormal(double alpha)
{
	double al = alpha;
	double t = sqrt((-2)*log(1 - al));
	double c0 = 2.515517;
	double c1 = 0.802853;
	double c2 = 0.010328;
	double d0 = 1.432788;
	double d1 = 0.189269;
	double d2 = 0.001308;
	double mistake = 0.00045;
	double fi = t - ((c0 + c1*t + c2*t*t) / (1 + d0*t + d1*t*t + d2*t*t*t)) + mistake;
	return fi;
}

double Distribution::inverseCDFHisquare(double k)
{
	double result = 0;
	double nu = k-1;
	double al = 1 - Eps;
	double F;
	F = nu*pow((1- 2/(9*nu)+ fi_inverseCDFNormal(al)*sqrt(2 / (9 * nu))),3);
	result = F;
	return result;
}

double Distribution::average(int * sequence, int num) {
	double result = 0;
	for (int i = 0; i < num; i++)
		result += sequence[i];
	result /= num;
	return result;
}

void Distribution::confidenceInterval(int * sequence, int num, double alpha)
{
	double pointEs = average(sequence, num);
	double fi = fi_inverseCDFNormal(alpha);
	double L = pointEs - sqrt((pointEs*(1-pointEs))/num)*fi;
	double U = pointEs + sqrt((pointEs*(1 - pointEs)) / num)*fi;
	cout << "L=" << L << endl;
	cout << "U=" << U << endl;
}
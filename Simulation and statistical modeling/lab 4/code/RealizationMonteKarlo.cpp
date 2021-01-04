#include "Monte-Karlo.h";
#include "Distribution.h";
#include "Math.h";
#include <stdio.h>;
#include <stdlib.h>;
#include <iostream>;
#include <fstream>
#include <iomanip>
#include <string>
#include <boost\multiprecision\cpp_int.hpp>
#include <boost\multiprecision\cpp_int\multiply.hpp>

using namespace std;
using namespace boost::multiprecision;



double Monte_Carlo::func_1(double x_)
{
	double x = 0;
	x = pow(x_, 10)*sqrt(1 + 2 * pow(x_, 8));
	return x;
}

double Monte_Carlo::countIntegral_1(double * seq)
{
	double I = 0, N = 10000;
	double a = 0, b = 1;
	Distribution * dist = new Distribution();
	double *s = dist->Uniform(seq, N, a, b);
	for (int i = 0; i < N; i++)
	{
		I += func_1(s[i]);
	}
	I *= (b - a) / N;
	return I;
}

double Monte_Carlo::func_2(double x_)
{
	double x = 0;
	x = 1 / (1 + pow(x_, 3));
	return x;
}

double Monte_Carlo::countIntegral_2(double * seq)
{
	double I = 0, N = 10000;
	double lambda = 1;
	Distribution * dist = new Distribution();
	double *s = dist->exponentialDist(seq, N, lambda);
	for (int i = 0; i < N; i++)
	{
		I += func_2(s[i]) / exp(-lambda*s[i]);
	}
	I = I / (N*lambda);
	return I;
}

double Monte_Carlo::quadr_gauss(int integr) {
	double res = 0;
	double k = 0;
	if (integr == 1)
	{
		k = 0.00001;
		double a = 0, b = 1;
		for (double i = a; i < b; i += k)
			res += func_1((i + i + k) / 2 + k / sqrt(12)) + func_1((i + i + k) / 2 - k / sqrt(12));
	}
	if (integr == 2)
	{
		k = 0.1;
		double a = 0, b = 1000;
		for (double i = a; i < b; i += k)
			res += func_2((i + i + k) / 2 + k / sqrt(12)) + func_2((i + i + k) / 2 - k / sqrt(12));
	}
	res *= k / 2;
	return res;
}

double Monte_Carlo::countIndepRandVals(int integr)
{
	double Eps = 0.001;
	double exactValue = 0;
	double sigma = 0;
	double fi = fi_inverseCDFNormal((0.95 + 1) / 2);
	if (integr == 1)
	{
		sigma = 0.0990483;
		exactValue = 0.13242437923930755;
	}
	else
	{
		sigma = 0.128055;
		exactValue = 1.2091995761561374;
	}
	double res = pow((sigma / Eps), 2)*pow(fi,2);
	return res;
}



double Monte_Carlo::fi_inverseCDFNormal(double alpha)
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




void Monte_Carlo::solvingSLAU(double * seq)
{

	///////////////////////////////////INITIALIZATION/////////////////////////////////////
	ifstream fin("17-student.txt");
	int n = 0;
	fin >> n;
	double ** A = new double*[n];
	double * f = new double[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			fin >> A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		fin >> f[i];
	}

	fin.close();
	double s = 0;
	int N = 1000;                       //Markov chain length 1000
	int * markov_chain = new int[N];  //Markov chain
	double * Q = new double[N];       //weights of states of Markov chain
	double * q = new double[n];
	int m = 10000;                      //quantity of realisations of Markov chain 10000
	double * ksi = new double[m];       //random values
	for (int i = 0; i < m; i++)
	{
		ksi[i] = 0;
	}
	double alpha;                       //BSV
	double * X = new double[n];         //Solution
	for (int i = 0; i < n; i++)
	{
		X[i] = 0;
	}
	double ** h = new double*[n];
	for (int i = 0; i < n; i++)
	{
		h[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			h[i][j] = 0;
		}
		h[i][i] = 1;
	}
	double n_ = n;
	double probability = (double)(1 / n_);
	double * pi = new double[n];        //vector of start posibilities of Markov chain
	for (int i = 0; i < n; i++)
	{
		pi[i] = probability;
	}
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += probability;
		q[i] = sum;
	}

	double ** p = new double*[n];       //matrix of states of Markov chain
	for (int i = 0; i < n; i++)
	{
		p[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			p[i][j] = probability;
		}
	}


	//int numMM = 14039333;
	//double * seq = random_generate_maclaren_marsali((rand() % (numMM)+1), 220760, 961853, 14039333, 3219,
	//	2698, 571, 23531, 24273, m*(N + 1));
	//int numMM = 1728931;
	//double * seq = random_generate_maclaren_marsali((rand() % (numMM)+1), 353323, 565573, 19027279, 4703,
	//2868, 301, 23531, 24273, m*(N + 1));

	//////////////////////////////Modeling of m Markov chains/////////////////////////////
	for (int num = 0; num < n; num++)
	{
		////////////////////////////////////
		for (int i = 0; i < m; i++)
		{
			ksi[i] = 0;
		}
		////////////////////////////////////
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < n; k++)
				{
					//alpha = rand() / float(RAND_MAX);
					alpha = seq[i*(j + 1)];
					if (alpha < q[k])
					{
						markov_chain[j] = k;
						break;
					}
				}
			}

			if (pi[markov_chain[0]] > 0)
				Q[0] = h[num][markov_chain[0]] / pi[markov_chain[0]];
			else
				Q[0] = 0;

			for (int j = 1; j < N; j++)
			{
				if (p[markov_chain[j - 1]][markov_chain[j]] > 0)
					Q[j] = (Q[j - 1] * A[markov_chain[j - 1]][markov_chain[j]]) / p[markov_chain[j - 1]][markov_chain[j]];
				else
					Q[j] = 0;
			}

			for (int j = 0; j < N; j++)
			{
				ksi[i] += Q[j] * f[markov_chain[j]];
			}
		}

		////////Counting X////////

		for (int j = 0; j < m; j++)
		{
			X[num] += ksi[j];
		}
		X[num] = X[num] / m;
	}


	for (int i = 0; i < n; i++)
	{
		cout << X[i] << "  ";
	}
	cout << endl;
	cout << "Difference" << endl;

	for (int j = 0; j < n; j++)
	{
		alpha = 0;
		for (int k = 0; k < n; k++)
			alpha += A[j][k] * X[k];
		cout << (X[j] - f[j] - alpha) << "  ";
	}
	cout << endl;


	//////////////////////////////////CLEANING MEMORY/////////////////////////////////////
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
	delete[] f;
	delete[] markov_chain;
	delete[] Q;
	delete[] q;
	delete[] ksi;
	delete[] X;
	for (int i = 0; i < n; i++)
		delete[] h[i];
	delete[] h;
	delete[] pi;
	for (int i = 0; i < n; i++)
		delete[] p[i];
	delete[] p;
}
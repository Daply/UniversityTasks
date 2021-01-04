#include <iostream>
#include <fstream>
#include <cmath>
#include "Distribution.h";
#include "Monte-Karlo.h";

using namespace std;
using namespace boost::multiprecision;

__int64 linear_congruent_operator(__int64 x0, __int64 a, __int64 c, __int64 m) //works right!!!
{
	__int64 result = (a*x0 + c) % m;
	return result;
}

double * random_generate_lco(__int64 x0, __int64 a,
	__int64 c, __int64 m, __int64 n)                //works right!!!
{
	__int64 * seq = new __int64[n];
	double * seqDouble = new double[n];
	double d;
	seq[0] = linear_congruent_operator(x0, a, c, m);
	d = seq[0];
	seqDouble[0] = d / m;
	for (int i = 1; i < n; i++)
	{
		seq[i] = linear_congruent_operator(seq[i-1],a,c,m);
		d = seq[i];
		seqDouble[i] = d/ m;
	}
	return seqDouble;
}

double * random_generate_maclaren_marsali(__int64 x0_1, __int64 a1, __int64 c1,
	__int64 m1, __int64 x0_2, __int64 a2, __int64 c2, __int64 m2,
	__int64 k, __int64 n)                                  //works right!!!
{
	double * V = new double[k];
	double * seqA = new double[n];
	double * seqB = random_generate_lco(x0_1, a1, c1, m1, n + k);
	double * seqC = random_generate_lco(x0_2, a2, c2, m2, n + k);

	for (int i = 0; i < k; i++)
		V[i] = seqB[i];
	for (int i = 0; i < n; i++)
	{
		int s = seqC[i] * k;
		seqA[i] = V[s];
		V[s] = seqB[i + k];
	}
	delete []V;
	delete []seqB;
	delete []seqC;
	return seqA;
}

double * alpha_gener()
{
	int N = 10000;
	double * seq = new double[N];
	double i_, N_ = N;
	for (int i = 0; i < N; i++)
	{
		i_ = i;
		seq[i] = i_ / (N_+1);
	}

	return seq;
}

int countExperiments(int integr)
{
	int count = 0;
	int N = 1000;
	double * seq = random_generate_maclaren_marsali(14039333, 220760, 961853, 14039333, 3219,
		2698, 571, 23531, 24273, 0);
	Monte_Carlo * mv = new Monte_Carlo();
	for (int i = 0; i < N; i++)
	{
		//if (i % 10 == 0)
		//	cout << i << endl;
		seq = random_generate_maclaren_marsali(14039333-2*i, 220760, 961853, 14039333, 3219,
			2698, 571, 23531, 24273, 10000);
		if (integr == 1)
		{
			if (abs(0.132424 - mv->countIntegral_1(seq))< 0.001)
				count++;
		}
		else
		{
			if (abs(1.209199 - mv->countIntegral_2(seq))< 0.001)
				count++;
		}

	}
	delete seq;
	delete mv;
	return count;
}

int main()
{
	double * seq = random_generate_maclaren_marsali(14039333, 220760, 961853, 14039333, 3219,
		2698, 571, 23531, 24273, 10000);
	double * seq_ = alpha_gener();

	Monte_Carlo * mc = new Monte_Carlo();

	///////////////////////SOLVING INTEGRALS///////////////////////////
	cout << "Solution of first integral using Monte-Karlo method" << endl;
	cout << setprecision(10) << mc->countIntegral_1(seq) << endl;
	cout << "Solution of first integral using Quadratic Gauss method" << endl;
	cout << setprecision(10) << mc->quadr_gauss(1) << endl;
	cout << "Number of random values for exact 0.001" << endl;
	cout << setprecision(10) << mc->countIndepRandVals(1) << endl;
	cout << "Number experiments for exact 0.001" << endl;
	cout << setprecision(10) << countExperiments(1) << endl;
	cout << "Solution of first integral using Monte-Karlo method with given generator" << endl;
	cout << setprecision(10) << mc->countIntegral_1(seq_) << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "Solution of second integral using Monte-Karlo method" << endl;
	cout << setprecision(10) << mc->countIntegral_2(seq) << endl;
	cout << "Solution of second integral using Quadratic Gauss method" << endl;
	cout << setprecision(10) << mc->quadr_gauss(2) << endl;
	cout << "Number of random values for exact 0.001" << endl;
	cout << setprecision(10) << mc->countIndepRandVals(2) << endl;
	cout << "Number of experiments for exact 0.001" << endl;
	cout << setprecision(10) << countExperiments(2) << endl;
	cout << "Solution of second integral using Monte-Karlo method with given generator" << endl;
	cout << setprecision(10) << mc->countIntegral_2(seq_) << endl;
	/////////////////////////SOLVING SLAU//////////////////////////////
	
	int numMM = 14039333, m = 10000, N = 1000;
	double * seq1 = random_generate_maclaren_marsali((rand() % (numMM)+1), 220760, 961853, 14039333, 3219,
		2698, 571, 23531, 24273, m*(N + 1));

	mc->solvingSLAU(seq1);

	delete seq;
	delete seq1;
	delete seq_;
	delete mc;
	system("pause");
}
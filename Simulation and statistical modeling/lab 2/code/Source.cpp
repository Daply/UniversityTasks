#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include "Distribution.h";
#include <boost\multiprecision\cpp_int.hpp>
#include <boost\multiprecision\cpp_int\multiply.hpp>

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

void print(double * a, double* a1[], int n )
{
	for (int i = 0; i < n; i+=10) 
		{
			for (int j = 0; j < 100; j++)
			{
				a1[i/100][j] = a[i + j];
			}
		}
			
	cout << "Macklaren-Marsali sequence" << endl;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			cout << setprecision(10) << a1[i][j] << "  ";
		}
		cout << endl;
	}
}

int max_(int* seq, int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (seq[i]>seq[max])
			max = i;
	}
	return seq[max];
}

int min_(int* seq, int n)
{
	int min = 0;
	for (int i = 1; i < n; i++)
	{
		if (seq[i]<seq[min])
			min = i;
	}
	return seq[min];
}

double * randoms(int n)
{
	srand(time(0));
	double * r = new double[n];
	for (int i = 0; i < n; i++) {
		r[i] = (rand() % n + 1);
		r[i] = r[i] / n;
	}
	return r;
}

int main()
{
	ofstream fout("output.txt");
	ifstream fin("inputMM.txt");

	__int64 x0_1, a1, c1, m1;
	__int64 x0_2, a2, c2, m2;
	__int64 koef,n = 10000; 

	//fin >> x0_1;
	//fin >> a1; 
	//fin >> c1;
	//fin >> m1;
	//fin >> x0_2; 
	//fin >> a2; 
	//fin >> c2; 
	//fin >> m2;
	//fin >> koef;
	//fin >> n;

	int mod = 24;
	double alpha = 0.95;
	double * a = random_generate_maclaren_marsali(1728931, 353323, 565573, 19027279, 4703,
		2868, 301, 23531, 100, n);
	//double * a = random_generate_maclaren_marsali(x0_1, a1, c1, m1, x0_2, a2, c2, m2, k, n);
	double * b = random_generate_maclaren_marsali(1728931, 353323, 565573, 19027279, 4703,
		2868, 301, 23531, 100, mod*n);
	//double * b = random_generate_maclaren_marsali(x0_1, a1, c1, m1, x0_2, a2, c2, m2, k, mod*n);
	double * c = random_generate_maclaren_marsali(1728931, 353323, 565573, 19027279, 4703,
		2868, 301, 23531, 100, 50 * n);
	//double * c = random_generate_maclaren_marsali(x0_1, a1, c1, m1, x0_2, a2, c2, m2, k, 50*n);

	double *a_rand = randoms(n);
	double *b_rand = randoms(mod*n);
	double *c_rand = randoms(50*n);

	Distribution* dist = new Distribution();
	int* seqBernulli = dist->Bernulli(a, n);
	int* seqBernulliRand = dist->Bernulli(a_rand, n);
	cout << "Bernulli distribution" << endl;
	double k = 2;
	double delta = dist->inverseCDFHisquare(k);
	double hi = dist->HiSquareCriteria(seqBernulli, n, "Bernulli", k)-1;
	int H = dist->hipotez(delta,hi);
	cout << "probability=" << 0.6 << endl;
	cout << "H" << H << "  " << setprecision(15) << hi  << "  " << delta << endl;
	cout << "Confidence interval" << endl;
	dist->confidenceInterval(seqBernulli, n, (alpha+1)/2);
	////////////////////////////////////////////////////////////////////////////
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqBernulliRand, n, "Bernulli", k);
	H = dist->hipotez(delta, hi);
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;
	cout << "Confidence interval" << endl;
	dist->confidenceInterval(seqBernulliRand, n, (alpha + 1) / 2);

	int* seqDiscrete = dist->Discrete(a,n);
	int* seqDiscreteRand = dist->Discrete(a_rand, n);
	cout << "Discrete distribution" << endl;
	k = mod + 1;
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqDiscrete, n, "Discrete", k);
	H = dist->hipotez(delta, hi);
	cout << "a=" << 0 << " b=" << mod << endl;
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;
	//////////////////////////////////////////////////////////////////////////////
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqDiscreteRand, n, "Discrete", k);
	H = dist->hipotez(delta, hi);
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;

	int* seqBinomial = dist->Binomial(b, n);
	int* seqBinomialRand = dist->Binomial(b_rand,n);
	int max = max_(seqBinomial,n);
	int min = min_(seqBinomial,n);
	cout << "Binomial distribution" << endl;
	k = max - min + 1;
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqBinomial, n, "Binomial", k);
	H = dist->hipotez(delta, hi);
	cout << "n=" << (mod-1) << " probability=" << 0.6 << endl;
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;
	////////////////////////////////////////////////////////////////////////////
	max = max_(seqBinomialRand, n);
	min = min_(seqBinomialRand, n);
	k = max - min + 1;
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqBinomialRand, n, "Binomial", k);
	H = dist->hipotez(delta, hi);
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;

	int* seqNBinomial = dist->negativeBinomial(b, n);
	int* seqNBinomialRand = dist->negativeBinomial(b,n);
	max = max_(seqNBinomial, n);
	min = min_(seqNBinomial, n);
	cout << "Negative binomial distribution" << endl;
	k = mod;
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqNBinomial, n, "Negative binomial", k);
	H = dist->hipotez(delta, hi);
	cout << "n=" << (mod - 1) << " probability=" << 0.6 << endl;
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;
	//////////////////////////////////////////////////////////////////////////////
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqNBinomialRand, n, "Negative binomial", k);
	H = dist->hipotez(delta, hi);
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;

	int* seqGeometric = dist->Geometric(a, n);
	int* seqGeometricRand = dist->Geometric(a_rand,n);
	max = max_(seqGeometric, n);
	min = min_(seqGeometric, n);
	cout << "Geometric distribution" << endl;
	k = max - min + 1;
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqGeometric, n, "Geometric", k);
	H = dist->hipotez(delta, hi);
	cout << "probability=" << 0.6 << endl;
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;
	//////////////////////////////////////////////////////////////////////////////
	max = max_(seqGeometricRand, n);
	min = min_(seqGeometricRand, n);
	k = max - min + 1;
	delta = dist->inverseCDFHisquare(k);
	hi = dist->HiSquareCriteria(seqGeometricRand, n, "Geometric", k);
	H = dist->hipotez(delta, hi);
	cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;

	//int* seqPousson = dist->Pouasson(c, n);
	//int* seqPoussonRand = dist->Pouasson(c_rand,n);
	//max = max_(seqPousson, n);
	//min = min_(seqPousson, n);
	//cout << "Pousson distribution" << endl;
	//k = max - min + 1;
	//delta = dist->inverseCDFHisquare(k);
	//hi = dist->HiSquareCriteria(seqPousson, n, "Pousson", k);
	//H = dist->hipotez(delta, hi);
	//cout << "lambda=" << 3 << endl;
	//cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;
	////////////////////////////////////////////////////////////////////////////////
	//max = max_(seqPoussonRand, n);
	//min = min_(seqPoussonRand, n);
	//k = max - min + 1;
	//delta = dist->inverseCDFHisquare(k);
	//hi = dist->HiSquareCriteria(seqPoussonRand, n, "Pousson", k);
	//H = dist->hipotez(delta, hi);
	//cout << "H" << H << "  " << setprecision(15) << hi << "  " << delta << endl;


	system("pause");

	delete [] a;
	delete [] b;
	delete [] c;
	delete dist;
}
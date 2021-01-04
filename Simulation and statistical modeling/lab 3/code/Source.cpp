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

void print(double * a, int n )
{			
	cout << "Macklaren-Marsali sequence" << endl;
		for (int j = 0; j < 100; j++)
		{
			cout << setprecision(10) << a[j] << "  ";
		}
		cout << endl;
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
	int N = 100000;
	double deltaChi = 1073.64;  // from table for k = 1000
	double deltaKolmogor = 1.36;
	//////////////////
	///for uniform dist
	double a = -1, b = 1;
	//////////////////
	///for normal and lognormal dist
	int m = 12, k = 1000;
	double mu = 0, sigma = 0.2;
	//////////////////
	///for exponential dist
	double lambda = 2;
	//////////////////
	///for Veibulla-Gnedenko dist
	double VGlambda = 5, alpha = 2;
	//////////////////
	///Gamma dist
	double Galpha = 6, Gbeta = 2;
	//////////////////
	///for Cauchy dist
	double gamma = 2.5, coef = 3;
	//////////////////
	///for Logistic dist
	double A = 2, B = 3;
	//////////////////
	///for Chi square dist
	int K = 4;
	//////////////////
	///for Student dist
	int Sm = 7;
	//////////////////

	////////for normal, lognormal distribution
	double * seq = random_generate_maclaren_marsali(1728931, 353323, 565573, 19027279, 4703,
		2868, 301, 23531, 100, N*m);
	////////for uniform, exponential, veibulla-gnedenko, cauchy distribution
	double * seq1 = random_generate_maclaren_marsali(1728931, 353323, 565573, 19027279, 4703,
		2868, 301, 23531, 100, N);
	////////for gamma
	double * seqG = random_generate_maclaren_marsali(1728931, 353323, 565573, 19027279, 4703,
		2868, 301, 23531, 100, N*Galpha);
	////////for chisquare distribution
	double * seq2 = random_generate_maclaren_marsali(1728931, 353323, 565573, 19027279, 4703,
		2868, 301, 23531, 100, m*N*(K+1));
	////////for student distribution
	double * seqS = random_generate_maclaren_marsali(1728931, 353323, 565573, 19027279, 4703,
		2868, 301, 23531, 100, m*(Sm+1)*N);


	Distribution * dist = new Distribution();
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout("uniform.txt");
	double * sequence = dist->Uniform(seq1, N, a, b);
	for(int i = 0; i < N; i++)
		fout << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "--------------Uniform distribution-----------------" << endl;
	double pearson = dist->HiSquareCriteria(sequence, N, "Uniform", k);
	double kolmogorov = dist->KolmogorovCriteria(sequence, N, "Uniform");
	int hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	double mean = dist->middle(sequence, N);
	double disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout1("normal.txt");
	sequence = dist->normalDist(seq, N, m, mu, sigma);
	for (int i = 0; i < N; i++)
		fout1 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "--------------Normal distribution------------------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "Normal", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "Normal");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout2("lognormal.txt");
	sequence = dist->lognormalDist(seq, N, m, mu, sigma);
	for (int i = 0; i < N; i++)
		fout2 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "-------------Lognormal distribution----------------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "Lognormal", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "Lognormal");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout3("exponential.txt");
	sequence = dist->exponentialDist(seq1, N, lambda);
	for (int i = 0; i < N; i++)
		fout3 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "------------Exponential distribution---------------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "Exponential", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "Exponential");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout4("Veibulla-Gnedenko.txt");
	sequence = dist->Veibull_GnedenkoDist(seq1, N, VGlambda, alpha);
	for (int i = 0; i < N; i++)
		fout4 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "-----------Veibulla-Gnedenko distribution----------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "Veibulla-Gnedenko", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "Veibulla-Gnedenko");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout5("gamma.txt");
	sequence = dist->gammaDist(seqG, N, Galpha, Gbeta);
	for (int i = 0; i < N; i++)
		fout5 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "--------------Gamma distribution-------------------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "Gamma", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "Gamma");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout6("cauchy.txt");
	sequence = dist->CauchyDist(seq1, N, coef, gamma);
	for (int i = 0; i < N; i++)
		fout6 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "--------------Cauchy distribution------------------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "Cauchy", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "Cauchy");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout7("logistic.txt");
	sequence = dist->Logistic(seq1, N, A, B);
	for (int i = 0; i < N; i++)
		fout7 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "--------------Logistic distribution----------------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "Logistic", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "Logistic");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	N = 1000;
	ofstream fout8("chisquare.txt");
	sequence = dist->ChiSquareDist(seq2, N, m, K);
	for (int i = 0; i < 1000; i++)
		fout8 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "--------------ChiSquare distribution---------------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "ChiSquare", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "ChiSquare");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;
	////////////////////////////////////////////////////////////////////////////////////
	ofstream fout9("student.txt");
	sequence = dist->Student(seqS, N, m, Sm);
	for (int i = 0; i < 1000; i++)
		fout9 << setprecision(10) << sequence[i] << endl;
	fout.close();

	cout << "--------------Student distribution-----------------" << endl;
	pearson = dist->HiSquareCriteria(sequence, N, "Student", k);
	kolmogorov = dist->KolmogorovCriteria(sequence, N, "Student");
	hipotez = dist->hipotez(deltaChi, pearson);
	cout << "Pearson: " << pearson << "   " << deltaChi << "  H" << hipotez << endl;
	hipotez = dist->hipotez(deltaKolmogor, kolmogorov);
	cout << "Kolmogorov: " << kolmogorov << "   " << deltaKolmogor << "  H" << hipotez << endl;
	mean = dist->middle(sequence, N);
	disp = dist->variance(sequence, N);
	cout << "mean: " << mean << "  variance: " << disp << endl;


	delete[]seq;
	delete[]seq1;
	delete[]seq2;
	delete[]seqG;
	delete dist;
	system("pause");
}
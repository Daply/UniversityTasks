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

double * Distribution::normalDist(double * sequence, int num, int m, double mu, double sigma) {
	double * seq = new double[num];
	double sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += sequence[m*i + j];
		}
		seq[i] = sigma * (-6+sum)+mu;
	}
	return seq;
}

double * Distribution::lognormalDist(double * sequence, int num, int m, double mu, double sigma) {
	double * norm_seq = normalDist(sequence, num, m, mu, sigma);
	double * seq = new double[num];
	double sum = 0;
	for (int i = 0; i < num; i++)
	{
		seq[i] = exp(norm_seq[i]);
	}
	return seq;
}

double * Distribution::exponentialDist(double * sequence, int num, double lambda)
{
	double * seq = new double[num];
	for (int i = 0; i < num; i++)
	{
		seq[i] = -(log(sequence[i]) / lambda);
	}
	return seq;
}

double * Distribution::Veibull_GnedenkoDist(double * sequence, int num, double lambda, double alpha)
{
	double * seq = new double[num];
	for (int i = 0; i < num; i++)
	{
		seq[i] = lambda * pow(-log(1-sequence[i]) , 1 / alpha);
	}
	return seq;
}

double * Distribution::gammaDist(double * sequence, int num, double alpha, double beta) {
	double * seq = new double[num];
	double lam = 1 / beta;
	int al = alpha;
	double * seqExp = exponentialDist(sequence, al*num, lam);
	double sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum = 0;
		for (int j = 0; j < al; j++)
		{
			
			sum += seqExp[al*i+j];
		}
		seq[i] = sum;
	}		
	return seq;
}

double * Distribution::CauchyDist(double * sequence, int num, double coef, double gamma)
{
	double * seq = new double[num];
	for (int i = 0; i < num; i++)
	{
		double PI = 3.14;
		seq[i] = coef + gamma*(tan(PI*(sequence[i]-0.5)));
	}
	return seq;
}

double * Distribution::Logistic(double * sequence, int num, double a, double b)
{
	double * seq = new double[num];
	for (int i = 0; i < num; i++)
	{
		seq[i] = a + b*log(sequence[i]/(1-sequence[i]));
	}
	return seq;
}

double * Distribution::ChiSquareDist(double * sequence, int num, int m, int k)
{
	int t;
	double * seq = new double[num];
	double * seqForNorm = new double[m*num];
	double ** Z = new double*[k];
	for (int i = 0; i < k; i++)
	{
		Z[i] = new double[num];
		t = 0;
		for (int j = m*(i)*num; j < m*(i+1)*num; j++)
		{
			seqForNorm[t] = sequence[j];
			t++;
		}
		for (int l = 0; l < num; l++)
		{
			Z[i][l] = normalDist(seqForNorm, num, m, 0, 1)[l];			    
		}
	}
	double sum;
	for (int l = 0; l < num; l++)
	{
		sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += Z[i][l]* Z[i][l];
		}
		seq[l] = sum;
	}

	for (int l = 0; l < k; l++)
	{
		delete Z[l];
	}
	delete[] seqForNorm;
	return seq;
}

double * Distribution::Student(double * sequence, int num, int m, int Sm)
{
	int t;
	double * seq = new double[num];
	double * seqForNorm = new double[m*num];
	double ** Z = new double*[Sm+1];
	for (int i = 0; i < Sm+1; i++)
	{
		Z[i] = new double[num];
		t = 0;
		for (int j = m*(i)*num; j < m*(i + 1)*num; j++)
		{
			seqForNorm[t] = sequence[j];
			t++;
		}
		for (int l = 0; l < num; l++)
		{
			Z[i][l] = normalDist(seqForNorm, num, m, 0, 1)[l];
		}
	}


	//for (int l = 0; l < Sm+1; l++)
	//{
	//	for (int i = 0; i < num; i++)
	//	{
	//		cout << Z[l][i] << "  ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;


	double sum;
	double sm = Sm;
	double coef = 1 / sm;
	for (int l = 0; l < num; l++)
	{
		sum = 0;
		for (int i = 1; i < Sm+1; i++)
		{
			sum += Z[i][l] * Z[i][l];
		}
		seq[l] = Z[0][l]/sqrt((coef)*sum);
	}

	for (int l = 0; l < Sm+1; l++)
	{
		delete Z[l];
	}
	delete[] seqForNorm;
	return seq;
}

////////////////////////////Hi Square Criteria Realization///////////////////////////////////

int comp(const double *a, const double *b)
{
	if (*(double*)a > *(double*)b) return 1;
	else if (*(double*)a < *(double*)b) return -1;
	else return 0;
};

double Distribution::HiSquareCriteria(double * seq, int num, string dist, double k)
{
	int position = 0;
	int n = 0;
	double * sortedSeq = new double[num];
	qsort(seq, num, sizeof(double), (int(*) (const void *, const void *)) comp);
	for (int i = 0; i < num; i++)
		sortedSeq[i] = (double)seq[i];
	double X0 = sortedSeq[0];
	double Xn = sortedSeq[num-1];

	//cout << "Xmin " << X0 << " Xmax " << Xn << endl;

	double Xright, Xleft = 0;
	double X2 = 0;
	double h = (Xn-X0) / (k);

	//cout << "h " << h << endl;

	Xright = X0 + h;
	double pi = CDF(Xright,dist);
	//cout << "Pi " << pi << endl;
	int f = 0;
	//cout << "Xright  " << Xright << endl;
	for(int i = 0; i < k-1; i++)
	{
		while (sortedSeq[position] < Xright)
		{
			n++; 
			position++;
		}
		if(pi!= 0)
		X2 += pow((n - num*pi),2)/(num*pi);
		n = 0;
		Xleft = Xright;
		Xright += h;
		pi = CDF(Xright, dist) - CDF(Xleft, dist);
	}	
	Xleft = Xn - h;
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

////////////////////////////Kolmogorov criteria Realization///////////////////////////////////

double max_(double * seq, int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (seq[i]>seq[max])
			max = i;
	}
	return seq[max];
}

double Distribution::KolmogorovCriteria(double * seq, int num, string dist)
{
	double i_, num_;
	double * sortedSeq = new double[num];
	qsort(seq, num, sizeof(double), (int(*) (const void *, const void *)) comp);
	for (int i = 0; i < num; i++)
		sortedSeq[i] = (double)seq[i];

	double * f = new double[num];
	for (int i = 0; i < num; i++)
	{
		i_ = i;
		num_ = num;
		f[i] = i_ / num;
	}

	double * r = new double[num];
	for (int i = 0; i < num; i++)
		r[i] = abs(f[i]-CDF(sortedSeq[i],dist));
	double D = max_(r,num);
	double S = sqrt(num)*D;
	return S;
};

int Distribution::hipotez(double delta, double hi)
{
	if (delta > hi)
		return 0;
	else
		return 1;
};

////////////////////////////Cumulative functions realization///////////////////////////////////

double Distribution::CDF(double x, string dist)
{
	double result = 0;
	if (dist.compare("Uniform") == 0)						///WORKS RIGHT!!!
	{
		double a = -1, b = 1;
		if (x < a)
			result = 0;
		if (x >= a && x < b)
			result = (x - a) / (b - a);
		if (x >= b)
			result = 1;
	}
	if (dist.compare("Normal") == 0)                        ///WORKS RIGHT!!!
	{
		double mu = 0, sigma = 0.2;
		result = 0.5*(1+erf((x-mu)/sqrt(2*pow(sigma,2))));
	}
	if (dist.compare("Lognormal") == 0)                        ///WORKS RIGHT!!!
	{
		double mu = 0, sigma = 0.2;
		result = 0.5 + 0.5*(erf((log(x) - mu) / sqrt(2 * pow(sigma, 2))));
	}
	if (dist.compare("Exponential") == 0)                        ///WORKS RIGHT!!!
	{
		double lambda = 2;
		if (x >= 0)
			result = 1 - exp(-lambda*x);
		else
			result = 0;
	}
	if (dist.compare("Veibulla-Gnedenko") == 0)
	{
		double lambda = 5, alpha = 2;
		result = 1 - exp(-(pow(x/lambda, alpha)));
	}
	if (dist.compare("Cauchy") == 0)                        ///WORKS RIGHT!!!
	{
		double gamma = 2.5, coef = 3, PI = 3.14;
		result = (1/PI)*atan((x - coef)/gamma)+0.5;
	}
	if (dist.compare("Logistic") == 0)
	{
		double a = 2, b = 3;
		result = 1 / (1+exp(-(x-a)/b));
	}
	if (dist.compare("ChiSquare") == 0)                       
	{
		double k = 4;
		double x_ = (pow((x/k),1/3)-(1-2/(9*k)))/sqrt(2/(9*k));
		result = Normal(x_);
	}
	if (dist.compare("Student") == 0)
	{
		double gamma = 2.5, coef = 3, PI = 3.14;
		result = (1 / PI)*atan((x - coef) / gamma) + 0.5;
	}
	return result;
};

double Distribution::Normal(double x)
{
	double result;
	double mu = 0, sigma = 0.2;
	result = 0.5*(1 + erf((x - mu) / sqrt(2 * pow(sigma, 2))));
	return result;
}

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

double Distribution::middle(double * seq, int num)
{
	double sum = 0, n = num;
	for (int i = 0; i < num; i++)
		sum += seq[i];
	return sum / n;
}

double Distribution::variance(double * seq, int num)
{
	double sum = 0, n = num;
	double mean = middle(seq, num);
	for (int i = 0; i < num; i++)
		sum += pow(seq[i]-mean,2);
	return sum / (n-1);
}
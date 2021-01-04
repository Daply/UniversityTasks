#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Distribution.h";
#include "Monte-Karlo.h";
#include <iostream>
#include <queue>        // подключаем заголовочный файл очереди
#include <string>       // заголовочный файл для работы со строками типа string

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
		seq[i] = linear_congruent_operator(seq[i - 1], a, c, m);
		d = seq[i];
		seqDouble[i] = d / m;
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
	delete[]V;
	delete[]seqB;
	delete[]seqC;
	return seqA;
}

void execute(int & arm)
{

}

int main()
{
	ofstream fout("exponential.txt");
	int ARM1 = 1, ARM2 = 2, ARM3 = 3;

	queue<int> ecm_queue;

	Distribution * dist = new Distribution();
	double * seq = random_generate_maclaren_marsali(14039333, 220760, 961853, 14039333, 3219,
		2698, 571, 23531, 24273, 3600);
	double * seqExp = dist->exponentialDist(seq, 3600, 9);
	double * seqUni = dist->Uniform(seq, 3600, 4, 20);

	for (int j = 0; j < 3600; j++)
		fout << seqExp[j] << endl;
	fout.close();

	double lambda1 = 0.05, lambda2 = 0.04, lambda3 = 0.01;
	int * pouasson1 = dist->Pouasson(seq, 3600, 1 / lambda1);
	int * pouasson2 = dist->Pouasson(seq, 3600, 1 / lambda2);
	int * pouasson3 = dist->Pouasson(seq, 3600, 1 / lambda3);
	int * bern = dist->Bernulli(seq, 3600, 0.4);

	//cout << "Pousson" << endl;
	//for (int j = 0; j < 100; j++)
	//	cout << pouasson1[j] << "  ";
	//cout << endl;
	//cout << endl;

	//cout << "Exponential" << endl;
	//for (int j = 0; j < 100; j++)
	//	cout << int(seqExp[j]*100) << "  ";
	//cout << endl;
	//cout << endl;

	int count1 = 0, count2 = 0, count3 = 0;
	int i = 0, j = 0, k = 0, l = 0, b = 0;
	int timeARM1 = 0, timeARM2 = 0, timeARM3 = 0;
	int countDoneARM1 = 0, countDoneARM2 = 0, countDoneARM3 = 0;
	int timeForExec = 0;
	bool startExec = false;
	for (int time_seconds = 0; time_seconds < 3600; time_seconds++)
	{

		if (time_seconds-timeARM1 == pouasson1[i])
		{
			count1++;									 //задача пришла, но еще не выполнена
			ecm_queue.push(ARM1);							 //кладём задачу в очередь на выполнение
			timeARM1 = time_seconds;                     //запоминаем время для отсчёта следующего промежутка
			i++;
		}
		if (time_seconds - timeARM2 == pouasson2[j])
		{
			count2++;									 //задача пришла, но еще не выполнена
			ecm_queue.push(ARM2);							 //кладём задачу в очередь на выполнение
			timeARM2 = time_seconds;                     //запоминаем время для отсчёта следующего промежутка
			j++;
		}
		if (time_seconds - timeARM3 == pouasson3[k])
		{
			count3++;									 //задача пришла, но еще не выполнена
			ecm_queue.push(ARM3);							 //кладём задачу в очередь на выполнение
			timeARM3 = time_seconds;                     //запоминаем время для отсчёта следующего промежутка
			k++;
		}
		if (!ecm_queue.empty())                            //если в очереди есть элементы, то начинаем выполнение
		{
			if (!startExec)
			{
				timeForExec = time_seconds;                  //запомнили время начала выполнения
				startExec = true;
			}
			if (time_seconds-timeForExec == int(seqExp[l]*100))               //выполнение задачи
			{
				int task = ecm_queue.front();
				switch (task)
				{
					case 1:
						countDoneARM1++;
						break;
					case 2: 
						countDoneARM2++;
						break;
					case 3:
						countDoneARM3++;
						break;
				default:
					break;
				}
				ecm_queue.pop();
				timeForExec = 0;
				startExec = false;
				l++;
			}
		}
		if (bern[b] == 1)
		{
			time_seconds += seqUni[b];
			b++;
		}
		
	}


	cout << setw(14) << "ARM1" << setw(8) << "ARM2" << setw(8) << "ARM3" << endl;
	cout << "All tasks  " << count1 << setw(8) << count2 << setw(8) << count3 << endl; //     180 70 35
	cout << "Done tasks " << countDoneARM1 << setw(8) << countDoneARM2 << setw(8) << countDoneARM3 << endl; //     180 70 35   выполненных 285  невып 2
	cout << "Done: " << countDoneARM1 + countDoneARM2 + countDoneARM3 << endl;
	cout << "Not done: " << (count1 + count2 + count3)-(countDoneARM1 + countDoneARM2 + countDoneARM3) << endl;

	system("pause");
	return 0;

}
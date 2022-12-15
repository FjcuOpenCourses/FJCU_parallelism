#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

void mySleep(int time)
{

	int i_max = time, j_max = time;
	int i, j, s, k;
	for (i = 0; i < i_max; i++)
	{
		for (j = 0; j < j_max; j++)
		{
			s = i;
		}
	}
}

void sub(int gSize)
{
	float a[10001], x;
	int i;
	printf("Process size: %d Group Size: %d\n", 10000 / gSize, gSize);
	//cout << "Process size: " << 10000 / gSize << " Grouping Size: " << gSize << endl;
#pragma omp parallel
	{
#pragma omp for schedule(static, gSize)
		for (i = 1; i <= 10000; i++)
		{
			x = i;
			x = 3 * x * i + 5 * x * x - 4 * i * i;
			a[i] = x;
			a[i] = sqrt(a[i]);
			mySleep(2000);
			if (fabs(a[i] - 2 * i) > 0.001)
			{
				//printf("error: %.2lf not equal to %d\n", a[i], 2 * i);
				//cout << " error: " << a[i] << " not equal to " << 2 * i << endl;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	clock_t start;
	clock_t finish;
	int gSize = 800, num_threads = 10000 / gSize;

	start = clock();
	sub(gSize);

	finish = clock() - start;
	double interval = finish / (double)CLOCKS_PER_SEC;

	printf("%lf Parallel clock cycles\n", (double)finish);
	printf("%lf Parallel seconds elapsed\n", interval);

	clock_t bstart;
	clock_t bfinish;
	int bgSize = 10000;
	
	bstart = clock();
	sub(bgSize);

	bfinish = clock() - bstart;
	double binterval = bfinish / (double)CLOCKS_PER_SEC;


	printf("%lf Sequence clock cycles\n", (double)bfinish);
	printf("%lf Sequence seconds elapsed\n", binterval);

	double speedup = binterval / interval;
	double fast = speedup / num_threads;

	printf("%lf speedup \n", speedup);
	printf("%lf Utilization \n", fast);

	system("pause");
	return 0;
}


// Project_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define M 3
#define N 9
#include <stdlib.h>
#include <iostream>


using namespace std;
int train[M][N];

void sleep() {
	double a = a = (rand() % 2001) + 100;
	int i, c = 1;
	for (i = 0; i < a; i++) {
		c++;
	}
}

void booking(int processNUM) {
	int i = 0, j = 0;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
#pragma omp critical
			if (train[i][j] == 0) {
				sleep();
				train[i][j] = 1;
				printf("process %d book seat %d %d\n", processNUM, i, j);
				//cout << "process " << processNUM << " book seat " << i << " " << j << endl;
			}
			else
			{
				sleep();
				printf("process %d skipped, seat %d %d booked\n", processNUM, i, j);
			}
		}
	}
}

int main() {
	int i = 0, j = 0;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if ((i + j) % 3 == 0) {
				train[i][j] = 1;
			}
			else {
				train[i][j] = 0;
			}
		}
	}
#pragma omp parallel for
	for (i = 1; i < 4; i++)
	{
		booking(i);
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

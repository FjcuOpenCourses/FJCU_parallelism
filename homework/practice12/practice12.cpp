#include <iostream>
#include <stdlib.h>
#include <omp.h>

#define n 32
#define numiter 1000

using namespace std;
float A[n + 2][n + 2], B[n + 2][n + 2];

void Jacobi() {
#pragma omp parallel num_threads(n)
	{
	int id = omp_get_thread_num() + 1;
	for (int k = 1; k < numiter; k++) {
		for (int j = 1; j <= n; j++) {
			B[id][j] = (A[id - 1][j] + A[id][j - 1] + A[id + 1][j] + A[id][j + 1]) / 4;
#pragma omp barrier
			for (int h = 1; h <= n; h++) {
				A[id][h] = B[id][h];
			}
#pragma omp barrier
		}
	}
	}
}

int main() {
	
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			A[i][j] = 0;
		}
	}
	for (int i = 0; i < n + 2; i++) {
		A[0][i] = 9;
		A[n + 1][i] = 7;
	}
	for (int i = 0; i < n + 2; i++) {
		A[i][0] = 4;
		A[i][n + 1] = 1;
	}
	#pragma omp parallel for
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				B[i][j] = A[i][j];
			}
		}

	Jacobi();

	for (int i = 0; i < n +2; i++) {
		for (int j = 0; j < n +2; j++) {
			cout << (int)A[i][j];
		}
		cout << endl;
	}
}

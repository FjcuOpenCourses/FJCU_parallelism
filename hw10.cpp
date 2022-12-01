#include <stdlib.h>
#define n 32
#define numiter 1000
float A[n+2][n+2], B[n+2][n+2];
int i,j,count, k;
spinlock Arrival , Departure;

void Barrier(){
	Lock(Arrival);
		count = count + 1;
	if(count < n)
		Unlock(Arrival);
		else Unlock(Departure);

	Lock(Departure);
		count = count - 1;
	if(count > 0)
		Unlock(Departure);
	else Unlock(Arrival);
}

void Jacobi(){
	forall i = 1 to n do{
        int k;
		for(k=1;k<numiter;k++){
            int j;
            for(j=1;j<n;j++){   
                B[i,j]=(A[i-1,j]+A[i,j-1]+A[i+1,j]+A[i,j+1])/4;
                Barrier();
                A[i]=B[i];
                Barrier();
            }            
        }
	}

}

main(){
	for(i = 0; i < n+2; i++){
		for(j = 0; j < n+2; j++){
			A[i][j] = 0;
		}
	}
	for(i = 0; i < n+2; i++){
		A[0][i] = 9;
		A[n+1][i] = 7;
	}
	for(i = 0; i < n+2; i++){
		A[i][0] = 4;
		A[i][n+1] = 1;
	}
	forall i = 1 to n do
		B[i] = A[i];

   	count = 0;
   	Unlock(Arrival);
   	Lock(Departure);
	Jacobi();

	for(i = 0; i < n+2; i++){
		for(j = 0; j < n+2; j++){
			cout.width(1);
			cout << (int)A[i][j];
		}
		cout << endl;
	}

}
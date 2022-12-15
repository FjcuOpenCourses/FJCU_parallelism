#define M 3
#define N 9
#include <stdlib.h>
int train[M][N];
spinlock L;
void sleep(){
	double a = a=(rand() % 2001) +100;
	int i, c = 1;
	for(i = 0;i<a;i++){
		c++;

    }
}
void booking(int processNUM){	
       int i = 0, j = 0;
	for(i = 0;i < M;i++){	
	      for(j = 0;j<N;j++){

			if(train[i][j]==0){
			       sleep();
				train[i][j] = 1;
				cout<<"process"<<processNUM<<" book seat"<<i<<" "<<j<<endl;
            }
		}
	}
}		

void booking(int processNUM){	
       int i = 0, j = 0;
	for(i = 0;i < M;i++){	
	      for(j = 0;j<N;j++){
			Lock(i);
			if(train[i][j]==0){
			       sleep();
				train[i][j] = 1;
				cout<<"process"<<processNUM<<" book seat"<<i<<" "<<j<<endl;
            }
            Unlock();	
        }	
    }
}
int main(){
	int i = 0, j = 0;
	for(i = 0; i < M; i++){
		for(j = 0; j<N; j++){
			if((i+j) % 3 == 0){
				train[i][j] = 1;
			 }else{
				train[i][j] = 0;
	}	}	}
	forall i = 1 to 4 do
        booking(i);
	return 0;
}	

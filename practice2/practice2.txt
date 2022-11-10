#include<math.h>

void mySleep(){
	int i_max =20, j_max = 20;
	int i,j,s;
	for(i=0;i<i_max;i++){
		s = i+j;
	}
}
main(){
	float a[1001],x;
	int i;
	for(i=1;i<1000;i++){
		x = i;
		x = 3*x*x +x*x;
		a[i] = x;
	}
	forall i =1 to 100 grouping 7 do {
		a[i] = SQRT(a[i]);
		mySleep();
	}
	forall i =1 to 100 do {
		if(a[i] != 2*i){
			cout <<"error"<<a[i]<<"<>"<<2*i<<endl;
		}
	}
	
}
main(){

   int i, j, k;

   forall i = 1 to 8 do{

        for(j=i*10;  j<i*100; j++)

             for(k=i*10;  k<i*100;  k++)   k/i/i;

      cout<<"Hello! world! from thread " << i << endl;

   }

}
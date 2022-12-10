#define endmark -1
#include <stdlib.h>
int stream commchan;

void mySleep() {
    int a = (rand() %1501) +100;
    int  i_max = a,  j_max = 30 ;
    int  i, j, s;
    for (i = 0;i < i_max; ++i)
        for (j = 0;j < j_max; ++j)
               s = i + j;
}

void Producer(){
    int num;
    for(num = 1; num < 21; num++){
        mySleep();
        cout<<"produced "<< num << "th bread" << endl;
        send(commchan,num);

    }
    send(commchan, endmark);
    cout<<"produced completed"<< endl;
	
}
void Consumer(){
    int bb;
    mySleep();
    recv(commchan, bb);
    while(bb != endmark){
        if(bb%2!=0&&bb%3!=0){
            cout<<"got "<< bb << "th bread" << endl;
            
        }else{
	    cout<<"skip "<< bb << "th bread" << endl;
	}
	mySleep(); 
        recv(commchan, bb);
    }
    cout<<"consume completed"<< endl;
}

main(){
    FORK Producer();
    FORK Consumer();
}
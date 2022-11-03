#define endmark -1
int stream c2in;
int stream c23;
int stream c35;
int stream c57;
int stream c7o;

void P2(){
    int xvalue;
    recv(c2in,xvalue);
    while(xvalue!= endmark){
        if(xvalue%2!=0) send(c23,xvalue);
        recv(c2in,xvalue);
    }
    send(c23,xvalue);
}
void P3(){
    int xvalue;
    recv(c23,xvalue);
    while(xvalue!= endmark){
        if(xvalue%3!=0) send(c35,xvalue);
        recv(c23,xvalue);
    }
    send(c35,xvalue);
}
void P5(){
    int xvalue;
    recv(c35,xvalue);
    while(xvalue!= endmark){
        if(xvalue%5!=0) send(c57,xvalue);
        recv(c35,xvalue);
    }
    send(c57,xvalue);
}
void P7(){
    int xvalue;
    recv(c57,xvalue);
    while(xvalue!= endmark){
        if(xvalue%7!=0) send(c7o,xvalue);
        recv(c57,xvalue);
    }
    send(c7o,xvalue);
}
main(){
    int i, xvalue;
    for(i=2;i<100;i++)
        send(c2in,i);
    send(c2in,endmark);
    fork P2();
    fork P3();
    fork P5();
    fork P7();
    recv(c7o,xvalue);
    while(xvalue!=endmark){
        cout << xvalue << endl;
        recv(c7o,xvalue);
    }

}
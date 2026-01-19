#include<iostream>
using namespace std;

int clear(int num,int i){
    int bitMask=(~0)<<i;
    return num & bitMask;
}


int main(){
    cout<<clear(15,2);
    return 0;
}
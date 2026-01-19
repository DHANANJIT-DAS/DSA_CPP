#include<iostream>
using namespace std;

int clear(int num,int i,int j){

    int temp1=(~0)<<i;

    int temp2=(~0)<<(j+1);

    int bitMask=~(temp1 ^ temp2);

    return num & bitMask;

}


int main(){
    cout<<clear(31,1,3);
    return 0;
}
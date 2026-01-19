#include<iostream>
using namespace std;

bool powerOf2(int num){
    int bitMask=num-1;
    if(!(num & bitMask)){
        return 1;
    }
    else {
        return 0;
    }
}


int main(){
    cout<<powerOf2(7);
    return 0;
}
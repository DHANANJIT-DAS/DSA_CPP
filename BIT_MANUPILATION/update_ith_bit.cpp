#include<iostream>
using namespace std;

int update(int num,int i,int val){
    int bitMask=~(1<<i);
    num=num & bitMask; // clear i th bit
    
    
        return num | (val <<i); // if val=0 num remains same ,if 1 then | with (1<<i)
}


int main(){
    cout<<update(7,3,1);
    return 0;
}
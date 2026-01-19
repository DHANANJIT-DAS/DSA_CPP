#include<iostream>
using namespace std;

int set_ith_bit(int num,int i){
    int bitMask=1<<i;

    int result=num | bitMask;

    return result;
    
}

int clear_ith_bit(int num,int i){
    int bitMask=~(1<<i);

    return num & bitMask;
 

}


int main(){
    
    cout<<set_ith_bit(6,3)<<endl;
    cout<<clear_ith_bit(5,2);
    return 0;
}
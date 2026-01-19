#include<iostream>
using namespace std;

void count_bit(int num,int &sum){

    if(num==0){
        return;
    }

    sum=sum+(num & 1);
    
     num=num>>1;

     count_bit(num,sum);
}


int main(){
    int sum=0;
    count_bit(10,sum);
    cout<<sum;
    return 0;
}
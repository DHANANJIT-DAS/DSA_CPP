#include<iostream>
using namespace std;

int division(int dividend,int divisor){

    bool sign=true;

    if((dividend>=0 && divisor<0) ||dividend<0 && divisor>0){
        sign =false;
    }

    int D=abs(dividend);
    int d=abs(divisor);


    int ans=0;

    while(D>=d){
        int power=0;
        while(D>=(d<<(power+1))){
            power++;
        }

        ans=ans+(1<<power);
        D=D-(d<<power);

    }

    return sign ? ans : -ans;

}

int main(){
   cout<< division(-22,7);
    return 0;
}
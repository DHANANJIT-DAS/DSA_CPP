#include<iostream>
using namespace std;


//O(log n )complexity
int power(int x,int n){
    if(n==0){
        return 1;
    }
    int a=power(x,n/2);
    if(n%2==0){
       return a*a;
    }else{
        return x*a*a;
    }

}



//O(n) complexity
int pow(int x,int n){
    if(n==0){
        return 1;
    }
    return x*pow(x,n-1);
}
int main(){

    cout<<power(2,10);
    return 0;
}
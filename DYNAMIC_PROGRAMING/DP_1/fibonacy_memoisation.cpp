#include<iostream>
#include<vector>
using namespace std;

int fib(int n){   // O(2^n)
    if(n==0 || n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int fibDP(int n,vector<int>&f){   // O(n)
    if(n==0 || n==1){
        return n;
    }
    if(f[n]!=-1){
        return f[n];
    }

    f[n]=fibDP(n-1,f)+fibDP(n-2,f);

    return f[n];
}

int main(){
    int n=6;
    cout<<fib(6)<<endl;

    vector<int>f(n+1,-1);
    cout<<fibDP(6,f)<<endl;
    return 0;
}
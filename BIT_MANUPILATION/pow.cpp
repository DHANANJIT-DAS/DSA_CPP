#include<iostream>
using namespace std;

void pow(int x,int n,int &ans){

    if(n==0){
        return ;
    }

    
    if(n & 1){
        ans=ans*x;
    }
    n=n>>1;
    x=x*x;
    pow(x,n,ans);
    

}


int main(){
    int ans=1;
    pow(3,4,ans);
    cout<<ans;
    return 0;
}
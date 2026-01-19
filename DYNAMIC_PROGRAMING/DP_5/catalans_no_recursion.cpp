#include<iostream>
#include<vector>
using namespace std;


int catalans_no(int n){

    if(n==0 || n==1){
        return 1;
    }

    int ans=0;

    for(int i=0;i<n;i++){
        ans=ans+catalans_no(i)*catalans_no(n-i-1);
    }
    return ans;
}

int main(){

    cout<<catalans_no(6);

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;



int catalans_no(int n,vector<int>&DP){

    if(n==0 || n==1){
        return 1;
    }

    if(DP[n]!=-1){
        return DP[n];
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans+catalans_no(i,DP)*catalans_no(n-i-1,DP);
    }

    DP[n]=ans;
    return DP[n];
}

int main(){

    int n=6;
    vector<int>DP(n+1,-1);
    cout<<catalans_no(n,DP);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;


int catalans_no(int n){

    vector<int>DP(n+1,1);

    for(int i=2;i<=n;i++){

        int ans=0;
        for(int j=0;j<i;j++){
            ans=ans+DP[j]*DP[i-1-j];
        }
        DP[i]=ans;
    }

    return DP[n];
}


int main(){
    cout<<catalans_no(6);
    return 0;
}
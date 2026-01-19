#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&DP){

    if(amount==0){
        return 0;
    }

    if(i==coins.size()){
        return -1;
    }

    if(DP[i][amount]!=0){
        return DP[i][amount];
    }
    
    if(amount>=coins[i]){
        int a=solve(coins,amount-coins[i],i,DP);
        int b=solve(coins,amount,i+1,DP);

        if(a!=-1 && b!=-1){
            DP[i][amount]=min(a+1,b);
            return DP[i][amount];
        }
        else{
            DP[i][amount]=a==-1?b:a+1;
            return DP[i][amount];
        }
    }
    else{
        DP[i][amount]=solve(coins,amount,i+1,DP);
        return DP[i][amount];
    }

}

int coin_change(vector<int>&coins,int &amount){

    vector<vector<int>>DP(coins.size()+1,vector<int>(amount+1,0));

    return solve(coins,amount,0,DP);
}


int main(){
    vector<int>coins={1,2,5};
    int amount=100;

    cout<<coin_change(coins,amount);
    return 0;
}
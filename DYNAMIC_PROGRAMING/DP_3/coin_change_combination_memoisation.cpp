#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>& coins,int amount,int i,vector<vector<int>>&DP){

    if(amount==0){
        return 1;
    }
    if(i==coins.size()){
        return 0;
    }

    if(DP[i][amount]!=-1){
        return DP[i][amount];
    }

    if(coins[i]<=amount){
        DP[i][amount]=solve(coins,amount-coins[i],i,DP)+solve(coins,amount,i+1,DP);
        return DP[i][amount];
    }
    else{
        DP[i][amount]=solve(coins,amount,i+1,DP);
        return DP[i][amount];
    }
    
}

int coin_change(vector<int>& coins,int &amount){

    vector<vector<int>>DP(coins.size()+1,vector<int>(amount+1,-1));
    return solve(coins,amount,0,DP);
}



int main(){

    vector<int>coins={3,5,7,8,9,10,11};
    int amount=500;

    cout<<coin_change(coins,amount);
    return 0;
}
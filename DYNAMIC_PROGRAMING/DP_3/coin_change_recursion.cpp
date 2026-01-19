#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>&coins,int amount,int i){

    if(amount==0){
        return 0;
    }

    if(i==coins.size()){
        return -1;
    }
    


    if(amount>=coins[i]){
        int a=solve(coins,amount-coins[i],i);
        int b=solve(coins,amount,i+1);

        if(a!=-1 && b!=-1){
            return min(a+1,b);
        }
        else{
            return a==-1?b:a+1;
        }
    }
    else{
        return solve(coins,amount,i+1);
    }

    
    

}

int coin_change(vector<int>&coins,int &amount){
    return solve(coins,amount,0);
}

int main(){
    vector<int>coins={1,2,5};
    int amount=100;

    cout<<coin_change(coins,amount);
    return 0;
}
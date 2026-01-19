#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int>& coins,int amount,int i,int & count){

    if(amount==0){
        count++;
        return;
    }
    if(i==coins.size()){
        return;
    }

    if(coins[i]<=amount){
        solve(coins,amount-coins[i],i,count);
    }

    solve(coins,amount,i+1,count);
}



int coin_change( vector<int>& coins,int amount) {

    int count=0;

    solve(coins,amount,0,count);

    return count;
        
}


int main(){

    vector<int>coins={3,5,7,8,9,10,11};
    int amount=500;

    cout<<coin_change(coins,amount);
    return 0;
}
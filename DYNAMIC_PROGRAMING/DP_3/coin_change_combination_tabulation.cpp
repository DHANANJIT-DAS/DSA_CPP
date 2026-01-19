#include<iostream>
#include<vector>
using namespace std;




int coin_change(vector<int>coins,int amount){

    vector<vector<int>>DP(coins.size()+1,vector<int>(amount+1,0));
    for(int i=0;i<=coins.size();i++){
        DP[i][0]=1;
    }


    for(int i=1;i<=coins.size();i++){
        for(int j=1;j<=amount;j++){
            if(coins[i-1]<=j){
                DP[i][j]=DP[i-1][j]+DP[i][j-coins[i-1]];
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }

    return DP[coins.size()][amount];

}











int main(){

    vector<int>coins={3,5,7,8,9,10,11};
    int amount=500;

    cout<<coin_change(coins,amount);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;



int coin_change1(vector<int>&coins,int & amount){

    vector<int>DP(amount+1,1e9);
    DP[0]=0;


    for(int i=1;i<=amount;i++){

        for(int j=0;j<coins.size();j++){
            int rem=i-coins[j];
            if(rem>=0){
                DP[i]=min(1+DP[rem],DP[i]);
            }
            
        }
    }

    return DP[amount];

}

int coin_change2(vector<int>&coins,int & amount){
    vector<vector<int>>DP(coins.size()+1,vector<int>(amount+1,0));

    for(int i=1;i<=amount;i++){
        DP[0][i]=-1;
    }

    for(int i=1;i<=coins.size();i++){
        for(int j=1;j<=amount;j++){
            if(j>=coins[i-1]){
                int a=DP[i][j-coins[i-1]];
                int b=DP[i-1][j];
                if(a!=-1 && b!=-1){
                    DP[i][j]=min(1+a,b);
                }
                else{
                    DP[i][j]=a==-1?b:a+1;
                }
                
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }

    return DP[coins.size()][amount];
}


int main(){
    vector<int>coins={1,2,5};
    int amount=100;

    cout<<coin_change2(coins,amount);
    return 0;
}
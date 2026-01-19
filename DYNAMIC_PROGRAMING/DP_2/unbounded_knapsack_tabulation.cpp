#include<iostream>
#include<vector>
using namespace std;



int unbounded_knapsack(vector<int>&val,vector<int>&weight,int &totalweight){

    vector<vector<int>>DP(val.size()+1,vector<int>(totalweight+1,0));

    for(int i=1;i<=val.size();i++){
        for(int j=1;j<=totalweight;j++){
            int itemval=val[i-1];
            int itemweight=weight[i-1];
            if(j>=itemweight){
                DP[i][j]=max(itemval+DP[i][j-itemweight],DP[i-1][j]);
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }

    return DP[val.size()][totalweight];
}


int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>weight={2,5,1,3,4};
    int totalWeight=7;

    
    cout<<unbounded_knapsack(val,weight,totalWeight)<<endl;

    
    return 0;
}
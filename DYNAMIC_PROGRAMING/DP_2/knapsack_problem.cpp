#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int>&val,vector<int>&weight,int totalWeight,int i,int profit,int &max_profit){

    if(i==val.size() || totalWeight==0){
        return;
    }

    if(weight[i]<=totalWeight){
        profit=profit+val[i];
        totalWeight=totalWeight-weight[i];
        max_profit=max(max_profit,profit);

        solve(val,weight,totalWeight,i+1,profit,max_profit);
        
        totalWeight=totalWeight+weight[i];
        profit=profit-val[i];
    }

    solve(val,weight,totalWeight,i+1,profit,max_profit);
}

int knapsack_problem(vector<int>&val,vector<int>&weight,int &totalWeight){

    int max_profit=0;
    int profit=0;
    solve(val,weight,totalWeight,0,profit,max_profit);

    return max_profit;
}

int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>weight={2,5,1,3,4};

    int totalWeight=7;

    cout<<knapsack_problem(val,weight,totalWeight);

    return 0;
}
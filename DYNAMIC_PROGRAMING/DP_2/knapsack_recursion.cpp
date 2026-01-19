#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>&val,vector<int>&weight,int totalWeight,int i){
    if(i==val.size() || totalWeight==0){
        return 0;
    }

    int profit1=0;
    if(weight[i]<=totalWeight){
        profit1=val[i]+solve(val,weight,totalWeight-weight[i],i+1);
    }

    int profit2=solve(val,weight,totalWeight,i+1);

    return max(profit1,profit2);
}

int knapsack_problem(vector<int>&val,vector<int>&weight,int &totalWeight){

    
    return solve(val,weight,totalWeight,0);
}

int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>weight={2,5,1,3,4};

    int totalWeight=7;

    cout<<knapsack_problem(val,weight,totalWeight);

    return 0;
}
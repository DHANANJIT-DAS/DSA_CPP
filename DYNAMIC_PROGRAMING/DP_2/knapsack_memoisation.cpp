#include<iostream>
#include<vector>
using namespace std;


int solver(vector<int>&val,vector<int>&weight,int totalWeight,int i,vector<vector<int>>&DP){

    if(DP[i][totalWeight]!=-1){
        return DP[i][totalWeight];
    }
    
    if(i==val.size() || totalWeight==0){
        return 0;
    }

    int profit1=0;
    if(weight[i]<=totalWeight){
        profit1=val[i]+solver(val,weight,totalWeight-weight[i],i+1,DP);
    }
    int profit2=solver(val,weight,totalWeight,i+1,DP);

    DP[i][totalWeight]= max(profit1,profit2);
    return DP[i][totalWeight];
   
}

int knapsack_memoisation(vector<int>&val,vector<int>&weight,int &totalWeight){   // O(n*totalWeight)

    vector<vector<int>>DP(val.size()+1,vector<int>(totalWeight+1,-1));
    return solver(val,weight,totalWeight,0,DP);
}

int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>weight={2,5,1,3,4};
    int totalWeight=7;

    
    cout<<knapsack_memoisation(val,weight,totalWeight)<<endl;

    
    return 0;
}

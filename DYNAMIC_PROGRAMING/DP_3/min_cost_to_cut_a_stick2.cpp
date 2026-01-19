#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// memoisation

int solve(vector<int>&cuts,int start,int end,vector<vector<int>>&DP){

    if(start>end){
        return 0;
    }

    if(DP[start][end]!=-1){
        return DP[start][end];
    }

    int cost=INT32_MAX;
    for(int i=start;i<=end;i++){
        cost=min(cost,solve(cuts,start,i-1,DP)+solve(cuts,i+1,end,DP));
    }

    DP[start][end]=cuts[end+1]-cuts[start-1]+cost;
    return DP[start][end];

}

int minCost(vector<int>&cuts,int & length){

    
    sort(cuts.begin(),cuts.end());
    cuts.push_back(length);
    cuts.insert(cuts.begin(),0);


    vector<vector<int>>DP(cuts.size()+1,vector<int>(cuts.size()+1,-1));
    return solve(cuts,1,cuts.size()-2,DP);
}






//  tabulation

int minCost_tabulation(int &length,vector<int>&cuts){

    sort(cuts.begin(),cuts.end());
    cuts.push_back(length);
    cuts.insert(cuts.begin(),0);

    vector<vector<int>>DP(cuts.size(),vector<int>(cuts.size(),0));



    for(int i=cuts.size()-2;i>0;i--){
        for(int j=i;j<=cuts.size()-2;j++){
            if(i==j){
                DP[i][j]=cuts[i+1]-cuts[i-1];
            }
            else{
                int cost=INT32_MAX;
                for(int k=i;k<=j;k++){
                    cost=min(cost,DP[k+1][j]+DP[i][k-1]+cuts[j+1]-cuts[i-1]);
                }
                DP[i][j]=cost;
                
            }
        }
    }


    return DP[1][cuts.size()-2];

}


int main(){

    vector<int>cuts = {1,3,4,5};
    int length=7;
    cout<<minCost_tabulation(length,cuts);
    return 0;
}
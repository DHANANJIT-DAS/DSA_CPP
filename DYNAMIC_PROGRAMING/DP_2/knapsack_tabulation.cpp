#include<iostream>
#include<vector>
using namespace std;


int knapsack_tabulation2(vector<int>&val,vector<int>&weight,int &totalWeight){  // O(val.size()*totalWeight)
    vector<vector<int>>DP(val.size()+1,vector<int>(totalWeight+1,0));

    for(int i=1;i<=val.size();i++){
        for(int j=1;j<=totalWeight;j++){        // travelling the val and weight from left to right
            if(weight[i-1]<=j){
                DP[i][j]=max(val[i-1]+DP[i-1][j-weight[i-1]],DP[i-1][j]);
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }

    for(int i=0;i<=val.size();i++){
        for(int j=0;j<=totalWeight;j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return DP[val.size()][totalWeight];

}

int knapsack_tabulation(vector<int>&val,vector<int>&weight,int &totalWeight){  // O(val.size()*totalWeight)

    vector<vector<int>>DP(val.size()+1,vector<int>(totalWeight+1,0));


    for(int i=val.size()-1;i>=0;i--){            // travelling the val and weight from right to left
        for(int j=1;j<=totalWeight;j++){
            if(j>=weight[i]){
                DP[i][j]=max(DP[i+1][j],val[i]+DP[i+1][j-weight[i]]);
            }
            else{
                DP[i][j]=DP[i+1][j];
            }
        }
    }


    for(int i=0;i<=val.size();i++){
        for(int j=0;j<=totalWeight;j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return DP[0][totalWeight];
}


int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>weight={2,5,1,3,4};
    int totalWeight=7;

    
    cout<<knapsack_tabulation2(val,weight,totalWeight)<<endl;

    return 0;
}
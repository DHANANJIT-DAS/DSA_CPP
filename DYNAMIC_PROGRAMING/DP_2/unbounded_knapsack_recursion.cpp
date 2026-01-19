#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>&val,vector<int>&weight,int totalweight,int i){

    if(i==val.size() || totalweight==0){
        return 0;
    }

    int profit1=0;
    if(weight[i]<=totalweight){
        profit1=val[i]+solve(val,weight,totalweight-weight[i],i);
    }
    int profit2=solve(val,weight,totalweight,i+1);

    return max(profit1,profit2);

}

int unbounded_knapsack(vector<int>&val,vector<int>&weight,int & totalweight){
    return solve(val,weight,totalweight,0);
}
int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>weight={2,5,1,3,4};
    int totalWeight=7;

    
    cout<<unbounded_knapsack(val,weight,totalWeight)<<endl;

    
    return 0;
}
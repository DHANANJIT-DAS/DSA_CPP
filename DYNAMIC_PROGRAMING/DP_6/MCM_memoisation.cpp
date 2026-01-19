#include<iostream>
#include<vector>
using namespace std;


int min_operation(vector<int>&matrics,int start,int end,vector<vector<int>>&DP){

    if(start>=end){
        return 0;
    }
    if(DP[start][end]!=-1){
        return DP[start][end];
    }

    int ans=INT32_MAX;
    for(int i=start;i<end;i++){
        int currentOps=matrics[start-1]*matrics[i]*matrics[end];
        ans=min(ans,min_operation(matrics,start,i,DP)+min_operation(matrics,i+1,end,DP)+currentOps);
    }
    
    return DP[start][end]= ans;
}


int main(){

    vector<int>matrixs={1,2,3,4,3};
    int n=matrixs.size();
    vector<vector<int>>DP(n,vector<int>(n,-1));

    cout<<min_operation(matrixs,1,matrixs.size()-1,DP);

    return 0;
}
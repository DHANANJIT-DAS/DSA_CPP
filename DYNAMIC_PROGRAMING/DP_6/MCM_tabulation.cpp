#include<iostream>
#include<vector>
using namespace std;


int MCM_tabulation(vector<int>matrics){

    int n=matrics.size();

    vector<vector<int>>DP(n,vector<int>(n,0));

    for(int i=n-1;i>0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                DP[i][j]=0;
            }
            else{
                int ans=INT32_MAX;
                for(int k=i;k<j;k++){
                    int currentOps=matrics[i-1]*matrics[k]*matrics[j];
                    ans=min(ans,DP[i][k]+DP[k+1][j]+currentOps);
                }
                DP[i][j]=ans;
            }
        }
    }

   

    return DP[1][n-1];

}

int main(){
    vector<int>matrics={1,2,3,4,3};
    cout<<MCM_tabulation(matrics);
    return 0;
}
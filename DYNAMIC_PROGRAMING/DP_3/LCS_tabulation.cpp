#include<iostream>
#include<vector>
using namespace std;


int longest_common_subsequence(string a,string b){

    int n=a.size();
    int m=b.size();

    vector<vector<int>>DP(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                DP[i][j]=1+DP[i-1][j-1];
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }


    return DP[n][m];

}


int main(){
    string a="abd";
    string b="xyd";

    cout<<longest_common_subsequence(a,b);
    return 0;
}
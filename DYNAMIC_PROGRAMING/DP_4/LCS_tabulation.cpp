#include<iostream>
#include<vector>
#include<string>
using namespace std;


int longest_common_substring(string a,string b){

    int n=a.size();
    int m=b.size();

    vector<vector<int>>DP(n+1,vector<int>(m+1,0));

    int ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                DP[i][j]=1+DP[i-1][j-1];
                ans=max(ans,DP[i][j]);
            }
            else{
                DP[i][j]=0;
            }
        }
    }

    return ans;

}

int main(){

    string a="abeshk";
    string b="akrshk";

    cout<<longest_common_substring(a,b);
    return 0;
}
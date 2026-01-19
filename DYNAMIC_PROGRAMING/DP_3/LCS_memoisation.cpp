#include<iostream>
#include<vector>
using namespace std;



int longest_common_subsequence(string a,string b,vector<vector<int>>&DP){

    if(a.size()==0 || b.size()==0){
        return 0;
    }

    int n=a.size();
    int m=b.size();
    if(DP[n][m]!=-1){
        return DP[n][m];
    }


    if(a[a.size()-1]==b[b.size()-1]){
        DP[n][m]= 1+longest_common_subsequence(a.substr(0,a.size()-1),b.substr(0,b.size()-1),DP);
        return DP[n][m];
    }
    else{
        DP[n][m]=  max( longest_common_subsequence(a,b.substr(0,b.size()-1),DP),longest_common_subsequence(a.substr(0,a.size()-1),b,DP));
        return DP[n][m];
    }


}

int main(){
    string a="bfd";
    string b="hbf";


    vector<vector<int>>DP(a.size()+1,vector<int>(b.size()+1,-1));

    cout<<longest_common_subsequence(a,b,DP);
    return 0;
}
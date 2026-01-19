#include<iostream>
#include<vector>
#include<string>
using namespace std;


int longest_common_substring(string a,string b,vector<vector<int>>&DP){

    if(a.size()==0 || b.size()==0){
        return 0;
    }

    int n=a.size();
    int m=b.size();

    if(DP[n][m]!=-1){
        return DP[n][m];
    }

    int length=0;
    while( n>0 && m>0  &&   a[n-1]==b[m-1]){
        length++;
        n--;
        m--;
    }

    DP[n][m]= max(length,max(longest_common_substring(a.substr(0,a.size()-1),b,DP),longest_common_substring(a,b.substr(0,b.size()-1),DP)));
    return DP[n][m];


}


int main(){

    string a="abeshka";
    string b="akrshks";

    int n=a.size();
    int m=b.size();

    vector<vector<int>>DP(n+1,vector<int>(m+1,-1));

    cout<<longest_common_substring(a,b,DP);
    return 0;
}
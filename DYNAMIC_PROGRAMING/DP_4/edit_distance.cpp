#include<iostream>
#include<vector>
#include<string>
using namespace std;


int min_operation(string a,string b){

    int m=a.size();
    int n=b.size();

    if(n==0){
        return m;
    }
    if(m==0){
        return n;
    }

    if(a[m-1]==b[n-1]){
        return min_operation(a.substr(0,m-1),b.substr(0,n-1));
    }
    else{
        int addition=1+min_operation(a,b.substr(0,n-1));
        int deletion=1+min_operation(a.substr(0,m-1),b);
        int replace=1+min_operation(a.substr(0,m-1),b.substr(0,n-1));

        return min(addition,min(deletion,replace));
    }

}



int min_operation_DP(string a,string b){

    int m=a.size();
    int n=b.size();


    vector<vector<int>>DP(m+1,vector<int>(n+1,0));

    for(int i=0;i<=n;i++){
        DP[0][i]=i;
    }
    for(int i=0;i<=m;i++){
        DP[i][0]=i;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            if(a[i-1]==b[j-1]){
                DP[i][j]=DP[i-1][j-1];
            }
            else{
                DP[i][j]=1 + min(DP[i-1][j-1],min(DP[i][j-1],DP[i-1][j]));
            }

        }
    }

    return DP[m][n];
}

int main(){
    string a="horse";
    string b="ros";

    cout<<min_operation_DP(a,b);

}
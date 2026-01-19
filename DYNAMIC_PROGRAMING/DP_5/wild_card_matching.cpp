#include<iostream>
#include<vector>
#include<string>
using namespace std;


bool isPossible(string Text,string Pattern){

    

    int m=Text.size();
    int n=Pattern.size();

    if(m==0 && n==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(m==0 && Pattern[n-1]!='*'){
        return false;
    }
    

    char ch =Pattern[n-1];

    if(ch=='*' || ch=='?'){

        if(ch=='?'){
            
            return isPossible(Text.substr(0,m-1),Pattern.substr(0,n-1));
        }
        else{
            for(int i=0;i<=Text.size();i++){
                if(isPossible(Text.substr(0,m-i),Pattern.substr(0,n-1))){
                    return true;
                }
            }
            return false;

        }


    }
    else{

        if(Text[m-1]==Pattern[n-1]){
            return isPossible(Text.substr(0,m-1),Pattern.substr(0,n-1));
        }
        else{
            return false;
        }

    }

    
}


int isPossible_DP(string Text,string Pattern){

    int m=Text.size();
    int n=Pattern.size();

    vector<vector<int>>DP(m+1,vector<int>(n+1,0));

    DP[0][0]=1;

    for(int i=1;i<=m;i++){
        DP[i][0]=0;
    }

    for(int i=1;i<=n;i++){
        if(Pattern[i-1]=='*'){
            DP[0][i]=DP[0][i-1];
        }
        else{
            DP[0][i]=0;
        }
        
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            char ch=Pattern[j-1];
            if(ch=='*' || ch=='?'){
                if(ch=='?'){
                    DP[i][j]=DP[i-1][j-1];
                }
                else{
                    for(int k=0;k<=i;k++){
                        if(DP[i-k][j-1]==1){
                            DP[i][j]=1;
                            break;
                        }
                        DP[i][j]=0;
                    }
                }

            }
            else{
                if(Text[i-1]==Pattern[j-1]){
                    DP[i][j]=DP[i-1][j-1];
                }
                else{
                    DP[i][j]=0;
                }
            }
            
        }
    }

    return DP[m][n];

}


int main(){


    string Text="baaabab";
    string Pattern="**ba****ab*";

    cout<<isPossible_DP(Text,Pattern);

    return 0;
}
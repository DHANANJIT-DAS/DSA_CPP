#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>&price,vector<int>&length,int totalLength,int i,vector<vector<int>>&DP){

    if(i==price.size() || totalLength==0){
        return 0;
    }
    if(DP[i][totalLength]!=-1){
        return DP[i][totalLength];
    }

    int profit1=0;
    if(length[i]<=totalLength){
        profit1=price[i]+solve(price,length,totalLength-length[i],i,DP);
    }
    int profit2=solve(price,length,totalLength,i+1,DP);

    DP[i][totalLength]= max(profit1,profit2);
    return DP[i][totalLength];
}

int rod_cutting(vector<int>&price,vector<int>&length,int & totalLength){   // memoisation

    vector<vector<int>>DP(length.size()+1,vector<int>(totalLength+1,-1));
    return solve(price,length,totalLength,0,DP);
}

int rod_cutting_tabulation(vector<int>&price,vector<int>&length,int & totalLength){

    vector<vector<int>>DP(length.size()+1,vector<int>(totalLength+1,0));

    for(int i=1;i<=price.size();i++){
        for(int j=1;j<=totalLength;j++){

            if(j>=length[i-1]){
                DP[i][j]=max(price[i-1]+DP[i][j-length[i-1]],DP[i-1][j]);
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }

    return DP[price.size()][totalLength];
    

}

int main(){

    vector<int> price={1,5,8,9,10,17,17,20};
    vector<int> length={1,2,3,4,5,6,7,8};
    int totalLength=8;
    cout<<rod_cutting_tabulation(price,length,totalLength);
    return 0;
}



/* we have a rod of length totalLength . we have to cut it in such a way that its total price is max.

   a piece of rod of length length[i] costs price[i].
*/
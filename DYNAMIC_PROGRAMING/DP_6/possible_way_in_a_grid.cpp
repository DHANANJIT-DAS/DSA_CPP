#include<iostream>
#include<vector>
using namespace std;





int no_of_ways_DP(int n,int m){

    vector<vector<int>>DP(n,vector<int>(m,1));

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            DP[i][j]=DP[i-1][j]+DP[i][j-1];
        }
    }
    return DP[n-1][m-1];

}


int no_of_ways(int n,int m){
    if(n==1 || m==1){
        return 1;
    }
    
    return no_of_ways(n-1,m)+no_of_ways(n,m-1);
}


int main(){
    cout<<no_of_ways(3,3);

    return 0;
}



/*

  there is a n * m grid .
  how many ways are possible to go from (1,1) to (n,m);
*/

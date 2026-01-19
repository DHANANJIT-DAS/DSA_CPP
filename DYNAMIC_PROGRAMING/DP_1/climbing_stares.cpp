#include<iostream>
#include<vector>
using namespace std;


// person can climb 1 or 2 steps at a time , find no. ow ways to climb n stares
int climbing_stares(int n){  // O(2^n)
    if(n==1 || n==2){
        return n;
    }
    return climbing_stares(n-1)+climbing_stares(n-2);
}

int climbing_stares_DP(int n){  //O(n)
    vector<int>ways(n+1,-1);
    ways[1]=1;
    ways[2]=2;
    for(int i=3;i<=n;i++){
        ways[i]=ways[i-1]+ways[i-2];
    }
    return ways[n];
}

int main(){
    cout<<climbing_stares(5);
    cout<<climbing_stares_DP(5);
    return 0;
}
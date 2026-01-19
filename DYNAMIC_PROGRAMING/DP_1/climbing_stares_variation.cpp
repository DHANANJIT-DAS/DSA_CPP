// a person can climb 1 or 2 or 3 strps at a time , no of ways to climb n stares

#include<iostream>
#include<vector>
using namespace std;

/*

int climbing_stares(int n){
    if(n==1 || n==2 || n==3){
        if(n==3){
            return 4;
        }
        else{ 
            return n;
        }
    }
    return climbing_stares(n-1)+climbing_stares(n-2)+climbing_stares(n-3);
}


int climbing_stares_DP(int n){
    vector<int>ways(n+1,-1);
    ways[1]=1;
    ways[2]=2;
    ways[3]=4;
    for(int i=4;i<=n;i++){
        ways[i]=ways[i-1]+ways[i-2]+ways[i-3];
    }
    return ways[n];
}
int main(){
    int n=4;
    cout<<climbing_stares_DP(n);
    return 0;
}

*/


// a person can climb 1 or 3 steps at a time , no of ways to climb n stares



int climbing_stares(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 1;
    }
    if(n==3){
        return 2;
    }

    return climbing_stares(n-1)+climbing_stares(n-3);
}

int climbing_staresDP(int n){
    vector<int>ways(n+1,-1);
    ways[1]=1;
    ways[2]=1;
    ways[3]=2;

    for(int i=4;i<=n;i++){
        ways[i]=ways[i-1]+ways[i-3];
    }
    return ways[n];
}

int climbing_staresDP2(int n,vector<int>&ways){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 1;
    }
    if(n==3){
        return 2;
    }
    if(ways[n]!=-1){
        return ways[n];
    }

    ways[n]=climbing_staresDP2(n-1,ways)+climbing_staresDP2(n-3,ways);
    return ways[n];
}


int main(){
    int n=6;
    vector<int>ways(n+1,-1);
    cout<<climbing_staresDP2(n,ways);
    return 0;
}


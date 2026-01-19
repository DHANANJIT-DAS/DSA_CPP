#include<iostream>
#include<vector>
using namespace std;



int possible_mountain( int n){

    if(n==0 || n==1){
        return 1;
    }

    int ans=0;

    for(int i=0;i<n;i++){
        ans=ans+ possible_mountain(i)*possible_mountain(n-i-1);
    }

    return ans;

}

int main(){

    cout<<possible_mountain(4);
    return 0;
}
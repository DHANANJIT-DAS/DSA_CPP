#include<iostream>
#include<string>
using namespace std;

int gridWays(int n,int m,int i,int j,string str){
    
    if(i==n-1 && j==m-1){
        cout<<str<<endl;
        return 1;
    }


     if(i>=n){
        return 0;
    }
    else if(j>=m){
       return 0;
    }
    return gridWays(n,m,i,j+1,str+'R')+gridWays(n,m,i+1,j,str+'D');

    


}


int main(){

    string str="";
    int n=3;
    int m=3;
    cout<<gridWays(n,m,0,0,str);
    return 0;
}
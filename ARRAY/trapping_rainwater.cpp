#include<iostream>
#include<climits>
using namespace std;


int waterTrapped(int height[],int n){

    int leftBoundary[n];
    int rightBoundary[n];

    leftBoundary[0]=0;

    for(int i=1;i<n;i++){
        leftBoundary[i]=max(height[i-1],leftBoundary[i-1]);
    }

    rightBoundary[n-1]=0;
    for(int i=n-2;i>=0;i--){
        rightBoundary[i]=max(height[i+1],rightBoundary[i+1]);
    }

    int amount=0;

    for(int i=0;i<n;i++){
        int currentamount=min(leftBoundary[i],rightBoundary[i])-height[i];

        if(currentamount>=0){
            amount=amount+currentamount;
        }
        
    }
    return amount;

}

int main(){

    int height[]={4,2,0,6,3,2,5};
    cout<<waterTrapped(height,7);

    return 0;
}
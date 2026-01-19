#include<iostream>
using namespace std;

void allOccurance(int arr[],int i,int n,int target){
    if(i==n){
        return;
    }
    if(arr[i]==target){
        cout<<i<<" ";

    }
    allOccurance(arr,i+1,n,target);
    


}
int main(){

    int arr[]={1,4,2,5,7,5,6,8,5,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=4;
    allOccurance(arr,0,n,target);
    return 0;
}
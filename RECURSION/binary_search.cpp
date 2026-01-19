#include<iostream>
using namespace std;
int binarySearch(int arr[],int strt,int end,int target){

    if(strt>end){
        return -1;
    }


    
    int mid=(strt+end)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        return binarySearch(arr,strt,mid-1,target);
    }
    else{
       return binarySearch(arr,mid+1,end,target);
    }


}


int main(){

    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=8;

   cout<< binarySearch(arr,0,n-1,target);

    return 0;
}
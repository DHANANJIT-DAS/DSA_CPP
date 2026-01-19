#include<iostream>
#include<vector>
using namespace std;


int search(vector<int>&arr,int target,int strt,int end){

    
    if(strt>end){
        return -1;
    }
    int mid=(strt+end)/2;
    if(arr[mid]==target){
        return mid;
    }

    if(arr[strt]<=arr[mid]){
        //case 1
        if(target>=arr[strt] && target<arr[mid]){
            return search(arr,target,strt,mid-1);
        }
        else{
            return search(arr,target,mid+1,end);
        }
    }
    else{
       //case2
       if(target>arr[mid] && target<=arr[end]){
           return search(arr,target,mid+1,end);
        }
        else{
           return search(arr,target,strt,mid-1);
        }
    }

}


int main(){

    vector<int>arr={7,8,9,10,1,2,3,4,5,6};
    int target=7;

    cout<<search(arr,target,0,arr.size()-1);



    return 0;
}
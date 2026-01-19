#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int merge(vector<int>&arr,int strt,int mid,int end){

    int count=0;

    vector<int>temp;
    int i=strt;
    int j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
            count=count+(mid-i+1);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }

    for(int k=strt,x=0;k<=end;k++,x++){
        arr[k]=temp[x];
    }
    return count;

}

int mergeSort(vector<int>&arr,int strt,int end){

    int count=0;

    if(strt==end){
        return 0;
    }
    int mid=(strt+end)/2;

    count=count+mergeSort(arr,strt,mid);
    count=count+mergeSort(arr,mid+1,end);
    count=count+merge(arr,strt,mid,end);

    return count;
}

int inverseCount(vector<int>&arr){
    int n=arr.size();
    return mergeSort(arr,0,n-1);
}

int main(){
    vector<int>arr={2,4,1,3,5};
    cout<<inverseCount(arr);
    
    return 0;
}
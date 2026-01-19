#include<iostream>
#include<string>
#include<vector>
using namespace std;

void print(vector<string>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<string>&arr,int mid,int strt,int end){
    vector<string>temp;
    int i=strt;
    int j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }

    for(int k=strt,idx=0;k<=end;k++,idx++){
        arr[k]=temp[idx];
    }

}

void divide(vector<string>&arr,int strt,int end){

if(strt==end){
    return;
}

    int mid=(strt+end)/2;
    divide(arr,strt,mid);
    divide(arr,mid+1,end);
    merge(arr,mid,strt,end);

}


int main(){
    vector<string>arr={"sun","earth","mars","mercury"};
    divide(arr,0,arr.size()-1);
    print(arr);
}
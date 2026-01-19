#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int>&arr,int strt,int mid,int end){  // O(n) complexity

    vector<int>temp;
    
    int i=strt;
    int j=mid+1;
    
    while(i<=mid && j<=end ){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
            
        }
        else{
            temp.push_back(arr[j]);
            j++;
            
        }

    }
    

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int k=strt,x=0;k<=end;k++,x++){
        arr[k]=temp[x];
    }



}

void divide(vector<int>&arr,int strt,int end){   //O(log n) complexity
    if(strt==end){
        return;
    }

    int mid=(strt+end)/2;
    divide(arr,strt,mid);  //left
    divide(arr,mid+1,end);  //right

    merge(arr,strt,mid,end);

}


int main(){
    vector<int>arr={3,5,7,2,5,4,5,67,8,9,3,5,7,2,5,7,87};
    int n=arr.size();
    divide(arr,0,n-1);
    print(arr);
    return 0;
}
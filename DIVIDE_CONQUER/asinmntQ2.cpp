#include<iostream>
#include<vector>
using namespace std;


//method 1  O(n) time complexity

/*
int majorityElement(vector<int>arr){
    int count=0;
    int element;
    for(int i=0;i<arr.size();i++){
        if(count==0){
            element=arr[i];
        }
        if(element==arr[i]){
            count++;
        }
        if(element !=arr[i]){
            count--;
        }
    }
    return element;


}

int main(){
    vector<int>arr={1,2,1,3,1,4,1};
    cout<<majorityElement(arr);
    return 0;
}
*/

// method 2 O(n*log n) time complexity

int count(vector<int>arr,int strt,int end,int majority){
    int count=0;
    for(int i=strt;i<=end;i++){
        if(majority==arr[i]){
            count++;
        }
    }
    return count;

}

int majorityElement(vector<int>&arr,int strt,int end){

    if(strt==end){
        return arr[strt];
    }
    
    int mid=(strt+end)/2;

    int left=majorityElement(arr,strt,mid);
    int right=majorityElement(arr,mid+1,end);

    if(left==right){
        return left;
    }
    
    int leftCount=count(arr,strt,mid,left);
    int rightCount=count(arr,mid+1,end,right);
    

    return leftCount > rightCount ? left : right;
    
}

int main(){
    vector<int>arr={1,3,1,1,4,1,1,4};
    int n=arr.size();
    cout<<majorityElement(arr,0,n-1);
}




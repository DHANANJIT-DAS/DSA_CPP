#include<iostream>
#include<climits>
using namespace std;


int max_subarray_sum(int arr[],int n){


    int ans=INT32_MIN;
    int sum=0;


    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            ans=max(ans,sum);
        }
        sum=0;
    }

    return ans;
}


int max_sum(int arr[],int n){  //  kadane's algorithm

    int ans=INT_MIN;
    int sum=0;

    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
        }

    }
    return ans;
}


int main(){

    int arr[6]={2,-3,6,-5,4,2};
    cout<<max_sum(arr,6);
    return 0;
}
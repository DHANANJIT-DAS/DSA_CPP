#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int largest_subarray_sum_0(vector<int>&nums){   // sum[i,j]=sum[j]-sum[i-1]
    unordered_map<int,int>M;  //(sum till index i,i)
    M[0]=-1;
    int sum=0;
    int length=0;
    for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
        if(M.count(sum)){
            length=max(length,i-M[sum]);
        }
        else{
            M[sum]=i;
        }
    }

    return length;
}


// int length(vector<int>&nums){
//     int length=0;
//     int sum=0;
//     for(int i=0;i<nums.size();i++){
//         for(int j=i;j<nums.size();j++){
//             sum=sum+nums[j];
//             if(sum==0){
//                 length=max(length,j-i+1);
//             }
//         }
//         sum=0;
//     }
//     return length;
// }


int main(){
    vector<int>nums={10,-10,5,8,7,9,-9,-8,-5,-7};
    cout<<largest_subarray_sum_0(nums);
    return 0;
}
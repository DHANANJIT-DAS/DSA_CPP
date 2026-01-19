#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int countSubarray(vector<int>&nums,int k){  //sum[i,j]=sum[j]-sum[i-1]
    unordered_map<int,int>M; //(sum,count)
    M[0]=1;
    int sum=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
        if(M.count(sum-k)){
            ans=ans+M[sum-k];
        }
        
        M[sum]++;
        
    }
    return ans;
}
int main(){
    vector<int>arr={10,-10,2,3,-5,1,-1};
    cout<<countSubarray(arr,0);
    return 0;
}
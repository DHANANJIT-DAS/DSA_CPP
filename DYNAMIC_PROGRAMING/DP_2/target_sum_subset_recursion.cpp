#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>&nums,int target,int i){

    if(i==nums.size() || target==0){
        return 0;
    }
    

    int take=0;
    if(nums[i]<=target){
        take=nums[i]+solve(nums,target-nums[i],i+1);
    }
    int skip=solve(nums,target,i+1);
    return max(take,skip);
}

bool target_sum(vector<int>&nums,int &target){

    
    return solve(nums,target,0)==target;
   
}

int main(){

    vector<int>nums={4,2,7,1,3};
    int target=7;

    cout<<target_sum(nums,target);
    return 0;
}
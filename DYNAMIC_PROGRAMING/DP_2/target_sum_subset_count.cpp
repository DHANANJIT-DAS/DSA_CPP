#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int>&nums,int target,int i,int &count){

    if(target==0){
        count++;
        return;
    }
    if(i==nums.size()){
        return;
    }


    if(target>=nums[i]){
        solve(nums,target-nums[i],i+1,count);
    }
    solve(nums,target,i+1,count);

}

int target_sum(vector<int>&nums,int target){
    int count=0;
    solve(nums,target,0,count);
    return count;
}


int main(){
    vector<int>nums={4,2,7,1,3};
    int target=7;

    cout<<target_sum(nums,target);
    return 0;
}
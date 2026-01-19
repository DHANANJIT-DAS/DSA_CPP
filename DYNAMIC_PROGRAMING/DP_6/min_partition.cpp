#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int maxVal(vector<int>&nums,int target,int i){


    if(target==0 || i>=nums.size()){
        return 0;
    }


    if(nums[i]<=target){
        int val1=nums[i]+maxVal(nums,target-nums[i],i+1);
        int val2=maxVal(nums,target,i+1);

        return max(val1,val2);

    }
    else{
        return maxVal(nums,target,i+1);
    }
}



int min_diff(vector<int>&nums){

    int n=nums.size();

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }

    

    
    int target=sum/2;


    int maxHalf=maxVal(nums,target,0);

    return (sum-maxHalf)-maxHalf;


}


int min_diff_DP(vector<int>&nums){

    int n=nums.size();

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    
    int target=sum/2;


    vector<vector<int>>DP(n+1,vector<int>(target+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){

            if(nums[i-1]<=j){
                DP[i][j]=max(nums[i-1]+DP[i-1][j-nums[i-1]],DP[i-1][j]);
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }

    return (sum-DP[n][target])-DP[n][target];
}

int main(){
    vector<int>nums={1,6,11,5};

    cout<<min_diff_DP(nums);

}



/*

partition a array into two subset such that their sum difference is minimum.

0 <= nums[i] <= 1e9

*/
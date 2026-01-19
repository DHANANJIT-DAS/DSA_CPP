#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int solve(vector<int>arr1,vector<int>arr2,int sum){

    int halfSum=sum/2;
    int ans=INT32_MAX;

    for(int i=0;i<arr1.size();i++){
        int x=arr1[i];
        auto it =lower_bound(arr2.begin(),arr2.end(),halfSum-x);
        if(it !=arr2.end()){
            ans=min(ans,abs(sum-2*(x+*it)));
        }
    }

    return ans;
}

void createPart(vector<int>&nums,vector<vector<int>>&part,int i,int n,int sum){


    if(i==nums.size()){
        part[n].push_back(sum);
        return;
    }
    
    createPart(nums,part,i+1,n+1,sum+nums[i]);
    createPart(nums,part,i+1,n,sum);



}

int minDifference(vector<int>nums){
    int n=nums.size()/2;

    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }

    vector<int>nums1(n,-1),nums2(n,-1);

    for(int i=0;i<n;i++){
        nums1[i]=nums[i];
        nums2[i]=nums[n+i];
    }

    vector<vector<int>>part1(n+1);
    vector<vector<int>>part2(n+1);

    createPart(nums1,part1,0,0,0);
    createPart(nums2,part2,0,0,0);

    for(int i=0;i<=n;i++){
        sort(part2[i].begin(),part2[i].end());
    }

    
    int ans=INT32_MAX;

    for(int i=0;i<=n;i++){
        ans=min(ans,solve(part1[i],part2[n-i],sum));
    }
    

    return ans;


}

int main(){
    vector<int>nums={-36,36};

    cout<<minDifference(nums);
    

    return 0;
}


/*

given an integer array of size 2n.

we have to split it in two array of size n,n  such that their sum difference is minimum.

  -1e9 <= nums[i] <= 1e9
*/
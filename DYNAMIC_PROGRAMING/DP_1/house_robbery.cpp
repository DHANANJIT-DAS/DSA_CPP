#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>&nums,int i,int n){  // O(2^n)

    if(i>=n){
        return 0;
    }

    int steal=nums[i]+solve(nums,i+2,n);
    int skip=solve(nums,i+1,n);

    return max(steal,skip);
}

int house_robbery(vector<int>&nums){
    int n=nums.size();
    return solve(nums,0,n);
}

// -----------------------------------------------------------------------//
//------------------------------------------------------------------------//

int solve_memo(vector<int>&nums,int i,int n,vector<int>&max_money){  // O(n)

    if(i>=n){
        return 0;
    }

    if(max_money[i]!=-1){
        return max_money[i];
    }

    int steal=nums[i]+solve_memo(nums,i+2,n,max_money);
    int skip=solve_memo(nums,i+1,n,max_money);

    max_money[i]=max(steal,skip);

    return max_money[i];
}


int house_robbery_DP_memo(vector<int>&nums){
    int n=nums.size();
    vector<int>max_money(n,-1);

    return solve_memo(nums,0,n,max_money);
}





//--------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------//


int house_robbery_tabular(vector<int>nums){
    int n=nums.size();
    vector<int>max_money(n,0);
    max_money[0]=nums[0];
    max_money[1]=max(nums[0],nums[1]);
    

    for(int i=2;i<n;i++){
        max_money[i]=max(nums[i]+max_money[i-2],max_money[i-1]);
    }
    return max_money[n-1];
}










int main(){
    vector<int>nums={12,3,4,5,3,17};// no of money each house has
    //cout<<house_robbery_DP_memo(nums);

    cout<<house_robbery_tabular(nums);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;


bool target_sum(vector<int>nums,int target){
    vector<vector<int>>DP(nums.size()+1,vector<int>(target+1,0));


    for(int i=1;i<=nums.size();i++){
        for(int j=1;j<=target;j++){
            if(nums[i-1]<=j){
                DP[i][j]=max(nums[i-1]+DP[i-1][j-nums[i-1]],DP[i-1][j]);
            }
            else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }

    for(int i=0;i<=nums.size();i++){
        for(int j=0;j<=target;j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    return DP[nums.size()][target]==target;
}

int main(){
    vector<int>nums={4,2,7,1,3};
    int target=7;

    cout<<target_sum(nums,target);
    return 0;
}
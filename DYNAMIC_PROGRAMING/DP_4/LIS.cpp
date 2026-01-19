#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


int longest_increasing_subsequence(vector<int>&nums){

    unordered_set<int>S;
    
    for(int i=0;i<nums.size();i++){
        S.insert(nums[i]);
    }

    vector<int>copy;

    for(int el:S){
        copy.push_back(el);
    }

    sort(copy.begin(),copy.end());

    vector<vector<int>>DP(nums.size()+1,vector<int>(copy.size()+1,0));

    for(int i=1;i<=nums.size();i++){
        for(int j=1;j<=copy.size();j++){
            if(nums[i-1]==copy[j-1]){
                DP[i][j]=1+DP[i-1][j-1];
            }
            else{
                DP[i][j]=max(DP[i][j-1],DP[i-1][j]);
            }
        }
    }

    return DP[nums.size()][copy.size()];

}

int main(){

    vector<int>nums={50,3,10,7,40,80};
    cout<<longest_increasing_subsequence(nums);
    return 0;
}
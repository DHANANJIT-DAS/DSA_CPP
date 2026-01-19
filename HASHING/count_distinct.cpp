#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int> count_distinct(vector<int>nums){
    unordered_map<int,int>M; //(element,frequency)
    vector<int>ans;

    for(int i=0;i<nums.size();i++){
        M[nums[i]]++;
    }
    for(auto x:M){
        if(x.second==1){
            ans.push_back(x.first);
        }
    }
    return ans;
}

void print_vec(vector<int>&nums){
    for(auto x:nums){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>nums={2,4,3,6,7,8,3,5,6,2,4,6,7,34,5,6};
    vector<int>ans=count_distinct(nums);

    print_vec(ans);
    return 0;
}
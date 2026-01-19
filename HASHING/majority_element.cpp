#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> majority_element(vector<int>&arr){
    unordered_map<int,int>M; //(element,frequency)
    vector<int>ans;

    for(int i=0;i<arr.size();i++){
        M[arr[i]]++;
    }

    for(auto x:M){
        if(x.second>arr.size()/3){
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
    vector<int>nums={1,3};
    vector<int>ans=majority_element(nums);
    print_vec(ans);

    return 0;
}
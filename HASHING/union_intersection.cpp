#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


vector<int> Union(vector<int>&nums1,vector<int>&nums2){
    unordered_set<int>S; //(element)
    vector<int>ans;

    for(int i=0;i<nums1.size();i++){
        S.insert(nums1[i]);
    }
    for(int i=0;i<nums2.size();i++){
        S.insert(nums2[i]);
    }

    for(auto x:S){
        ans.push_back(x);
    }

    return ans;
}

vector<int> intersection(vector<int>&nums1,vector<int>&nums2){
    unordered_set<int>S; //(element)
    vector<int>ans;

    for(int i=0;i<nums1.size();i++){
        S.insert(nums1[i]);
    }

    for(int i=0;i<nums2.size();i++){
        if(S.find(nums2[i])!=S.end()){
            ans.push_back(nums2[i]);
            S.erase(nums2[i]);
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
    vector<int>nums1={1,2,3,4};
    vector<int>nums2={4,5,6,7};

    vector<int>Union_set=Union(nums1,nums2);
    vector<int>Intersection_set=intersection(nums1,nums2);

    print_vec(Intersection_set);
    return 0;
}
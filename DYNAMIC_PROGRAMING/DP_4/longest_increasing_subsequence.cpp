#include<iostream>
#include<vector>
using namespace std;


int longest_increasing_subsequence(vector<int>&nums,int i,int lastVal){

    if(i==nums.size()){
        return 0;
    }

    int currentVal=nums[i];

    if(lastVal < currentVal){
        int a= 1+longest_increasing_subsequence(nums,i+1,currentVal);
        int b= longest_increasing_subsequence(nums,i+1,lastVal);
        return max(a,b);
    }
    else{
        return longest_increasing_subsequence(nums,i+1,lastVal);
    }
    

}

int main(){

    vector<int>nums={50,3,10,7,40,80};
    cout<<longest_increasing_subsequence(nums,0,0);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;


int lastOccurance(vector<int>&nums,int target,int i){
    if(i==nums.size()){
        return -1;
    }
    


    int x=lastOccurance(nums,target,i+1);
    if(x ==-1 && nums[i]==target){
       
       return i;
       
       
    }else{
    
        return x;
    }
    
    


}

int firstOccurance(vector<int> &nums,int target,int i){
    if(i==nums.size()){
        return -1;
    }
    if(nums[i]==target){
        return i;
    }

    return firstOccurance(nums,target,i+1);

}


int main(){

    vector<int>nums={1,2,3,4,5,6,3};
    
    int target=3;

    //cout<<firstOccurance(nums,target,0);
    cout<<lastOccurance(nums,target,0);

    return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;



void printNum(vector<int>nums,string ans,vector<string>key){
    if(nums.size()==0){
        cout<<ans<<endl;
        return;
    }

    int number=nums[0];
    for(int i=0;i<nums.size()-1;i++){
        nums[i]=nums[i+1];
    }
    nums.pop_back();


    for(int i=0;i<key[number-2].size();i++){
        printNum(nums,ans+key[number-2][i],key);

    }

}


int main(){

    string ans="";
    vector<string>key={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<int>nums={2,3};
    printNum(nums,ans,key);
    return 0;
}
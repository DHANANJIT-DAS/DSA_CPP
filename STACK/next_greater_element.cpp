#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> next_greater_element(vector<int>&nums){
    int n=nums.size();
    stack<int>temp;
    vector<int>ans(n,0);
    

    for(int i=n-1;i>=0;i--){
        while(!temp.empty() && temp.top()<=nums[i]){
            temp.pop();
        }
        if(temp.empty()){
           ans[i]=-1;
           temp.push(nums[i]);
           continue;
        }else{
            ans[i]=temp.top();
            temp.push(nums[i]);
        }

    }
    return ans;

}
int main(){
    vector<int>nums={6,8,0,1,3};
    vector<int>nextGreater=next_greater_element(nums);
    print(nums);
    print(nextGreater);
    return 0;
}
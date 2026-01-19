#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int min_absolute_diff_of_pairs(vector<int>&arr1,vector<int>&arr2){

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    int minAbsDiff=0;

    for(int i=0;i<arr1.size();i++){
        minAbsDiff=minAbsDiff+abs(arr1[i]-arr2[i]);
    }
    return minAbsDiff;

}

int main(){
    vector<int>arr1={1,2,3};
    vector<int>arr2={2,1,3};
    cout<<min_absolute_diff_of_pairs(arr1,arr2);
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


pair<int,int> pair_sum(vector<int>&arr,int target){
    unordered_map<int,int>M; // (key->arr[i],value->i)
    for(int i=0;i<arr.size();i++){
        int x=target-arr[i];
        if(M.count(x)){
            return make_pair(M[x],i);
        }
        else{
            M[arr[i]]=i;
        }
    }
    return {-1,-1};
}

int main(){
    vector<int>arr={1,2,7,11,15,5,9};
    int target=9;
    pair<int,int>P=pair_sum(arr,target);
    cout<<"("<<P.first<<","<<P.second<<")";
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second < p2.second;
}

int max_length(vector<pair<int,int>>&pairs){

    sort(pairs.begin(),pairs.end(),compare);

    int max_length=1;
    int current_end=pairs[0].second;

    for(int i=1;i<pairs.size();i++){
        if(current_end<=pairs[i].first){
            max_length++;
            current_end=pairs[i].second;
        }
    }

    return max_length;
}

int main(){
    
    vector<pair<int,int>>pairs={{5,24},{39,60},{5,28},{27,40},{50,90}};

    cout<<max_length(pairs);
    return 0;
}
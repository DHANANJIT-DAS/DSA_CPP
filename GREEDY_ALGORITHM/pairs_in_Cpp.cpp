#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




bool compare(pair<int,int>p1,pair<int,int>p2){
    return (p1.second < p2.second || (p1.second==p2.second && p1.first < p2.first));
}
int main(){

    /*

    vector<pair<int,int>>arr={{1,2},{3,4},{5,6},{7,8},{9,10}};
    for(int i=0;i<arr.size();i++){
        cout<<arr[i].first<<","<<arr[i].second<<endl;
    }

    */


    vector<int>start={1,2,3,4,5,6,7,8,9,10};
    vector<int>end={4,2,7,4,9,6,2,2,2,2};

    vector<pair<int,int>>pairs(start.size(),make_pair(0,0));

    for(int i=0;i<pairs.size();i++){
        pairs[i]=make_pair(start[i],end[i]);
    }

    for(int i=0;i<pairs.size();i++){
        cout<<pairs[i].first<<","<<pairs[i].second<<endl;
    }


    sort(pairs.begin(),pairs.end(),compare);

    for(int i=0;i<pairs.size();i++){
        cout<<pairs[i].first<<","<<pairs[i].second<<endl;
    }


    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second < p2.second;
}

int max_activity(vector<int>start,vector<int>end){

    vector<pair<int,int>>start_end(start.size(),{0,0});  //(start,end)

    for(int i=0;i<start.size();i++){
        start_end[i]=make_pair(start[i],end[i]);
    }

    sort(start_end.begin(),start_end.end(),compare);

    int max_activity=1;
    int current_end=start_end[0].second;

    for(int i=1;i<start_end.size();i++){
        if(current_end<=start_end[i].first){
            max_activity++;
            current_end=start_end[i].second;
        }
        
    }
    return max_activity;

}
int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};

    cout<<max_activity(start,end);
    return 0;
}
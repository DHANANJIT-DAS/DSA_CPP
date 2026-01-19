#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second > p2.second ;
}

int max_profit(vector<pair<int,int>>&deadline_profit){

    sort(deadline_profit.begin(),deadline_profit.end(),compare);

    unordered_set<int>S;

    int profit=deadline_profit[0].second;
    S.insert(deadline_profit[0].first);

    for(int i=1;i<deadline_profit.size();i++){
        for(int j=deadline_profit[i].first;j>0;j--){
            if(S.find(j)==S.end()){
                S.insert(j);
                profit+=deadline_profit[i].second;
                break;
            }
        }
    }

    return profit;
}


int main(){
    vector<pair<int,int>>deadline_profit={{2,10},{6,65},{4,20},{2,22},{2,80},{6,70},{5,60},{4,25}};

    cout<<max_profit(deadline_profit);
    return 0;
}
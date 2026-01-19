#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct pair_hash {       // custom hashing for pair<int,int>   since pair<int,int> can't be hashed by default  
    size_t operator()(const pair<int, int>& p) const noexcept {
        // Combine hashes of both integers
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};


int solve(int strtlen,int endlen,vector<int>& cuts,unordered_map<pair<int,int>,int,pair_hash>&DP){

    if(DP[make_pair(strtlen,endlen)]){
        return DP[make_pair(strtlen,endlen)];
    }
    
    int cost=INT32_MAX;

    for(int i=0;i<cuts.size();i++){
        if(strtlen<cuts[i] && cuts[i]<endlen){
            cost=min(cost,solve(strtlen,cuts[i],cuts,DP)+solve(cuts[i],endlen,cuts,DP));
        }
    }
    

    if(cost==INT32_MAX){
        DP[make_pair(strtlen,endlen)]=0;
    }
    else{
       DP[make_pair(strtlen,endlen)]= cost+(endlen-strtlen);
    }
    return DP[make_pair(strtlen,endlen)];
}

int minCost(int length, vector<int>& cuts) {
    unordered_map<pair<int,int>,int,pair_hash>DP;
    return solve(0,length,cuts,DP);
}

int main(){

    vector<int>cuts = {1,3,4,5};
    int length=7;
    cout<<minCost(length,cuts);
    return 0;
}
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<string,int>M;
    M["India"]=150;
    M["Nepal"]=280;
    M["UK"]=50;
    M["US"]=360;
    M["Russia"]=260;

    //cout<<M["India"];
    cout<<M.count("Russia")<<endl;
    for(pair<string,int> country:M){
        cout<<country.first<<","<<country.second<<endl;
    }
    M.erase("Russia");
    cout<<M.count("Russia");
    

    return 0;
}
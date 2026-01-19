#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){

    map<string,int>M;

    M["India"]=120;
    M["China"]=234;
    M["US"]=12;
    M["UK"]=123;
    M["Nepal"]=345;
    M["Indonesia"]=34;

    M["India"]=239;

    M.erase("China");

    for(pair<string,int>country:M){
        cout<<country.first<<","<<country.second<<endl;
    }

    cout<<M.count("China");

    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

vector<string> itinerary(unordered_map<string,string>M){
    unordered_set<string>to;
    vector<string>ans;
    string strt="";

    for(auto el:M){
        to.insert(el.second);
    }

    for(auto el:M){
        if(to.find(el.first)==to.end()){
            strt=el.first;
        }
    }

    ans.push_back(strt);
    while(M.count(strt)){
        ans.push_back(M[strt]);
        strt=M[strt];
        
    }

    return ans;

}

void print(vector<string>ans){
    for(auto x:ans){
        cout<<x<<"-->";
    }
    cout<<endl;
}
int main(){
    unordered_map<string,string>tickets;
    tickets["Chennai"]="Bengaluru";
    tickets["Mumbai"]="Delhi";
    tickets["Goa"]="Chennai";
    tickets["Delhi"]="Goa";

    
    print(itinerary(tickets));

    return 0;
}
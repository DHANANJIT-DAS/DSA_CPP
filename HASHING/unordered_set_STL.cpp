#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int>S;
    S.insert(1);
    S.insert(5);
    S.insert(10);
    S.insert(12);

    cout<<S.size()<<endl;

    for(int x:S){
        cout<<x<<" ";
    }
    cout<<endl;
    int x=5;
    S.erase(5);
    
    if(S.find(x)!=S.end()){
        cout<<x<<" exist";
    }else{
        cout<<x<<" doesn't exist";
    }

    return 0;
}
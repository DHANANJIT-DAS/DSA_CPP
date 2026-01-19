#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int>S;

    S.insert(5);
    S.insert(8);
    S.insert(1);
    S.insert(7);

    cout<<S.size()<<endl;

    for(int x:S){
        cout<<x<<" ";
    }
    cout<<endl;
    int x=5;
    S.erase(x);

    if(S.find(x)!=S.end()){
        cout<<x<<" exist";
    }
    else{
        cout<<x<<" doesn't exist";
    }

    return 0;
}
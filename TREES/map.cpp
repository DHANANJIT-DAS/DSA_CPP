#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    map<int,string> M;
    M[101]="rahul";
    M[102]="neha";
    M[105]="rajat";
    M[110]="ankan";
    M[150]="rahul";

    cout<<M[102]<<endl;
    M[150]="dhananjit";
    
    

    for(auto itr:M){
        cout<<itr.first<<":"<<itr.second<<endl;
    }
    return 0;
}
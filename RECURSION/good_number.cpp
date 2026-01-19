#include<iostream>
#include<string>
using namespace std;
void even(int,int&,string);

void odd(int n,int &count,string ans){

    if(n==0){
        count++;
        cout<<ans<<endl;
        return ;
    }

    string prime="2357";
    
    for(int i=0;i<prime.size();i++){
    
        even(n-1,count,ans+prime[i]);
    }
    
}



void even(int n,int &count,string ans){

    if(n==0){
        count++;
        cout<<ans<<endl;
        return ;
    }


    for(int i=0;i<5;i++){
        string even="02468";
        
        odd(n-1,count,ans+even[i]);
        
    }
}


int main(){

    int n=2;
    int count=0;
    string ans="";
    even(n,count,ans);

    cout<<count<<endl;


    return 0;
}
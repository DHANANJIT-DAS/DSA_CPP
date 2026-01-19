#include<iostream>
#include<string>
using namespace std;

void remDuplicate(string str,string &ans,int i,bool map[]){
    if(i==str.length()){
        cout<<ans;
        return;
    }
    if(map[(int)str[i]-'a']==0){
        ans=ans+str[i];
        map[(int)str[i]-'a']=1;
    }
    remDuplicate(str,ans,i+1,map);

}


int main(){
    string str="dhananjit";
    string ans="";
    bool map[26]={false};

    remDuplicate(str,ans,0,map);

    return 0;
}
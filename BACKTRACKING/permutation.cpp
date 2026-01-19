#include<iostream>
#include<string>
using namespace std;
void permutation(string str,string ans){

    if(str.size()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.size();i++){
        permutation(str.substr(0,i)+str.substr(i+1,str.size()-i-1),ans+str[i]);
    }

}
int main(){
    string str="abc";
    string ans="";
    permutation(str,ans);
    return 0;

}
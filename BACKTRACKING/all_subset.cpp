#include<iostream>
#include<string>
using namespace std;
void subset(string str,string sub){

    if(str.size()==0){
        cout<<sub<<endl;
        return;
    }

    subset(str.substr(1,str.size()-1),sub+str[0]);
    subset(str.substr(1,str.size()-1),sub);
}
int main(){
    string str="abcd";
    string sub="";
    subset(str,sub);
    return 0;
}
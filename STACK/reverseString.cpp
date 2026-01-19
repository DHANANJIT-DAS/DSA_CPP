#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseString(string str){
    stack<char>temp;
    for(int i=0;i<str.size();i++){
        temp.push(str[i]);
    }
    str="";
    while(!temp.empty()){
        str.push_back(temp.top());
        temp.pop();
    }
    return str;
}
int main(){
    string str="abcdef";
    str=reverseString(str);
    cout<<str;
    return 0;
}
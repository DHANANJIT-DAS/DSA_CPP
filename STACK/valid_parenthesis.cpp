#include<iostream>
#include<stack>
using namespace std;
bool opening(char ch){
    return (ch=='(') || (ch=='{') || (ch=='[');
}
bool closing(char ch){
    return (ch==')') || (ch=='}') || (ch==']');
}
bool isMatching(char top,char ch){
    if(top=='(' && ch==')'){
        return true;
    }
    if(top=='{' && ch=='}'){
        return true;
    }
    if(top=='[' && ch==']'){
        return true;
    }

    return false;

}

bool valid_parenthesis(string str){
    stack<char>temp;
    for(int i=0;i<str.size();i++){

        if(opening(str[i])){
            temp.push(str[i]);
            continue;
        }
        if(closing(str[i])){
            if(temp.empty()){
                return false;
            }
            if(!isMatching(temp.top(),str[i])){
                return false;
            }
            else{
                temp.pop();
            }
        }
    }
    if(!temp.empty()){
        return false;
    }
    return true;
}
int main(){
    string str="]]]]";
    cout<<valid_parenthesis(str);
    return 0;
}
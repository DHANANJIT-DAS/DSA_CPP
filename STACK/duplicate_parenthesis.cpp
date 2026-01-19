#include<iostream>
#include<stack>
using namespace std;

bool duplicate_parenthesis(string exprsn){
    stack<char>temp;
    for(int i=0;i<exprsn.size();i++){

        if(exprsn[i]!=')'){
            temp.push(exprsn[i]);
        }
        
        else{
            if(temp.top()=='('){
                return true;
            }
            while(temp.top()!='('){
                temp.pop();
            }
            temp.pop();
        }
        
        
    }
    return false;
}

int main(){
    string exprsn="(((a+b)+c))";
    cout<<duplicate_parenthesis(exprsn);
    return 0;
}

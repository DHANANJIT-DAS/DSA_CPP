#include<iostream>
#include<stack>
using namespace std;

void push_at_bottom(stack<int>&s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int topElement=s.top();
    s.pop();
    push_at_bottom(s,val);
    s.push(topElement);
}

void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }

    int top=s.top();
    s.pop();
    reverseStack(s);
    push_at_bottom(s,top);

}
void printStack(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);
    printStack(s);

    
    return 0;
}
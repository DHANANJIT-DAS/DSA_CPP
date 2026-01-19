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
int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    push_at_bottom(s,6);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

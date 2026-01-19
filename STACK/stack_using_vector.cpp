#include<iostream>
#include<vector>
using namespace std;

class Stack{
   
    vector<int>stack;

    public:

    void push(int val){
        stack.push_back(val);
    }
    void pop(){
        if(! isEmpty()){
            stack.pop_back();
        }
        else{
            return;
        }
        
    }
    int top(){
        if(! isEmpty()){
            return stack[stack.size()-1];
        }
        else{
            cout<<"stack empty..";
            return -1;
        }
        
    }
    bool isEmpty(){
        return stack.size()==0;
    }
};
int main(){
    Stack s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    while(! s1.isEmpty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }

    return 0;
}
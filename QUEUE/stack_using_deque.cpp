#include<iostream>
#include<deque>
using namespace std;

template<class T>
class Stack{
    deque<T>dq;
public:
    void push(T val){
        dq.push_back(val);
    }
    void pop(){
        dq.pop_back();
    }
    T top(){
        return dq.back();
    }
    bool isEmpty(){
        return dq.empty();
    }

};

int main(){
    Stack<int>S;
    for(int i=1;i<=5;i++){
        S.push(i);
    }
    while(!S.isEmpty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    return 0;
}
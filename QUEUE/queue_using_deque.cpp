#include<iostream>
#include<deque>
using namespace std;

template<class T>
class Queue{
    deque<T>dq;
public:
    void push(T val){
        dq.push_back(val);
    }
    void pop(){
        dq.pop_front();
    }
    T front(){
        return dq.front();
    }
    bool isEmpty(){
        return dq.empty();
    }

};
int main(){
    Queue<int>Q;
    for(int i=1;i<=5;i++){
        Q.push(i);
    }
    for(int i=1;i<=5;i++){
        cout<<Q.front()<<" ";
        Q.pop();
    }

    return 0;
}
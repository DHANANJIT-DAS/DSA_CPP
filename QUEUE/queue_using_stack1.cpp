#include<iostream>
#include<stack>
using namespace std;

template<class T>
class Queue{
    stack<T>s;

    public:

    void push_at_bottom(T &val){
        if(s.empty()){
            s.push(val);
            return;
        }
        
        T temp=s.top();
        s.pop();
        push_at_bottom(val);
        s.push(temp);
    }

    void push(T val){
        push_at_bottom(val);
    }
    void pop(){
        s.pop();
    }
    T front(){
        return s.top();
    }

    bool isEmpty(){
        return s.empty();
    }

};
int main(){
    Queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
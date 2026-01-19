#include<iostream>
# include<queue>
using namespace std;

template<class T>
class Stack{
    queue<T>q1;                   // push O(n) complexity;
    queue<T>q2;                   // pop O(1)  complexity;         
                                  // front O(1) complexity;
    public:

    void push(T val){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        q1.pop();

    }
    T top(){
        return q1.front();
    }
    bool isEmpty(){
        return q1.empty();
    }

};

int main(){
    Stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
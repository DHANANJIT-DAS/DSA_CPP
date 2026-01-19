#include<iostream>
# include<queue>
using namespace std;

template<class T>
class Stack{
    
    queue<T>q;

    void reverse_queue(){
        
        if(q.empty()){
            return;
        }
        T temp=q.front();
        q.pop();
        reverse_queue();
        q.push(temp);

    }

    public:

    void push(T val){
        reverse_queue();
        q.push(val);
        reverse_queue();

    }
    void pop(){
        q.pop();
    }

    T top(){
        return q.front();
    }
    bool isEmpty(){
        return q.empty();
    }
};

int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}


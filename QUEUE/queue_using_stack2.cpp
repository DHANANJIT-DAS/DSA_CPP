#include<iostream>
#include<stack>
using namespace std;

template<class T>
class Queue{

    stack<T>s1;                // push()  is O(n) complexity;
    stack<T>s2;                // pop()   is O(1) complexity;
    public:                    // front() is O(1) complexity;

    void push(T val){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }
    void pop(){
        s1.pop();

    }
    T front(){
        return s1.top();
    }

    bool isEmpty(){
        return s1.empty();
    }

};



template<class T>
class queue{

    stack<T>s1;                     //push()  is O(1) complexity;
    stack<T>s2;                     //pop()   is O(n) complexity;
    T f;                            //front() is O(1) complexity;
    bool frontInitialize;
    public:
    queue(){
        frontInitialize=false;
    }

    void push(T val){
        s1.push(val);
        if(frontInitialize==false){
            f=val;
            frontInitialize=true;
        }
    }
    void pop(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();

        if(!s2.empty()){
            f=s2.top();
        }
        else{
            frontInitialize=false;
        }
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }

    T front(){
        return f;
    }

    bool isEmpty(){
        return s1.empty();
    }


    

};

int main(){
    queue<char> q;
    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
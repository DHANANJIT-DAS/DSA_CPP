#include<iostream>
using namespace std;

template<class T>
class Queue{
    T *arr;

    int capacity;
    int currSize;
    int f;
    int r;
    public:
    Queue(int n){
        capacity=n;
        currSize=0;
        f=-1;
        b=-1;
        arr=new T[capacity];
    }

    void push(T val){
        if(currSize==capacity){
            return;
        }
        r=(r+1)%capacity;
        arr[r]=val;
        currSize++;
        if(f==-1){
            f=0;
        }
        
        
    }
    void pop(){
        if(!isEmpty()){
            f=(f+1)%capacity;
            currSize--;
        }
        
    }

    T front(){
        if(!isEmpty()){
            return arr[f];
        }
        
        
    }

    bool isEmpty(){
        return currSize==0;
    }
};
int main(){
    Queue<char> q(5);

    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    q.push('e');
    q.push('f');

    cout<<q.front()<<" ";
    q.pop();
    q.push('f');
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();

    return 0;
}
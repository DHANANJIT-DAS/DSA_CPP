#include<iostream>
#include<string>
using namespace std;

template<class T>
class node{
    public:
    T data;
    node<T>* next;
    node(T data){
        this->data=data;
        next=NULL;
    }
    ~node(){
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }

};
template<class T>
class Queue{
    node<T>* head;
    node<T>* tail;

    public:

    Queue(){
        head=NULL;
        tail=NULL;
    }
    ~Queue(){
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }
    
    void push(T val){
        node<T>* newNode=new node<T>(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }

    }
    void pop(){
        if(head==NULL){
            return;
        }
        else if(head->next==NULL){
            delete head;
            head=tail=NULL;
        }
        else{
            node<T>* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    T front(){
        return head->data;
    }
    bool isEmpty(){
        return head==NULL;
    }

};

int main(){
    Queue<string> q;
    q.push("Hi");
    q.push("I");
    q.push("am");
    q.push("Dhananjit");

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
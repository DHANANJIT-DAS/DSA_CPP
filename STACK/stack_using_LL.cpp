#include<iostream>
#include<string>
#include<vector>
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
        if(next !=NULL){
            delete next;
            next=NULL;
        }
    }

};

template<class T>
class List{

    public:

    node<T>* head;

    List(){
        head=NULL;
    }

    ~List(){
        if(head !=NULL){
            delete head;
            head=NULL;
        }
    }



    void push_front(T val){
        node<T>* newNode=new node<T>(val);
        if(head==NULL){
           head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }


    


    void pop_front(){
        if(head==NULL){
           return;
        }
        node<T>* temp=head->next;
        head->next=NULL;
        delete head;
        head=temp;
       
    }

    

    
};


template<class T>
class Stack{
    List<T> ll;

    public:

    void push(T val){
        ll.push_front(val);

    }
    void pop(){
        ll.pop_front();
    }

    T top(){
        return ll.head->data;
    }

    bool isEmpty(){
        return ll.head==NULL;
    }
    
};

int main(){
    Stack<string> s;
    s.push("world");
    s.push("hellow");
    s.push("hi");
    while(! s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
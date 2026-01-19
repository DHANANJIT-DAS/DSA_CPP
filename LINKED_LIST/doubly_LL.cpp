#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node*prev;
    node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
    ~node(){
        if(next !=NULL){
            delete next;
            next=NULL;
        }
    }

};

class List{
    public:
    node* head;
    node* tail;

    List(){
        head=NULL;
        tail=NULL;
    }

    ~List(){
        if(head !=NULL){
            delete head;
            head=NULL;
        }
    }

    void push_back(int data){
        node* newNode=new node(data);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=tail->next;
        }
    }

    void push_front(int data){
        node* newNode=new node(data);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            return;
        }
        
        node* temp=head;
        head=head->next;
        if(head !=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            return;
        }
        node* temp=tail;
        tail=tail->prev;
        if(tail !=NULL){
            tail->next=NULL;
        }
        temp->prev=NULL;
        delete temp;
    }

    void printList(){
        node* temp=head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.pop_back();
    ll.pop_front();
    ll.printList();
    return 0;
}
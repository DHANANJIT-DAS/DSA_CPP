#include<iostream>
using namespace std;


class node{

    public:
    
    int data;
    node* next;
    
    
    node(int data){
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


class List{

    public:

    node* head;

    List(){
        head=NULL;
    }

    ~List(){
        if(head !=NULL){
            delete head;
            head=NULL;
        }
    }



    void push_front(int val){
        node* newNode=new node(val);
        if(head==NULL){
           head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }


    void push_back(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=newNode;
        }
        else{
           node* temp=head;
           while(temp->next !=NULL){
            temp=temp->next;
           }
           temp->next=newNode;
        }
        
    }


    void pop_front(){
        if(head==NULL){
           return;
        }
        node* temp=head->next;
        head->next=NULL;
        delete head;
        head=temp;
       
    }

    void pop_back(){
        if(head==NULL){
           return;
        }
       node* temp =head;
       node* prev=NULL;
       while(temp->next !=NULL){
            prev=temp;
            temp=temp->next;
       }
       if(prev==NULL){
        delete temp;
        head=NULL;
       }else{
            prev->next=NULL;
            delete temp;
       }
    }


    void printList(){
        node* temp=head;
        while(temp !=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int getsize(){
        int size=0;
        node* temp=head;
        while(temp !=NULL){
            size++;
            temp=temp->next;
        }
        return size;
    }

    void remove_Nth_node(int n){
        if(head==NULL){
            return;
        }

        int size=getsize();
        if(n>size){
            return;
        }
        node* previous=NULL;
        node*current=head;

        for(int i=0;i<(size-n);i++){
            previous=current;
            current=current->next;
        }
        if(previous !=NULL){
            previous->next=current->next;
            current->next=NULL;
            delete current;
        }
        else{
            head=head->next;
            current->next=NULL;
            delete current;
        }
        
    }

    
    

};






int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.printList();
    ll.remove_Nth_node(4);
    ll.printList();

   
    return 0;
}
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


    void insert(int val,int index){
        if(index<1){
            return;
        }

        node* current=head;
        node* previous=NULL;
        for(int i=1;i<index;i++){
            previous=current;
            if(previous==NULL){
                return;
            }
            current=current->next;
        }

        node* newNode=new node(val);
        if(current==NULL){
            previous->next=newNode;
        }

        if(previous !=NULL){
            newNode->next=current;
            previous->next=newNode;
        }
        else{
            newNode->next=current;
            head=newNode;
        }
       
        
    }


};



int main(){

    List ll;
    ll.push_front(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_front(0);
    ll.insert(5,7);
   
    ll.printList();

    


    return 0;
}
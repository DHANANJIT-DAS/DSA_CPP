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
};


bool detectCycle(node* head){

    node* slow=head;
    node* fast=head;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }

    return false;

}

void makeCycle(node* head,int n){
    if(head== NULL || head->next==NULL){
        return;
    }
    node*temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    node* tail=temp;
    temp=head;
    for(int i=1;i<n;i++){
        temp=temp->next;
    }
    tail->next=temp;

    return;

}

void breakCycle(node* head){
    node* slow=head->next;
    node* fast=head->next->next;
    while(slow !=fast){
        slow=slow->next;
        fast=fast->next->next;
    }

    slow=head;
    if(fast !=slow){
        node* previous=fast;
        while(slow !=fast){
            previous=fast;
            slow=slow->next;
            fast=fast->next;
        
        }
        previous->next=NULL;

    }

    else{
        while(fast->next !=slow){
            fast=fast->next;
        }
        fast->next=NULL;
    }
}


int main(){

    List ll;
    for(int i=1;i<=10;i++){
        ll.push_back(i);
    }

    
    makeCycle(ll.head,2);
    
    if(detectCycle(ll.head)){
        breakCycle(ll.head);
    }

    ll.printList();

    return 0;
}
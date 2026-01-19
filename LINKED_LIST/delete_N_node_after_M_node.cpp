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

node* deleteNode(node* head,int m,int n){
    if(m==0 && n==0){
        return head;
    }
    if(n==0){
        return head;
    }
    if(m==0){
        delete head;
        return NULL;
    }
    node* current=head;
    node* prev1=NULL;
    node* prev2=NULL;
    while(current !=NULL){
        for(int i=1;i<=m;i++){
            prev1=current;
            current=current->next;
            if(current==NULL){
                return head;
            }
        }
        
        prev1->next=NULL;
        
        
        node* temp=current;
        for(int i=1;i<=n;i++){
            prev2=current;
            current=current->next;
            if(current==NULL){
                delete temp;
                return head;
            }
        }
        
        prev2->next=NULL;
        
        
        prev1->next=current;
        delete temp;
        
        
    }
    return head;
}



int main(){

    List ll;
    for(int i=1;i<=20;i++){
        ll.push_back(i);
    }
    ll.printList();
    ll.head=deleteNode(ll.head,3,2);
    ll.printList();
    
    


    return 0;
}
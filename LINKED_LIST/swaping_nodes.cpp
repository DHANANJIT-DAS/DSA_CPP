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

node* swapNode(node* head,int x,int y){
    if(x==y){
        return head;
    }
    if(y<x){
        swap(x,y);
    }

   

    node* x_current=head;
    node* x_previous=NULL;
    node* y_current=NULL;
    node* y_previous=NULL;
    for(int i=1;i<x;i++){
        x_previous=x_current;
        x_current=x_current->next;
    }
    node* x_next=x_current->next;

    y_current=x_current;
    for(int i=1;i<=y-x;i++){
        y_previous=y_current;
        y_current=y_current->next;
    }
    node* y_next=y_current->next;
    
    if(x_previous !=NULL){

        if(y-x==1){
            x_previous->next=y_current;
            y_current->next=x_current;
            x_current->next=y_next;
        }
        else{
            x_previous->next=y_current;
            y_current->next=x_next;

            y_previous->next=x_current;
            x_current->next=y_next;
        }

        
    }
    else{
        if(y-x==1){
            y_current->next=x_current;
            x_current->next=y_next;
            head=y_current;
        }
        
        else{
            y_current->next=x_next;

            y_previous->next=x_current;
            x_current->next=y_next;

            head=y_current;
        }

    }
    return head;

}


int main(){

    
    List ll;
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_front(1);
    ll.push_back(9);
    ll.push_back(10);
    ll.printList();
    ll.head=swapNode(ll.head,9,8);
    ll.printList();


    return 0;
}

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

node* odd_even(node* head){
    node* evenHead=NULL;
    node* evenTail=NULL;
    node* oddHead=NULL;
    node* oddTail=NULL;
    node* temp=NULL;
    while(head !=NULL){
        temp=head;
        head=head->next;
        temp->next=NULL;

        if(temp->data %2 ==0){
           
            if(evenHead !=NULL){
                evenTail->next=temp;
                evenTail=evenTail->next;
            }
            else{
                evenHead=temp;
                evenTail=evenHead;
            }
        }
        else{
            if(oddHead !=NULL){
                oddTail->next=temp;
                oddTail=oddTail->next;
            }
            else{
                oddHead=temp;
                oddTail=oddHead;
            }
            

        }
    }
    evenTail->next=oddHead;
    return evenHead;
}

int main(){

    List ll;
    
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(7);
    ll.push_back(3);
    ll.push_back(8);
    ll.push_back(12);
    ll.printList();
    ll.head=odd_even(ll.head);
    ll.printList();

    return 0;
}
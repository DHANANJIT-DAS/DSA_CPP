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

node* merge(node* leftHead,node* rightHead){
    node* head=NULL;
    node* prev=NULL;
    if(leftHead->data <=rightHead->data){
        head=leftHead;
        prev=head;
        leftHead=leftHead->next;
        head->next=NULL;
    }
    else{
        head=rightHead;
        prev=rightHead;
        rightHead=rightHead->next;
        head->next=NULL;
    }
    node* temp=NULL;
    while(leftHead !=NULL && rightHead !=NULL){
        if(leftHead->data <= rightHead->data){
            temp=leftHead;
            leftHead=leftHead->next;
            temp->next=NULL;
            prev->next=temp;
            prev=prev->next;
        }
        else{
            temp=rightHead;
            rightHead=rightHead->next;
            temp->next=NULL;
            prev->next=temp;
            prev=prev->next;
        }

    }

    if(leftHead !=NULL){
        prev->next=leftHead;

    }
    if(rightHead !=NULL){
        prev->next=rightHead;
    }
    return head;
}
node * split_at_mid(node* head){

    node* slow=head;
    node* fast=head;
    node* previous_of_slow=NULL;
    while(fast !=NULL && fast->next !=NULL){
        previous_of_slow=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if( previous_of_slow !=NULL){
         previous_of_slow->next=NULL;
    }
   
    return slow;

}

node* mergeSort(node * head){
    if(head->next == NULL){
        return head;
    }
    node* rightHead=split_at_mid(head);

    head=mergeSort(head);
    rightHead=mergeSort(rightHead);

    return merge(head,rightHead);
    

}



int main(){

   

    List ll;
    ll.push_back(22);
    ll.push_back(4);
    ll.push_back(6);
    ll.push_back(21);
    ll.push_back(3);
    ll.push_back(7);
    ll.push_back(2);
    ll.push_back(1);
    ll.push_back(22);
     ll.push_back(7);
    ll.push_back(21);
    ll.push_back(12);
    ll.printList();
    ll.head=mergeSort(ll.head);
    ll.printList();



    return 0;
}
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

};


class List{
     public:

    node* head;

    List(){
        head=NULL;
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


node* merge(node* left,node* right){
    List ans;
    node* i=left;
    node* j=right;
    while(i !=NULL && j !=NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i=i->next;
        }
        else{
            ans.push_back(j->data);
            j=j->next;
        }
    }
    while(i !=NULL){
        ans.push_back(i->data);
        i=i->next;
    }
    while(j !=NULL){
        ans.push_back(j->data);
        j=j->next;
    }
   
    delete left;
    delete right;
    return ans.head;

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

node* mergeSort(node* head){
    if(head->next ==NULL){
        return head;
    }
    node* rightHead=split_at_mid(head);

    head=mergeSort(head);
    rightHead=mergeSort(rightHead);

    return merge(head,rightHead);
}


int main(){

    List ll;
    
    ll.push_back(4);
    ll.push_back(2);
    ll.push_back(41);
    ll.push_back(23);
    ll.push_back(14);
    
    
    
    ll.printList();
    ll.head=mergeSort(ll.head);
    ll.printList();


    


    return 0;
}


//this is not a correct code because it doesnt use destructor .so it causes memory leak .
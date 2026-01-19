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

int getsize(node* head){
        int size=0;
        node* temp=head;
        while(temp !=NULL){
            size++;
            temp=temp->next;
        }
        return size;
    }

node* reverseList(node* head){
    node* previous=NULL;
    node* current=head;
       

    while(current !=NULL){

        node* nextNode=current->next;

        current->next=previous;

        previous=current;
        current=nextNode;
            
    }

    return previous;
}


bool isPalindrome(node* head){
    if(getsize(head)<=1){
        return true;
    }

    node* slow=head;
    node* fast=head;
    node* prev=NULL;
    while(fast !=NULL && fast->next !=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    node* reverseHead=reverseList(slow);
    node* temp1=head;
    node* temp2=reverseHead;

    bool ans=true;
    
    while(temp1!=NULL && temp2 !=NULL){
        if(temp1->data !=temp2->data){
            ans=false;
            break;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(!ans){
        ans=false;
    }

    reverseHead=reverseList(reverseHead);
    prev->next=reverseHead;
    return ans;

}

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(5);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    cout<<isPalindrome(ll.head)<<endl;
    ll.printList();

   
    return 0;
}
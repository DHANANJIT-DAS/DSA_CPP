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

node* split_at_mid(node* head){
    node* slow=head;
    node* fast=head;
    node* prev_of_slow=NULL;
    while(fast !=NULL && fast->next !=NULL){
        prev_of_slow=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev_of_slow){
        prev_of_slow->next=NULL;
    }
    
    return slow;
}

node* reverseList(node* head){
    node* prev=NULL;
    node* current=head;
    node* nextNode=NULL;
    while(current !=NULL){
        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    return prev;
}
void alternatemerge(node*head,node* head2){
    
    node* list1=head;
    node* list2=head2;
    while(list1->next !=NULL){
        head2=head2->next;
        list2->next=list1->next;
        list1->next=list2;
        list2=head2;
        list1=list1->next->next;
    }
    list1->next=head2;

}
void zig_zag(node*head){
    if (head== NULL || head->next==NULL){
        return;
    }
    node* midHead=split_at_mid(head);
    node* head2=reverseList(midHead);
    alternatemerge(head,head2);
    
}

int main(){

   List ll;
   ll.push_back(1);
   ll.push_back(2);
   ll.push_back(3);
   ll.push_back(4);
   ll.push_back(5);
   ll.push_back(6);
   ll.push_back(7);
   ll.push_back(8);
   ll.push_back(9);
   ll.push_back(10);
   ll.push_back(11);

   
   
   zig_zag(ll.head);
   ll.printList();

    


    return 0;
}
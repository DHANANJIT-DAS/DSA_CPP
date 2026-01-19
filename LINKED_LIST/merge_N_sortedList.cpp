#include<iostream>
#include<vector>
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
    node* tail;

    List(){
        head=NULL;
        tail=NULL;
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
           head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }


    void push_back(int val){
        node* newNode=new node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        
    }


    void pop_front(){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        temp=NULL;
    }

    void pop_back(){
        if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
        }
        if(head->next==tail){
            head->next=NULL;
            delete tail;
            tail=head;
        }
        node*temp=head;

        while(temp->next != tail){
            temp=temp->next;
        }

        temp->next=NULL;
        delete tail;
        tail=temp;
    }


    void printList(){
        node* temp=head;
        while(temp !=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        return ;
    }


};

node* merge(node* head1,node* head2){
    node* dummy=new node(-1);
    node* tail=dummy;
    while(head1 !=NULL && head2 !=NULL){
        if(head1->data <= head2->data){
            tail->next=head1;
            head1=head1->next;
            tail=tail->next;
            tail->next=NULL;
        }
        else{
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
            tail->next=NULL;
        }
    }
    if(head1 !=NULL){
        tail->next=head1;
    }
    if(head2 !=NULL){
        tail->next=head2;
    }
    node* head=dummy->next;
    dummy->next=NULL;
    delete dummy;
    return head;
}

node* merge_N_List(vector<node*>&arr){
    if(arr.size()==0){
        return NULL;
    }
    if(arr.size()==1){
        return arr[0];
    }

    node* head=arr[0];
    for(int i=1;i<arr.size();i++){
        head=merge(head,arr[i]);
    }
    return head;

}



int main(){

    List l1;
    l1.push_back(1);
    l1.push_back(4);
    l1.push_back(7);
    l1.push_back(12);

    List l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(6);
    l2.push_back(4);

    List l3;
    l3.push_back(1);
    l3.push_back(7);
    l3.push_back(7);
    l3.push_back(13);

    List l4;
    l4.push_back(5);
    l4.push_back(8);
    l4.push_back(31);

    vector<node*>arr;
    arr.push_back(l1.head);
    arr.push_back(l2.head);
    arr.push_back(l3.head);
    arr.push_back(l4.head);

    List l5;

    l5.head=merge_N_List(arr);
    l5.printList();
    l1.head=NULL;
    l2.head=NULL;
    l3.head=NULL;
    l4.head=NULL;
    
    


    return 0;
}
#include<iostream>
#include<string>
using namespace std;


class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }

};

class HashTable{
    int totalSize;
    int currSize;
    Node** hashTable;


    int hashFuncn(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx=(idx+key[i]*key[i])%totalSize;
        }
        return idx;
    }

    void rehashing(){

        Node** oldTable=hashTable;
        int oldSize=totalSize;

        totalSize=totalSize*2;
        currSize=0;
        hashTable=new Node* [totalSize];

        for(int i=0;i<totalSize;i++){
            hashTable[i]=NULL;
        }

        for(int i=0;i<oldSize;i++){
            Node* temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }

            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
        }


        delete[] oldTable;

    }

public:

    HashTable(int totalSize){
        this->totalSize=totalSize;
        currSize=0;
        hashTable=new Node*[totalSize];

        for(int i=0;i<totalSize;i++){
            hashTable[i]=NULL;
        }
    }



    void insert(string key,int val){

        int idx=hashFuncn(key);

        Node* newNode=new Node(key,val);
        newNode->next=hashTable[idx];
        hashTable[idx]=newNode;
        currSize++;

        double thresold=currSize/(double)totalSize;
        if(thresold>1){
            rehashing();
        }

    }

    bool exist(string key){
        int idx=hashFuncn(key);
        Node* temp=hashTable[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    int search(string key){
        int idx=hashFuncn(key);
        Node* temp=hashTable[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
        }
        return -1;

    }
    void erase(string key){
        int idx=hashFuncn(key);
        Node* temp=hashTable[idx];
        Node* prev=NULL;
        while(temp!=NULL){
            
            if(temp->key==key){
                if(prev==NULL){
                    hashTable[idx]=temp->next;
                }
                else{
                    prev->next=temp->next;
                }
                break;
                
            }
            prev=temp;
            temp=temp->next;
        }

    }

    void print(){
        for(int i=0;i<totalSize;i++){
            Node* temp=hashTable[i];
            cout<<i<<" : ";
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->val<<")";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    

};


int main(){
    HashTable H(5);
    H.insert("India",120);
    H.insert("indonesia",150);
    H.insert("China",160);
    H.insert("UK",195);
    H.insert("US",170);
    H.insert("brazil",180);
    H.insert("russia",1210);

    
    cout<<H.search("brazil");
    H.print();
    cout<<"___________"<<endl;
    H.erase("China");
    H.print();
    cout<<"___________"<<endl;
    H.erase("UK");
    H.print();

    return 0;
}
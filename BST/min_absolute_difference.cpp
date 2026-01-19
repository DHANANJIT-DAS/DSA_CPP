#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

};

void find_key(Node* root,int k,int &min_diff,Node* &min_diff_key){
    if(root==NULL){
        return;
    }

    if(abs(root->data - k)==0){
        min_diff_key=root;
        min_diff=0;
        return;
    }

    if(abs(root->data - k) < min_diff){
        min_diff=abs(root->data - k);
        min_diff_key=root;
    }

    if(k > root->data){
        find_key(root->right,k,min_diff,min_diff_key);
    }
    else{
        find_key(root->left,k,min_diff,min_diff_key);
    }


}

Node* min_absolute_diff(Node* root,int k){
    int min_diff=INT32_MAX;
    Node* min_diff_key=NULL;

    find_key(root,k,min_diff,min_diff_key);
    return min_diff_key;
}


   
int main(){

    Node* root=new Node(8);
    root->left=new Node(5);
    root->right=new Node(11);
    root->left->left=new Node(3);
    root->left->right=new Node(6);
    root->right->right=new Node(20);

    cout<<min_absolute_diff(root,5)->data;
    
    return 0;
}
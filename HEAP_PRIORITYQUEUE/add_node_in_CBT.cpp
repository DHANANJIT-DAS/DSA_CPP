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


int getLeftHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    return getLeftHeight(root->left)+1;
}

int getRightHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    return getRightHeight(root->right)+1;
}

int isbalanced(Node* root){
    if(root==NULL){
        return 0;
    }

    int left=getLeftHeight(root);
    int right=getRightHeight(root);
    if(left==right){
        return right;
    }
    return -1;
}

Node* add_Node_in_left(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    root->left= add_Node_in_left(root->left,val);
    return root;
}



Node* add_Node_in_CBT(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }

    int left=isbalanced(root->left);
    int right=isbalanced(root->right);

    if(left == right){
        root->left= add_Node_in_left(root->left,val);
    }
    else if(left==right+1){
        root->right= add_Node_in_left(root->right,val);
    }
    else if(left==-1){
        root->left=add_Node_in_CBT(root->left,val);
    }
    else if(right==-1){
        root->right=add_Node_in_CBT(root->right,val); 
    }
    return root;
    
}
int main(){

    Node* root=new Node(4);
    root->left=new Node(5);
    root->right=new Node(8);
    root->left->left=new Node(12);
    root->left->right=new Node(15);
    root->right->left=new Node(18);
    root->right->right=new Node(20);
    root->left->left->left=new Node(120);
    root->left->left->right=new Node(122);
    root->left->right->left=new Node(128);
    root->left->right->right=new Node(130);
    root->right->left->left=new Node(140);
    root->right->left->right=new Node(150);
    root->right->right->left=new Node(170);
    root->right->right->right=new Node(180);

    root=add_Node_in_CBT(root,10);

    cout<<root->left->left->left->left->data;

    return 0;
}

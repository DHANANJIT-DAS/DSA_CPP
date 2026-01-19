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

Node* insert(Node* root,int val){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    else if(root->data > val){
        root->left=insert(root->left,val);
    }

    else if(root->data < val){
        root->right=insert(root->right,val);
    }
    else{
        root->left=insert(root->left,val);
    }
    return root;
}

Node* build_BST(vector<int>arr){
    Node* root=NULL;
    for(int i=0;i<arr.size();i++){
        root=insert(root,arr[i]);
    }

    return root;
}



Node* inorder_successor(Node* root){
    if(root->left==NULL){
        return root;
    }
    return inorder_successor(root->left);
}

Node* deleteNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    else if(root->data==val){

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            Node* next=root->left==NULL ? root->right:root->left;
            root->left==NULL ? root->right=NULL:root->left=NULL;
            delete root;
            return next;
        }
        else{
            Node* inorderSuccessor=inorder_successor(root->right);
            root->data=inorderSuccessor->data;
            root->right=deleteNode(root->right,inorderSuccessor->data);
        }

    }
    else if(root->data > val){
        root->left=deleteNode(root->left,val);
    }
    else{
        root->right=deleteNode(root->right,val);
    }
    return root;
}



void inorderTreversel(Node* root){
    if(root==NULL){
        return;
    }
    inorderTreversel(root->left);
    cout<<root->data<<" ";
    inorderTreversel(root->right);
}

   
int main(){
    vector<int>nodeData={1,2,4,6,3,23,45,21,67,89,34};
    Node* root=build_BST(nodeData);
    inorderTreversel(root);
    cout<<endl;
    root=deleteNode(root,45);
    inorderTreversel(root);
    cout<<endl;
    return 0;
}
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


void inorderTreversel(Node* root){
    if(root==NULL){
        return;
    }
    inorderTreversel(root->left);
    cout<<root->data<<" ";
    inorderTreversel(root->right);
}

   
int main(){
    vector<int>nodeData={1,2,4,6,3,23,45,21,67,45,89,34,45,45};
    Node* root=build_BST(nodeData);
    inorderTreversel(root);
    return 0;
}
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


bool validate_BST(Node* root,Node* max,Node* min){
    if(root==NULL){
        return true;
    }
    if(min !=NULL && root->data <=min->data){
        return false;
    }
    if(max !=NULL && root->data >=max->data){
        return false;
    }

    return validate_BST(root->left,root,min) &&
    validate_BST(root->right,max,root);

}


bool valid_BST(Node* root){
    Node* max=NULL;
    Node* min=NULL;
    return validate_BST(root,max,min);
    
}

int main(){
    vector<int>nodeData={1,2,4,6,3,23,45,21,67,45,89,34,45,45};
    Node* root=build_BST(nodeData);
    cout<<valid_BST(root);
    return 0;
}
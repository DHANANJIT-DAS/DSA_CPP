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



Node* search(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    else if(root->data==val){
        return root;
    }
    else if(root->data > val){
        return search(root->left,val);
    }
    else{
        return search(root->right,val);
    }
}


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
   
int main(){
    vector<int>nodeData={1,2,4,4,13,67,33,23,75,34,23,12,45,76};
    Node* root=build_BST(nodeData);

    cout<<search(root,34)->data;
    
    return 0;
}
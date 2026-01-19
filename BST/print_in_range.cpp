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



void print_in_range(Node* root,int strt,int end){
    if(root==NULL){
        return;
    }
    
    if(strt <= root->data && root->data <=end){
        print_in_range(root->left,strt,end);
        cout<<root->data<<" ";
        print_in_range(root->right,strt,end);
    }
    else if(root->data < strt){
        print_in_range(root->right,strt,end);
    }
    else{
        print_in_range(root->left,strt,end);
    }
    
}
   
int main(){
    vector<int>nodeData={1,2,4,6,3,23,45,21,67,45,89,34,45,45};
    Node* root=build_BST(nodeData);
    print_in_range(root,1,6);
    return 0;
}
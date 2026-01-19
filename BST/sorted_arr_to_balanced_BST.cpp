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

Node* build_BST(vector<int>&arr,int start,int end){
    if(start>end){
        return NULL;
    }

    int mid=(start+end)/2;
    Node* newNode=new Node(arr[mid]);
    newNode->left=build_BST(arr,start,mid-1);
    newNode->right=build_BST(arr,mid+1,end);
    return newNode;

}

Node* balanced_BST(vector<int>&arr){
    int start=0;
    int end=arr.size()-1;
    return build_BST(arr,start,end);

}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
   
int main(){
    vector<int>nodeData={1,2,3,4,5,6,7,8,9,10};
    Node* root=balanced_BST(nodeData);
    inorder(root);
    return 0;
}
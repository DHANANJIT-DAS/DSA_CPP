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





class info{

public:

    bool isBST;
    int max;
    int min;
    int size;
    
    info(bool isBST,int max,int min,int size){
        this->isBST=isBST;
        this->max=max;
        this->min=min;
        this->size=size;
    }

    

};

static int maxSize;

info* largestBST(Node* root){
    if(root==NULL){
        return new info(true,INT32_MIN,INT32_MAX,0);
    }
    info* left=largestBST(root->left);
    info* right=largestBST(root->right);

    int currMax=max(root->data,max(left->max,right->max));
    int currMin=min(root->data,min(left->min,right->min));
    int currSize=left->size+right->size+1;
    bool currisBST=false;
    if(left->isBST==true && right->isBST==true && root->data>left->max && root->data<right->min){
        currisBST=true;
        maxSize=max(currSize,maxSize);
    }
    
    return new info(currisBST,currMax,currMin,currSize);

}
   
int main(){
    vector<int>nodeData={1,2,4,6,3,23,21,67,45,89,34};
    Node* root=build_BST(nodeData);
    largestBST(root);
    cout<<maxSize;
    
    return 0;
}
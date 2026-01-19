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



static int idx=-1;

Node* buildTree(vector<int>&nodeData){
    idx++;

    if(nodeData[idx]==-1){
        return NULL;
    }

    Node* newNode=new Node(nodeData[idx]);
    newNode->left=buildTree(nodeData);
    newNode->right=buildTree(nodeData);
    return newNode;

}

bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    if(!isIdentical(root1->left,root2->left)){
        return false;
    }
    if(!isIdentical(root1->right,root2->right)){
        return false;
    }
    return true;
}

bool isSubtree(Node* root,Node* subroot){
    if(subroot==NULL){
        return true;
    }
    if(root==NULL){
        return false;
    }
    
    if(root->data==subroot->data){
        if(isIdentical(root,subroot)){
            return true;
        }
    }
    if(isSubtree(root->left,subroot)){
        return true;
    }
    if(isSubtree(root->right,subroot)){
        return true;
    }
    return false;

}
int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    Node* subroot=new Node(4);
    cout<<isSubtree(root,subroot);
    
    return 0;
}
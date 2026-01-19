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

int count_of_nodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftCount=count_of_nodes(root->left);
    int rightCount=count_of_nodes(root->right);
    return leftCount+rightCount+1;

    
}

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
int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    int count=count_of_nodes(root);
    cout<<count;
    return 0;
}
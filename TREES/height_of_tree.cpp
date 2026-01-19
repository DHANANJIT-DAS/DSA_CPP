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

int height_of_tree(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=height_of_tree(root->left);
    int rightHeight=height_of_tree(root->right);

    return max(leftHeight,rightHeight)+1;

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
    int height=height_of_tree(root);
    cout<<height;
    return 0;
}
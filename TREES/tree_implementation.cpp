#include<iostream>
#include<vector>
using namespace std;

static int idx=-1;
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

Node* buildTree(vector<int> &nodeData){
    
    idx++;
    if(nodeData[idx]==-1){
        return NULL;
    }
    Node* currentNode=new Node(nodeData[idx]);
    currentNode->left=buildTree(nodeData);
    currentNode->right=buildTree(nodeData);
    return currentNode;


}




void makePreOrder(Node* root,vector<int>& preOrder){
    if(root==NULL){
        preOrder.push_back(-1);
        return;
    }
    preOrder.push_back(root->data);
    makePreOrder(root->left,preOrder);
    makePreOrder(root->right,preOrder);
}

vector<int> buildPreOrder(Node* root){
    vector<int>preOrder;
    makePreOrder(root,preOrder);
    return preOrder;

}


int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodeData);
    

    

}
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

void postorderTreversel(Node* root){
    if(root==NULL){
        return;
    }
    postorderTreversel(root->left);
    postorderTreversel(root->right);
    cout<<root->data<<" ";
}
int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodeData);
    postorderTreversel(root);
    return 0;
}
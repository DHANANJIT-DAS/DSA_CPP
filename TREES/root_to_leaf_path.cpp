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





void printVector(vector<int>path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void make_path(Node* root,vector<int>&path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        printVector(path);
        path.pop_back();
        return;
    }
    
    make_path(root->left,path);
    make_path(root->right,path);
    path.pop_back();

}
void root_to_leaf_path(Node* root){
    vector<int>path;
    make_path(root,path);
}
   
int main(){
    vector<int>nodeData={8,5,3,1,-1,-1,4,-1,-1,6,-1,-1,10,-1,11,-1,14,-1,-1};
    Node* root=buildTree(nodeData);
    root_to_leaf_path(root);
    return 0;
}
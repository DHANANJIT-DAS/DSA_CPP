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

bool find_path(Node* root,vector<int>&ancestor,int &val){

    if(root==NULL){
        return false;
    }
    int current=root->data;
    if(current==val){
        ancestor.push_back(current);
        return true;
    }
    if(find_path(root->left,ancestor,val)){
        ancestor.push_back(current);
        return true;
    }
    if(find_path(root->right,ancestor,val)){
        ancestor.push_back(current);
        return true;
    }
    return false;
}


int LCA(Node* root,int n1,int n2){       // valid for all cases 
    
    vector<int>path1;
    vector<int>path2;
    find_path(root,path1,n1);
    find_path(root,path2,n2);
    int lca=INT32_MIN;
    for(int i=path1.size()-1, j=path2.size()-1;i>=0 && j>=0;i--,j--){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
    return lca;

}




Node* LCA2(Node* root,int n1,int n2){    // valid only when all node->data  are unique  and both n1 and n2 exist in tree
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* left=LCA2(root->left,n1,n2);
    Node* right=LCA2(root->right,n1,n2);

    if(left && right){
        return root;
    }
    
    return left==NULL? right:left;

}


int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodeData);
    cout<<LCA2(root,4,6)->data;
    
    return 0;
}
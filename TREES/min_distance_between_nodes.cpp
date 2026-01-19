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




bool find_path(Node* root,vector<Node*>&ancestor,int &val){

    if(root==NULL){
        return false;
    }
    int current=root->data;
    if(current==val){
        ancestor.push_back(root);
        return true;
    }
    if(find_path(root->left,ancestor,val)){
        ancestor.push_back(root);
        return true;
    }
    if(find_path(root->right,ancestor,val)){
        ancestor.push_back(root);
        return true;
    }
    return false;
}


Node* LCA(Node* root,int n1,int n2){
    vector<Node*>path1;
    vector<Node*>path2;
    find_path(root,path1,n1);
    find_path(root,path2,n2);
    Node* lca=NULL;
    for(int i=path1.size()-1, j=path2.size()-1;i>=0,j>=0;i--,j--){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
    return lca;

}


int distance(Node* root,int &val){
    if(root==NULL){
        return -1;
    }
    if(root->data==val){
        return 0;
    }
    int left=distance(root->left,val);
    if(left!=-1){
        return left+1;
    }
    int right=distance(root->right,val);
    if(right!=-1){
        return right+1;
    }
    return -1;

}


int min_distance(Node* root,int n1,int n2){

    Node* lca=LCA(root,n1,n2);

    int distance1=distance(lca,n1);
    int distance2=distance(lca,n2);

    return distance1+distance2;

   
}




int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    cout<<min_distance(root,4,6);
    return 0;
}
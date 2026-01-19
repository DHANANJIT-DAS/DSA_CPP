#include<iostream>
#include<vector>
#include<map>
#include<string>
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

string find_duplicate_subtree(Node* root,vector<Node*>&result,map<string,int>&M){
    if(root==NULL){
        return "";
    }

    string left=find_duplicate_subtree(root,result,M);
    string right=find_duplicate_subtree(root,result,M);

    string current=left+","+to_string(root->data)+","+left;
    M[current]++;

    if(M[current]==2){
        result.push_back(root);
    }

    return current;
}

vector<Node*> duplicate_subtree(Node* root){
    vector<Node*>result;
    map<string,int>M;  // (tree string,count)
    find_duplicate_subtree(root,result,M);
    return result;
}

int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    
    return 0;
}
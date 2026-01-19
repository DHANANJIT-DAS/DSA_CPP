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

void print_vector(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool ancestor_vals(Node* root,vector<int>&ancestor,int &val){

    if(root==NULL){
        return false;
    }
    int current=root->data;
    if(current==val){
        ancestor.push_back(current);
        return true;
    }
    if(ancestor_vals(root->left,ancestor,val)){
        ancestor.push_back(current);
        return true;
    }
    if(ancestor_vals(root->right,ancestor,val)){
        ancestor.push_back(current);
        return true;
    }
    return false;
}

vector<int> find_ancestor(Node* root,int val){

    vector<int>ancestor;
    ancestor_vals(root,ancestor,val);
    return ancestor;
}

int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    vector<int>ancestor=find_ancestor(root,7);
    print_vector(ancestor);
    
    return 0;
}
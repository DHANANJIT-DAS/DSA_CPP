#include<iostream>
#include<vector>
#include<queue>
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


int transform(Node* root){
    if(root==NULL){
        return 0;
    }

    int oldLeft=transform(root->left);
    int oldRight=transform(root->right);
    int currentval=root->data;
    root->data=oldLeft+oldRight;
    if(root->left){
        root->data=root->data + root->left->data;
    }
    if(root->right){
        root->data=root->data + root->right->data;
    }
    return currentval;
}



void levelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node* current=Q.front();
        Q.pop();
        if(current==NULL){
            cout<<endl;
            if(Q.empty()){
                break;
            }else{
                Q.push(NULL);
            }
        }
        else{
            cout<<current->data<<" ";
            if(current->left){
                Q.push(current->left);
            }
            if(current->right){
                Q.push(current->right);
            }
        }
    }
}


int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    levelOrder(root);
    cout<<endl;
    transform(root);
    levelOrder(root);
    
    return 0;
}
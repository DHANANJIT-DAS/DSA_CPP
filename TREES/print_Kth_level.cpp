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



void print_Kth_level(Node* root,int k){
    if(root==NULL){
        return;
    }
    int count=1;
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        Node* current=Q.front();
        Q.pop();
        if(current==NULL){
            count++;
            if(!Q.empty()){
                Q.push(NULL);
            }
            else{
                break;
            }
            if(count>k){
                return;
            }
            
        }
        else{
            if(count==k){
                cout<<current->data<<" ";
            }
            if(current->left){
                Q.push(current->left);
            }
            if(current->right){
                Q.push(current->right);
            }
        }

        
    }


}


void print_Kth_level2(Node* root,int k,int level){
    if(root==NULL){
        return;
    }
    if(level==k){
        cout<<root->data<<" ";
        return;
    }
    print_Kth_level2(root->left,k,level+1);
    print_Kth_level2(root->right,k,level+1);
}



int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
   
    print_Kth_level2(root,2,1);
    return 0;
}
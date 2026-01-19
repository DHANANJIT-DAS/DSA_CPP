#include<iostream>
#include<vector>
#include<queue>
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


void levelorderTreversel(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty()){
        Node* currentNode=Q.front();
        Q.pop();
        
        cout<<currentNode->data<<" ";
        
        if(currentNode->left){
            Q.push(currentNode->left);
        }
        if(currentNode->right){
            Q.push(currentNode->right);
        }
    }

}


   
int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodeData);
    
    levelOrder(root);

    return 0;
}
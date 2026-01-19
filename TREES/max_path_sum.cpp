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


int max_path_sum(Node* root,int &sum){
    if(root==NULL){
        return 0;
    }

    int left=max(0,max_path_sum(root->left,sum));
    int right=max(0,max_path_sum(root->right,sum));

    int current_sum=left+right+root->data;
    if(current_sum>=sum){
        sum=current_sum;
    }
    

    return max(left,right)+root->data;

}

int max_sum(Node* root){
    int sum=INT16_MIN;
    max_path_sum(root,sum);
    return sum;
}

int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodeData);
    
    return 0;
}
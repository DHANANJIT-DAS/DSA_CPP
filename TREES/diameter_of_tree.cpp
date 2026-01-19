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

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    return max(leftHeight,rightHeight)+1;
}



int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int currentDia=height(root->left)+height(root->right)+1;
    int leftDia=diameter(root->left);
    int rightDia=diameter(root->right);

    return max(currentDia,max(leftDia,rightDia));
}


pair<int,int> Diameter(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int,int>leftInfo=Diameter(root->left);//(LD,LH)
    pair<int,int>rightInfo=Diameter(root->right);//(RD,RH)
    int currentDia=leftInfo.second+rightInfo.second+1;
    int currentHeight=max(leftInfo.second,rightInfo.second)+1;
    return make_pair(max(currentDia,max(leftInfo.first,rightInfo.first)),currentHeight);
}


int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    cout<<Diameter(root).first;
    
    return 0;
}
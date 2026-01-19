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




void inorder(Node* root,vector<int>&BST){
    if(root==NULL){
        return;
    }
    inorder(root->left,BST);
    BST.push_back(root->data);
    inorder(root->right,BST);
}

vector<int> merge(vector<int>&BST1,vector<int>&BST2){
    vector<int>mergeBST;

    int i=0;
    int j=0;
    while(i<BST1.size() && j<BST2.size()){
        if(BST1[i]<=BST2[j]){
            mergeBST.push_back(BST1[i]);
            i++;
        }
        else{
            mergeBST.push_back(BST2[j]);
            j++;
        }
    }
    while(i<BST1.size()){
        mergeBST.push_back(BST1[i]);
        i++;
    }
    while(j<BST2.size()){
        mergeBST.push_back(BST2[j]);
        j++;
    }
    return mergeBST;
}

Node* build_balanced_BST(vector<int>&arr,int strt,int end ){
    if(strt>end){
        return NULL;
    }

    int mid=(strt+end)/2;
    Node* newNode=new Node(arr[mid]);
    newNode->left=build_balanced_BST(arr,strt,mid-1);
    newNode->right=build_balanced_BST(arr,mid+1,end);
    return newNode;

}

Node* merge_2_BST(Node* root1,Node* root2){
    vector<int>BST1;
    inorder(root1,BST1);
    vector<int>BST2;
    inorder(root2,BST2);

    vector<int> mergeBST=merge(BST1,BST2);

    return build_balanced_BST(mergeBST,0,mergeBST.size()-1);
}



void inorderTreversel(Node* root){
    if(root==NULL){
        return;
    }
    inorderTreversel(root->left);
    cout<<root->data<<" ";
    inorderTreversel(root->right);
}
   
int main(){

    Node*  root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(4);

    Node* root2=new Node(9);
    root2->left=new Node(3);
    root2->right=new Node(12);

    inorderTreversel(root1);
    cout<<endl;
    inorderTreversel(root2);
    cout<<endl;

    Node* root=merge_2_BST(root1,root2);

    inorderTreversel(root);


    
    
    return 0;
}

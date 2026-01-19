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


bool search(Node* root,int root2_data,int target){
    if(root==NULL){
        return false;
    }

    while(root !=NULL){
        if(root->data + root2_data==target){
            return true;
        }
        else if(target-root2_data > root->data){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return false;
    

}


bool is_Exist_Pair(Node* root1,Node* root2,int target){
    if(root2==NULL){
        return false;
    }

    return search(root1,root2->data ,target) || is_Exist_Pair(root1,root2->left,target) || is_Exist_Pair(root1,root2->right,target);
}


   
int main(){

    Node* root1=new Node(5);
    root1->left=new Node(3);
    root1->right=new Node(7);
    root1->left->left=new Node(2);
    root1->left->right=new Node(4);
    root1->right->left=new Node(6);
    root1->right->right=new Node(8);


    Node* root2=new Node(10);
    root2->left=new Node(6);
    root2->right=new Node(15);
    root2->left->left=new Node(3);
    root2->left->right=new Node(8);
    root2->right->left=new Node(11);
    root2->right->right=new Node(18);

    cout<<is_Exist_Pair(root1,root2,12);

    
    return 0;
}
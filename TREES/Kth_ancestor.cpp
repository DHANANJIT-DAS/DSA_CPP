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

int find_kth_ancestor(Node* root,int &k,int &val, int &kthAncestor){
    if(root==NULL){
        return -1;
    }
    if(root->data==val){
        if(k==0){
            kthAncestor=root->data;
        }
        return 0;
    }
    int left=find_kth_ancestor(root->left,k,val,kthAncestor);
    
    int right=find_kth_ancestor(root->right,k,val,kthAncestor);
    

    

    if(right==-1 && left==-1){
        return -1;
    }
    int order_of_ancestor= left==-1 ? right+1:left+1;
    if(order_of_ancestor==k){
        kthAncestor=root->data;
    }
    return order_of_ancestor;


}

int Kth_ancestor(Node* root,int k,int val){
    int kthAncestor=INT32_MIN;
    find_kth_ancestor(root,k,val,kthAncestor);
    return kthAncestor;
}




int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodeData);
    cout<<Kth_ancestor(root,2,5);

    

}
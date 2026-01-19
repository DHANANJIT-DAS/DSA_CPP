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




int find_width(Node* root){
    queue<pair<Node*,int>>Q;   // (node,node idx)

    int width=0;
    Q.push(make_pair(root,0));

    while(!Q.empty()){
        
        int strt_idx=Q.front().second;
        int end_idx=Q.back().second;
        width=max(width,end_idx-strt_idx+1);
        int Qsize=Q.size();
        for(int i=1;i<Qsize;i++){
            pair<Node*,int>current=Q.front();
            Q.pop();
            if(current.first->left){
                Q.push(make_pair(current.first->left,current.second*2+1));
            }
            if(current.first->right){
                Q.push(make_pair(current.first->right,current.second*2+2));
            }
        }
    }
    return width;

}
int main(){
    vector<int>nodeData={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    cout<<find_width(root);
    return 0;
}
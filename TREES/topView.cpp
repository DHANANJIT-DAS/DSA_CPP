#include<iostream>
#include<vector>
#include<map>
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


map<int,int>  horizontal_distance(Node* root){
    map<int,int>M; // (horizontal distance,node->data)

    if(root==NULL){
        return M;
    }
    queue<pair<Node*,int>>Q; // (node,horizontal distance)
    Q.push(make_pair(root,0));

    while(!Q.empty()){
        pair<Node*,int> current=Q.front();
        Q.pop();

        if(M.count(current.second)==0){
          M[current.second]=current.first->data;
        }


        if(current.first->left){
            Q.push(make_pair(current.first->left,current.second-1));
        }
        if(current.first->right){
            Q.push(make_pair(current.first->right,current.second+1));
        }
    }

    return M;

}

void topView(Node* root){
    map<int,int>M=horizontal_distance(root);
    for(pair<int,int> itr:M){
        cout<<itr.first<<":"<<itr.second<<endl;
    }
}

int main(){
    vector<int>nodeData={1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};
    Node* root=buildTree(nodeData);
    topView(root);
    
   
    return 0;
}
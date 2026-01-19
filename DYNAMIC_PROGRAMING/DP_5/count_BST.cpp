#include<iostream>
#include<vector>
using namespace std;



int countBST(int n){

    if(n==1 || n==0){
        return 1;
    }

    int ans=0;

    for(int i=0;i<n;i++){
        ans=ans+countBST(i)*countBST(n-i-1);
    }
    return ans;


}

int main(){

    cout<<countBST(4);

    return 0;
}



/*

lets say we have n nodes, and the node values are =[1,2,3,4,5,6,7,8]

now we pic one by one element as root node and all left elments as left BST and all right elements as right BST

the possibility of making a BST by taking node 4 =

combination(1,2,3) * combination(5,6,7,8)


like this we traverse all node as root node and add them to get final ans

*/
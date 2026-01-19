#include<iostream>
#include<vector>
using namespace std;



int min_operation(vector<int>&matrixs,int start,int end){

    if(start>=end){
        return 0;
    }

    int ans=INT32_MAX;
    for(int i=start;i<end;i++){

        int currentOps=matrixs[start-1]*matrixs[i]*matrixs[end];

        ans=min(ans,min_operation(matrixs,start,i)+min_operation(matrixs,i+1,end)+currentOps);
    }

    return ans;

}

int main(){
    vector<int>matrixs={1,2,3,4,3};

    cout<<min_operation(matrixs,1,matrixs.size()-1);

    return 0;
}



/*
    [1,2,3,4,3,5,7,8,4,5,6]  given an array of size n.

    we can make n-1  matrix with  i-1 row and  i column.

    find min operation to multiply all matrics .
*/
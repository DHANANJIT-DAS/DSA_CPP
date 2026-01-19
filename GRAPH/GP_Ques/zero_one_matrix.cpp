#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
using namespace std;


class trip{
public:
    int x;
    int y;
    int d;
    trip(int x,int y,int d){
        this->x=x;
        this->y=y;
        this->d=d;
    }
};



vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

    vector<pair<int,int>>del={{0,1},{1,0},{-1,0},{0,-1}};

    int r=mat.size();
    int c=mat[0].size();

    vector<vector<int>>ans(r,vector<int>(c,0));

    queue<trip>Q;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){

            if(mat[i][j]==0){
                
                Q.push(trip(i,j,0));
                mat[i][j]=-1;
            }

        }
    }

    while(!Q.empty()){

        int c_r=Q.front().x;
        int c_c=Q.front().y;
        int c_d=Q.front().d;

        Q.pop();
        ans[c_r][c_c]=c_d;

        for(int i=0;i<4;i++){

            int n_r=c_r+del[i].first;
            int n_c=c_c+del[i].second;

            if(n_r>=0 && n_r<r && n_c>=0 && n_c<c && mat[n_r][n_c]!=-1){
                
                Q.push(trip(n_r,n_c,c_d+1));
                mat[n_r][n_c]=-1;
            }
        }

    }

    return ans;

        
}



int main(){

    vector<vector<int>>mat={{0,0,0},
                            {0,1,0},
                            {1,1,1}};

    vector<vector<int>>ans=updateMatrix(mat);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}



/*
    Given an 'm x n' binary matrix 'mat', return the distance of the nearest '0' for each cell.
    The distance between two cells sharing a common edge is 1.

    ex-

    Input: mat = [[0,0,0],
                  [0,1,0],
                  [1,1,1]]

    Output:ans= [[0,0,0],
                [0,1,0],
                [1,2,1]]

*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
using namespace std;


void DFS(int i,int j,vector<vector<int>>&grid,vector<pair<int,int>>&shape,int b_r,int b_c){

    int r=grid.size();
    int c=grid[0].size();
    vector<int>dx={1,0,-1,0};
    vector<int>dy={0,1,0,-1};


    grid[i][j]=0;
    shape.emplace_back(i-b_r,j-b_c);

    for(int k=0;k<4;k++){
        int n_r=i+dx[k];
        int n_c=j+dy[k];

        if(n_r>=0 && n_r<r && n_c>=0 && n_c<c && grid[n_r][n_c]==1){
            DFS(n_r,n_c,grid,shape,b_r,b_c);
        }
    }
}

int no_of_distinct_islands(vector<vector<int>>& grid){

    int r=grid.size();
    int c=grid[0].size();

    set<vector<pair<int,int>>>S;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){

                vector<pair<int,int>>shape;
                DFS(i,j,grid,shape,i,j);
                S.insert(shape);

            }
        }
    }

    return S.size();

}

int main(){
    vector<vector<int>>grid={{1,1,0,1,1},
                             {1,0,0,0,0},
                             {0,0,0,0,1},
                             {1,1,0,1,1}};



    cout<<no_of_distinct_islands(grid);
    return 0;
}


/*
    Given a binary matrix 'grid' of m*n. grid[i][j]=1 represents land and grid[i][j]=0 represents water.
    Two lands are connected if their sides are connected.
    Return no of distinct islands. Two islands are disconnected if their shape are not same.

    Ex-

    Input: Grid= [[1,1,0,1,1],
                  [1,0,0,0,0],
                  [0,0,0,0,1],
                  [1,1,0,1,1]]

    Output : ans= 3
*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;


int shortestPath(vector<vector<int>> &grid, pair<int, int> src,pair<int, int> dest) {
        
    if(src.first==dest.first && src.second==dest.second){
        return 0;
    }

    int r=grid.size();
    int c=grid[0].size();
        
    vector<int>dx={1,0,-1,0};
    vector<int>dy={0,1,0,-1};

    queue< pair< pair<int,int>,int> >Q;

    Q.push({{src.first,src.second},0});
    grid[src.first][src.second]=0;

    while(!Q.empty()){

        int i=Q.front().first.first;
        int j=Q.front().first.second;
        int d=Q.front().second;
        Q.pop();

        for(int k=0;k<4;k++){
            int n_r=i+dx[k];
            int n_c=j+dy[k];

            if(n_r>=0 && n_r<r && n_c>=0 && n_c<c && grid[n_r][n_c]==1){
                Q.push({{n_r,n_c},d+1});
                grid[n_r][n_c]=0;

                if(n_r==dest.first && n_c==dest.second){
                    return d+1;
                }
            }
        }

    }

    return -1;
        
}

int main(){
    return 0;
}



/*
    Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between 
    a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

    If the path is not possible between source cell and destination cell, then return -1.

    Ex--

    Input:  grid[][] = {{1, 1, 1, 1},
                        {1, 1, 0, 1},
                        {1, 1, 1, 1},
                        {1, 1, 0, 0},
                        {1, 0, 0, 1}}
                        
            source = {0, 1}
            destination = {2, 2}
            Output: 3

*/
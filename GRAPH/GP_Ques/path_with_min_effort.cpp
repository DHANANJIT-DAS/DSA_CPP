#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;



int minCostPath(vector<vector<int>>& mat) {

    int r=mat.size();
    int c=mat[0].size();

    vector<vector<int>>dist(r,vector<int>(c,1e9));
    dist[0][0]=0;

    vector<int>dx={1,0,-1,0};
    vector<int>dy={0,1,0,-1};

    set< pair<int,pair<int,int>> >S;
    S.insert({0,{0,0}});

    while(!S.empty()){

        auto it=S.begin();
        int c_d=it->first;
        int c_r=it->second.first;
        int c_c=it->second.second;
        S.erase(it);

        if(c_r==r-1 && c_c==c-1){
            return c_d;
        }

        for(int i=0;i<4;i++){

            int n_r=c_r+dx[i];
            int n_c=c_c+dy[i];

            if(n_r>=0 && n_r<r && n_c>=0 && n_c<c ){

                int d=abs(mat[n_r][n_c]-mat[c_r][c_c]);

                if(max(c_d,d) <dist[n_r][n_c]){

                    if(dist[n_r][n_c]!=1e9){
                        S.erase({dist[n_r][n_c],{n_r,n_c}});
                    }

                    dist[n_r][n_c]=max(d,c_d);
                    S.insert({dist[n_r][n_c],{n_r,n_c}});
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
    You are given a 2D array mat[][], of size n*m. Your task is to find the minimum possible path cost from 
    the top-left cell (0, 0) to the bottom-right cell (n-1, m-1) by moving up, down, left, or right between adjacent cells.

    Note: The cost of a path is defined as the maximum absolute difference between the values of any two consecutive 
    cells along that path.


    Ex--

    Input: mat[][] = [[7, 2, 6, 5],
                      [3, 1, 10, 8]]
           Output: 4

           Explanation: The route of [7, 3, 1, 2, 6, 5, 8] has a minimum value of maximum absolute difference 
           between any two consecutive cells in the route, i.e., 4.

*/
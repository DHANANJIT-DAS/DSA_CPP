#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


void replace(int i,int j,vector<vector<char>>&grid,vector<vector<char>>&ans){

    vector<pair<int,int>>del={{0,1},{1,0},{-1,0},{0,-1}};
    int r=grid.size();
    int c=grid[0].size();

    grid[i][j]='X';
    ans[i][j]='O';

    for(int i=0;i<4;i++){

        int n_r=i+del[i].first;
        int n_c=j+del[i].second;

        if(n_r>=0 && n_r<r && n_c>=0 && n_c<c && grid[n_r][n_c]=='O'){
            replace(n_r,n_c,grid,ans);
        }
    }


}

vector<vector<char>> replace_O_with_X(vector<vector<char>>grid){

    int r=grid.size();
    int c=grid[0].size();

    vector<vector<char>>ans(r,vector<char>(c,'X'));

    vector<pair<int,int>>boundary;

    for(int j=0;j<c;j++){
        if(grid[0][j]=='O'){
            boundary.emplace_back(0,j);
        }
        if(grid[r-1][j]=='O'){
            boundary.emplace_back(r-1,j);
        }
    }
    for(int i=1;i<r-1;i++){
        if(grid[i][0]=='O'){
            boundary.emplace_back(i,0);
        }
        if(grid[i][c-1]=='O'){
            boundary.emplace_back(i,c-1);
        }
    }

    for(int i=0;i<boundary.size();i++){

        int c_r=boundary[i].first;
        int c_c=boundary[i].second;

        if(grid[c_r][c_c]=='O'){
            replace(c_r,c_c,grid,ans);
        }
        
    }

    return ans;
}


int main(){

    vector<vector<char>>grid={{'X','X','X','X','X'},
                              {'X','O','X','X','X'},
                              {'X','O','O','X','O'},
                              {'X','O','X','X','O'},
                              {'X','X','X','X','X'}};

    vector<vector<char>>ans=replace_O_with_X(grid);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}


/*  

    Given an 'm x n' matrix 'grid', all grid[i][j]='X' or 'O'.
    Replace all 'O' or cluster of 'O' which are surrounded by 'X' in all four direction - up,down,left,right.

    Ex--
    Input : grid= [ ['X','X','X','X','X'],
                    ['X','O','X','X','X'],
                    ['X','O','O','X','O'],
                    ['X','O','X','X','O'],
                    ['X','X','X','X','X'] ]

    Output: ans=  [ ['X','X','X','X','X'],
                    ['X','X','X','X','X'],
                    ['X','X','X','X','O'],
                    ['X','X','X','X','O'],
                    ['X','X','X','X','X'] ]

*/
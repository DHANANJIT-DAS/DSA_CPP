#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>maze,int row,int column){

    int m=maze.size();
    int n=maze[0].size();

    if(row<0 || row>=m || column <0 || column>=n){
        return false;
    }
    if(maze[row][column]==0){
        return false;
    }

    return true;

}

void findPath(vector<vector<int>>maze,string ans,int row,int column){

    int m=maze.size();
    int n=maze[0].size();

    


    if(row==m-1 && column==n-1){
        cout<<ans<<endl;
        return;
    }

    maze[row][column]=0;

    if(isSafe(maze,row+1,column)){
        findPath(maze,ans+'D',row+1,column);
    }
    if(isSafe(maze,row-1,column)){
        findPath(maze,ans+'U',row-1,column);
    }
    if(isSafe(maze,row,column+1)){
        findPath(maze,ans+'R',row,column+1);
    }
    if(isSafe(maze,row,column-1)){
        findPath(maze,ans+'L',row,column-1);
    }



}


int main(){
    vector<vector<int>>maze={{1,1,1,1},{1,0,0,0},{1,1,1,1},{1,1,0,1}};
    string ans="";

    if(maze[0][0]==0){
        return 0;
    }


    findPath(maze,ans,0,0);
    return 0;
}
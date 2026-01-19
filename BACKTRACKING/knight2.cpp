#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printBoard(vector<vector<int>>board){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(vector<vector<int>>board,int x,int y){

    int n=board.size();
    return(x>=0 && x<n && y>=0 && y<n && board[x][y]==-1);

}



bool knight(vector<vector<int>>board,int x,int y,int count){

    if(count==64){
        printBoard(board);
        return true;
    }

    vector<int>xMove={2, 1, -1, -2, -2, -1, 1, 2};
    vector<int>yMove={1, 2, 2, 1, -1, -2, -2, -1};

    for(int i=0;i<8;i++){
        int next_x=x+xMove[i];
        int next_y=y+yMove[i];

        if(isSafe(board,next_x,next_y)){
            board[next_x][next_y]=count;
            if(knight(board,next_x,next_y,count+1)){
                return true;
            }
            board[next_x][next_y]=-1;
        }

    }
    return false;
}


int main(){

    vector<vector<int>>board(8,vector<int>(8,-1));

    board[0][0]=0;

    knight(board,0,0,1);

    

    return 0;
}
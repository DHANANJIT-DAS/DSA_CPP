#include<iostream>
#include<vector>
using namespace std;
void printBoard(vector<vector<char>> board){
    int row=board.size();
    
    for(int i=0;i<row;i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----------------"<<endl;

}

bool isSafe(vector<vector<char>>board,int row,int column){
int n=board.size();
    //horizontal safety
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }

    //vertical safety
    for(int i=0;i<row;i++){
        if(board[i][column]=='Q'){
            return false;
        }
    }
    //diagonal left safety

    
    for(int i=row,j=column;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    //diagonal right safety
    for(int i=row,j=column;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;


}

 void nQueen(vector<vector<char>>board,int row){
    
    
    int n=board.size();

    if(row==n){
        printBoard(board);
        
        return;
    }


    for(int j=0;j<n;j++){
        if(isSafe(board,row,j)){
           board[row][j]='Q';
           nQueen(board,row+1);
           board[row][j]='.';
           
        }
    }

 }
    





int main(){
    vector<vector<char>>board;
    int n=4;
    for(int i=0;i<n;i++){
        vector<char>row;
        for(int i=0;i<n;i++){
            row.push_back('.');
        }
        board.push_back(row);
    }
    printBoard(board);

    nQueen(board,0);


    
    return 0;

}
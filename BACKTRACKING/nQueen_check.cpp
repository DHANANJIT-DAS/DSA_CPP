#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>board,int row,int column){
int n=board.size();
    //horizontal safety
    for(int j=column+1;j<n;j++){
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

    
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    //diagonal right safety
    for(int i=row-1,j=column+1;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;


}

bool checkSafe(vector<vector<char>>nQueen,int row){
    int n=nQueen.size();

    if(row==n){
        return true;
    }



    for(int j=0;j<n;j++){
        if(nQueen[row][j]=='Q'){
            if(isSafe(nQueen,row,j)){
                return checkSafe(nQueen,row+1);
            }
            else{
                return false;
            }
        }

    }



}



int main(){

    vector<vector<char>>nQueen={{'.','Q','.','.'},{'.','.','.','Q'},{'Q','.','.','.'},{'.','.','Q','.'}};

   cout<< checkSafe(nQueen,0);

    return 0;
}
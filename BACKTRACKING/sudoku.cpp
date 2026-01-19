#include<iostream>
#include<vector>
using namespace std;

void printSudoku(vector<vector<int>>matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}

bool isSafe(vector<vector<int>>matrix,int row,int column,int digit){

    int n=matrix.size();

    //horizontal safety
    for(int j=0;j<n;j++){
        if(matrix[row][j]==digit){
            return false;
        }
    }
    //ver<tical safety
    for(int i=0;i<n;i++){
        if(matrix[i][column]==digit){
            return false;
        }
    }

    //grid safety
    int strtRow=(row/3)*3;
    int strtColumn=(column/3)*3;
    for(int i=strtRow;i<strtRow+3;i++){
        for(int j=strtColumn;j<strtColumn+3;j++){
            if(matrix[i][j]==digit){
                return false;
            }
        }
    }

    return true;

}

bool sudoku(vector<vector<int>>matrix,int row,int column){

    if(row==9 && column==0){
        printSudoku(matrix);
        return true;
    }

    int nextRow=row;
    int nextColumn=column+1;
    if(nextColumn==9){
        nextRow=row+1;
        nextColumn=0;
    }

    if(matrix[row][column] !=0){
        return sudoku(matrix,nextRow,nextColumn);
    }
    for(int i=1;i<=9;i++){
        if(isSafe(matrix,row,column,i)){
            matrix[row][column]=i;
            if(sudoku(matrix,nextRow,nextColumn)){
                return true;
            }
            matrix[row][column]=0;
        }
    }

    return false;

}
int main(){

    vector<vector<int>>matrix={{0,0,8,0,0,0,0,0,0},
                               {4,9,0,1,5,7,0,0,2},
                               {0,0,3,0,0,4,1,9,0},
                               {1,8,5,0,6,0,0,2,0},
                               {0,0,0,0,2,0,0,6,0},
                               {9,6,0,4,0,5,3,0,0},
                               {0,3,0,0,7,2,0,0,4},
                               {0,4,9,0,3,0,0,5,7},
                               {8,2,7,0,0,9,0,1,3}};
    sudoku(matrix,0,0);

    return 0;
}
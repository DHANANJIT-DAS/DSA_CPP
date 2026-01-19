#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(int i,int j,vector<vector<int>>cell,vector<vector<char>>board){

    if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
        return false;
    }

    for(int k=0;k<cell.size();k++){
        if(cell[k][0]==i && cell[k][1]==j){
            return false;
        }
    }
    return true;

}

bool adjacent(vector<vector<char>>board,string word,string ans,int row,int column,vector<vector<int>>cells){
    
    if(word[0]==board[row][column]){
        cells.push_back({row,column});
        word=word.substr(1,word.length()-1);
        ans=ans+board[row][column];

        if(word.size()==0){

            cout<<ans<<endl;
            return true;
        }


        if(isSafe(row+1,column,cells,board)){
           if(adjacent(board,word,ans,row+1,column,cells)){return true;}
        }
        if(isSafe(row-1,column,cells,board)){
           if(adjacent(board,word,ans,row-1,column,cells)){return true;}
        }
        if(isSafe(row,column+1,cells,board)){
           if(adjacent(board,word,ans,row,column+1,cells)){return true;}
        }
        if(isSafe(row,column-1,cells,board)){
           if(adjacent(board,word,ans,row,column-1,cells)){return true;}
        }

    }
    return false;

}

bool wordSearch(vector<vector<char>>board,string word,string ans,int row,int column){

    int nextRow=row;
    int nextColumn=column+1;
    if(nextColumn==board[row].size()){
        nextRow=row+1;
        nextColumn=0;
    }

    if(row==board.size() && column==0){
        return false;
    }


    if(word[0]==board[row][column]){

        vector<vector<int>>cells;
        vector<int>cell1={row,column};
        cells.push_back(cell1);

       ans=ans+board[row][column];

       string copyword=word;

       word=word.substr(1,word.size()-1);
       if(word.size()==0){
        cout<<ans<<endl;
        return true;
       }
       
       if(isSafe(row+1,column,cells,board)){
        if(adjacent(board,word,ans,row+1,column,cells)){
            return true;
        }
       }
       if(isSafe(row-1,column,cells,board)){
        if(adjacent(board,word,ans,row-1,column,cells)){
            return true;
        }
       }
       if(isSafe(row,column-1,cells,board)){
        if(adjacent(board,word,ans,row,column-1,cells)){
            return true;
        }
       }
       if(isSafe(row,column+1,cells,board)){
        if(adjacent(board,word,ans,row,column+1,cells)){
            return true;
        }
       }

       ans.pop_back();
       word=copyword;
       cells.pop_back();




    }

     return wordSearch(board,word,ans,nextRow,nextColumn);

}


int main(){
    vector<vector<char>>board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="ABCESEEDASFCS";
    string ans="";
    cout<<wordSearch(board,word,ans,0,0);
    return 0;
}
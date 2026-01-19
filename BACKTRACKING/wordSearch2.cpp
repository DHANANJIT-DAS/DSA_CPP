#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool adjacentMatch(vector<vector<char>>&board,string word,string ans,int row,int column){

    if(word.length()==0){
        cout<<ans<<endl;
        return true;

    }

    if(row<0 || row>=board.size() || column<0 || column>=board[0].size()){
        return false;
    }
    if(board[row][column]=='#'){
        return false;
    }
    

    if(word[0]==board[row][column]){
        char temp=board[row][column];
        ans=ans+temp;
        board[row][column]='#';
        string subword=word;
        word=word.substr(1,word.length()-1);
        if(adjacentMatch(board,word,ans,row+1,column)){
            return true;
        }
        if(adjacentMatch(board,word,ans,row-1,column)){
            return true;
        }
        if(adjacentMatch(board,word,ans,row,column+1)){
            return true;
        }
        if(adjacentMatch(board,word,ans,row,column-1)){
            return true;
        }

        ans.pop_back();
        board[row][column]=temp;
        word=subword;

    }
    return false;

}

bool wordSearch(vector<vector<char>>&board,string word,string ans,int row,int column){

    int nextRow=row;
    int nextColumn=column+1;
    if(nextColumn==board[row].size()){
        nextRow=row+1;
        nextColumn=0;
    }

    if(row==board.size() && column==0){
        return false;
    }

    if(adjacentMatch(board,word,ans,row,column)){
        return true;
    }




    return wordSearch(board,word,ans,nextRow,nextColumn);

}



int main(){

    vector<vector<char>>board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="EEDA";
    string ans="";

    cout<<wordSearch(board,word,ans,0,0);
    return 0;
}

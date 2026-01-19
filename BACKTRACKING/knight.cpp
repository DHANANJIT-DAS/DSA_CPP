#include<iostream>
#include<vector>

using namespace std;

void printBoard(int board[][8]){

    int n=8;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}

bool isSafe(int board[][8],int x,int y){
    int N=8;
   return(x>=0 && x<N && y>=0 && y<N && board[x][y]==-1);
}




bool knight(int board[][8],int x,int y,int count,int xMove[],int yMove[]){

     
    if(count==64){
        
        return true;
    }

    

    for(int i=0;i<8;i++){
        int next_x=x+xMove[i];
        int next_y=y+yMove[i];

        if(isSafe(board,next_x,next_y)){
            board[next_x][next_y]=count;
            
            if(knight(board,next_x,next_y,count+1,xMove,yMove)){
                return true;
            }
            else{
               board[next_x][next_y]=-1;
            }
            
        }
    }

    
    return false;

    

}


int main(){

    int board[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=-1;
        }
    }

    int xMove[8]={2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8]={1, 2, 2, 1, -1, -2, -2, -1};

    board[0][0]=0;

    knight(board,0,0,1,xMove,yMove);
        
    

    printBoard(board);

    return 0;
}
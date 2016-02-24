/* Project 1: Knight's Tour */

#include <iostream>
#include <cstdlib>
using namespace std;


class KnightsTour{        //command line args:
  int size;               // if 1: <size>
  int LASTMOVE;           // if 2: <x> <Y>
  int** board;            // if 3: <size> <x> <y>

public:
  void setSize(int s){
    size = s;
  }
  
  int** make2dArray(int size1, int size2){
  	int ** ar = new int*[size1];
  	for (int i=0; i<size1; i++){
  	ar[i] = new int[size2];
  
  	}
  	return ar;
  }
  
  void makeBoard(){
    	board = make2dArray(size,size);
  	LASTMOVE = size * size;
  }
  
  void printBoard(){
  	for(int i = 0; i < size;i++){
  		for(int j = 0; j < size;j++){
  			cout<<" "<<(board[i][j]<10 ? " ":"" )<< board[i][j];
  		}
      cout<<"\n";
    }
  }
  
  bool validMove(int x, int y){
  	if(x < size && y < size && x >= 0 && y >= 0){
  		if(board[x][y] == 0){
  		return true;
  		}
  	}
  	return false;
  }
  
  int** validMoves(int x,int y){
  	int** moves = make2dArray(8,2);
  	for(int i = 0; i<8;i++){
  		for(int j = 0; j<2;j++){
  		moves[i][j] =-1;
  		}
  	}
  
  	int count=0;
  	if(validMove(x+2,y+1)){
  		moves[count][0] = x+2;
  		moves[count++][1] =y+1;
  	}
  	if(validMove(x+1,y+2)){
  		moves[count][0] = x+1;
  		moves[count++][1] =y+2;
      }
  	if(validMove(x-1,y+2)){
  		moves[count][0] = x-1;
  		moves[count++][1] =y+2;
      }
  	if(validMove(x-2,y+1)){
  		moves[count][0] = x-2;
  		moves[count++][1] =y+1;
      }
  	if(validMove(x-2,y-1)){
  		moves[count][0] = x-2;
  		moves[count++][1] =y-1;
  	}
  	if(validMove(x-1,y-2)){
  		moves[count][0] = x-1;
  		moves[count++][1] =y-2;
  	}
  	if(validMove(x+1,y-2)){
  		moves[count][0] = x+1;
  		moves[count++][1] =y-2;
  	}
  	if(validMove(x+2,y-1)){
  		moves[count][0] = x+2;
  		moves[count][1] =y-1;
  	}
  
  	return moves;
  }
  
  int nextMovesCount(int x, int y){
  	int count = 0;
  	if(validMove(x+2,y+1)){
            count++;
          }
        if(validMove(x+1,y+2)){
            count++;
          }
        if(validMove(x-1,y+2)){
      	  count++;
          }
        if(validMove(x-2,y+1)){
      	  count++;
          }
        if(validMove(x-2,y-1)){
      	  count++;
        }
        if(validMove(x-1,y-2)){
      	  count++;
        }
        if(validMove(x+1,y-2)){
      	  count++;
        }
        if(validMove(x+2,y-1)){
      	  count++;
        }
        return count;
  }
  
  int** processArrayForWarnsdorf(int** validMovesArray){
  	int** moves2 = make2dArray(8,2);
  	for(int i = 0; i < 8;i++){
  		for(int j = 0; j < 2;j++){
  			moves2[i][j] =-1;
  		}
  	}
  	int cnt;
  
  	for(int i = 0; i<8;i++){
  		cnt = 0;
  		int x = validMovesArray[i][0];
  		int y = validMovesArray[i][1];
  		cnt = nextMovesCount(x,y);
  		if(moves2[cnt][0] == -1){
  			moves2[cnt][0] = x;
  			moves2[cnt][1] = y;
  		}
  		else if((++cnt <8) && moves2[cnt][0] == -1){
  			moves2[cnt][0] = x;
  			moves2[cnt][1] = y;
  		}
  		else if((++cnt <8) && moves2[cnt][0] == -1){
  			moves2[cnt][0] = x;
  			moves2[cnt][1] = y;
  		}
  		else if((cnt-=3) > 0 && moves2[cnt][0] == -1){
  			moves2[cnt][0] = x;
  			moves2[cnt][1] = y;
  		}
  		else if((--cnt > 0) && moves2[cnt][0] == -1){
  			moves2[cnt][0] = x;
  			moves2[cnt][1] = y;
  		}
  	}
  	return moves2;
  }
  
  int** getNextMoves(int x, int y){
    return processArrayForWarnsdorf(validMoves(x,y));
  }
  
  bool kTour(int x, int y, int movNum){ // change to read nextmoves in backwards order
      if (movNum > LASTMOVE){
        return true;
      }
  
      int** nextMoves = getNextMoves(x,y);
      int cx,cy;
      for (int i = 0;i<8;i++) {
        cx = nextMoves[i][0];
        cy = nextMoves[i][1];
        if(cx==-1 || cy==-1){
          continue;
        }
        board[cx][cy] = movNum;
        if (kTour(cx, cy, movNum + 1)){
            return true;
  	}
        board[cx][cy] = 0;
      }
  
        return false;
    }
  
  void kTour(int startingX,int startingY){
  	makeBoard();
  	board[startingX][startingY] = 1;
  	if(!kTour(startingX,startingY,2)){
  		cout<<"No Solution :(";
      }
      else{
  		printBoard();
      }
    }
};
int main(int argc, char* argv[]){
  
	KnightsTour k;
	int startX = 0, startY = 0;
	int boardSize = 8;
	
	if(argc ==2){
	  boardSize = atoi(argv[1]);
	}
	else if(argc == 3){
	  startX = atoi(argv[1]);
	  startY = atoi(argv[2]);
	}
	else if(argc == 4){
	  boardSize = atoi(argv[1]);
	  startX = atoi(argv[2]);
	  startY = atoi(argv[3]);
	}
	k.setSize(boardSize);
	k.kTour(startX,startY);
	
	
	return 0;
}



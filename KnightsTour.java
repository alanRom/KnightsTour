/* Project 1: Knight's Tour */
public class KnightsTour{
  public static void main(String[] args){
    int startX =0,startY=0;
    size = 8;
    if(args.length ==1){                  //command line args:
      size = Integer.parseInt(args[0]);   // if 1: <size>
    }                                     // if 2: <x> <y>
    else if(args.length == 2){            // if 3: <size> <x> <y>
      size = 8;
      startX= Integer.parseInt(args[0]);
      startY = Integer.parseInt(args[1]);
    }
    else if(args.length == 3){
      size = Integer.parseInt(args[0]);
      startX= Integer.parseInt(args[1]);
      startY = Integer.parseInt(args[2]);
    }
    
    kTour(startX,startY);
  
  }
  
  public static void kTour(int cx, int cy){
    makeBoard(size);
    board[cx][cy]=1;
    if(!kTour(cx,cy,2)){
      System.out.println("No Solution");
    }
    else{
      printBoard();
    }
  }
  
  public static boolean kTour(int x, int y, int movNum){
    if (movNum > LASTMOVE){
      return true;
    }
    
    int[][] nextMoves = getNextMoves(x,y);

    for (int[] mv : nextMoves) {
      x = mv[0];
      y = mv[1];
      if(x==-1 || y==-1){
        continue;
      }
      board[x][y] = movNum;
      if (kTour(x, y, movNum + 1))
          return true;
      board[x][y] = 0;
    }

      return false;
  }
  
  public static void makeBoard(int n){
    board=new int[n][n];
    LASTMOVE = n*n;
  }

  public static void printBoard(){
      for(int[] i:board){
        for(int j: i){
          System.out.print(" " +((j<10)? " "+j:j));
        }
        System.out.println("");
      }
  }
  
  public static boolean validMove(int x,int y){
      if(x<board.length && y < board.length && x>=0 && y>=0 ){
        if(board[x][y] == 0){
          return true;
        }
      }
      return false;
  }
  public static int[][] getNextMoves(int x,int y){
	  return processArrayForWarnsdorf(validMoves(x,y));
  }
  public static int nextMovesCount(int x, int y){
      int count=0;
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
  
  public static int[][] processArrayForWarnsdorf(int[][] validMovesArray){
	  int [][] moves2 = new int[8][2];
	  for(int i = 0; i<moves2.length;i++){
	        for(int j = 0; j<moves2[0].length;j++){
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
  
  public static int[][] validMoves(int x, int y){
      int[][] moves = new int[8][2];
      for(int i = 0; i<moves.length;i++){
        for(int j = 0; j<moves[0].length;j++){
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
          moves[count++][1] =y-1;
      }
      return moves;
    }
  
  
  
  private static int[][] board;
  private static int LASTMOVE;
  private static int size;
}

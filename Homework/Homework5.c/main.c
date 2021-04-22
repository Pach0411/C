Agregar tambien el archvo .h para que funcione
 Primero debes de poner la fila y despues la columna (separados de un espacio) like : 3 4
 El tamaño del board ya esta definido y es de 10x10 
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

int main() {
  
    int gameover = 0; // used to check if the game is over or not
  
    char uncovered_board[dimension][dimension];
                                     
    char current_board[dimension][dimension]; 
                                   
    int totalmoves; // stores the total moves left for the user before they win.

    int i,j;
    int x,y;

    int totalbombs[NUMBOMBS][2]; // stores (x,y) coordinates of all bombs.
  
    srand(time(0)); // Seed the random number generator.

    // Initialize the current board.
    for (i=0;i<dimension;i++) {
        for (j=0;j<dimension;j++) {
            current_board[i][j] = '_';
            uncovered_board[i][j] = '_';
        }
    }

    // Randomly choose where the bombs will go.
    getbombs(totalbombs);
  
    // Place the bombs onto the board.
    for (i=0;i<NUMBOMBS;i++) 
        uncovered_board[totalbombs[i][0]][totalbombs[i][1]]='*';
  
    totalmoves = dimension*dimension - NUMBOMBS;
 //Continue
    while (!gameover) {

        printf("Actual board : \n");
        printboard(current_board);
        getmove(&x,&y);
        printf(" %c\n", current_board[7][1]);

        gameover = movement(current_board,uncovered_board,totalbombs,x,y,&totalmoves);

        if ((!gameover) && (totalmoves==0)) {
            printf(" You win!!\n");
            gameover = 1;
        }
    }
    return 0;
}
void getmove(int *x,int *y) {

    // Read in move.
    printf("To enter a move type row / space / colum like: 2 3\n");
    printf ("This is a row ||,  and this is a colum ==\n");
    printf("Enter your move, (row column) -> ");
    scanf("%d%d", x, y);
  
    while (!valid(*x,*y)) {
        printf(" Those aren't valid coordinates. Please try again.\n");
        printf("Enter your move, (row column) -> ");
        scanf("%d%d", x, y);
    }
}
void printboard(char board[][dimension]) {

    int i,j;

    // Print out dimension labels.
    printf("    ");
    for (i=0;i<dimension;i++)
        printf("%d ", i);
    printf("\n\n");

    //  actual board.
    for (i=0;i<dimension;i++) {
    
        printf("%d   ", i);
        for (j=0;j<dimension;j++)
            printf("%c ",board[i][j]); 
        printf("\n");
    }
}
int movement(char board[][dimension], char realboard[][dimension],
            int totalbombs[][2], int row, int column, int *totalmoves) {

  int i, j, num;
    if (realboard[row][column]=='*') {
    
        board[row][column]='*';
        for (i=0;i<NUMBOMBS;i++) 
            board[totalbombs[i][0]][totalbombs[i][1]]='*';
    
        printboard(board);
        printf("You lose!\n");
        return 1;
    }
    // square already chosen.
    else if (board[row][column]!='_') {
    
        printf("That square as already been cleared.\n");
        return 0;
    }
    // Execute a normal non-losing move.
    else {
 
        // Calculate the number of adjacent bombs, and place this number on the regular board.
        num = numberbombs(row, column, totalbombs);
        (*totalmoves)--;
        
        board[row][column]=(char)(num+'0');

        if (num == 0) {
   
            for (i=-1;i<2;i++) {
	            for (j=-1;j<2;j++) {
	  
	                if (valid(row+i,column+j) && (board[row+i][column+j]=='_'))
	                    movement(board, realboard, totalbombs, row+i, column+j, totalmoves);
	            }
            }
        }
      return 0;
    }
}
int valid(int row, int column) {
    if (row < 0) return 0;
    
    else if (row >= dimension) return 0;
  
    else if (column < 0) return 0;
  
    else if (column >= dimension) return 0;
    
    else return 1;
}
int numberbombs(int row ,int column ,int totalbombs[][2]) {

int i;
int count = 0;
    for (i=0;i<NUMBOMBS;i++) {

        if ((abs(row-totalbombs[i][0])<=1+TOLERANCE) && (abs(column-totalbombs[i][1])<=1+TOLERANCE)) {
            count++; 
        }  
    }
    return count;
}
void getbombs(int bomblist[][2]) {
  
int i;
int help;
int curbombs[dimension*dimension];
  
    for (i=0; i<dimension*dimension; i++)
        curbombs[i] = 0;
    i = 0;
    while(i<NUMBOMBS) { // Continue until all random bombs have been created.
    
        help = rand()%(dimension*dimension);

        if (curbombs[help]==0) {// Only add the bomb if it is not a duplicate.
      
            bomblist[i][0] = help/dimension;
            bomblist[i][1] = help%dimension;
            i++;
            curbombs[help] = 1;
        }
    }
}

const int dimension= 10; //  length of the board ( 10 x 10 in this case.) 
const int NUMBOMBS = 10; // number of bombs
const double TOLERANCE = 0.001; 
 
void printboard(char[][dimension]);
int numberbombs(int,int,int[][2]);
int movement(char[][dimension], char[][dimension], int[][2], int, int, int*);
void getbombs(int[][2]);
void getmove(int*, int*);
int valid(int,int);

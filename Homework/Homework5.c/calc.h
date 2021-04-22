#define forloop(i, x) for(i = 0; i != x; i++)
#define BOMB -1  //set bombs//
#define CONTL 10  //number of rows and columns (counter line)//

#define LOST 'l' 
#define WON 'O'
#define OK '?'

void bombs(int);
void neighbours(int); 
int open();
void kaboom();
void empty(int, int);
char field(int, int);
void set(int, int, char);


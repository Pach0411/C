#define forloop(i, x) for(i = 0; i != x; i++)
#define BOMB -1  //numero de bombas//
#define CONTL 10  //numero de filas y columnas (linea de contador)//

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


#define MAX 80
typedef struct BinaryTreenode
{
  char* user;
  char* password;
  struct BinaryTreenode* rightchild;
  struct BinaryTreenode* leftchild;
  unsigned int depth;
}


node;
char line[MAX], password[MAX], user[MAX];
int getout();
void get (char l[MAX],char p[MAX],char u[MAX]);
node* insert(char* u, char* p, node* pos, int d);
void delete(node* position, char* a, char* p, int* n);
void alpha(node* position);

/*Este programa fue creado con ayuda del repo de la profe que es https://github.com/satuelisa/C/tree/main/Ch6, Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988) y tambien
con ayuda de mis compañeros de clase como rulgamer07 y Victor Villegas*/

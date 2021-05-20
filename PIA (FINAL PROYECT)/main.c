#include<stdio.h>
#include<stdlib.h>

struct turno
{
    char pieza;
    //color de la ficha /0 vacio / 1 Negro / 2 Blanco
}t[8][8];

struct jugadores
{
    char nombres[35];
    int puntaje;
}J[2];
int MovimientoBlancas(int x,int y,int direccion,struct turno t[8][8]);
int MovimientoNegras(int x,int y,int direccion,struct turno t[8][8]);
void fichas(struct turno t[8][8]);
void imprimetablero(struct turno t[8][8]);

int main()
{
    int op,x,y,dir,b;
    //struct color color;
    J[0].puntaje=0;
    J[1].puntaje=0;
    do
    {
    printf("\n 1.Play \n 2.Credits \n 3.Rules \n 4.Marker \n 5.Exit \n Select an option Player: ");
    scanf("%i",&op);printf("\n");

    switch(op)
    {
    case 1:
         {
           int i,j,band;

           printf("\nSet the name of the Player 1 <Whites> : ");fflush(stdin);gets(J[0].nombres);
           printf("\nSet the name of the Player 2 <Blacks> : ");fflush(stdin);gets(J[1].nombres);
           printf("\n________________GAME START__________________\n");
           fichas(t);//imprime tablero con las fichas ordenadas();
           do
           {
             do
             {
               printf("\nIT'S THE TURN OF THE WHITES( %s )",J[0].nombres);
               printf("\nSELECT THE X AXIS: ");scanf("%i",&x);
               printf("\nSELECT THE Y AXIS: ");scanf("%i",&y);
               printf("\nPUT THE DIRECTIONS(LEFT=0)(RIGHT=1): ");scanf("%i",&dir);
               b=MovimientoBlancas(x,y,dir,t);
               band=checaTablero(t);//ver si gano alguien o una ficha se convertira en dama
             }while(b==0);
             if(b==1 && band==0)
             {
              do
              {
               printf("\nIT'S THE TURNO OF THE BLACKS( %s )",J[1].nombres);
               printf("\nSELECT THE X AXIS: ");scanf("%i",&x);
               printf("\nSELECT THE Y AXIS: ");scanf("%i",&y);
               printf("\nPUT THE DIRECTIONS(LEFT=0)(RIGHT=1): ");scanf("%i",&dir);
               b=MovimientoNegras(x,y,dir,t);
               band=checaTablero(t);//ver si gano alguien o una ficha se convertira en dama
              }while(b==0);
             }
             //band=checaTablero(t);
           }while(band==0);
         }
           break;

    case 2:printf("\n CREDITS\n ASSIGMENT: Programacion Estructurada\n TEACHER: Satu Elisa Schaeffer\n STUDENT:Pedro Andres Hinojosa Castaneda\n");
           break;

    case 3:printf("\n RULES \n -Si el jugador tiene una ficha con la oportunidad de comer y no come, en el turno del contrincante se removera la ficha como sancion. \n");
           printf("\n -Al momento de comer tantas fichas como pueda por la diagonal que decide comer. \n");
           printf("\n -Cuando un peon llega al final de la fila del bando contrario este se convertira en dama \n");
           printf("\n -La dama puede moverse libremente unicamente por la diagonal \n");
           printf("\n -Si al final queda 1 sola ficha de cada jugador es empate");
           break;

    case 4:printf("\n______________GAME SCORE LIST_____________\n");
           printf("\nNAME OF THE PLAYER <WHITES> : %s \t %i",J[0].nombres,J[0].puntaje);
           printf("\nNAME OF THE PLAYER <BLACKS>  : %s \t %i\n",J[1].nombres,J[1].puntaje);
           break;

    case 5:printf("\n END OF THE GAME \n");
           getch();
           return 0;
           break;

    }
    }while(op!=5);
getch();
return 0;
}

void imprimetablero(struct turno t[8][8])
{
    int x,y;
    printf("\n\t    ");
    for(x=0;x<8;x++)
        printf("%i   ",x);
   printf("\n\t");
   for(x=0;x<8;x++)
   {
    printf("%i",x);
    for(y=0;y<8;y++)
    {
        printf(" |");
        for(y=0;y<8;y++)
        printf(" %c |",t[x][y]);
    }
    printf("\n\t  -");
    for(y=0;y<8;y++)
        printf("----");
    printf("\n\t");
   }
}
void fichas(struct turno t[8][8])
{
   //struct turno;
   int i,j;
   //Asignacion valores N
   for(i=0;i<3;i++)
    for(j=0;j<8;j++)
   {
       if(i%2==0)
        if(j%2==0)
           t[i][j].pieza=' ';
        else
          t[i][j].pieza='B';
       else //separacion
        if(j%2==0)
           t[i][j].pieza='B';
        else
          t[i][j].pieza=' ';
   }
   //Vaciar los valores de la fila 3 y 4
    for(i=3;i<5;i++)
     for(j=0;j<8;j++)
      t[i][j].pieza=' ';
   //Asignacion valores de B
   for(i=7;i>4;i--)
    for(j=0;j<8;j++)
   {
       if(i%2==0)
        if(j%2==0)
           t[i][j].pieza=' ';
        else
          t[i][j].pieza='W';
       else //separacion
        if(j%2==0)
           t[i][j].pieza='W';
        else
          t[i][j].pieza=' ';
   }
   imprimetablero(t);
}
int checaTablero(struct turno t[8][8])
{
   int band,i,j,x,y,negras=12,blancas=12,a=0,q=0,r=0;
   band=0;
   for(i=0;i<8;i++)//for(j=0;j<8;j++)
    {
        if(t[0][i].pieza=='W')
        {
            t[0][i].pieza='D';
        }
    }
    for(j=0;j<8;j++)
    {
        if(t[7][j].pieza=='B')
        {
            t[7][j].pieza='M';
        }
    }
    imprimetablero(t);
    if(band==0)
    {
        for(i=0;i<8;i++)
  {
      for(j=0;j<8;j++)
      {
          if(t[i][j].pieza=='W')
            blancas-=1;
          if(t[i][j].pieza=='B')
            negras-=1;
      }
  }
  for(i=0;i<8;i++)
  {
      for(j=0;j<8;j++)
      {
          if(t[i][j].pieza==' ')
            a+=1;
          if(t[i][j].pieza=='D' || t[i][j].pieza=='M')
            a-=1;
      }
  }
   for(i=0;i<8;i++)
  {
      for(j=0;j<8;j++)
      {
          if(t[i][j].pieza=='B' || t[i][j].pieza=='M')
            q+=1;
      }
  }
   for(i=0;i<8;i++)
  {
      for(j=0;j<8;j++)
      {
          if(t[i][j].pieza=='W' || t[i][j].pieza=='D')
            r+=1;
      }
  }
    }
  if(blancas==11 && negras==11)
  {
      J[0].puntaje+=1;
      J[1].puntaje+=1;
      band=1;
      printf("\nEND OF THE GAME\nDRAW\n");
  }
  if(a==62)
  {
      J[0].puntaje+=1;
      J[1].puntaje+=1;
      band=1;
      printf("\nEND F THE GAME\nDRAW\n");
  }
  if(q==0)
  {
      printf("\n¡¡WHITES WIN!!\n");
      J[0].puntaje+=1;
      band=1;
  }
  if(r==0)
  {
      printf("\n¡¡BLACKS WIN!!\n");
      J[1].puntaje+=1;
      band=1;
  }
   return band;
}
int MovimientoBlancas(int x,int y,int direccion,struct turno t[8][8])//izquierda 0 y derecha 1
{
  int band=1,j,p,i,a,w,z;

  if(t[y][x].pieza!=' ' && t[y][x].pieza !='B')
  {
  if(t[y][x].pieza=='W')
  {
      if(direccion==1)//derecha
      {
          if(x+1<8 && y-1>-1)
             {
                 if(t[y-1][x+1].pieza==' ')
                 {
                     t[y-1][x+1].pieza='W';
                     t[y][x].pieza=' ';
                 }
                 else
                 if(t[y-1][x+1].pieza=='W' || t[y-1][x+1].pieza=='D')
                 {
                    printf("ILLEGAL MOVEMENT, THERE IS A PIECE ON THE PREVIOUSLY SAID MOVEMENT \n");
                    band=0;
                 }
                 if(t[y-1][x+1].pieza=='B'|| t[y-1][x+1].pieza=='M')
                 {
                     if(t[y-2][x+2].pieza==' ' && x+2<=7 && y-2>=0)
                     {
                      j=x;
                      p=y;
                      a=0;
                      for(i=1;i<8;i++)
                      {
                          x=j+i+a;
                          y=p-i-a;
                          if((t[y][x].pieza=='B'|| t[y][x].pieza=='M') && t[y-1][x+1].pieza==' ' && x+1<8 && y-1>-1)
                          {
                              t[y-1][x+1].pieza='W';
                              t[y+1][x-1].pieza=' ';
                              t[y][x].pieza=' ';
                              a++;
                          }
                          else break;
                      }
                     }
                     else
                     {
                         printf("\nCAN'T BE CAPTURED\n");
                         band=0;
                     }
                 }
             }
             else
             {
               printf("\nILLEGAL MOVEMENT\nTHE PIECE IS LEAVING THE BOARD \n");
               band=0;
             }
      }
      //else
      if(direccion == 0)//izquierda
      {
          if(x-1>-1 && y-1>-1)
             {
                 if(t[y-1][x-1].pieza==' ')
                 {
                     t[y-1][x-1].pieza='W';
                     t[y][x].pieza=' ';
                 }
                 else
                 if(t[y-1][x-1].pieza=='W' || t[y-1][x-1].pieza=='D')//DAMA
                 {
                    printf("ONE PIECE IS INTERRUPTING THE MOVEMENT\n");
                    band=0;
                 }
                 if(t[y-1][x-1].pieza=='B'|| t[y-1][x-1].pieza=='M')
                 {
                     if(t[y-2][x-2].pieza==' ' && y-2>=0  && x-2>=0)
                     {
                      j=x;
                      p=y;
                      a=0;
                      for(i=1;i>-1;i--)
                      {
                          x=j-i-a;
                          y=p-i-a;
                          if((t[y][x].pieza=='B'|| t[y][x].pieza=='M') && t[y-1][x-1].pieza==' ' && x-1>-1 && y-1>-1)
                          {
                              t[y-1][x-1].pieza='W';
                              t[y+1][x+1].pieza=' ';
                              t[y][x].pieza=' ';
                              a--;
                          }
                          else break;
                      }
                     }
                     else
                     {
                         printf("\nCAN'T BE CAPTURED\n");
                         band=0;
                     }
                 }
             }
             else
             {
               printf("\nILLEGAL MOVEMENT\nTHE PIECE IS LEAVING THE BOARD\n");
               band=0;
             }
      }
      if(direccion != 1 && direccion != 0)
      {
          printf("\nINVALID DIRECTION");
          band=0;
      }

  }
  else
  if(t[y][x].pieza=='D')
  {
      int direccion2,hacer;
      printf("\nCHECKER DIRECTION <UP=1><DOWN=0>: ");scanf("%i",&direccion2);
      if(direccion2==1)//mover para arriba
      {
          if(direccion==1)//derecha arriba
          {
              printf("\nSELECT THE CHECKER DIRECTION");
              printf("\nSELECT THE X AXIS: ");scanf("%i",&j);
              printf("\nSELECT THE Y AXIS: ");scanf("%i",&p);
              w=x;
              z=y;
              for(;x<j;x++)
              {
                  //printf("\n%i\t %i",y,x);
                  if(t[y][x].pieza=='B')//si hay un aliado en la diagonal
                  {
                      printf("\nINVALID MOVEMENT\nPIECE OF THE TEAM IS THERE");
                      band=0;
                      break;
                  }
                  if((t[y][x].pieza=='B'&& t[y-1][x+1].pieza=='B') ||  t[y][x].pieza == 'M' || t[y-1][x+1].pieza == 'M')//si hay muchas fichas enemigas que no se pueden comer
                  {
                      printf("\nTHERE ARE A LOT OF ENEMIES PIECES AT THE ROAD");
                      band=0;
                      break;
                  }
                  if((t[y][x].pieza=='B' && t[y-1][x+1].pieza==' ') || (t[y][x].pieza == 'M' && t[y-1][x+1].pieza==' '))//para comer
                  {
                      t[y][x].pieza=' ';
                      //printf("\nEntro");
                  }
                  y--;
              }
              if(band==1)
              {
                    if(t[p][j].pieza==' ')
                      {
                          t[z][w].pieza=' ';
                          t[p][j].pieza='D';
                      }
                      else
                      if(t[p][j].pieza!=' ' && t[p][j].pieza!='D')
                      {
                          printf("\nBUSY COORDINATES\n");
                          band=0;
                      }
              }
          }
          if(direccion==0)//izquierda arriba
          {
              printf("\nIngrese el Movimiento de la Dama");
              printf("\nIngrese el eje x: ");scanf("%i",&j);
              printf("\nIngrese el eje y: ");scanf("%i",&p);
              w=x;
              z=y;
              for(;y>p;y--)
              {
                  //printf("\n%i\t %i",y,x);
                  if(t[y][x].pieza=='B')//si hay un aliado en la diagonal|| t[y][x].pieza == 'M'
                  {
                      printf("\nMovimiento Invalido\nCompañero de Equipo en el Camino");
                      band=0;
                      break;
                  }
                  if((t[y][x].pieza=='B'&& t[y-1][x-1].pieza=='B')||  t[y][x].pieza == 'M' || t[y-1][x-1].pieza == 'M')//si hay muchas fichas enemigas que no se pueden comer|| t[y-1][x-1].pieza == 'M'
                  {
                      printf("\nMuchas Fichas Enemigas en el camino");
                      band=0;
                      break;
                  }
                  if((t[y][x].pieza=='B'&& t[y-1][x-1].pieza==' ' ) ||  (t[y][x].pieza == 'M' && t[y-1][x-1].pieza==' ' ))//para comer|| t[y][x].pieza == 'M'
                  {
                      t[y][x].pieza=' ';
                      //printf("\nEntro");
                  }
                  x--;
              }
              if(band==1)
              {
                    if(t[p][j].pieza==' ')
                      {
                          t[z][w].pieza=' ';
                          t[p][j].pieza='D';
                      }
                      else
                      if(t[p][j].pieza!=' ' && t[p][j].pieza!='D')
                      {
                          printf("\nCoordenadas Ocupadas\n");
                      }
              }
          }
      }
      if(direccion2==0)//mover para abajo
      {
          if(direccion==1)//derecha abajo
          {
             printf("\nIngresa la COORDENADA hacia donde desea moverla\n");
             printf("\nIngrese Eje x: ");scanf("%i",&j);
             printf("\nIngrese Eje y: ");scanf("%i",&p);
             if(p<8 && p>y && j<8 && j>x)
             {
               if(t[p][j].pieza==' ')
               {
                     for(i=1;j-i>=x;i++)
                     {
                         if(t[p-i][j-i].pieza==' ' || t[p-i][j-i].pieza=='D')
                               hacer=1;
                         else
                         {
                           hacer=0;
                           break;
                         }
                     }
                     //COMER FICHA DE DAMA PRUEBA
                     if(hacer==0)
                     {
                     for(i=1;j-i>x;i++)
                    {
                        if((t[p-i][j-i].pieza=='B' || t[p-i][j-i].pieza=='M')  && t[p-i][j-i].pieza!='B')
                        {
                            if(t[p-i-1][j-i-1].pieza==' ' || t[p-i-1][j-i-1].pieza=='D')
                            hacer=2;
                            else
                            {
                                hacer=4;
                                break;
                            }
                        }
                        else
                            hacer=4;
                    }
                    }
                     if(hacer==1)
                   {t[p][j].pieza='D';
                   t[y][x].pieza=' ';}
                   if(hacer==2)//COMER FICHA DE DAMA PRUEBA
                    {
                        t[p][j].pieza='D';
                        for(i=1;j-i>=x;i++)
                            t[p-i][j-i].pieza=' ';
                    }
                    if(hacer==4 || hacer==0)
                    {
                        printf("\nNO SE PUDO MOVER A LA DAMA\nUNA FICHA LO IMPIDIO\n");
                        band=0;
                    }
               }
               else
               if(t[p][j].pieza!=' ')
                 {
                    printf("\nNO SE PUDO MOVER A LA DAMA\nUNA FICHA LO IMPIDIO\n");
                    band=0;
                 }
             }
             else
             {
                 printf("\n\nMOVIMIENTO INVALIDO\nLA DAMA NO PUEDE COLOCARSE EN ESA CASILLA\n");
                 band=0;
             }

          }
          if(direccion==0)//izquierda abajo
          {
              printf("\nIngresa la COORDENADA hacia donde desea moverla\n");
             printf("\nIngrese Eje x: ");scanf("%i",&j);
             printf("\nIngrese Eje y: ");scanf("%i",&p);
             if(p<8 && j>-1 && p>y && j<x)
             {
               if(t[p][j].pieza==' ')
               {
                 for(i=1;j+i<=x;i++)
                 {
                     if(t[p-i][j+i].pieza==' ' || t[p-i][j+i].pieza=='D')
                           hacer=1;
                     else
                     {
                       hacer=0;
                       break;
                     }
                 }
                 //COMER FICHA DE DAMA PRUEBA
                 if(hacer==0)
                 {
                 for(i=1;j+i<x;i++)
                {
                    if((t[p-i][j+i].pieza=='B' || t[p-i][j+i].pieza=='M')  && t[p-i][j+i].pieza!='B')
                    {
                        if(t[p-i-1][j+i+1].pieza==' ' || t[p-i-1][j+i+1].pieza=='D')
                        hacer=2;
                        else
                        {
                            hacer=4;
                            break;
                        }
                    }
                    else
                        hacer=4;
                }
                }
                 if(hacer==1)
               {t[p][j].pieza='D';
               t[y][x].pieza=' ';}
               if(hacer==2)//COMER FICHA DE DAMA PRUEBA
                {
                    t[p][j].pieza='D';
                    for(i=1;j+i<=x;i++)
                        t[p-i][j+i].pieza=' ';
                }
                if(hacer==4 || hacer==0)
                {
                    printf("\n NO SE PUDO MOVER A LA DAMA\nUNA FICHA LO IMPIDIO\n");
                    band=0;
                }
               }
               else
               if(t[p][j].pieza!=' ')
                 {
                    printf("\nNO SE PUDO MOVER A LA DAMA\nUNA FICHA LO IMPIDIO\n");
                    band=0;
                }
             }
             else
             {
                 printf("\n\nMOVIMIENTO INVALIDO\nLA DAMA NO PUDE COLOCARSE EN ESA CASILLA\n");
                 band=0;
             }

          }
      }
  }
  else
      {
          printf("\nCordenada Incorrecta\nFICHA NO ENCONTRADA");
          band=0;
      }
  }
  else
      {
          printf("\nCordenada Incorrecta\nFICHA NO ENCONTRADA");
          band=0;
      }
   //imprimetablero(t);

  return band;
}
int MovimientoNegras(int x,int y,int direccion,struct turno t[8][8])
{
            int band=1,j,p,i,a,w,z;

   if(t[y][x].pieza=='B')
     {
         if(direccion==1)
         {
             if(x+1<8 && y+1<8)
             {
                 if(t[y+1][x+1].pieza==' ')
                 {
                     t[y+1][x+1].pieza='B';
                     t[y][x].pieza=' ';
                 }
                 else
                 if(t[y+1][x+1].pieza=='B' || t[y+1][x+1].pieza=='M')//DAMA
                 {
                    printf("UNA FICHA INTERRUMPIO EL AVANCE\n");
                    band=0;
                 }
                 if(t[y+1][x+1].pieza=='W' || t[y+1][x+1].pieza=='D')
                 {
                     if(t[y+2][x+2].pieza==' ' && x+2<=7 && y+2<=7)
                     {
                      j=x;
                      p=y;
                      a=0;
                      for(i=1;i<8;i++)
                      {
                          x=j+i+a;
                          y=p+i+a;
                          if((t[y][x].pieza=='W' || t[y][x].pieza=='D') && t[y+1][x+1].pieza==' ' && x+1<8 && y+1<8)
                          {
                              t[y+1][x+1].pieza='B';
                              t[y-1][x-1].pieza=' ';
                              t[y][x].pieza=' ';
                              a++;
                          }
                          else
                            break;
                      }
                     }
                     else
                     {
                         printf("\nNO SE PUDO CAPTURAR\n");
                         band=0;
                     }
                 }
             }
             else
             {
               printf("\nMOVIMIENTO INVALIDO\nLA FICHA SE SALE DEL TABLERO\n");
               band=0;
             }
         }
         else   //MOVER A LA IZQUIERDA
         {
            if(direccion==0)
         {
             if(x-1>-1 && y+1<8)
             {
                 if(t[y+1][x-1].pieza==' ')
                 {
                     t[y+1][x-1].pieza='B';
                     t[y][x].pieza=' ';
                 }
                 else
                 if(t[y+1][x-1].pieza=='B' || t[y+1][x-1].pieza=='M')//DAMA
                 {
                    printf("UNA FICHA INTERRUMPIO EL AVANCE\n");
                    band=0;
                 }
                 if(t[y+1][x-1].pieza=='W' || t[y+1][x-1].pieza=='D')
                 {
                     if(t[y+2][x-2].pieza==' ' && y+2<=7 && x-2>=0)
                     {
                      j=x;
                      p=y;
                      a=0;
                      for(i=1;i<8;i++)
                      {
                          x=j-i-a;
                          y=p+i+a;
                          if((t[y][x].pieza=='W' || t[y][x].pieza=='D') && t[y+1][x-1].pieza==' ' && x-1>-1 && y+1<8)
                          {
                              t[y+1][x-1].pieza='B';
                              t[y-1][x+1].pieza=' ';
                              t[y][x].pieza=' ';
                              a++;
                          }
                          else break;
                      }
                     }
                     else
                     {
                         printf("\nNO SE PUDO CAPTURAR\n");
                         band=0;
                     }
                 }
             }
             else
             {
               printf("\nMOVIMIENTO INVALIDO\nLA FICHA SE SALE DEL TABLERO\n");
               band=0;
             }
         }
         else
         {
             printf("\nDIRECCION INCORRECTA\n");
             band=0;
         }
         }
     }
     else if(t[y][x].pieza=='M')//Dama
     {
          int direccion2,hacer;
          printf("\nDireccion de la Dama <arriba=1><abajo=0>: ");scanf("%i",&direccion2);
          if(direccion2==1)//mover para arriba
          {
              if(direccion==1)//derecha arriba
              {
                  printf("\nIngrese el Movimiento de la Dama");
                  printf("\nIngrese el eje x: ");scanf("%i",&j);
                  printf("\nIngrese el eje y: ");scanf("%i",&p);
                  w=x;
                  z=y;
                  for(;x<j;x++)
                  {
                      //printf("\n%i\t %i",y,x);
                      if(t[y][x].pieza=='B')//si hay un aliado en la diagonal
                      {
                          printf("\nMovimiento Invalido\nCompañero de Equipo en el Camino");
                          band=0;
                          break;
                      }
                      if(t[y][x].pieza=='B'&& t[y-1][x+1].pieza=='B')//|| t[y][x].pieza == 'M'&& t[y-1][x+1].pieza=='B'|| t[y-1][x+1].pieza == 'M')//si hay muchas fichas enemigas que no se pueden comer
                      {
                          printf("\nMuchas Fichas Enemigas en el camino");
                          band=0;
                          break;
                      }
                      if(t[y][x].pieza=='B' && t[y-1][x+1].pieza==' ')//para comer || t[y][x].pieza == 'M'
                      {
                          t[y][x].pieza=' ';
                          //printf("\nEntro");
                      }
                      y--;
                  }
                  if(band==1)
                  {
                        if(t[p][j].pieza==' ')
                          {
                              t[z][w].pieza=' ';
                              t[p][j].pieza='M';
                          }
                          else
                          if(t[p][j].pieza!=' ' && t[p][j].pieza!='M')
                          {
                              printf("\nCoordenadas Ocupadas\n");
                          }
                  }
              }
              if(direccion==0)//izquierda arriba
              {
                  printf("\nIngrese el Movimiento de la Dama");
                  printf("\nIngrese el eje x: ");scanf("%i",&j);
                  printf("\nIngrese el eje y: ");scanf("%i",&p);
                  w=x;
                  z=y;
                  for(;y>p;y--)
                  {
                      //printf("\n%i\t %i",y,x);
                      if(t[y][x].pieza=='B')//si hay un aliado en la diagonal|| t[y][x].pieza == 'M'
                      {
                          printf("\nMovimiento Invalido\nCompañero de Equipo en el Camino");
                          band=0;
                          break;
                      }
                      if(t[y][x].pieza=='B'&& t[y-1][x-1].pieza=='B')//si hay muchas fichas enemigas que no se pueden comer|| t[y-1][x-1].pieza == 'M'
                      {
                          printf("\nMuchas Fichas Enemigas en el camino");
                          band=0;
                          break;
                      }
                      if(t[y][x].pieza=='B'&& t[y-1][x-1].pieza==' ')//para comer|| t[y][x].pieza == 'M'
                      {
                          t[y][x].pieza=' ';
                          //printf("\nEntro");
                      }
                      x--;
                  }
                  if(band==1)
                  {
                        if(t[p][j].pieza==' ')
                          {
                              t[z][w].pieza=' ';
                              t[p][j].pieza='M';
                          }
                          else
                          if(t[p][j].pieza!=' ' && t[p][j].pieza!='M')
                          {
                              printf("\nCoordenadas Ocupadas\n");
                          }
                  }
              }
          }
          if(direccion2==0)//mover para abajo
          {
              if(direccion==1)//derecha abajo
              {
                 printf("\nIngresa la COORDENADA hacia donde desea moverla\n");
                 printf("\nIngrese Eje x: ");scanf("%i",&j);
                 printf("\nIngrese Eje y: ");scanf("%i",&p);
                 if(p<8 && p>y && j<8 && j>x)
                 {
                   if(t[p][j].pieza==' ')
                   {
                         for(i=1;j-i>=x;i++)
                         {
                             if(t[p-i][j-i].pieza==' ' || t[p-i][j-i].pieza=='M')
                                   hacer=1;
                             else
                             {
                               hacer=0;
                               break;
                             }
                         }
                         //COMER FICHA DE DAMA PRUEBA
                         if(hacer==0)
                         {
                         for(i=1;j-i>x;i++)
                        {
                            if((t[p-i][j-i].pieza=='W' || t[p-i-1][j-i-1].pieza=='D') && t[p-i][j-i].pieza!='B')
                            {
                                if(t[p-i-1][j-i-1].pieza==' ' || t[p-i-1][j-i-1].pieza=='M')
                                hacer=2;
                                else
                                {
                                    hacer=4;
                                    break;
                                }
                            }
                            else
                                hacer=4;
                        }
                       }
                         if(hacer==1)
                       {t[p][j].pieza='M';
                       t[y][x].pieza=' ';}
                       if(hacer==2)//COMER FICHA DE DAMA PRUEBA
                        {
                            t[p][j].pieza='M';
                            for(i=1;j-i>=x;i++)
                                t[p-i][j-i].pieza=' ';
                        }
                        if(hacer==4 || hacer==0)
                        {
                            printf("\nNO SE PUDO MOVER A LA DAMA\nUNA FICHA LO IMPIDIO\n");
                            band=0;
                        }
                   }
                   else
                   if(t[p][j].pieza!=' ')
                     {
                        printf("\nNO SE PUDO MOVER A LA DAMA\nUNA FICHA LO IMPIDIO\n");
                        band=0;
                     }
                 }
                 else
                 {
                     printf("\n\nMOVIMIENTO INVALIDO\nLA DAMA NO PUEDE COLOCARSE EN ESA CASILLA\n");
                     band=0;
                 }

              }
              if(direccion==0)//izquierda abajo
              {
                  printf("\nIngresa la COORDENADA hacia donde desea moverla\n");
                 printf("\nIngrese Eje x: ");scanf("%i",&j);
                 printf("\nIngrese Eje y: ");scanf("%i",&p);
                 if(p<8 && j>-1 && p>y && j<x)
                 {
                   if(t[p][j].pieza==' ')
                   {
                     for(i=1;j+i<=x;i++)
                     {
                         if(t[p-i][j+i].pieza==' ' || t[p-i][j+i].pieza=='M')
                               hacer=1;
                         else
                         {
                           hacer=0;
                           break;
                         }
                     }
                     //COMER FICHA DE DAMA PRUEBA
                     if(hacer==0)
                     {
                     for(i=1;j+i<x;i++)
                    {
                        if((t[p-i][j+i].pieza=='W' || t[p-i][j+i].pieza=='D') && t[p-i][j+i].pieza!='B')
                        {
                            if(t[p-i-1][j+i+1].pieza==' ' || t[p-i-1][j+i+1].pieza=='M')
                            hacer=2;
                            else
                            {
                                hacer=4;
                                break;
                            }
                        }
                        else
                            hacer=4;
                     }
                    }
                     if(hacer==1)
                   {t[p][j].pieza='M';
                   t[y][x].pieza=' ';}
                   if(hacer==2)//COMER FICHA DE DAMA PRUEBA
                    {
                        t[p][j].pieza='M';
                        for(i=1;j+i<=x;i++)
                            t[p-i][j+i].pieza=' ';
                    }
                    if(hacer==4 || hacer==0)
                    {
                        printf("\nNO SE PUDO MOVER A LA DAMA\nUNA FICHA LO IMPIDIO\n");
                        band=0;
                    }
                   }
                   else
                   if(t[p][j].pieza!=' ')
                     {
                        printf("\nNO SE PUDO MOVER A LA DAMA\nUNA FICHA LO IMPIDIO\n");
                        band=0;
                    }
                 }
                 else
                 {
                     printf("\n\nMOVIMIENTO INVALIDO\nLA DAMA NO PUDE COLOCARSE EN ESA CASILLA\n");
                     band=0;
                 }
              }
          }
      }
      else
         {
             printf("\n INVALID MOVEMENT\nTHE PIECE ISN'T FOUND\n");
             band=0;
         }
     return band;
}

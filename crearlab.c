
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define RENS 15
#define COLS 15

void Crear_Laberinto(char Laberinto[RENS][COLS]); //crea el laberinto
void Encontrar_Inicio(char Laberinto[RENS][COLS], int *x, int *y); //encuentra la E o e, y le da las coordenadaas a *x y a *y
int Padre(char Laberinto[RENS][COLS], int x, int y, char Laberinto_optimo[RENS][COLS], int pasos, int *caminos, int *pasostemp, int flag); //funcion que buscara los caminos, es recursiva
void Funcion_optima(char Laberinto[RENS][COLS], char Laberinto_optimo[RENS][COLS], int pasos, int *caminos, int *pasostemp, int flag); //funcion encargada de determinar si esa salida es optima y de  imprimir los pasos y caminos.
void Imprimir(char Laberinto[RENS][COLS]); //imprime el laberinto
void Final(char Laberinto_optimo[RENS][COLS], int pasostemp, int caminos); //imprime la funcion optima.

int main (void)
{
  int pasos, x,y, caminos=1, pasostemp, flag; 
  pasos=0;
  char Laberinto[RENS][COLS], Laberinto_optimo[RENS][COLS];
  printf("\nLa primera opcion despliega paso por paso e ilustra  todas las salidas posibles, la opcion 2 despliega la solucion optima. Que opcion quieres, 1 o 2?\n");
  scanf("%d", &flag);
  Crear_Laberinto(Laberinto);
  Encontrar_Inicio(Laberinto, &x, &y);
  Padre(Laberinto,x, y, Laberinto_optimo, pasos, &caminos, &pasostemp, flag);
  Final(Laberinto_optimo, pasostemp, caminos);
}

void Crear_Laberinto(char Laberinto[RENS][COLS])
{
  int x, y;
  x=0;
  strcpy(Laberinto[0], "@@@@@@@@@@@@@@@");
  strcpy(Laberinto[1], "@S           E@");
  strcpy(Laberinto[2], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[3], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[4], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[5], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[6], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[7], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[8], "@             @");
  strcpy(Laberinto[9], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[10],"@ @@@@@@@@@@@ @");
  strcpy(Laberinto[11],"@ @@@@@@@@@@@ @");
  strcpy(Laberinto[12],"@ @@@@@@@@@@@ @");
  strcpy(Laberinto[13],"@             @");
  strcpy(Laberinto[14],"@@@@@@@@@@@@@@@");
  Imprimir(Laberinto);
}
void Encontrar_Inicio(char Laberinto[RENS][COLS], int *x, int *y)
{
  int j, i; 
  for(j=0; j<RENS; j++)
    { 
      for(i=0; i<COLS; i++)
	{
	  if(Laberinto[j][i]== 'e' ||Laberinto[j][i]== 'E' )
	    {
	      *x=i;
	      *y=j;
	    }
	}
    }
}

int Padre(char Laberinto[RENS][COLS], int x, int y, char Laberinto_optimo[RENS][COLS], int pasos, int *caminos, int *pasostemp, int flag)
{
  if(Laberinto[y][x] == ' ' || Laberinto[y][x]== 'E')
    {
      if(Laberinto[y][x] == ' ') //si esta sobre un espacio imprime una X
	Laberinto[y][x] = 'X';
      if(Laberinto[y][x]== 'E' && pasos > 0)
	return 0;
      
      if(flag==1)
	{
	  Imprimir(Laberinto);
	}
      pasos++; //4 funciones recursivas que inspeccionan al rededor de la casilla Laberinto[y][x]
      Padre(Laberinto, x,  y-1, Laberinto_optimo, pasos, caminos,pasostemp, flag);
      Padre(Laberinto, x+1, y, Laberinto_optimo, pasos, caminos, pasostemp, flag);
      Padre(Laberinto, x-1, y, Laberinto_optimo, pasos, caminos, pasostemp, flag);
      Padre(Laberinto, x, y+1, Laberinto_optimo, pasos, caminos, pasostemp, flag);
      if(Laberinto[y][x]== 'X')// va borrando las X
	{
	  Laberinto[y][x] = ' ';
	  if(flag==1) //el valor de la flag depende de lo que el usuario haya elegido como opcion
	    {
	      Imprimir(Laberinto);
	    }
	}
    }
  if(Laberinto[y][x]== '@')
    return 0;
  
  if(Laberinto[y][x]== 'S')
    {
      Funcion_optima(Laberinto, Laberinto_optimo, pasos, caminos, pasostemp, flag);
      *caminos= *caminos+1;
    }
}


  
void Funcion_optima(char Laberinto[RENS][COLS], char Laberinto_optimo[RENS][COLS], int pasos, int *caminos, int *pasostemp, int flag)
{
  int r, h, i, j;
  if(*caminos == 1) //iguala la primera salida a pasostemp, para que luego las demas puedan ser coomparadas con esta
    {
      *pasostemp = pasos;
      for(r=0; r<=14; r++)
	{
	  for(h=0; h<=14; h++)
	    {
	      Laberinto_optimo[r][h] = Laberinto[r][h];
	    }
	}
    }
  if(*pasostemp > pasos) //coomparacion de los 2 tipos de pasos
    {
      *pasostemp = pasos;
      for(j=0; j<=14; j++)
	{
	  for(i=0; i<=14; i++)
	    {
	      Laberinto_optimo[j][i] = Laberinto[j][i];
	    }
	}
    }
  if(flag==1)
    {
      printf("Se hizo en %d pasos.\n", pasos);
      printf("Este es el camino %d.\n", *caminos);
    }
}

void Imprimir(char Laberinto[RENS][COLS])
{
  int x,y;
  getchar();
  system("clear");
  for(y=0; y<RENS; y++)
    {
      for(x=0; x<RENS; x++)
	printf("%c", Laberinto[y][x]);
      printf("\n");
    }
}

void Final(char Laberinto_optimo[RENS][COLS], int pasostemp, int caminos) //imprime optima
{
  int x,y;
  getchar();
  system("clear");
  printf("\n La salida optima es:\n");
  for(y=0; y<RENS; y++)
    {
      for(x=0; x<RENS; x++)
	printf("%c", Laberinto_optimo[y][x]);
      printf("\n");
    }
  printf("\nCon un total de %d pasos\n", pasostemp);
  printf("Hay un total de %d caminos\n", caminos);
}


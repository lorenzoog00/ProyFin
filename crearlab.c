
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Crear_Laberinto(char Laberinto[15][15]);
void Encontrar_Inicio(char Laberinto[15][15], int *ex, int *ey, int *x, int *y);
int Padre(char Laberinto[15][15], int x, int y, char Laberinto_optimo[15][15], int pasos, int *caminos, int *pasostemp);
void Funcion_optima(char Laberinto[15][15], char Laberinto_optimo[15][15], int pasos, int *caminos, int *pasostemp);
void Imprimir(char Laberinto[15][15]);
void Final(char Laberinto_optimo[15][15], int pasostemp);
int main (void)
{
  int ex, ey, pasos, x,y, caminos=1, pasostemp;
  pasos=0;
  char Laberinto[15][15], Laberinto_optimo[15][15];
  Crear_Laberinto(Laberinto);
  Encontrar_Inicio(Laberinto, &ex, &ey, &x, &y);
  Padre(Laberinto,x, y, Laberinto_optimo, pasos, &caminos, &pasostemp);
  Final(Laberinto_optimo, pasostemp);
}

void Crear_Laberinto(char Laberinto[15][15])
{
  int x, y;
  x=0;
  strcpy(Laberinto[0], "@@@@@@@@@@@@@@@");
  strcpy(Laberinto[1], "@S            @");
  strcpy(Laberinto[2], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[3], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[4], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[5], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[6], "@ @E@@@@@@@@@ @");
  strcpy(Laberinto[7], "@ @ @@@@@@@@@ @");
  strcpy(Laberinto[8], "@             @");
  strcpy(Laberinto[9], "@ @@@@@@@@@@@ @");
  strcpy(Laberinto[10],"@ @@@@@@@@@@@ @");
  strcpy(Laberinto[11],"@ @@@@@@@@@@@ @");
  strcpy(Laberinto[12],"@ @@@@@@@@@@@ @");
  strcpy(Laberinto[13],"@             @");
  strcpy(Laberinto[14],"@@@@@@@@@@@@@@@");
  Imprimir(Laberinto);
}
void Encontrar_Inicio(char Laberinto[15][15], int *ex ,int *ey, int *x, int *y)
{
  int j, i; 
  for(j=0; j<15; j++)
    { 
      for(i=0; i<15; i++)
	{
	  if(Laberinto[j][i]== 'e' ||Laberinto[j][i]== 'E' )
	    {
	      *ex=i;
	      *ey=j;
	    }
	}
    }
  *y=*ey;
  *x=*ex;
}

int Padre(char Laberinto[15][15], int x, int y, char Laberinto_optimo[15][15], int pasos, int *caminos, int *pasostemp)
{
  if(Laberinto[y][x] == ' ' || Laberinto[y][x]== 'E')
    {
      if(Laberinto[y][x] == ' ')
	Laberinto[y][x] = 'X';
      if(Laberinto[y][x]== 'E' && pasos>0)
	return 0;
      
           
      Imprimir(Laberinto);
      pasos++;
      Padre(Laberinto, x, y-1, Laberinto_optimo, pasos, caminos, pasostemp);
      Padre(Laberinto, x+1, y, Laberinto_optimo, pasos, caminos, pasostemp);
      Padre(Laberinto, x-1, y, Laberinto_optimo, pasos, caminos, pasostemp);
      Padre(Laberinto, x, y+1, Laberinto_optimo, pasos, caminos, pasostemp);
      if(Laberinto[y][x]== 'X')
	{
	  Laberinto[y][x] = ' ';
	  Imprimir(Laberinto);
	}
    }
  if(Laberinto[y][x]== '@')
    return 0;
  if(Laberinto[y][x]== 'S')
    {
      Funcion_optima(Laberinto, Laberinto_optimo, pasos, caminos, pasostemp);
      *caminos= *caminos+1;
    }
}


  
void Funcion_optima(char Laberinto[15][15], char Laberinto_optimo[15][15], int pasos, int *caminos, int *pasostemp)
{
  int r, h, i, j;
  if(*caminos == 1)
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
  //printf("%d", *pasostemp);
  if(*pasostemp > pasos)
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
  printf("Se hizo en %d pasos.\n", pasos);
  printf("Este es el camino %d.\n", *caminos);
}

void Imprimir(char Laberinto[15][15])
{
  int x,y;
  getchar();
  system("clear");
  for(y=0; y<=14; y++)
    {
      for(x=0; x<=14; x++)
	printf("%c", Laberinto[y][x]);
      printf("\n");
    }
  
}

void Final(char Laberinto_optimo[15][15], int pasostemp)
  
{
  int x,y;
  getchar();
  system("clear");
  printf("\n La salida optima es:\n");
  for(y=0; y<=14; y++)
    {
      for(x=0; x<=14; x++)
	printf("%c", Laberinto_optimo[y][x]);
      printf("\n");
    }
  printf("\n Con un total de %d pasos\n", pasostemp);
}


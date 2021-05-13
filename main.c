#include <stdio.h>                                                                  
#include <stdlib.h>                                                                 
#include <string.h>                                                                 
                                                                                    
#define LONG 40                                                                     
                                                                                    
//#include "Crear_Lab"                                                              
  //#include "Caso2"                                                                  
    //#include "Caso3"                                                                  
      //#include "Caso4"                                                                  
	//#include "Caso5"                                                                  
                                                                                    
void Enter();                                                                       
                                                                                    
int main(int argc, char *argv[])                                                    
{                                                                                   
  char Caso2[LONG],Caso3[LONG],Caso4[LONG],Caso1[LONG],Validacion[LONG];            
  int i,j;                                                                          
                                                                                    
  strcpy(Caso2,"entrada");                                            
  strcpy(Caso3,"-pasos");                                     
  strcpy(Caso4,"./laberinto <entrada><salida>");                                    
  strcpy(Caso1,"./laberinto");                              
                                                                                    
  system("clear");                                                                  
                                                                                    
  if(argc == 1) // o sea laberinto
    if(strcmp(Caso1, argv[0])==0)
      {                                                                               
	printf("- - - - - USO DEL PROGRAMA - - - - - \n");                            
	printf("Este programa despliega un laberinto, el cual para ser inicializado  \
se seguirán\n los siguientes comandos:\n");                                         
	printf("laberinto <Entrada>: inicializará el archivo que contiene el mejor ca\
mino.\n");                                                                          
	printf("laberinto -pasos <entrada>:Desplegará todos los caminos posibles así \
como cuántos pasos recorrió y cuántas veces encontró la saldia. \n");               
	printf("\n ");
      }
    else
      printf("\nCometiste un error, comando no reconocido.\n");
                                                                               
  if (argc==2)
    {
      if(strcmp(Caso2, argv[1])==0) //flag=0                                                     
	printf("caso 2\n");
      else
	printf("\nCometiste un error, comando no reconocido. \n");
    }
  if (argc==3) //flag=1
    {
      if((strcmp(Caso3, argv[1])==0) && strcmp(Caso2, argv[2])==0)
	printf("caso 3/n");
      else
	printf("\nCometiste un error, comando no reconocido. \n");
    } 
}


void Enter()
{
  char Tecla;

  printf("Presiona <enter> para continuar...\n");
  Tecla = getchar();
}      

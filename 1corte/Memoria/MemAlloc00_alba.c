/****************************************************************************
Pontificia Universidad Javeriana
Autor: Juan camilo alba
Fecha: 13/08/2024
Materia: Sistermas Operativos
Tema: Gestion de Memoria
Topico: Reserva de memoria con la funcion malloc().
La funcion malloc reserva un espacio de memoria de tamaño requerido y
devuelve un puntero señalando al comienzo de la memoria recien reservada.
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){
  //declaracion de los punteros donde se guardara la memoria asignada
  int *bloque=malloc(4*sizeof(int));//asignacion de memoria para 4 enteros
  int *puntero=malloc(15*sizeof(*puntero));//asignacion de memoria para 15 enteros
  //bucle para llenar los espacios de memoria asignados en bloque
  for(int i=0;i<4;i++){
    bloque[i]=i*2;
    printf("El valor de memoria reservada bloque00[%d]= %d\n",i,bloque[i]);  
  }
  
  if(puntero!=NULL){
    *(puntero+7)=1467; //se le asigna a la posicion 8 de los espacios reservados en puntero el numero 1467 
    printf("El valor de la 8va posicion de puntero es:%d \n",*(puntero+7));  
  }

  
  free(bloque);//se libera la memoria de bloque
  free(puntero);//se libera la memoria de puntero
  return 0;
}

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
  
  int *bloque00=malloc(4*sizeof(int));
  int *puntero=malloc(15*sizeof(*puntero));
  
  for(int i=0;i<4;i++){
    bloque00[i]=i*2;
    printf("El valor de memoria reservada bloque00[%d]= %d\n",i,bloque00[i]);  
  }
  
  if(puntero!=NULL){
    *(puntero+7)=9889; 
    printf("El valor de la 8va posicion de puntero es:%d \n",*(puntero+7));  
  }

  
  free(bloque00);
  free(puntero);
  return 0;
}

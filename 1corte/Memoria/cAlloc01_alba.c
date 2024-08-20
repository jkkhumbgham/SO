/****************************************************************************
Pontificia Universidad Javeriana
Autor: Juan camilo alba
Fecha: 13/08/2024
Materia: Sistermas Operativos
Tema: Gestion de Memoria
Topico: Reserva de memoria en la funcion calloc().
La funcion calloc reserva un espacio de memoria de tamaño requerido.
Los espacios de igual tamaño y de memoria contigua, la asignacion es dinamica.
Inicialmente esta inicializado en 0.
devuelve un puntero señalando el inicio del espacio de memoria reservado.
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(){
 
  int *p1=calloc(4,sizeof(int));
  int *puntero=calloc(10,sizeof(int));
  int *p3=calloc(5,sizeof *p3);

  printf("Construccion y calcculo de la secuencia de los primeros 10 terminos\n");  
  for(int i=0;i<10;i++){
    *(puntero+i)=i;
    printf("El valor de la secuencia es: %d \n",*(puntero+i));  
  }

  
  free(p1);
  free(puntero);
  free(p3);

  return 0;
}

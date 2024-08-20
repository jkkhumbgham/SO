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
  //bloque de declaracion de variables
  int *p0=calloc(4,sizeof(int));//se declara el puntero p0 y se le asigna memoria para 4 enteros
  int *p1=calloc(10,sizeof(int));//se declara el puntero p1 y se le asigna memoria para 10 enteros
  int *p2=calloc(5,sizeof *p2);//se declara el puntero p2 y se le asigna memoria para 5 espacios del tamaño del p2 que es int

  printf("Construccion y calculo de la secuencia de los primeros 10 terminos\n");  
 //bucle para llenar y presentar el contenido de p1
  for(int i=0;i<10;i++){
    *(p1+i)=i;//se asigna a el contenido de p1 el valor de i
    printf("El valor de la secuencia es: %d \n",*(puntero+i));  //se imprime el numero recien asignado
  }

  //bloque para liberar las memorias reservadas
  free(p0);//se libera la memoria de p0
  free(p1);//se libera la memoria de p1
  free(p2);//se libera la memoria de p2

  return 0;
}

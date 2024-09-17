/****************************************************************************
Pontificia Universidad Javeriana
Autor: Juan camilo alba
Fecha: 20/08/2024
Materia: Sistermas Operativos
Tema: Gestion de Memoria
Topico: Cambiar el tamaño de un bloque de memoria reservada con la funcion realloc.
La funcion realloc cambia el tamaño de un bloque de memoria.
si se busca agrandar el bloque se intenta ampliar el bloque de memoria. 
Si hay suficiente espacio contiguo, el bloque se amplía en la misma ubicación.
Si no hay suficiente espacio, asigna un nuevo bloque de memoria con el tamaño requerido, 
copia los datos del bloque original al nuevo bloque, y libera el bloque original.
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Bloque de declaracion de variables
    int *arr = malloc(5 * sizeof(int)); //asignamos memoria para un arreglo de 5 enteros con la funcion malloc

    // bloque de inicializacion de arreglo arr
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1; //a la posicion del arreglo i se le asigna el valor de i+1
    }
    // bloque de impresion de los valores del arreglo
    printf("Arreglo original:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // bloque de cambio de tamaño del arreglo
    arr = realloc(arr, 10 * sizeof(int));// Usamos realloc para cambiar el tamaño del arreglo a 10 enteros

    // Bloque de inicializacion del nuevo arreglo
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;// debido a que ya tenemos 5 datos se llena desde new_arr[5] con el valor de i+1
    }
    //bloque de impresion de valores del nuevo arreglo
    printf("Arreglo redimensionado:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    free(arr); // liberamos la memoria de new_arr

    return 0;
}

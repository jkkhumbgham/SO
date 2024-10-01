/**********
Pontificia Universidad Javeriana
Autor: Juan Camilo Alba
Fecha: 3/09/2024
Materia: Sistemas Operativos
Tópico: Introducción a Procesos Fork.
Fork: Al ser invocado, crea 2 procesos: un proceso padre y un proceso hijo.
Cada uno de estos dos procesos tiene un espacio de memoria diferente (son
procesos independientes), y son idénticos hasta que el programador lo determine.
**********/

#include <stdio.h>    // Librería estándar de entrada/salida
#include <stdlib.h>   // Librería estándar para funciones como atoi y exit
#include <unistd.h>   // Para usar funciones como fork y getpid
#include <sys/types.h> // Definición de tipos de datos como pid_t

/*
  Nombre: creacion_fork
  Argumentos: un entero que representa la generación (línea o número de iteración)
  Función: La función crea un proceso usando fork() y almacena el ID del proceso 
  retornado por fork en la variable `proceso`. Luego, verifica si la creación del 
  proceso hijo fue exitosa y muestra mensajes diferentes para el proceso padre e hijo.
*/
void creacion_fork(int linea){
    pid_t proceso;  // Variable para almacenar el valor retornado por fork (ID del proceso)
    
    // Llamada a fork() para crear un nuevo proceso
    proceso = fork();
    
    // Si el valor retornado por fork() es menor a 0, hubo un error en la creación del proceso
    if(proceso < 0){
        printf("Error creación proceso\n");
        exit(1); // Salir del programa con un código de error
    }
    // Si el valor retornado es 0, este es el proceso hijo
    else if (proceso == 0)
        printf("%d: Proceso =HIJO=: %d\n", linea, getpid()); // getpid() obtiene el ID del proceso hijo
    // Si el valor retornado es mayor que 0, este es el proceso padre
    else
        printf("%d: Proceso =PADRE= %d\n", linea, getpid()); // getpid() obtiene el ID del proceso padre
}

int main(int argc, char *argv[]){
    // Convertir el primer argumento pasado al programa (número de iteraciones) a entero
    int p = (int) atoi(argv[1]);
    
    // Bucle para crear tantos procesos como indique el argumento p
    for(int i = 0; i < p; i++)
        creacion_fork(i); // Crear un nuevo proceso en cada iteración

    printf("\n---\n\n"); // Separador visual en la salida
    return 0; // Retornar 0 para indicar que el programa terminó correctamente
}


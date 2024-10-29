#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

// Función que se ejecutará en cada hilo
// Imprime el número del trabajo correspondiente al hilo
static void *funcion(void *argumentos){
  size_t job = *(size_t *)argumentos;  // Obtiene el trabajo asignado
  printf("\n\t Job %zu \n", job);      // Imprime el número del trabajo
  return NULL;
}

int main(int argc, char *argv[]) {
    // Convierte el primer argumento en el número de hilos a crear (N)
    int N = (int)atoi(argv[1]);

    // Declara un vector de trabajos y un vector de hilos de tamaño N
    size_t jobs[N];        // Cada elemento representa un trabajo único
    pthread_t hilos[N];    // Cada elemento representa un hilo único

    // Crea N hilos, asignando un trabajo único a cada hilo
    for(int i = 0; i < N; i++){
      jobs[i] = i;  // Asigna un número de trabajo a cada elemento en el vector jobs
      // Crea el hilo y pasa la dirección del trabajo correspondiente
      pthread_create(&hilos[i], NULL, funcion, jobs + i);
    }

    // Espera a que cada hilo termine su ejecución
    for(int i = 0; i < N; i++){
      pthread_join(hilos[i], NULL); // Espera a que el hilo 'i' finalice
    }

    return 0;
}

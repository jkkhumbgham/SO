#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

// Variables globales para el contador y el número máximo de threads
int counter = 0;
int max = 4; // Número de threads de productor y consumidor a crear

// Definición de mutex y variables de condición para sincronización
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER; // Protege la variable counter
pthread_mutex_t condp_mutex = PTHREAD_MUTEX_INITIALIZER;   // Mutex para controlar la condición del productor
pthread_mutex_t condc_mutex = PTHREAD_MUTEX_INITIALIZER;   // Mutex para controlar la condición del consumidor
pthread_cond_t condVarProd = PTHREAD_COND_INITIALIZER;     // Condición para el productor
pthread_cond_t condVarCons = PTHREAD_COND_INITIALIZER;     // Condición para el consumidor

// Función que ejecuta el thread productor
static void *productor(){
  while(1){
    // Bloquea condp_mutex para verificar la condición de producción
    pthread_mutex_lock(&condp_mutex);
    while(counter >= 10){ // Si el contador es >= 10, espera hasta que el consumidor consuma
      pthread_cond_wait(&condVarProd, &condp_mutex); // Espera en la condición del productor
    }
    pthread_mutex_unlock(&condp_mutex); // Libera condp_mutex

    // Incrementa el contador protegido por counter_mutex
    pthread_mutex_lock(&counter_mutex);
    counter++; // Incrementa el contador
    pthread_cond_signal(&condVarCons); // Señala a los consumidores que pueden consumir
    printf("Soy el productor %d || Contador = %d\n", (int)pthread_self(), counter);
    pthread_mutex_unlock(&counter_mutex); // Libera counter_mutex

    // Si el contador es mayor que 7, el productor duerme por 4 segundos para reducir la velocidad
    if(counter > 7){
      sleep(4);
    }
  }
}

// Función que ejecuta el thread consumidor
void *consumidor(){
  while(1){
    sleep(1); // Simula tiempo de procesamiento
    
    // Bloquea condc_mutex para verificar la condición de consumo
    pthread_mutex_lock(&condc_mutex);
    while(counter <= 0){ // Si el contador es <= 0, espera hasta que el productor incremente el contador
      pthread_cond_signal(&condVarProd); // Despierta al productor si está dormido
      pthread_cond_wait(&condVarCons, &condc_mutex); // Espera en la condición del consumidor
    }
    pthread_mutex_unlock(&condc_mutex); // Libera condc_mutex

    // Decrementa el contador protegido por counter_mutex
    pthread_mutex_lock(&counter_mutex);
    if(counter > 0){
      printf("Soy consumidor %d valor contador = %d\n", (int)pthread_self(), counter);
      counter--; // Decrementa el contador
      pthread_cond_signal(&condVarProd); // Señala a los productores que pueden producir
    }
    pthread_mutex_unlock(&counter_mutex); // Libera counter_mutex
  }
}

// Funciones de productor y consumidor para ser usadas en pthread_create
void *consumidor();
void *productor();

int main(int argc, char *argv[]) {
    pthread_t produc[max]; // Array de threads productores
    pthread_t cons[max];   // Array de threads consumidores

    // Crear threads de productores y consumidores
    for(int i = 0; i < max; i++){
      pthread_create(&produc[i], NULL, &productor, NULL);
      pthread_create(&cons[i], NULL, &consumidor, NULL);
    }

    // Esperar a que todos los threads terminen
    for(int i = 0; i < max; i++){
      pthread_join(produc[i], NULL);
      pthread_join(cons[i], NULL);
    }

    return 0;
}

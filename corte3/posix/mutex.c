#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
int counter = 0;
int max = 4;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condp_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condc_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condVarProd = PTHREAD_COND_INITIALIZER;
pthread_mutex_t condVarCons = PTHREAD_COND_INITIALIZER;
//funcion para ejecutar en el thread
static void *productor(){
  while(1){
    pthread_mutex_lock(&condp_mutex);
    while(counter >= 10){
      pthread_cond_wait(&condVarProd, &condp_mutex);
    }
    pthread_mutex_unlock(&condp_mutex);
    pthread_mutex_lock(&counter_mutex);
    counter++;
    pthread_cond_signal(&condVarCons);
    printf("soy el productor %d || Contador = %d\n", pthread_self(), counter);
    pthread_mutex_unlock(&condp_mutex);
    pthread_mutex_unlock(&counter_mutex);
    if(counter > 7){
      sleep(4);
    }
  }
}
void *consumidor(){
  while(1){
    sleep(1);
    pthread_mutex_lock(&condc_mutex);
    while(counter<=0){
      pthread_cond_signal(&condVarProd);
      pthread_cond_wait(&condVarCons, &condc_mutex);
    }
    pthread_mutex_unlock(&condc_mutex);
    pthread_mutex_lock(&counter_mutex);
    if(counter>0){
      printf("soy consumidor %d valor contador = %d \n",pthread_self(),counter);
      counter--;
      pthread_cond_signal(&condVarProd);
    }
    pthread_mutex_unlock(&counter_mutex);
    pthread_mutex_unlock(&condc_mutex);
  }
}
void *consumidor();
void *productor();

int main(int argc, char *argv[]) {
    pthread_t produc[max];
     pthread_t cons[max];
    for(int i = 0; i < max; i++){
      pthread_create(&produc[i], NULL, &productor, NULL);
      pthread_create(&cons[i], NULL, &consumidor, NULL);
    }
  for(int i = 0; i < max; i++){
      pthread_join(produc[i],NULL);
      pthread_join(cons[i], NULL);
    }
  return 0;
}

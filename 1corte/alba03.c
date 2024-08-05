/**************************************************************************
Pontificia universidad javeriana
autor: juan alba
Fecha: 23/07/24
Materia: SO
Tema: progamacion en C
Requerimientos:
        
**************************************************************************/
#include<stdio.h>

int main(int argc, char *argv[]){
  printf("Hola: %s",argv[1]);
  printf(" %s\n;",argv[2]);
  printf("\n");
  printf("Cuantos años tienes:");
    int edad;
    scanf("%d",&edad);
  printf("Cual es tu comida favorita:");
    char com[100];
    scanf("%s",com);
  printf("Como se llama tu mejor amigo:");
    char amigo[100];
    scanf("%s",amigo);
  printf("Tienes alergias:");
    char al[100];
    scanf("%s",al);
  printf("en que te quieres especializar:");
    char es[100];
    scanf("%s",es);
  printf("cual es tu hobby:");
    char ho[100];
    scanf("%s",ho);
  printf("al %s %s de %d años\n es mejor sentarlo con %s y gente que hable de %s o haga %s\n quiere comer %s y es alergico a %s",argv[1],argv[2],edad,amigo,es,ho,com,al);
    return(0);
  
}


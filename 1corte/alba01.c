/**************************************************************************
Pontificia universidad javeriana
autor: juan alba
Fecha: 23/07/24
Materia: SO
Tema: progamacion en C
Requerimientos:
        -Funcion Bienvenida
        -Funcion de suma de enteros
        -Funcion de calculo del areade una circunferencia
**************************************************************************/
#include<stdio.h>
/*Funcion bienvenida*/
void Bienvenida(){
  printf("Hola Mundo...\n");
  printf("\t\t es la clase de SO....\n");
}
/*Funcion suma dos enteros*/
int sumaenteros(){
  printf("el primer entero es: \n");
  int num;
  scanf("%d",&num);
  printf("el segundo entero es: \n");
  int num2;
  scanf("%d",&num2);
  int suma= num + num2;  
  printf("el resultadode sumar %d mas %d es: %d\n",num,num2,suma);  
}
/*Funcion calculo area*/
void area(){
  printf("Digite el radio del circulo: \n");
  int radio;
  scanf("%d",&radio);
  float pi=3.14;
  float area = radio*radio*pi;
  printf("el resultdo del area con radio %d es %f",radio,area);
}
int main(int argc, char *argv[]){
    Bienvenida();
    sumaenteros();
    area();
    return(0);
}


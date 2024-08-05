/**************************************************************************
Pontificia universidad javeriana
autor: juan alba
Fecha: 23/07/24
Materia: SO
Tema: progamacion en C
Requerimientos:
        
**************************************************************************/

#include <stdio.h>

int main() {
    // Ejemplo de entero
    int ent = 1;
    printf("Formato para entero (int(d)): %d\n", ent);

    // Ejemplo de flotante
    float flo = 1.23;
    printf("Formato para flotante (float(f)): %f\n", flo);

    // Ejemplo de doble precisión
    double dou = 1.234567;
    printf("Formato para doble (double(f)): %f\n", dou);

    // Ejemplo de carácter
    char car = 'A';
    printf("Formato para carácter (char(c)): %c\n", car);

    // Ejemplo de cadena de texto
    char cade[] = "Ejemplo";
    printf("Formato para cadena de texto (string(s)): %s\n", cade);

    // Ejemplo de entero largo
    long lar = 123456789L;
    printf("Formato para entero largo (long(ld)): %ld\n", lar);

    // Ejemplo de entero largo largo
    long long ll = 123456789012345LL;
    printf("Formato para entero largo largo (long long(lld)): %lld\n", ll);

    // Ejemplo de valor sin signo entero
    unsigned int un = 4294967295U;
    printf("Formato para entero sin signo (unsigned int(u)): %u\n", un);

    return 0;
}


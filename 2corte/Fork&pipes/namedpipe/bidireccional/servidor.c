/**********
Pontificia Universidad Javeriana
Autor: Juan Camilo Alba
Fecha: 1/10/2024
Materia: Sistemas Operativos
Tópico: Comunicación bidireccional con named pipes

Este programa implementa un named pipe que recibe cadenas, 
les invierte el orden de los caracteres y envía las cadenas invertidas de vuelta 
al cliente. El proceso continúa hasta que se recibe la cadena "end", lo que 
finaliza la comunicación.

**********/

#include <stdio.h>      // Librería estándar de entrada/salida
#include <sys/stat.h>   // Para manejo de permisos y tipos de archivos
#include <sys/types.h>  // Para tipos de datos del sistema
#include <fcntl.h>      // Para operaciones de control de archivos
#include <unistd.h>     // Para funciones del sistema como read(), write(), y close()
#include <string.h>     // Para funciones de manipulación de cadenas

#define FIFO_FILE "/tmp/fifo_twoway"  // Definición del archivo FIFO para la comunicación

// Declaración de la función que invierte una cadena
void reverse_string(char *);

// Función principal del programa
int main() {
    int fd;                 // Descriptor de archivo para el pipe
    char readbuf[80];       // Buffer para almacenar la cadena leída
    char end[10];           // Cadena que contiene la palabra "end" para finalizar la comunicación
    int to_end;             // Variable para verificar si se ha recibido la palabra "end"
    int read_bytes;         // Número de bytes leídos del FIFO
  
    /* Crear el FIFO si no existe */
    mkfifo(FIFO_FILE, S_IFIFO|0640);  // Crear un pipe con permisos de lectura/escritura
    
    // Copiar la palabra "end" a la variable `end` para la comparación posterior
    strcpy(end, "end");

    // Abrir el pipe para lectura y escritura
    fd = open(FIFO_FILE, O_RDWR);

    // Bucle principal para leer y procesar mensajes
    while (1) {
        // Leer la cadena enviada por el cliente a través del pipe
        read_bytes = read(fd, readbuf, sizeof(readbuf));
        readbuf[read_bytes] = '\0';  // Asegurarse de que la cadena termine con el carácter nulo '\0'

        // Mostrar la cadena recibida
        printf("FIFOSERVER: Cadena recibida: \"%s\" y la longitud es %d\n", readbuf, (int)strlen(readbuf));

        // Comparar la cadena recibida con la palabra "end"
        to_end = strcmp(readbuf, end);

        // Si la cadena recibida es "end", finalizar el servidor
        if (to_end == 0) {
            close(fd);  // Cerrar el pipe
            break;      // Salir del bucle
        }

        // Invertir la cadena recibida
        reverse_string(readbuf);

        // Mostrar la cadena invertida que se va a enviar de vuelta
        printf("FIFOSERVER: Enviando cadena invertida: \"%s\" y la longitud es %d\n", readbuf, (int) strlen(readbuf));

        // Enviar la cadena invertida de vuelta al cliente a través del piep
        write(fd, readbuf, strlen(readbuf));

        /*
         * sleep(2) - Esto asegura que el otro proceso (cliente) tenga tiempo 
         * para leer el mensaje, de lo contrario, el servidor podría leer el 
         * mensaje enviado de vuelta.
         */
        sleep(2);  // Pausa de 2 segundos para evitar conflictos en la lectura y escritura simultánea
    }

    return 0;  // Finaliza el programa
}

/* 
nombre:reverse_string
argumentos:Esta función recibe un puntero a una cadena y cambia los caracteres en orden inverso.
objetivo:invertir una cadena
funcion:con ayuda de la variable temp la funcion toma el primer valor y lo pone en esta variable,
luego pone el valor de la posicion de last en la posicion de first y por ultimo pone el valor de 
temp en la posicion de last.
 
 
 */
void reverse_string(char *str) {
    int last, limit, first;
    char temp;

    last = strlen(str) - 1;  // Última posición del arreglo
    limit = last / 2;        // Punto medio para realizar el intercambio
    first = 0;               // Primera posición del arreglo
  
    // Bucle para intercambiar los caracteres de la cadena
    while (first < last) {
        temp = str[first];     // Almacenar temporalmente el valor de la primera posición
        str[first] = str[last]; // Asignar el valor de la última posición a la primera
        str[last] = temp;       // Asignar el valor temporal a la última posición
        first++;                // Avanzar la posición inicial
        last--;                 // Retroceder la posición final
    }

    return;  // Finalizar la función
}


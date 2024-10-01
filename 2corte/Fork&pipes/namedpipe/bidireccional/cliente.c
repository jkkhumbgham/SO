/**********
Pontificia Universidad Javeriana
Autor: Juan Camilo Alba
Fecha: 1/10/2024
Materia: Sistemas Operativos
Tópico: Comunicación bidireccional utilizando un named pipe (FIFO)

Este programa implementa la comunicación entre procesos de forma bidireccional 
usando un named pipe. El cliente puede enviar y recibir mensajes 
simultáneamente a través del pipe. El programa envía los datos introducidos 
por el usuario y, tras enviarlos, lee la respuesta desde el mismo pipe. 
La comunicación finaliza cuando el cliente envía la cadena "end".

**********/

#include <stdio.h>      // Librería estándar de entrada/salida
#include <sys/stat.h>   // Para manejo de permisos y tipos de archivos
#include <sys/types.h>  // Para tipos de datos del sistema
#include <fcntl.h>      // Para operaciones de control de archivos
#include <unistd.h>     // Para funciones del sistema como read(), write(), y close()
#include <string.h>     // Para funciones de manipulación de cadenas

#define FIFO_FILE "/tmp/fifo_twoway"  // Definición del archivo FIFO para la comunicación

int main() {
    int fd;                 // Descriptor de archivo para el pipe
    int end_process;        // Indicador para determinar si se debe finalizar el programa
    int stringlen;          // Longitud de la cadena ingresada por el usuario
    int read_bytes;         // Número de bytes leídos del pipe
    char readbuf[80];       // Buffer para almacenar la cadena leída o enviada
    char end_str[5];        // Cadena que contiene la palabra "end" para finalizar la comunicación

    // Mensaje inicial que informa al usuario sobre cómo finalizar el proceso
    printf("FIFO_CLIENT: Enviar mensajes infinitamente, para terminar ingresa \"end\"\n");

    // Abrir el pipe para lectura y escritura; si no existe, lo crea
    fd = open(FIFO_FILE, O_CREAT | O_RDWR);

    // Copiar la palabra "end" a la variable `end_str` para su comparación posterior
    strcpy(end_str, "end");

    // Bucle principal para enviar y recibir mensajes
    while (1) {
        printf("Ingresa una cadena: ");
        // Leer la cadena ingresada por el usuario
        fgets(readbuf, sizeof(readbuf), stdin);
        
        // Calcular la longitud de la cadena ingresada
        stringlen = strlen(readbuf);
        
        // Eliminar el carácter de nueva línea '\n' y reemplazarlo por el carácter nulo '\0'
        readbuf[stringlen - 1] = '\0';

        // Comparar la cadena ingresada con la palabra "end"
        end_process = strcmp(readbuf, end_str);

        // Si la cadena no es "end", se envía el mensaje y se espera la respuesta
        if (end_process != 0) {
            // Escribir la cadena ingresada en el pipe
            write(fd, readbuf, strlen(readbuf));
            printf("FIFOCLIENT: Cadena enviada: \"%s\" y la longitud es %d\n", readbuf, (int)strlen(readbuf));
            
            // Leer la respuesta del pipe
            read_bytes = read(fd, readbuf, sizeof(readbuf));
            
            // Asegurarse de que la cadena leída termine con '\0'
            readbuf[read_bytes] = '\0';
            
            // Imprimir la cadena recibida
            printf("FIFOCLIENT: Cadena recibida: \"%s\" y la longitud es %d\n", readbuf, (int)strlen(readbuf));
        } else {
            // Si la cadena es "end", se envía el mensaje final y se cierra el pipe
            write(fd, readbuf, strlen(readbuf));
            printf("FIFOCLIENT: Cadena enviada: \"%s\" y la longitud es %d\n", readbuf, (int)strlen(readbuf));
            
            // Cerrar el descriptor de archivo y salir del bucle
            close(fd);
            break;
        }
    }

    return 0;  // Finalizar el programa
}


/**************************************************************************
Pontificia Universidad Javeriana
Autor: Juan Alba
Fecha: 23/07/24
Materia: Sistemas Operativos
Tema: Comunicación entre procesos utilizando pipes

Este programa implementa un programa de lectura de un FIFO que lee mensajes enviados a través
de un named pipe. Utiliza la función `mknod()` para crear el pipe si no existe y `read()`
para recibir los datos enviados desde otro proceso que escribe en el pipe.
El programa lee mensajes continuamente hasta que recibe la cadena "end".
        
**************************************************************************/

#include <stdio.h>      // Librería estándar de entrada/salida
#include <sys/stat.h>   // Para manejo de permisos de archivo
#include <sys/types.h>  // Para tipos de datos del sistema
#include <fcntl.h>      // Para operaciones de control de archivos
#include <unistd.h>     // Para funciones del sistema como read() y close()
#include <string.h>     // Para operaciones con cadenas como strcmp() y strcpy()

#define FIFO_FILE "MYFIFO" // Definimos el nombre del archivo FIFO

int main() {
    int fd;                // Descriptor de archivo para el FIFO
    char readbuf[80];      // Buffer para almacenar los datos leídos del FIFO
    char end[10];          // Cadena que contiene la palabra "end" para detener el programa
    int to_end;            // Variable para verificar si se ha leído "end"
    int read_bytes;        // Número de bytes leídos del FIFO
    
    /* Crear el FIFO si no existe */
    mknod(FIFO_FILE, S_IFIFO | 0640, 0);
    // mknod crea un archivo FIFO con permisos 0640 (lectura para el propietario y grupo)
    
    // Copiar la palabra "end" en la variable end para comparar más adelante
    strcpy(end, "end");
    
    // Bucle infinito que leerá datos del FIFO
    while (1) {
        // Abrir el archivo FIFO en modo solo lectura
        fd = open(FIFO_FILE, O_RDONLY);
        
        // Leer datos del FIFO, almacena el número de bytes leídos en `read_bytes`
        read_bytes = read(fd, readbuf, sizeof(readbuf));
        
        // Terminar la cadena leída agregando el carácter nulo '\0' al final
        readbuf[read_bytes] = '\0';
        
        // Imprimir la cadena recibida y su longitud
        printf("Cadena recibida: \"%s\" y la longitud es %d\n", readbuf, (int)strlen(readbuf));
        
        // Comparar la cadena leída con la palabra "end"
        to_end = strcmp(readbuf, end);
        
        // Si la cadena es "end", cerrar el archivo y terminar el bucle
        if (to_end == 0) {
            close(fd);  // Cerrar el descriptor de archivo
            break;      // Terminar el bucle y salir del programa
        }
    }

    return 0; // Finalizar el programa
}


/**************************************************************************
Pontificia universidad Javeriana
Autor: Juan Alba
Fecha: 23/07/24
Materia: Sistemas Operativos
Tema: Comunicación entre procesos con pipes

Este programa implementa un cliente FIFO (First In First Out) que envía 
mensajes a través de un named pipe (FIFO). El cliente envía mensajes 
infinitamente hasta que el usuario ingrese la palabra "end" para terminar 
la comunicación.
**************************************************************************/

#include <stdio.h>    // Librería estándar de entrada/salida
#include <sys/stat.h> // Para manejar el sistema de archivos y permisos
#include <sys/types.h> // Para tipos de datos del sistema
#include <fcntl.h>    // Para control de archivos, como open()
#include <unistd.h>   // Para manejo de operaciones del sistema como write() y close()
#include <string.h>   // Para operaciones con cadenas como strcmp() y strlen()

#define FIFO_FILE "MYFIFO" // Nombre del archivo para el pipe

int main() {
    int fd;             // Descriptor de archivo para el pipe
    int end_process;    // Variable para determinar cuándo terminar el proceso
    int stringlen;      // Longitud de la cadena ingresada
    char readbuf[80];   // Buffer donde se almacenará el mensaje ingresado por el usuario
    char end_str[5];    // Cadena para comparar si el usuario ingresa "end"
    
    // Mensaje inicial para el usuario
    printf("FIFO_CLIENT: Envíe mensajes indefinidamente, para terminar ingrese \"end\"\n");
    
    // Abrir el pipe en modo escritura (crearlo si no existe)
    fd = open(FIFO_FILE, O_CREAT | O_WRONLY);
    
    // Copiar la palabra "end" en la variable end_str para futuras comparaciones
    strcpy(end_str, "end");

    // Bucle infinito para enviar mensajes hasta que se ingrese "end"
    while (1) {
        // Solicitar al usuario que ingrese una cadena
        printf("Ingrese una cadena: ");
        fgets(readbuf, sizeof(readbuf), stdin); // Leer la cadena desde la entrada estándar (teclado)
        
        // Obtener la longitud de la cadena y eliminar el carácter de nueva línea
        stringlen = strlen(readbuf);
        readbuf[stringlen - 1] = '\0';
        
        // Comparar la cadena ingresada con "end"
        end_process = strcmp(readbuf, end_str);
  
        // Si la cadena ingresada no es "end"
        if (end_process != 0) {
            // Enviar el mensaje al pipe
            write(fd, readbuf, strlen(readbuf));
            // Mostrar el mensaje enviado y su longitud
            printf("Cadena enviada: \"%s\" con longitud de %d\n", readbuf, (int) strlen(readbuf));
        } else {
            // Si la cadena es "end", enviarla también y cerrar el descriptor de archivo
            write(fd, readbuf, strlen(readbuf));
            printf("Cadena enviada: \"%s\" con longitud de %d\n", readbuf, (int) strlen(readbuf));
            close(fd); // Cerrar el pipe
            break;     // Salir del bucle
        }
    }
    
    return 0; // Finalizar el programa
}


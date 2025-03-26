#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

#define block_size 8 // tamaño del bloque a encriptar

void encriptar(int fd, char *mensaje)
{
    size_t len = strlen(mensaje);
    unsigned char buffer[block_size];
    srand(time(NULL)); //  cambia la semilla cada vez q se ejecuta el programa segun el tiempo (time)
    // bucle para encriptar cada caracter
    for (int i = 0; i < len; i++)
    {
        // completar con 7 bytes aleatorios
        for (int j = 0; j < 7; j++)
        {
            buffer[j] = rand() % 256;
        }
        buffer[7] = mensaje[i];
        write(fd, buffer, block_size);
    }
}

int main(int argc, char *argv[])
{

    int fd = STDOUT_FILENO;

    // Agregar código aquí.
    if (argc == 1) // leer  desde la entrada estandar e imprimir en salida estandar
    {
        char mensaje[1024] = {0};  // Inicializa con ceros
        ssize_t bytes_leidos = read(STDIN_FILENO, mensaje, sizeof(mensaje) - 1);
        if (bytes_leidos > 0) {
            if (mensaje[bytes_leidos - 1] == '\n'){ // para no leer el salto de linea despues de presionar enter
                mensaje[bytes_leidos - 1] = '\0';  // para no leer basura
            }
        }      
        encriptar(fd, mensaje);
    }
    else if (argc == 2) // leer desde la terminal y imprimir en la salida estandar
    {
        encriptar(fd, argv[1]);
    }
    else if (argc == 3) // leer desde la terminal y imprimir en un archivo
    {
        fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644); // argv[1] es el nombre del archivo, lo abre en modo escritura con o_wronly, si no existe lo crea
                                                                // con o_creat y si existe le borra el conteido con o_trunc
        if (fd == -1)
        {
            perror("error al abrir el archivo");
            exit(EXIT_FAILURE);
        }
        encriptar(fd, argv[2]); // argv[2] es el mensaje
    }

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}

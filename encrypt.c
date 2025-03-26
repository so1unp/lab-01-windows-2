#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define block_size 8 // tamaño del bloque a encriptar

void encriptar(int fd, char *mensaje)
{
    size_t len = strlen(mensaje);
    unsigned char buffer[block_size];
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
        char mensaje[1024];
        read(STDIN_FILENO, mensaje, sizeof(mensaje));
        encriptar(fd, mensaje);
    }
    else if (argc == 2) // leer desde la terminal y imprimir en la salida estandar
    {
    }
    else if (argc == 3) // leer desde la terminal y imprimir en un archivo
    {
    }

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}

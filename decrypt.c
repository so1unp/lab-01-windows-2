#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define block_size 8 // tamaño en bytes del bloque

void desencriptar(char *mensaje, int len)
{

    unsigned char temp_buffer[1024]; // aca se guarda el mensaje desencriptado

    int j = 0; // cantidad de bytes escritos en temp_buffer


    for (int i = block_size - 1; i < len; i += block_size)
    {                                  // comienza en el ultimo byte (7), es decir en el caracter encriptado
        temp_buffer[j++] = mensaje[i]; // guarda solo el byte real
    }

    write(STDOUT_FILENO, temp_buffer, j); // escribir el mensaje desencriptado
}

int main(int argc, char *argv[])
{
    char mensaje[8];
    ssize_t bytes_leidos;
    // Agregar código aquí.
    if (argc == 1) // leer  desde la entrada estandar e imprimir en salida estandar
    {
        while (bytes_leidos > 0)
        {
            bytes_leidos = read(STDIN_FILENO, mensaje, sizeof(mensaje));

            desencriptar(mensaje, bytes_leidos);
        }
    }
    else if (argc == 2) // leer desde un archivo e imprimir en la salida estandar
    {
        int fd = open(argv[1], O_RDONLY);

        if (fd == -1)
        {
            perror("error al abrir el archivo");
            exit(EXIT_FAILURE);
        }
        while (bytes_leidos > 0)
        {
            bytes_leidos = read(STDIN_FILENO, mensaje, sizeof(mensaje));

            desencriptar(mensaje, bytes_leidos);
        }
        close(fd);
    }
    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}

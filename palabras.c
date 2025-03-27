#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Agregar código aquí.
    char frase[100];
    char buffer[100];
    char letra;
    char letra2;
    char palabra[100];
    int i = 0;
    while ((letra2 = getchar()) != EOF)
    {
        if (letra2 != ' ' && letra2 != '\n')
        {
            buffer[i] = letra2;
            i++;
        }
        else
        {

            buffer[i] = '\0';
            i = 0;
            printf("%s\n", buffer);
            // i++;
        }
    }

    // for (int i = 0;  (letra = getchar() != ' '); i++)
    // {
    //     if (letra)
    //     {
    //         /* code */
    //     }

    // }

    // printf(buffer);
    //

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}

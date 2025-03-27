#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Agregar código aquí.
    int num = 0;

    // printf("el resultado es: %d", resu);
    // // Termina la ejecución del programa.
    int suma = 0;
    if (argc > 1)
    {

        for (int i = 1; i < argc; i++)
        {
            suma += atoi(argv[i]);
        }
    }
    else
    {
        while (scanf("%d", &num) == 1)
        {
            suma += num;
        }
    }
    printf("el resultado es: %d", suma);
    exit(EXIT_SUCCESS);
}

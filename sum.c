#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Agregar código aquí.

    double num = 0;
    double sum = 0;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            sum += atof(argv[i]);
        }
    }
    else
    {
        while (scanf("%lf", &num) == 1)
        {
            sum += num;
        }
    }

    printf("Suma: %lf\n", sum);

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}

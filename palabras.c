#include <stdio.h>
#include <stdlib.h>

int main()
{
    int word;
    char buffer[100];
    // Agregar código aquí.
    int count = 0;
    while ((word = getchar()) != EOF)
    {
        if (word != ' ' && word != '\t' && word != '\n')
        {
            buffer[count] = (char)word;
            count++;
        }
        else
        {
            buffer[count] = '\0';
            count = 0;
            printf("%s\n", buffer);
        }
    }

    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}

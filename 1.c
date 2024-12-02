#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c;
    int total = 0;
    int *buffer;
    int *buffer2;
    char *nombre;
    int size = 1;
    int n = 1;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            buffer = realloc(buffer, (size + 1) * sizeof(int));
            buffer[size] = atoi(nombre);

            size++;
            n = 0;
        }
        else if (c == '\n')
        {
            buffer2 = realloc(buffer2, (size) * sizeof(int));
            buffer2[size] = atoi(nombre);

            n = 0;
        }

        printf("char : %c", c);
        printf("%p\n", nombre);
        nombre = realloc(nombre, (n) * sizeof(char));
        printf("char : %c", c);
        nombre[n++] = c;
    }

    printf("b%i\n", buffer[0]);

    free(buffer);
    free(buffer2);
}

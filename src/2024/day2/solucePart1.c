#include <stdio.h>
#include <stdlib.h>

int checkLine(int *buffer, int size)
{
    int prec = *buffer;
    int croissant = *buffer < *(buffer + 1);

    for (int i = 1; i < size; i++)
    {
        if (prec == *(buffer + i))
            return 0;

        else if (croissant)
        {
            if ((prec + 3) < *(buffer + i) || prec >= *(buffer + i))
                return 0;
        }
        else if (!croissant)
        {
            if ((prec - 3) > *(buffer + i) || prec <= *(buffer + i))
                return 0;
        }

        prec = *(buffer + i);
    }
    return 1;
}

int main(void)
{
    char c;
    int total = 0;

    int *buffer = NULL;
    char *number = NULL;
    int size = 0;
    int n = 0;
    int safeLine = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n')
        {
            number[n] = '\0';
            buffer = realloc(buffer, (size + 1) * sizeof(int));
            *(buffer + size) = atoi(number);
            size++;

            n = 0;
            free(number);
            number = NULL;
        }

        if (c == '\n')
        {
            safeLine += checkLine(buffer, size);

            size = 0;
            free(buffer);
            buffer = NULL;
        }
        else
        {
            number = realloc(number, (n + 1) * sizeof(char));
            number[n] = c;
            n++;
        }
    }

    free(number);
    free(buffer);

    printf("\n%i", safeLine);
    // reponse après test : 334
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char c;
    int total = 0;

    int *buffer = NULL;
    int *buffer2 = NULL;
    char *number = NULL;
    int size = 0;
    int size2 = 0;
    int n = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            buffer = realloc(buffer, (size + 1) * sizeof(int));
            *(buffer + size) = atoi(number);
            size++;
            n = 0;
            free(number);
            number = NULL;
        }

        else if (c == '\n')
        {
            buffer2 = realloc(buffer2, (size2 + 1) * sizeof(int));
            *(buffer2 + size2) = atoi(number);
            size2++;
            n = 0;
            free(number);
            number = NULL;
        }
        else
        {
            number = realloc(number, (n + 1) * sizeof(char));
            *(number + n) = c;
            n++;
        }
    }

    for (int i = 0, cmp = 0; i < size; i++)
    {
        cmp = 0;
        for (int j = 0; j < size; j++)
        {
            if (*(buffer + i) == *(buffer2 + j))
                cmp++;
        }
        total += *(buffer + i) * cmp;
    }

    printf("\n tot: %i", total);

    free(number);
    free(buffer);
    free(buffer2);

    // reponse après test : 1879048
    return 0;
}

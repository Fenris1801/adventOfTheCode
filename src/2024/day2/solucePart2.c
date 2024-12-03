#include <stdio.h>
#include <stdlib.h>

int is_safe(int *buffer, int size)
{
    int is_increasing = buffer[1] > buffer[0];
    for (int i = 1; i < size; i++)
    {
        int diff = buffer[i] - buffer[i - 1];
        if ((is_increasing && (diff < 1 || diff > 3)) ||
            (!is_increasing && (diff > -1 || diff < -3)))
        {
            return 0;
        }
    }
    return 1;
}

int checkLine(int *buffer, int size)
{
    if (size < 2)
        return 0;

    if (is_safe(buffer, size))
    {
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        int *temp = malloc((size - 1) * sizeof(int));
        int idx = 0;

        for (int j = 0; j < size; j++)
        {
            if (j != i)
            {
                temp[idx++] = buffer[j];
            }
        }

        if (is_safe(temp, size - 1))
        {
            free(temp);
            return 1;
        }

        free(temp);
    }

    return 0;
}

int main(void)
{
    char c;
    int safeLine = 0;

    int *buffer = NULL;
    char *number = NULL;
    int size = 0;
    int n = 0;

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
    // reponse après test : 400
    return 0;
}

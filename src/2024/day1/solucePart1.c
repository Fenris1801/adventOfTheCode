#include <stdio.h>
#include <stdlib.h>

void sort(int *list, int N)
{
    int i, j, c;
    for (i = 0; i < N - 1; i++)
        for (j = i + 1; j < N; j++)
            if (list[i] > list[j])
            {
                c = list[i];
                list[i] = list[j];
                list[j] = c;
            }
}

int compareList(int *list, int *list2, int size)
{
    int result = 0;

    // for (; *list; list++, list2++)
    for (int i = 0; i < size; i++)
    {
        result += abs(list[i] - list2[i]);
        // result += abs(*list - *list2);
    }
    return result;
}

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

    sort(buffer, size);
    sort(buffer2, size2);
    total += compareList(buffer, buffer2, size);
    free(number);
    free(buffer);
    free(buffer2);

    printf("\n%i", total);
    // reponse après test : 1879048
    return 0;
}

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

int compareList(int *list, int *list2)
{
    int result = 0;

    // for (; *list; list++, list2++)
    for (int i = 0; i < 5; i++)
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
    int size = 0;
    int size2 = 0;

    int cmp = 0;

    while ((c = getchar()) != EOF)
    {
        size = 0;
        for (; c != ' '; c = getchar())
        {
            buffer = realloc(buffer, (size + 1) * sizeof(int));
            *(buffer + size) = c - '0';
            size++;
        }

        size2 = 0;
        for (c = getchar(); c != '\n' && c != EOF; c = getchar())
        {
            buffer2 = realloc(buffer2, (size2 + 1) * sizeof(int));
            *(buffer2 + size2) = c - '0';
            size2++;
        }
        sort(buffer, 5);
        sort(buffer2, 5);

        total += compareList(buffer, buffer2);
        printf("%i ", compareList(buffer, buffer2));

        free(buffer);
        free(buffer2);
        buffer = buffer2 = NULL;
        cmp += 1;
    }

    printf("%i %i", total, cmp);
    return 0;
}

#include <stdlib.h>

int calPoints(char** operations, int operationsSize)
{
    int *values = (int*)malloc(operationsSize * sizeof(int));
    int t = 0;
    int sum = 0;
    for (int i = 0; i < operationsSize; i++)
    {
        switch(*operations[i])
        {
            case 'C':
                values[--t] = 0;
                break;
            case 'D':
                values[t] = values[t-1] * 2;
                t++;
                break;
            case '+':
                values[t] = values[t-1] + values[t-2];
                t++;
                break;
            default:
                values[t++] = atoi(operations[i]);
                break;
        }
    }

    for (int j = 0; j < t; j++)
    {
        sum += *(values + j);
    }
    free(values);
    return (sum);
}

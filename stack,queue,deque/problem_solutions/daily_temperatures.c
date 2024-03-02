#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *result = (int*)calloc(temperaturesSize, sizeof(int));
    int *stack = (int*)malloc(temperaturesSize * sizeof(int));
    int length = -1;
    for (int t = 0; t < temperaturesSize; t++)
    {
        while ((length != -1) && (temperatures[t] > temperatures[stack[length]]))
        {
            int previous = stack[length--];
            result[previous] = t - previous; 
        }
        stack[++length] = t;
    }
    free(stack);
    *returnSize = temperaturesSize;
    return (result);
}
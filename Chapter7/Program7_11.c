#include <stdio.h>

void multiplyByTwo(float array[], int n)
{
    int i;
    for (i=0; i<n; ++i)
        array[i] *= 2;
}

int main(void)
{
    float floatVals[4] = {1.2f, -3.7f, 6.2f, 8.55f};
    int i;
    void multiplyByTwo(float array[], int n);

    multiplyByTwo(floatVals, 4);

    for(i=0; i<4; ++i)
        printf("%.2f\n", floatVals[i]);
    printf("\n");
    return 0;
}
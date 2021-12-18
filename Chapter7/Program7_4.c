// Function to calculate the nth triangular number
#include <stdio.h>

int calculateTriangularNumber(int n)
{
    int i, triangularNumber = 0;
    for(i=1; i<=n; ++i)
        triangularNumber += i;
    printf("The %i triangular number is %i\n", n, triangularNumber);
    return triangularNumber;
}

int main(void)
{
    calculateTriangularNumber(10);
    calculateTriangularNumber(20);
    calculateTriangularNumber(50);
    return 0;
}
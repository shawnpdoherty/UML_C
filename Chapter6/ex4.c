// Write a program that calculates the average of an array 
// of 10 floating-point values.

#include <stdio.h>

int main (void)
{
    // declare float sum(for division) and an array of 10
    float sum, array[10] = { 
        93.0, 100.0, 100.0, 100.0, 100.0, 100.0, 
        100.0, 99.0, 99.0, 100.0 };

    for (int i = 0; i < 10; ++i)
        sum += array[i];
    
    printf("The average is %.2f\n", sum / 10);
};
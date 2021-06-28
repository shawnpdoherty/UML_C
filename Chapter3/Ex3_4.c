/* 6. Write a program to evaluate the polynomial 
*  shown here: 3x3 - 5x2 + 6
*  for x = 2.55 
*/

#include <stdio.h>

int main (void)
{
    float x = 2.55;

    printf("polynomial evaluates to %f\n", 3 * x * x * x - 5 * x * x + 6);
    
    return 0;
}
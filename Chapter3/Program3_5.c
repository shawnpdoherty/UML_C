// Basic C Template

#include <stdio.h>

int main (void)
{
    float   f1 = 123.125, f2;
    int     i1, i2 = -150;
    char    c = 'a';

    i1 = f1; // float to int convert
    printf("%f assigned to an int produces %i\n", f1, i1);
    
    f1 = i2; //int to float convert
    printf("%i assigned to a float produces %f\n", i2, f1);
    
    f1 = i2 / 100; // int divided by int
    printf("%i divided by 100 produces %f\n", i2, f1);
    
    f2 = i2 /100.0; //int divided by float
    printf("%i divided by a 100.0 produces %f\n", i2, f2);
    
    f2 = (float) i2 / 100; //type cast operator
    printf("(float) %i divided by 100 produces %f\n", i2, f2);
    
    return 0;
}
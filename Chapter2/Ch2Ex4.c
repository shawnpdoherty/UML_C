/* Write a program that subtracts the value 15 from 87 and displays theresult, 
*  together with an appropriate message, at the termina
*/


#include <stdio.h>

int main (void)
    {
        int value1, value2, remainder;
        value1 = 87;
        value2 = 15;
        remainder = value1 - value2;

        printf ("%i minus %i is %i\n", value1, value2, remainder);
        return (0);
    }
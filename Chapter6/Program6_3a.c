// Rewrite Program 6.3 so that arrays are not used
// use three variables: two to store the previous two Fibonacci numbers 
// and one to store the current one
#include <stdio.h>

int main(void)
{
    int Fiba = 0, Fibb = 1, Fibc;
    // generate a table of the first 15 Fibonacci numbers
    printf("%i\n", Fiba);
    printf("%i\n", Fibb);
    for (int i = 2; i < 15; ++i)
    {
        Fibc = Fiba + Fibb;
        printf("%i\n", Fibc);
        Fiba = Fibb;
        Fibb = Fibc;
    }
    return 0;
}
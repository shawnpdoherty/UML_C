#include <stdio.h>

int main(void)
{
    const char baseDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',\
                                 '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int convertedNumber[64];
    long int numberToConvert;
    int nextDigit, base, index = 0;

    //get the number and the base
    printf("Number to be converted?");
    scanf( "%ld", &numberToConvert);    
    printf("Base?");
    scanf("%d", &base);

    //convert to the indicated base
    
    /*An algorithm to generate the digits of the
    * converted number can be informally stated as follows: 
    * A digit of the converted number is obtained by taking the modulo
    * of the number by the base. The number is then divided by the base, 
    * with any fractional remainder discarded, and the process is repeated 
    * until the number reaches zero.
    */

    do 
    {
        convertedNumber[index] = numberToConvert % base;
        ++index;
        numberToConvert = numberToConvert/base;       
    }
    while (numberToConvert != 0);

    // display the number in reverse order
    printf("Converted number  = ");
    for (--index; index >=0; --index)
    {

        nextDigit = convertedNumber[index];
        printf ("%c", baseDigits[nextDigit]);
    }
    printf("\n");
    return 0;
}
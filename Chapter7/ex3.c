#include <stdio.h>
/*Newton-Raphson Method to Compute the Square Root of x
* Step 1. Set the value of guess to 1.
* Step 2. If |guess2-x| < ε, proceed to step 4.
* Step 3. Set the value of guess to (x/ guess + guess) / 2 andreturn to step 2.
* Step 4. The guess is the approximation of the square root.
*/


float absoluteValue(float x)
{
    if (x < 0)
        x = -x;
    return x;
}

float squareRoot(float x, float e)
{
    
    float guess = 1.0;
    // declare absoluteValue function
    float absoluteValue(float x);

    if (x < 0)
    {
        printf("Negative argument to squareRoot.\n");
        return -1;
    }
    while(absoluteValue(guess * guess - x) >= e)
        guess = (x / guess + guess) / 2.0;
    
    return guess;
}

int main (void)
{
    const float epsilon = .00001;
    printf("squareRoot(2.0) = %f\n", squareRoot(2.0, epsilon));
    printf("squareRoot(144.0) = %f\n", squareRoot(144.0, epsilon));
    printf("squareRoot(17.5) = %f\n", squareRoot(17.5, epsilon));
    return 0;
}
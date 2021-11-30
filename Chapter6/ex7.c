/* Sieve of Eratosthenes Algorithm
*  To Display All Prime Numbers Between 1 and n
*   Step 1: Define an array of integers P. Set all elements Pi to 0, 2 <= i <=n.
*   Step 2: Set i to 2.
*   Step 3: If i > n, the algorithm terminates.
*   Step 4: If Pi is 0, then i is prime.
*   Step 5: For all positive integer values of j, such that i x j ≤ n, set Pixj to1.
*   Step 6: Add 1 to i and go to step 3.
*/
#include <stdio.h>

int main(void)
{
    int n = 150;
    // Step 1: Define an array of integers P.
    int P[n];
    // Set all elements to 0.
    for (int i = 0; i < n; ++i)
        P[i] = 0;
    // Step 2: Set i to 2.
    int i = 2;
    // Step 3: If i > n, the algorithm terminates
    while (i <= n)
    {
        // Step 4: If Pi is 0, then i is prime.
        if (P[i] == 0)
        {
            printf("%i\n", i);
            // Step 5: For all positive integer values of j, such that 
            // i x j ≤ n, set Pixj to 1.
            // set j to i and while j is less than n, increment j by i. 
            // and set those multiples to 1.
            for (int j = i; j <= n; j += i)
                P[j] = 1;
        }
        // Step 6: Add 1 to i and go to step 3.
        ++i;
    }
    return 0;
}

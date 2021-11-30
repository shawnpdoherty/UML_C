#include <stdio.h>

int main (void)
{
    int ratingCounters[11], i, response;

    for (i = 1; i <= 10; i++ )
        // initialize array values to 0
        ratingCounters[i] = 0;

    printf("Enter your responses\n");

    for (i = 1; i <= 20; i++)
    {
        scanf("%i", &response);
        if ( response < 1 || response > 10)
            printf("bad response: %i\n", response);
        else
            ++ratingCounters[response];
    }

    printf("\n\nRating\t    Number of Responses\n");
    printf("------\t---------------------\n");

    for ( i = 1; i <= 10; i++)
        printf("%i\t\t%i\n", i, ratingCounters[i]);
    
    return 0;
}
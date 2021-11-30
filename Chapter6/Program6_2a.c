#include <stdio.h>
/*Program 6.2 permits only 20 responses to be entered. Modify thatprogram
* so that any number of responses can be entered. So that the userdoes not 
* have to count the number of responses in the list, set up theprogram so that
* the value 999 can be keyed in by the user to indicate thatthe last response
* has been entered.
*/
int main (void)
{
    int ratingCounters[11], i, response;
    // initialize array values to 0
    for (i = 1; i <= 10; i++ )        
        ratingCounters[i] = 0;

    printf("Enter your responses (enter 999 to indicate last response)\n");

    do {
        scanf("%i", &response);
        if (response >= 0 && response <= 10)
            ++ratingCounters[response];
        else
            printf("Invalid response.\n");
    } while (response != 999); 

    printf("\n\nRating\t    Number of Responses\n");
    printf("------\t---------------------\n");

    for ( i = 1; i <= 10; i++)
        printf("%i\t\t%i\n", i, ratingCounters[i]);
    
    return 0;
}
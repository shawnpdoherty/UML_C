//-----------------------------------------------------------------------------
//
// Homework: 1
//
// Name: Shawn Doherty
//
// Template provided by : Prof. Tim Niesen.
//
// Class: C Programming, Summer 2021
//
// Date: 5/24/21
//
// Description: Program which determines gross pay and outputs                
// be sent to a designated file.
//
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int clock_num;          // employee clock number
    float gross;            // gross pay for week (wage * hours)
    float hours;            // number of hours worked per week
    FILE *outputfileptr;    // pointer to output file
    float wage;             // hourly wage
    int process_num;        // number of employees to process

    // open a file called home1.txt as writeable
    if ((outputfileptr = fopen("home1.txt", "w")) == (FILE *) NULL)
    {
        // stderr will print to screen
        fprintf(stderr, "Error, Unable to open file\n"); 
        exit(1);
    }
    // create file header I kept this formatted to 80 char line limit
    fprintf (outputfileptr, 
                "\n\t\tShawn Doherty, C Programming, "
                "First Homework Assignment\n\n\n");
    fprintf (outputfileptr, "\tClock  Wage  Hours Gross Pay\n");
    fprintf (outputfileptr, 
                "\t------ ----- ----- -------\n");
    
    // Prompt for num of employees to process
    printf ("***Pay Calculator***.\n");
    printf ("Enter number of employees to process:");
    scanf("%i", &process_num);
    for (int i = 0; i < process_num; ++i)
    {
        printf ("Enter clock number for employee %i: ", i + 1);
        scanf ("%d", &clock_num);
        printf ("Enter weekly wage for employee %i: ", i + 1);
        scanf ("%f", &wage);
        printf ("Enter the number of hours employee %i worked: ", i + 1);
        scanf ("%f", &hours);
        // calculate gross pay
        gross = wage * hours;
        // print out employee information to a file 
        fprintf (outputfileptr, "\t%06i %5.2f %5.1f %7.2f\n",
            clock_num, wage, hours, gross);
    }
    return (0);
}

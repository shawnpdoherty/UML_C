//-----------------------------------------------------------------------------
//
// Homework: 2
//
// Name: Shawn Doherty
//
// Template provided by : Prof. Tim Niesen.
//
// Class: C Programming, Summer 2021
//
// Date: 6/1/2021
//
// Description: Write a C program that will calculate the overtime and gross
// pay of a set of employees given the number of hours they worked in a given
// week.   
// The clock, wage, hours, and calculated values for overtime hours and gross
// pay should be printed for each employee.                
//
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// constants
#define STD_HOURS 40.0      // set standard workweek hours
#define OVERTIME_RATE 1.5   // set overtime rate of pay
#define PROCESS_NUM 5       // set number of employee timesheets to process

int main ( )
{
    int clock_num;          // employee clock number
    float gross;            // gross pay for week (wage * hours)
    float hours_worked;     // number of hours worked per week
    float wage;             // hourly wage
    FILE *outputfileptr;    // pointer to output file

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
                "Second Homework Assignment\n\n\n");
    fprintf (outputfileptr, "\tClock  Wage  Hours  OT  Gross Pay\n");
    fprintf (outputfileptr, 
                "\t------ ----- -----  ----  -------\n");
    
    // Prompt for num of employees to process
    printf ("***Pay Calculator (w/Overtime)***.\n");
    
    // iterate through each employee 
    for (int i = 1; i <= PROCESS_NUM; ++i)
    {
        // declare and initialize overtime hours and set to 0
        float overtime_hours = 0.0;

        // prompt user for clock,wage and hours for each employee
        printf ("Enter clock number for employee %i: ", i );
        scanf ("%d", &clock_num);
        printf ("Enter weekly wage for employee %i: ", i );
        scanf ("%f", &wage);
        printf ("Enter the number of hours employee %i worked: ", i );
        scanf ("%f", &hours_worked);
        
        // overtime scenario handler for hours worked over standard  
        if (hours_worked > STD_HOURS)
        {
            // caculate number of overtime hours
            overtime_hours = hours_worked - STD_HOURS;
            // calculate gross pay by adding overtime pay to standard wage at standard hours
            gross = ( STD_HOURS * wage ) + ( overtime_hours * (OVERTIME_RATE * wage));
        }
        
        // standard hourly pay
        else
        {
        gross = hours_worked * wage;
        }
        
        // print out employee information to a file 
        fprintf (outputfileptr, "\t%06i %5.2f %5.1f %5.1f %7.2f\n",
            clock_num, wage, hours_worked, overtime_hours, gross);
    }

    return (0);
}

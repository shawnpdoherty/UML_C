#include <stdio.h>
#include <stdlib.h>
#include "employees.h"

//**************************************************************/ 
// Function: createReport  
// 
// Purpose: Obtains input from arguments in array form, the clock number 
// , wage, number of hours worked, overtime hours and gross pay 
// per employee and prints the results to a local file
// 
// Parameters: 
//
// emp_num - Array of employee clock numbers.
// emp_hrs - Array of number of hours worked by an employee
// ot_hrs - Array of hours of overtime worked per employee
// hourly_rate - Array of hourly rate per employee
// gross_pay - Array of gross pay per employee
// size - Number of employees to process 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/

void createReport(long emp_num[], float emp_hrs[], float hourly_rate[], float ot_hrs[], float gross_pay[], int size)
{
    FILE *outputfileptr;    // pointer to output file
    
    // declare an array with values to count totals(wage,hour,ot,gross)
    // initialize values to 0.0
    float total [4] = {0.0, 0.0, 0.0, 0.0};
   
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
                "Fourth Homework Assignment\n\n\n");
    fprintf (outputfileptr, "\tClock#  Wage  Hours   OT    Gross\n");
    fprintf (outputfileptr, 
                "\t------  ----- -----  ----  -------\n");
    
    // iterate through array to print to file and update totals
    for (int i = 0; i < NUM_EMPL; ++i)
    {
        // print out employee information to a file 
        fprintf (outputfileptr, "\t%06i  %5.2f %5.1f %5.1f  %7.2f\n",
            emp_num[i], hourly_rate[i], emp_hrs[i], ot_hrs[i], gross_pay[i]);
        
        // update totals
        total[0] += hourly_rate[i]; // sub 0 for wage total
        total[1] += emp_hrs[i]; // sub 1 for hours total 
        total[2] += ot_hrs[i]; // sub 2 for ot total       
        total[3] += gross_pay[i]; // sub 3 for gross total    
    }

    // optional section
    fprintf (outputfileptr, 
                "\t------  ----- -----  ----  -------\n");
    // output totals
    fprintf (outputfileptr, "\tTotal   %5.2f %5.1f %5.1f  %7.2f\n",
            total[0], total[1], total[2], total[3]);  
    // output averages based on totals
    fprintf (outputfileptr, "\tAverage %5.2f %5.1f %5.1f  %7.2f\n",
            total[0]/NUM_EMPL, total[1]/NUM_EMPL, total[2]/NUM_EMPL, total[3]/NUM_EMPL);    

}

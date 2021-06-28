#include <stdio.h>
#include "employees.h"

/********************************************************************
** Function: Output_Results_Screen
**
** Purpose: Outputs to screen in a table format the following
** information about an employee: Clock, Wage,
** Hours, Overtime, and Gross Pay.
**
** Parameters:
**
**   employeeData - an array of structures containing
**   employee information
**   size - number of employees to process
**
** Returns: Nothing (void)
**
********************************************************************/

void Output_Results_Screen ( struct employee employeeData[], int size )
{
    int i; /* loop index */
    
    // declare an array with values to count totals(wage,hour,ot,gross)
    // initialize values to 0.0
    float total [4] = {0.0, 0.0, 0.0, 0.0};
   
    //create file header
    printf ( "\n\t\tShawn Doherty, C Programming, "
                "Sixth Homework Assignment\n\n\n");
    
    printf ("\t----------------------------------------------------------\n");
    printf ("\tName                     Clock#  Wage  Hours   OT    Gross\n");
    printf ("\t----------------------------------------------------------\n");
    

    /* print information about each employee */
    for (i = 0; i < size ; ++i)
    {
        printf("\t%-5.10s, %-5.10s %-5c             %06li  %5.2f %4.1f   %4.1f %8.2f \n",
        employeeData[i].emp_name.first_name, employeeData[i].emp_name.last_name, employeeData[i].emp_name.middle_initial, employeeData[i].id_number, employeeData[i].wage, employeeData[i].hours,
        employeeData[i].overtime, employeeData[i].gross);

        // update totals
        total[0] += employeeData[i].wage; // sub 0 for wage total
        total[1] += employeeData[i].hours; // sub 1 for hours total 
        total[2] += employeeData[i].overtime; // sub 2 for ot total       
        total[3] += employeeData[i].gross; // sub 3 for gross total    
    }


    // optional section
    printf ("\t------  ----- -----  ----  -------\n");
    // output totals
    printf ("\tTotal   %5.2f %5.1f %5.1f  %7.2f\n",
            total[0], total[1], total[2], total[3]);  
    // output averages based on totals
    printf ("\tAverage %5.2f %5.1f %5.1f  %7.2f\n",
            total[0]/NUM_EMPL, total[1]/NUM_EMPL, total[2]/NUM_EMPL, total[3]/NUM_EMPL); 
}
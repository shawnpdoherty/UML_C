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
**   employeeStats - a structure containing employee statistics
**   size - number of employees to process
**
** Returns: Nothing (void)
**
********************************************************************/

void Output_Results_Screen ( struct employee employeeData[], struct stats employeeStats, int size )
{
    int i; /* loop index */
    
    //create file header
    printf ( "\n\t\tShawn Doherty, C Programming, "
                "Sixth Homework Assignment\n\n\n");
    printf ("\t-----------------------------------------------------\n");
    printf ("\tName                 Clock# Wage  Hours   OT   Gross\n");
    printf ("\t-----------------------------------------------------\n");
    
    /* print information about each employee */
    for (i = 0; i < size ; ++i)
    {
        //TODO FORMAT CORRECTLY
        printf ("\t%s, %s %c %06li %5.2f  %4.1f %4.1f %8.2f \n",
               employeeData[i].employee_name.last_name,
               employeeData[i].employee_name.first_name,
               employeeData[i].employee_name.middle_initial,
               employeeData[i].id_number,
               employeeData[i].wage,
               employeeData[i].hours,
               employeeData[i].overtime,
               employeeData[i].gross);
        
        // update totals
        employeeStats.total_wage += employeeData[i].wage; // add to wage total
        employeeStats.total_hours += employeeData[i].hours; // add to hours total 
        employeeStats.total_ot += employeeData[i].overtime; // add to total       
        employeeStats.total_gross += employeeData[i].gross; // add to gross total
    }

    // initialize minimum values to first value of array
    // this accounts for any 0.0 values that may be passed in as part of the array
    employeeStats.min_gross = employeeData[0].gross;
    employeeStats.min_hours = employeeData[0].hours;
    employeeStats.min_ot = employeeData[0].overtime;
    employeeStats.min_wage = employeeData[0].wage;

    employeeStats.max_hours = 0.0;
    employeeStats.max_gross = 0.0;
    employeeStats.max_ot = 0.0;
    employeeStats.max_wage = 0.0;

    for (i = 0; i < size ; ++i)
    {
        // CALCULATE MINIMUM VALUES
        // min wage
        if( employeeData[i].wage <= employeeStats.min_wage)
        {
            employeeStats.min_wage = employeeData[i].wage;
        }
        // min hours
        if( employeeData[i].hours <= employeeStats.min_hours)
        {
            employeeStats.min_hours = employeeData[i].hours;
        }
        // min ot
        if(employeeData[i].overtime <= employeeStats.min_ot)
        {
            employeeStats.min_ot = employeeData[i].overtime;
        }      
        // min gross
        if(employeeData[i].gross <= employeeStats.min_gross )
        {
            employeeStats.min_gross = employeeData[i].gross;
        }       
    }

    // CALCULATE MAXIMUM VALUES
    for (i = 0; i < size ; ++i)
    {
        // max wage
        if (employeeData[i].wage > employeeStats.max_wage)
        {
            employeeStats.max_wage = employeeData[i].wage;
        }
        // max hours
        if(employeeData[i].hours > employeeStats.max_hours)
        {
            employeeStats.max_hours = employeeData[i].hours;
        }
        // max ot
        if(employeeData[i].overtime > employeeStats.max_ot)
        {
            employeeStats.max_ot = employeeData[i].overtime;
        }    
        // max gross
        if(employeeData[i].gross > employeeStats.max_gross)
        {
             employeeStats.max_gross = employeeData[i].gross;
        }
    }

    printf ("\t-----------------------------------------------------\n");
    // output totals
    printf ("\tTotal:                      %5.2f %5.1f%5.1f  %7.2f\n",
            employeeStats.total_wage,
            employeeStats.total_hours,
            employeeStats.total_ot, 
            employeeStats.total_gross);  
    
    // output averages based on totals
    printf ("\tAverage:                    %5.2f %5.1f%5.1f  %7.2f\n",
            employeeStats.total_wage/NUM_EMPL, 
            employeeStats.total_hours/NUM_EMPL, 
            employeeStats.total_ot/NUM_EMPL, 
            employeeStats.total_gross/NUM_EMPL); 
    
    printf ("\tMinimum:                    %5.2f %5.1f%5.1f  %7.2f\n",
            employeeStats.min_wage, 
            employeeStats.min_hours, 
            employeeStats.min_ot, 
            employeeStats.min_gross); 
    
    printf ("\tMaximum:                    %5.2f %5.1f%5.1f  %7.2f\n",
            employeeStats.max_wage, 
            employeeStats.max_hours, 
            employeeStats.max_ot, 
            employeeStats.max_gross); 

}
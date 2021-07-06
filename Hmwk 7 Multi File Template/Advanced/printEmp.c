#include <stdio.h>
#include <string.h>
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

void Output_Results_Screen ( struct employee *emp_ptr, struct stats *stats_ptr, int size )
{
    // initialize minimum values to first value of array
    // this accounts for any 0.0 values that may be passed in as part of the array
    stats_ptr->min_gross = emp_ptr->gross;
    stats_ptr->min_hours = emp_ptr->hours;
    stats_ptr->min_ot = emp_ptr->overtime;
    stats_ptr->min_wage = emp_ptr->wage;
   
    
    int i; /* loop index */
    
    /* create file header */
    printf ( "\n\t\tShawn Doherty, C Programming\n "
                "\t\tSeventh Homework Assignment: Advanced\n\n\n");
    printf ("\t-----------------------------------------------------\n");
    printf ("\tName                 Clock# Wage  Hours   OT    Gross\n");
    printf ("\t-----------------------------------------------------\n");

    /* print information about each employee */
    for (i = 0; i < size ; ++i)
    {  
        /* dynamically set the middle initial format based on the column width */
        printf ("\t%s, %s %-*c %06li %5.2f  %4.1f %4.1f %8.2f\n",
               emp_ptr->employee_name.last_name,
               emp_ptr->employee_name.first_name,
               /* this formats the width of the entire name column */
               17 - (strlen(emp_ptr->employee_name.first_name) +
               strlen(emp_ptr->employee_name.last_name)),
               emp_ptr->employee_name.middle_initial,
               emp_ptr->id_number,
               emp_ptr->wage,
               emp_ptr->hours,
               emp_ptr->overtime,
               emp_ptr->gross);
        
        /* update totals */
        stats_ptr->total_wage += emp_ptr->wage; // add to wage total
        stats_ptr->total_hours += emp_ptr->hours; // add to hours total 
        stats_ptr->total_ot += emp_ptr->overtime; // add to total       
        stats_ptr->total_gross += emp_ptr->gross; // add to gross total

       
        /* CALCULATE MINIMUM VALUES */
        /* min wage */
        if( emp_ptr->wage <= stats_ptr->min_wage)
        {
            stats_ptr->min_wage = emp_ptr->wage;
        }
        // min hours
        if( emp_ptr->hours <= stats_ptr->min_hours)
        {
            stats_ptr->min_hours = emp_ptr->hours;
        }
        // min ot
        if(emp_ptr->overtime <= stats_ptr->min_ot)
        {
            stats_ptr->min_ot = emp_ptr->overtime;
        }      
        // min gross
        if(emp_ptr->gross <= stats_ptr->min_gross )
        {
            stats_ptr->min_gross = emp_ptr->gross;
        }       

        // Calculate Maximum values
        // max wage
        if (emp_ptr->wage > stats_ptr->max_wage)
        {
            stats_ptr->max_wage = emp_ptr->wage;
        }
        // max hours
        if(emp_ptr->hours > stats_ptr->max_hours)
        {
            stats_ptr->max_hours = emp_ptr->hours;
        }
        // max ot
        if(emp_ptr->overtime > stats_ptr->max_ot)
        {
            stats_ptr->max_ot = emp_ptr->overtime;
        }    
        // max gross
        if(emp_ptr->gross > stats_ptr->max_gross)
        {
                stats_ptr->max_gross = emp_ptr->gross;
        }      
        
        // increment pointer position in array
        ++emp_ptr;
    }


    printf ("\t-----------------------------------------------------\n");
    // output totals
    printf ("\tTotal:                      %5.2f %5.1f%5.1f  %7.2f\n",
            stats_ptr->total_wage,
            stats_ptr->total_hours,
            stats_ptr->total_ot, 
            stats_ptr->total_gross);  
    
    // output averages based on totals
    printf ("\tAverage:                    %5.2f %5.1f%5.1f  %7.2f\n",
            stats_ptr->total_wage/NUM_EMPL, 
            stats_ptr->total_hours/NUM_EMPL, 
            stats_ptr->total_ot/NUM_EMPL, 
            stats_ptr->total_gross/NUM_EMPL); 
    
    printf ("\tMinimum:                    %5.2f %5.1f%5.1f  %7.2f\n",
            stats_ptr->min_wage, 
            stats_ptr->min_hours, 
            stats_ptr->min_ot, 
            stats_ptr->min_gross); 
    
    printf ("\tMaximum:                    %5.2f %5.1f%5.1f  %7.2f\n",
            stats_ptr->max_wage, 
            stats_ptr->max_hours, 
            stats_ptr->max_ot, 
            stats_ptr->max_gross); 
}
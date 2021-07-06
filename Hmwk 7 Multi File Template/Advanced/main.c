/**********************************************************************
**
** HOMEWORK: #7 Advanced
**
** Name: Shawn Doherty
**
** Class: C Programming
**
** Date: 07/06/2021
**
** Description: This program prompts the user for the number of hours
** worked for each employee. It then calculates gross pay
** including overtime and displays the results in table. Employee information
** is stored in an array of structures and referenced through the use of 
** pointers.   
**
/**********************************************************************/


#include <stdio.h>
#include "employees.h"

int main ()
{
    /* Structure to store the employee information */
    struct employee employeeData[NUM_EMPL];

    /* Structure to store stats and initialize structure to zero values */
    struct stats employeeStats[] = {0};

    /* Pointer to an employee struct */
    struct employee *emp_ptr;

    /* Pointer to the stats struct */
    struct stats *stats_ptr;
   
    /* set pointer to beginning of employeeData array */
    emp_ptr = employeeData;

    /* set pointer to the beginning of the sats array */
    stats_ptr = employeeStats; 

    /* call function to populate employee information */
    Get_Employee_Info(emp_ptr, NUM_EMPL);

    /* call function to input hours for each employee record */
    Get_Hours (emp_ptr, NUM_EMPL);

    /* Function call to output results to the screen */
    Output_Results_Screen (emp_ptr, stats_ptr, NUM_EMPL);
    
    return (0); /* success */

} /* main */
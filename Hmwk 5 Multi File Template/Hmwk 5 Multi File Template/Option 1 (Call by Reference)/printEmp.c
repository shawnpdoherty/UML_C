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

    /* print information about each employee */
    for (i = 0; i < size ; ++i)
    {
        printf(" %06li %5.2f %4.1f %4.1f %8.2f \n",
        employeeData[i].id_number, employeeData[i].wage, employeeData[i].hours,
        employeeData[i].overtime, employeeData[i].gross);
    } /* for */

} /* Output_results_screen */
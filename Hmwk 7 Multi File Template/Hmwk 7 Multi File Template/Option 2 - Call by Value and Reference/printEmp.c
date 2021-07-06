#include <stdio.h>
#include <stdlib.h>
#include "employees.h"

/************************************************************************/
/*  Function: printData                                                 */
/*                                                                      */
/*  Purpose:    Outputs to screen in a table format the following:      */
/*                  - Employee First and Last Name                      */
/*                  - Employee clock number                             */
/*                  - Wage rate for an employee.                        */
/*                  - Total hours worked by employee.                   */
/*                  - Overtime Hours.                                   */
/*                  - Gross Pay.                                        */
/*                                                                      */
/*  Parameters: emp_ptr - pointer to array of structures                */
/*              size - number of employees to process                   */
/*                                                                      */
/*  Returns:    Nothing, since emp_ptr is passed by reference           */
/************************************************************************/

void printEmp ( struct employee * emp_ptr, int size )
{
    int n;  /* counter used in for loop to keep track of iterations */

    /* prints the output for all employees to the screen */
    for (n = 0; n < SIZE; n++)
    {
        printf ("%-20.20s %06i   $%5.2f     %4.1f      %4.1f    $%7.2f \n",
                emp_ptr->name,
                emp_ptr->id,
                emp_ptr->wage,
                emp_ptr->hours,
                emp_ptr->overtime,
                emp_ptr->gross);

        ++emp_ptr;  /* move to next employee */
    }
    printf ("\n");
}
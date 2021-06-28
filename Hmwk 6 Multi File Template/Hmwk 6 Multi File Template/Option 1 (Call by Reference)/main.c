/*********************************************************************
**
** HOMEWORK: #6 Structures and Strings (Call by Reference)
**
** Name: [Enter your Name]
**
** Class: C Programming
**
** Date: [enter the date]
**
** Description: This program prompts the user for the number of hours
** worked for each employee. It then calculates gross pay
** including overtime and displays the results in table. Functions
** and structures are used.
**
***********************************************************************/

/*Define and Includes */

#include <stdio.h>
#include "employees.h"

int main ()
{
    /* Set up a local variable and initialize the clock and wages of my employees */
    struct employee employeeData[NUM_EMPL] = {
        { "Connie Cobol", 98401, 10.60 },
        { "Mary Apl", 526488, 9.75 },
        { "Frank Fortran", 765349, 10.50 },
        { "Jeff Ada", 34645, 12.25 },
        { "Anton Pascal", 127615, 8.35 }
    };

    /* Call various functions needed to read and calculate info */

    /* Print the column headers */

    /* Function call to output results to the screen in table format. */
    Output_Results_Screen (employeeData, NUM_EMPL);

    return (0); /* success */

} /* main */
/**********************************************************************
**
** HOMEWORK: #6 Basic
**
** Name: Shawn Doherty
**
** Class: C Programming
**
** Date: 06/28/21 
**
** Description: This program prompts the user for the number of hours
** worked for each employee. It then calculates gross pay
** including overtime and displays the results in table. Functions
** and structures are used.
**
/**********************************************************************/


#include <stdio.h>
#include "employees.h"

int main ()
{
    /* Set up a local variable to store the employee information */
    struct employee employeeData[NUM_EMPL] = {
        { "Connie Cobol", 98401, 10.60 },
        { "Mary Apl", 526488, 9.75 },
        { "Frank Fortran", 765349, 10.50 }, /* initialize clock and wage values */
        { "Jeff Ada", 34645, 12.25 },
        { "Anton Pascal", 127615, 8.35 }
    };

    int i;  /* loop and array index */

    /* Call functions as needed to read and calculate information */
    for (i = 0; i < NUM_EMPL; ++i)
    {

        /* Prompt for the number of hours worked by the employee */
        employeeData[i].hours = Get_Hours (employeeData[i].id_number);

        /* Add other function calls as needed to calculate overtime and gross */
        employeeData[i].overtime = Get_Overtime_Hours(employeeData[i].hours);

        /* Function call to calculate gross pay */
        employeeData[i].gross = Get_Gross_Pay(employeeData[i].hours, employeeData[i].overtime, employeeData[i].wage);

    }

    /* Function call to output results to the screen */
    Output_Results_Screen (employeeData, NUM_EMPL);
    
    return (0); /* success */

} /* main */
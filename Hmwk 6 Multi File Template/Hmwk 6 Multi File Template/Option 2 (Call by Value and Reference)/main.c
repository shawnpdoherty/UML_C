/**********************************************************************
**
** HOMEWORK: #6 Structures and Strings (Call by Value and Reference)
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
        { "Anton Pascal", 27615, 8.35 }
    };

    int i;  /* loop and array index */

    /* Call functions as needed to read and calculate information */
    for (i = 0; i < NUM_EMPL; ++i)
    {

       /* Prompt for the number of hours worked by the employee */
       employeeData[i].hours = Get_Hours (employeeData[i].id_number);

       /* Add other function calls as needed to calculate overtime and gross */

    } /* for */

    /* Print the column headers */

    /* Function call to output results to the screen in table format. */
    Output_Results_Screen (employeeData, NUM_EMPL);

    return (0); /* success */

} /* main */
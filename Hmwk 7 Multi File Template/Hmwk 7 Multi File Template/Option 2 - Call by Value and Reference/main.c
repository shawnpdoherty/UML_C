/************************************************************************/
/*                                                                      */
/*  HOMEWORK:   7                                                       */
/*                                                                      */
/*  Name:   J Student                                                   */
/*                                                                      */
/*  Class:  C Programming, Cybercourse                                  */
/*                                                                      */
/*  Date:   <add your date>                                             */
/*                                                                      */
/*  Description:  Program which determines gross pay based on overtime  */
/*                and outputs a formatted answer.  Employee information */
/*                is stored in an array of structures and referenced    */
/*                through the use of pointers.                          */
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "employees.h"

/************************************************************************/
/*                           Function: Main                             */
/************************************************************************/

int main ()
{

    /* A structure array to hold information on employees */
    struct employee emp [SIZE]  =  { {"Connie Cobol", 98401, 10.60},
                                     {"Frank Fortran", 526488, 9.75},
                                     {"Mary Apl", 765349, 10.50},
                                     {"Jeff Ada", 34645, 12.25},
                                     {"Anton Pascal", 127615, 10.0}
                                   };


    int i;                       /* loop and array index */

    struct employee * emp_ptr;   /* pointer to an employee structure */


    emp_ptr = emp;   /* point to beginning of emp array */


    /* Read in hours, and calculate overtime and gross - Call by Value */
    for (i=0; i < SIZE; ++i)

    {

        /* Get user input for the hours worked for each employee */
        emp_ptr->hours = getHours ( emp_ptr->id );

        /* Add function calls to calculate employee overtime and gross */

        ++emp_ptr;  /* point to next employee */


    }
        /* Print column headers for employees */


    /* Print employee data to the screen - Call by Reference */
    printEmp ( emp, SIZE );


    return 0;

}
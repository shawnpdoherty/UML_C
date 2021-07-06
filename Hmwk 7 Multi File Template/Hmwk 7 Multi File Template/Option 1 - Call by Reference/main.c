/************************************************************************/
/*                                                                      */
/*  HOMEWORK:   7                                                       */
/*                                                                      */
/*  Name:   Joe Student                                                 */
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

int main()
{

    /* A structure array to hold information on employees */
    struct employee emp [SIZE]  =  { {"Connie Cobol", 98401, 10.60},
                                     {"Frank Fortran", 526488, 9.75},
                                     {"Mary Apl", 765349, 10.50},
                                     {"Jeff Ada", 34645, 12.25},
                                     {"Anton Pascal", 127615, 10.0}
                                   };

    /* Get user input for the hours worked for each employee */
    getHours ( emp, SIZE );

    /* Calculate overtime for each employee */

    /* Calculate gross pay for each employee */

    /* Print column headers for each employee */

    /* Print employee data to the screen */
    printEmp ( emp, SIZE );

    return 0;

} /* main */
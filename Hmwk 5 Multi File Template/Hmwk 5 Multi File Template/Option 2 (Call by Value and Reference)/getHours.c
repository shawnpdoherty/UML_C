#include <stdio.h>
#include "employees.h"

/*******************************************************************
** Function: Get_Hours
**
** Purpose: Prompts for hours for a given employee
**
** Parameters:
**
**   id_number - employee clock number
**
** Returns: hours - number of hours worked in a given week
**
*******************************************************************/
float Get_Hours (long int id_number)
{
    float hours = 0; /* hours worked in a given week */

    /* add code here to read in hours for the employee */
    printf("\nEnter hours worked by emp # %06li: ", id_number);
    scanf ("%f", &hours);
    
    return (hours);

}
#include <stdio.h>
#include "employees.h"

/*******************************************************************
** Function: Get_Gross_Pay
**
** Purpose: Caculate weekly gross pay including overtime if applicable
**
** Parameters:
**
**   hours - number of hours worked in a given week
**   overtime - number of overtime hours worked in a given week
**   wage - employee hourly rate
**
** Returns: gross - total pay for employee including any overtime
**
*******************************************************************/
float Get_Gross_Pay (float hours, float overtime, float wage)
{
    float gross = 0; /* initialize gross pay */

    // if overtime hours present calculate gross
    if (overtime > 0.0)
    {
        // regular wage total
        gross = wage * STD_HOURS;
        // add overtime wages to total
        gross = gross + (overtime * (wage * OT_RATE));
    }
    // if no overtime, calculate gross pay
    else
    {
        gross = hours * wage;
    }

    return (gross);

}
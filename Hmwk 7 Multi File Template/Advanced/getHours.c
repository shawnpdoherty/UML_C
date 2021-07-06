#include <stdio.h>
#include "employees.h"

/*******************************************************************
** Function: Get_Hours
**
** Purpose: Prompts for hours for a given employee
**
** Parameters:
**          emp_ptr - pointer to array of structures
**          size - number of employee records 

** Returns: Nothing(void)
**
*******************************************************************/
void Get_Hours (struct employee * emp_ptr, int size)
{
    for (int i = 0; i < size; ++i)
    {   
        /* get id number of employee record and assign hours to that record */
        printf("\nEnter hours worked by emp # %06li: ", emp_ptr->id_number);
        scanf ("%f", &emp_ptr->hours);

        /* Lets update overtime and gross while we're here */
        if ( emp_ptr->hours > STD_HOURS)
        {
            // add any hours worked over standard hours to overtime
            emp_ptr->overtime = emp_ptr->hours - STD_HOURS;
            emp_ptr->gross = (emp_ptr->wage * STD_HOURS) + 
                (emp_ptr->overtime * (emp_ptr->wage * OT_RATE));
        } 
        else
        {
            emp_ptr->gross = emp_ptr->hours * emp_ptr->wage;
        }
        /* increment the array */
        ++emp_ptr;
    }
}
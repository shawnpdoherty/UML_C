#include <stdio.h>
#include "employees.h"

/*******************************************************************
** Function: Get_Employee_Info
**
** Purpose: Prompts for employee data(ID,Name,hourly rate)
**
** Parameters:
**
**   emp_ptr - pointer to an a array of structures
**   size - the number of employees to process.
**
** Returns: void
**
*******************************************************************/

void Get_Employee_Info (struct employee * emp_ptr, int size)
{
    for (int i = 0; i < NUM_EMPL; ++i)
    {
    printf("\nEnter employee %i clock/id number.\nNOTE: please omit any leading 0's:\n", i + 1);
    scanf ("%li", &emp_ptr->id_number);  
    printf("Enter first name for employee %li\n", emp_ptr->id_number);
    scanf("%s", &emp_ptr->employee_name.first_name);
    printf("Enter middle initial for employee %li\n", emp_ptr->id_number);
    scanf(" %c", &emp_ptr->employee_name.middle_initial);
    printf("Enter last name for employee %li\n", emp_ptr->id_number);
    scanf("%s", &emp_ptr->employee_name.last_name);
    printf("Enter hourly rate for %s %s\n", emp_ptr->employee_name.first_name, emp_ptr->employee_name.last_name);
    scanf ("%f", &emp_ptr->wage);
    ++emp_ptr;
    }    
};
#include <stdio.h>
#include "employees.h"

void Get_Employee_Info (struct employee employeeData [ ], int size)
{
    for (int i = 0; i < NUM_EMPL; ++i)
    {
    printf("\nEnter employee %i clock/id number.\nNOTE: please omit any leading 0's:\n", i + 1);
    scanf ("%li", &employeeData[i].id_number);  
    printf("Enter first name for employee %li\n", employeeData[i].id_number);
    scanf("%s", &employeeData[i].employee_name.first_name);
    printf("Enter middle initial for employee %li\n", employeeData[i].id_number);
    scanf(" %c", &employeeData[i].employee_name.middle_initial);
    printf("Enter last name for employee %li\n", employeeData[i].id_number);
    scanf("%s", &employeeData[i].employee_name.last_name);
    printf("Enter hourly rate for %s %s\n", employeeData[i].employee_name.first_name, employeeData[i].employee_name.last_name);
    scanf ("%f", &employeeData[i].wage);
    }    
};
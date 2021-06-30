/**********************************************************************
**
** HOMEWORK: #6 Intermediate
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
    struct employee employeeData[NUM_EMPL];

    for (int i = 0; i < NUM_EMPL; ++i)
    {
        //need to get employee name(first, last, middle), clock/id number, and hourly rate
        printf("\nEnter employee %i clock/id number.\nNOTE: please omit any leading 0's:\n", i + 1);
        scanf ("%li", &employeeData[i].id_number);
        printf("Enter first name for employee %li\n", employeeData[i].id_number);
        scanf("%s", &employeeData[i].employee_name.first_name);
        printf("Enter middle initial for employee %li\n", employeeData[i].id_number);
        scanf(" %c", &employeeData[i].employee_name.middle_initial);
        printf("Enter last name for employee %li\n", employeeData[i].id_number);
        scanf("%s", &employeeData[i].employee_name.last_name);
        printf("\nEnter hourly rate for %s %s\n", employeeData[i].employee_name.first_name, employeeData[i].employee_name.last_name);
        scanf ("%f", &employeeData[i].wage);
    }

    struct stats employeeStats;  
    for(int i = 0; i < NUM_EMPL; ++i)
    {
        printf("%s %s\n", employeeData[i].employee_name.first_name, 
        employeeData[i].employee_name.last_name);    
    }
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
    Output_Results_Screen (employeeData, employeeStats, NUM_EMPL);
    
    return (0); /* success */

} /* main */
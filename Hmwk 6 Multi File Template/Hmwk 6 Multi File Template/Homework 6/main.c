/**********************************************************************
**
** HOMEWORK: #5 Structures
**
** Name: Shawn Doherty
**
** Class: C Programming
**
** Date: 06/25/21 
**
** Description: This program prompts the user for the number of hours
** worked for each employee. It then calculates gross pay
** including overtime and displays the results in table. Functions
** and structures are used.
**
/**********************************************************************/

#include <string.h>
#include <stdio.h>
#include "employees.h"

int main ()
{
    /* Set up a local variable to store the employee information */
    struct employee employeeData[NUM_EMPL];
    
    /* = {
        { 98401, 10.60 },
        { 526488, 9.75 },
        { 765349, 10.50 },
        { 34645, 12.25 },
        { 127615, 8.35 }
    };
    */
    
    int i;  /* loop and array index */

    /* Call functions as needed to read and calculate information */
    for (i = 0; i < NUM_EMPL; ++i)
    {
        // get name information
        // set local vars for names
        char firstname[10];
        char middle;
        char lastname[10];
        float hourly_rate;

        //prompt for name input
        printf("\nEnter employee first name: \n");
        scanf ("%s", &firstname);
        printf("\nEnter employee middle initial: \n");
        scanf (" %c", &middle);
        printf("\nEnter employee last name: \n");
        scanf ("%s", &lastname);

        //assign firstname
        strcpy(employeeData[i].emp_name.first_name, firstname);
        // assign middle initial 
        employeeData[i].emp_name.middle_initial = middle;
        //assign last name
        strcpy(employeeData[i].emp_name.last_name, lastname);

        //get employee clock(id) number
        printf("\nEnter employee clock/id number: \n");
        scanf ("%li", &employeeData[i].id_number);

        printf("\nEnter employee wage: \n");
        scanf("%f\n", &hourly_rate);
        employeeData[i].wage = hourly_rate;

        printf("%s, %s %c : %li\n", employeeData[i].emp_name.last_name, employeeData[i].emp_name.first_name, employeeData[i].emp_name.middle_initial, employeeData[i].id_number);
        /* Prompt for the number of hours worked by the employee */
        employeeData[i].hours = Get_Hours (employeeData[i].id_number);

        /* Add other function calls as needed to calculate overtime and gross */
        employeeData[i].overtime = Get_Overtime_Hours(employeeData[i].hours);

        /* Function call to calculate gross pay */
        employeeData[i].gross = Get_Gross_Pay(employeeData[i].hours, employeeData[i].overtime, employeeData[i].wage);

    }

    /* Function call to output results to the screen */
//    Output_Results_Screen (employeeData, NUM_EMPL);
    
    return (0); /* success */

} /* main */
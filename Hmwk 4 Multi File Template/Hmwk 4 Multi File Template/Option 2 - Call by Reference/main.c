//-----------------------------------------------------------------------------
//
// Homework: 3 Call by reference only
// with Optional Total and Average
// multiple file project
//
// Name: Shawn Doherty
//
// Template provided by : Prof. Tim Niesen.
//
// Class: C Programming, Summer 2021
//
// Date: 6/21/2021
//
// Description: Write a C program that will calculate the gross pay and 
// overtime hours for a set of employees.              
//
//
//-----------------------------------------------------------------------------


#include <stdio.h>
#include "employees.h"


int main ()
{

    /* Variable Declarations */

    long  int clock_num [NUM_EMPL] = {98401,526488,765349,34645,127615}; /* ID */
    float hours_worked [NUM_EMPL];      // array for number of hours worked
    float overtime_hours [NUM_EMPL];    // array for number of overtime hours
    float gross [NUM_EMPL];             // array for gross pay
    float wage[NUM_EMPL] = {10.60,9.75,10.50,12.25,8.35}; /* hourly wage rate */

    /* Function call to get hours worked for each employee */
    getHours (clock_num, hours_worked, NUM_EMPL);

    /* Function call to calculate overtime */
    getOvertimeHours (overtime_hours, hours_worked, NUM_EMPL);

    /* Function call to calculate gross pay */
    getGross (overtime_hours, hours_worked, wage, gross, NUM_EMPL);

    /* Function call to output results to the screen */
    createReport (clock_num, hours_worked, wage, overtime_hours, gross, NUM_EMPL);

    return (0);
}
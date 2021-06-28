#include <stdio.h>
#include "employees.h"

//**************************************************************/ 
// Function: getGross  
// 
// Purpose: Obtains input from arguments, the number of hours worked 
// ,hours of overtime, and wage per employee and stores the results 
// in an array that is passed back to the calling program by reference. 
// 
// Parameters: 
//
// ot_hrs - Array of overtime hours worked by an employee.
// emp_hrs - Array of number of hours worked by an employee
// hourly_rate - Array of hourly rate per employee
// gross_pay - Array of gross pay per employee.
// size - Number of employees to process 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/

void getGross(float ot_hrs[], float emp_hrs[], float hourly_rate[], float gross_pay[], int size)
{
    int count; /* loop counter */ 
    
    // cycle through arrays
    for (count = 0; count < size; ++count)
    {
        // check for overtime and if there are overtime hours calculate overtime
        if (ot_hrs[count] > 0.0)
        {
            // start gross pay as the rate multipled by the standard hours
            gross_pay[count] = hourly_rate[count] * STD_HOURS;
            // add to gross pay the overtime hours multiplied by the overtime rate
            gross_pay[count] = gross_pay[count] + (ot_hrs[count] * (hourly_rate[count] * OVERTIME_RATE));
        }
        // otherwise, there is no overtime and the gross pay is hours worked multiplied by hourly rate. 
        else
        {
            gross_pay[count] = emp_hrs[count] * hourly_rate[count];
        }
    }
}
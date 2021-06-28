#include <stdio.h>
#include "employees.h"

//**************************************************************/ 
// Function: getOvertimeHours  
// 
// Purpose: Obtains input from argument, an array containing employee 
// hours worked.  If the employee worked more than standard hours
// Overtime hours are calculated and the results are stored in an array 
// that is passed back to the calling program by reference. 
// 
// Parameters: 
//
// ot_hrs - Array of employee overtime hours.
// emp_hrs - Array of number of hours worked by an employee
// size - Number of employees to process 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/

void getOvertimeHours (float ot_hrs[], float emp_hrs[], int size)
{
    int count; /* loop counter */ 

    for (count = 0; count < size; ++count)
    {
        if (emp_hrs[count] > STD_HOURS)
        {
            ot_hrs[count] = emp_hrs[count] - STD_HOURS;
        }
    }
}

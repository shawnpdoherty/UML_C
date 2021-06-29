#include <stdio.h>
#include "employees.h"

//**************************************************************/ 
// Function: getOvertimeHours  
// 
// Purpose: Determine number of hours worked greater than standard hours 
//
// Parameters: 
//
// ot_hrs - Array of employee overtime hours.
// emp_hrs - Array of number of hours worked by an employee
// size - Number of employees to process 
// 
// Returns: overtimeHours - number of overtime hours worked in a given week
//  
//**************************************************************/
float Get_Overtime_Hours (float hours)
{
    float overtimeHours = 0; /* initialize overtime hours */

    // determine if employee worked more than standard hours
    if (hours > STD_HOURS)
    {
        // add any hours worked over standard hours to overtime
        overtimeHours = hours - STD_HOURS;
    }
    
    return (overtimeHours);
}
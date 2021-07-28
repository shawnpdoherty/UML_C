//*******************************************************************
//
//  Name:  processEmp.c
//
//  Purpose: File contains functions for reading input hours as
//           well as calculating payroll data.
//
//*******************************************************************

#include <stdio.h>
#include "employees.h"

//********************************************************************
// Function: getEmployeeHours()
//
// Purpose: Query the user for hours worked for the employee.
//
// Parameters:
//   empDataPtr - a pointer to a structure of type "employee"
//                containing employee info
//
// Returns: float (number of hours worked)
//
//********************************************************************
float getEmployeeHours(EMPLOYEE * empDataPtr)
{
  float hours=0;     // local variable to read user input into

  // prompt the user with the employee name.
  printf("Enter %s hours worked: ", empDataPtr->empName.first);
  // read in the number of hours worked
  scanf("%f", &hours);
 
  return hours;
}

//********************************************************************
// Function: getEmpmployeeOvertimeHour()
//
// Purpose: Calculate the number of hours the employee worked
//          over the "STD_HOURS" number.
//
// Parameters:
//   empDataPtr - a pointer to a structure containing employee info.
//
// Returns: float (overtime hours worked)
//
//********************************************************************
float getEmployeeOvertimeHours(EMPLOYEE * empDataPtr)
{
  
  return ((empDataPtr->hours <= STD_HOURS) ? 0.0 : empDataPtr->hours - STD_HOURS);
}

//********************************************************************
// Function: calculateEmployeeGrossPay()
//
// Purpose: Calculate the weekly gross pay from the employee
//          data structure.
//
// Parameters:
//   empDataPtr - a pointer to a structures of type "employee"
//                containing employee info.
//
// Returns: struct employee
//
//********************************************************************
void calculateEmployeeGrossPay(EMPLOYEE * empDataPtr)
{
  // NONEXEMPT employee: factor in overtime pay 
  if (empDataPtr->jobType == NONEXEMPT) {
    empDataPtr->gross = (empDataPtr->hours * empDataPtr->wage) +
                    (empDataPtr->overtime * empDataPtr->wage * OT_FACTOR);
  }
  // EXEMPT employee: earns no overtime pay. 
  else {
    float hours =           // hours the exempt employee worked
      (empDataPtr->hours > STD_HOURS) ? STD_HOURS : empDataPtr->hours;
    
    empDataPtr->gross = hours * empDataPtr->wage;
  }
}
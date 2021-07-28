//*******************************************************************
//
//  Name:  printEmp.c
//
//  Purpose: File contains functions for displaying employee payroll
//           and personal information as well as the company's weekly
//           total and average payroll data
//
//*******************************************************************

#include <stdio.h>
#include <string.h>
#include "employees.h"


//********************************************************************
// Function: outputEmployeePersonalInfo()
//
// Purpose: generate a formatted output of the input employee's
//          personal information. 
//
// Parameters:
//   empDataPtr - a pointer to an array of "employee" structures
//                containing employee info.
//
// Returns: void
//
//********************************************************************

void outputEmployeePersonalInfo(EMPLOYEE * nodePtr)
{

  char temp[20]="";      // buffer to store the formatted employee name.
  
  // print the header for the output columns
  
  printf("\n%-7s%-34s%-15s\n", "","Employee","Start Date");
  printf("%-18s%-22s%-4s%-4s%-6s%-11s%-10s\n","Name", "Address", "Day",
	 "Mon", "Year", "Bonus", "Status");
  for (int i = 0; i < 2; i++)
    printf("-------------------------------------");
  printf("\n");

  // cycle through each employee printing their name, address, start date,
  // bonus and job type.
  
   while (nodePtr != NULL) {
    
        // package the name, "last, first middle" into a single string.
    formatNameString(&nodePtr->empName, temp);
    
    printf("%-18s%-22s%-4d%-4d%-6d$%-10.2f%-8s\n",
	    temp, 
            nodePtr->address, 
            nodePtr->startDate.day,
	    nodePtr->startDate.month, 
            nodePtr->startDate.year,
	    nodePtr->bonus, 
            (nodePtr->jobType) ? "Exempt" : "Non Exempt");

        // clear the temporary buffer
    temp[0]='\0';
    nodePtr = nodePtr->next;
  }
}

//********************************************************************
// Function: outputEmployeePayrollInfo()
//
// Purpose: generate a formatted payroll data output for all employees.
//
// Parameters:
//   empDataPtr - a pointer to an array of "employee" structures
//                containing all employee info.
//
// Returns: void
//
//********************************************************************

void outputEmployeePayrollInfo(EMPLOYEE * nodePtr)
{

  char temp[20]="";      // buffer to store the formatted employee name.
  char *tmpPtr = temp;   // pointer to char buffer 
   
  // print the header to identify the payrol data columns
  
  printf("\n%-18s%-9s%-8s%-8s%-8s%-8s\n", "Name", "Clock","Wage",
	 "Hours","OT","Gross");
  printf("----------------------------------------------------------\n");

  // print the name and wage info for each employee
  
  while (nodePtr != NULL) {
    
    // package the name, last, first and middle into a single string.
    formatNameString(&nodePtr->empName, tmpPtr);

    // print the formatted payroll data 
    printf("%-18s%06li   %-8.2f%-8.1f%-8.2f%-8.2f\n",
	   tmpPtr, nodePtr->id_number, nodePtr->wage,
	   nodePtr->hours, nodePtr->overtime, nodePtr->gross);
    
    // clear the temporary buffer (for the name string)
    temp[0]='\0';
    nodePtr = nodePtr->next;
  }
  
  return;
}


//********************************************************************
// Function: outputEmployeeSummaryData()
//
// Purpose: Calculate the sum total for all employees wage, hours,
//          overtime and gross. Then generate a formatted output of
//          the total and average of each payroll category. Also output
//          the minimum and maximum values for each category. 
//
// Parameters:
//   empDataPtr - a pointer to an array of "employee" structures
//                containing all employee info.
//
// Returns: void
//
//********************************************************************

void outputEmployeeSummaryData(EMPLOYEE * nodePtr)
{
  float totalWage =           // local variable (sum of all employee wages)
    getTotal(nodePtr, WAGE_ID);
  float totalHours =          // local variable (sum of all hours worked)
    getTotal(nodePtr, HOURS_ID);
  float totalOvertime =       // local variable (sum of all overtime hours)
    getTotal(nodePtr, OT_ID);
  float totalGross =          // local variable (sum of all gross pay)
    getTotal(nodePtr, GROSS_ID);

  printf("----------------------------------------------------------\n");

  int empCount = getEmployeeCount(nodePtr);
  
  // print the totals of the payroll categories
  printf("%-18s%-9s%-8.2f%-8.1f%-8.2f%-8.2f\n", "", "Total", totalWage,
	 totalHours, totalOvertime, totalGross);

  // print the average values of the payroll categories
  printf("%-18s%-9s%-8.2f%-8.1f%-8.2f%-8.2f\n", "", "Average",
	 totalWage/empCount, totalHours/empCount,
	 totalOvertime/empCount, totalGross/empCount);

  // print the minimum values of the payroll categories
  printf("%-18s%-9s%-8.2f%-8.1f%-8.2f%-8.2f\n", "", "Minimum",
	 getExtremeValue(nodePtr, WAGE_ID, MIN_VALUE),
	 getExtremeValue(nodePtr, HOURS_ID, MIN_VALUE),
	 getExtremeValue(nodePtr, OT_ID, MIN_VALUE),
	 getExtremeValue(nodePtr, GROSS_ID, MIN_VALUE));

  // print the maximum values of the payroll categories
  printf("%-18s%-9s%-8.2f%-8.1f%-8.2f%-8.2f\n", "", "Maximum",
	 getExtremeValue(nodePtr, WAGE_ID, MAX_VALUE),
	 getExtremeValue(nodePtr, HOURS_ID, MAX_VALUE),
	 getExtremeValue(nodePtr, OT_ID, MAX_VALUE),
	 getExtremeValue(nodePtr, GROSS_ID, MAX_VALUE));
    
  return;
}
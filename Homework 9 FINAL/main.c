//*********************************************************************
//
// HOMEWORK: #8 Linked List with Dynamic memory allocation
//
// Name: J. Student
//
// Class: C Programming
//
// Date: July 16, 202x
//
// Description: This program prompts the user for the number
// hours worked for each employee. It then calculates gross pay
// including overtime and displays the results in table. 
// Functions and structures are used.
//
//********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"

// constants
#define EMPLOYEE_DATA_RECORD_COUNT 5 

// Global file pointer for employee input data
FILE * inputFile;


int main ()
{

  // Important to open the file only once in order to read the whole file.
  inputFile = fopen("data.txt", "r"); 
  if (inputFile == NULL) {
    printf("input data file could not be opened\n");
    return 1;
  }

  EMPLOYEE * head_ptr = NULL;      // pointer to the first Employee
  EMPLOYEE * current_ptr= NULL;    // pointer to the current Employee
  EMPLOYEE * temp_node;            // newly malloc'ed data structure to
                                         // add to the linked list.
  
  // load the newEmployee structure with with data from "data.txt" file
  // and insert that employee onto the linked list

  for (int i=0; i < EMPLOYEE_DATA_RECORD_COUNT; i++) {

    // read the data from file (getEmployeeInfo) then allocate memory for
    // that employee (addNode) and insert onto the linked list.

    if (current_ptr == NULL) {   // first node added to the list
      
      current_ptr = head_ptr = addNode(getEmployeeInfo());
      
    } else {

      current_ptr->next = addNode(getEmployeeInfo());
      current_ptr = current_ptr->next;

    }
  }

  // read in the employee hours worked, determine overtime hours
  // and calculate employee gross pay for each employee.
  
  for (current_ptr = head_ptr; current_ptr != NULL; current_ptr = current_ptr->next) {
    
    current_ptr->hours = getEmployeeHours(current_ptr);

    current_ptr->overtime = getEmployeeOvertimeHours(current_ptr);

    calculateEmployeeGrossPay(current_ptr);
  }
  
    
  // generate the employee payroll output
  outputEmployeePayrollInfo(head_ptr);

  // generate the summary payroll output (totals, averages, min and max)
  outputEmployeeSummaryData(head_ptr);

  // query for employee personal information
  char in;                 // char buffer to read input character
  
  printf("\nDo you want to see the employee personal info? (y/n): ");
  scanf(" %c", &in);
  if (in == 'y')
    outputEmployeePersonalInfo(head_ptr);

  // release all allocated memory back onto the heap and close the input
  // data file.
  freeSystemResources(head_ptr, inputFile);
  
  return (0); /* success */
    
} /* main */
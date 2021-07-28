//*******************************************************************
//  Name:  employees.c
//
//  Purpose:  contains Employee specific functions
//
//*******************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"


/* getEmployeeInfo refernces this global variable from main.c */
extern FILE *inputFile;

//********************************************************************
// Function: getEmployeeInfo()
//
// Purpose:    Read data from the input file into the employee
//             structure member data. 
//
// Parameters:  none
//
// Returns: pointer to Employee data structure
//
//********************************************************************
EMPLOYEE getEmployeeInfo(void)
{

  char fin[50];              // buffer for file input
  
  EMPLOYEE empData;   // structure to fill and return to caller

  // read each field from the data.txt input file. Assign the data to
  // the appropriate Employee structure members. Note: fscanf() default
  // delimeter is space " ". 
  
  fscanf(inputFile, "%s", fin);
  strcpy(empData.empName.first, fin);   // strcpy() string data
  
  fscanf(inputFile, "%s", fin);
  strcpy(empData.empName.middle, fin);  // strcpy() string data

  fscanf(inputFile, "%s", fin);
  strcpy(empData.empName.last, fin);   // strcpy() string data

  fscanf(inputFile, "%s", fin);
  empData.id_number = atoi(fin);       // convert from ascii to integer

  fscanf(inputFile, "%s", fin);
  empData.wage = atof(fin);            // convert from ascii to float
  
  fscanf(inputFile, "%[^;]", fin);  // use ; delimeter for address since 
  strcpy(empData.address, fin);     // the address contains spaces. (See
                                    // Kochan page 355) [...] and data.txt.
  fscanf(inputFile, "%s", fin);     // trash the ';' delimiting char

  fscanf(inputFile, "%s", fin);
  empData.startDate.day = atoi( fin);  // convert from ascii to integer

  fscanf(inputFile, "%s", fin);
  empData.startDate.month = atoi(fin); // convert from ascii to integer

  fscanf(inputFile, "%s", fin);
  empData.startDate.year = atoi(fin);  // convert from ascii to integer

  fscanf(inputFile, "%s", fin);
  empData.bonus = atof(fin);           // convert from ascii to float

  fscanf(inputFile, "%s", fin);
  empData.jobType = atoi(fin);         // convert from ascii to integer
  
  fscanf(inputFile, "%s", fin);
  empData.hours, atof(fin);            // convert from ascii to float

  fscanf(inputFile, "%s", fin);
  empData.overtime, atof(fin);         // convert from ascii to float

  fscanf(inputFile, "%s", fin);
  empData.gross, atof(fin);            // convert from ascii to float

  return empData;
}

//********************************************************************
// Function: addNode()
//
// Purpose:  add a Node of type employee to the linked list. Set the
//           Node next pointer to NULL;
//
// Parameters:
//   struct Employee newEmp - structure containing data describing the
//                            employee to add to the data base.
//
// Returns:
//   pointer to newly allocated Employee structure
//
//********************************************************************

EMPLOYEE * addNode(EMPLOYEE newEmp) 
{
  EMPLOYEE * temp;

  temp = (EMPLOYEE *) malloc (sizeof(EMPLOYEE));
  temp->next = NULL;

  temp->empName = newEmp.empName;
  strcpy(temp->address, newEmp.address);
  temp->startDate = newEmp.startDate;
  temp->bonus = newEmp.bonus;
  temp->jobType = newEmp.jobType;
  temp->id_number = newEmp.id_number;
  temp->wage = newEmp.wage;
  temp->hours = newEmp.hours;
  temp->overtime = newEmp.overtime;
  temp->gross = newEmp.gross;

  return temp;
}
  
//********************************************************************
// Function: getEmployeeCount()
//
// Purpose: traverse the linked list of employees counting the number
//          until the nextPtr = NULL.
//
// Parameters:
//   struct Node* nodePtr - pointer to the first (head) Node in the
//                          linked list
//
// Returns: int (the count or number of Nodes in the list)
//
//********************************************************************
int getEmployeeCount( EMPLOYEE* nodePtr)
{
  int count = 0;

  while (nodePtr != 0) {
    count++;
    nodePtr= nodePtr->next;
  }
  
  return count;
}

//********************************************************************
// Function: getTotal()
//
// Purpose: Calculate the sum total for all employees payroll data.
//          Either the wage, hours, overtime, or gross are summed.
//
// Parameters:
//   empDataPtr - a pointer to a linked list of "employee" structures
//                containing all employee info.
//   id         - indicate which payroll category to sum 
//
// Returns: float (the total value calculated)
//
//********************************************************************

float getTotal(EMPLOYEE* nodePtr, int id)
{
  float localTotal = 0;      // sum of the "id" payroll category

  // sum the wage, hours, overtime or gross values of each employee.
  switch (id)
    {
    case WAGE_ID:
      for (; nodePtr != NULL; nodePtr = nodePtr->next)
	localTotal += nodePtr->wage;
      break;
      
    case HOURS_ID:
      for (; nodePtr != NULL; nodePtr = nodePtr->next)
	localTotal += nodePtr->hours;
      break;
      
    case OT_ID:
      for (; nodePtr != NULL; nodePtr = nodePtr->next)
	localTotal += nodePtr->overtime;
      break;
      
    case GROSS_ID:
      for (; nodePtr != NULL; nodePtr = nodePtr->next)
	localTotal += nodePtr->gross;
      break;
      
    default:
      printf("getTotal(): unknown input\n");
    }  // end switch
      
  return localTotal;
}

//********************************************************************
// Function: getExtremeValue()
//
// Purpose: Search the input employee data structure "nodePtr" to
//          find the minimum or maximum value of the payroll
//          category specified in the "id" input parameter. Return
//          min or max based upon the "value" input parameter.
//
// Parameters:
//   empDataPtr - a pointer to a linked list of "employee" data structures
//                containing all employee info.
//   id         - indicate which payroll category to search.
//   value      - indicates to return Min or Max.
//
// Returns: float (the min or max value found)
//
//********************************************************************

float getExtremeValue(EMPLOYEE * nodePtr, int id, int value)
{
  int empCt = getEmployeeCount(nodePtr);  // number of employees in database
  
  float numbers[empCt];          // array for each value within the category 
  float *numPtr = numbers;       // pointer to array for values

  // fill the numPtr array with either wage, hours, overtime or gross
  // values from each employee.
  
    switch (id)
    {
    case WAGE_ID:
      while ( nodePtr != NULL) {
	*numPtr++ = nodePtr->wage;
	nodePtr= nodePtr->next;
      }
      break;

    case HOURS_ID:
      while ( nodePtr != NULL) {
	*numPtr++ = nodePtr->hours;
	nodePtr= nodePtr->next;
      }
      break;

    case OT_ID:
      while ( nodePtr != NULL) {
	*numPtr++ = nodePtr->overtime;
	nodePtr= nodePtr->next;
      }
      break;

    case GROSS_ID:
      while ( nodePtr != NULL) {
	*numPtr++ = nodePtr->gross;
	nodePtr= nodePtr->next;
      }
      break;
    }  // end switch

    numPtr = numbers;         // reset the numPtr to point to the 1st float

    // return the Min or Max of the payroll category
    return (value == MIN_VALUE) ? fMin(numPtr, empCt) : fMax(numPtr, empCt);
}

//********************************************************************
// Function: formatNameString()
//
// Purpose: Change the Name structure's members first, middle and last
//          as "last, first middle". 
//
// Parameters:
//   struct Name *lname - pointer to "name" structure containing members
//                        first, middle and last
//   char *buffer  - pointer to an empty string that is assigned the
//                   formatted name string used by the calling function.
//
// Returns: void
//
//********************************************************************
void formatNameString(NAME *lname, char *buffer)
{
    strcat(buffer, lname->last);
    strcat(buffer, ", ");
    strcat(buffer, lname->first);
    strcat(buffer, " ");
    strcat(buffer, lname->middle);
}
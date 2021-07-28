//*******************************************************************
//
//  Name:  utility.c
//
//  Purpose: File contains useful utility functions for processing
//           data
//
//  Functions: fMin - returns the minimum float value
//             fMax - returns the maximum float value
//             freesystemResources - frees up allocation space from a list
//
//*******************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "employees.h"

//************************************************************************
//  Function: fMin()
//
//  Purpose:  return the smallest of input float parameter values
//
//  Parameters:
//     float *input  - pointer to an array of float values
//
//  Returns: float (the smallest value in the input array)
//
//***********************************************************************

float fMin(float *input, int count)
{
  float minVal = input[0];     // holds the smallest value
  
  // loop through the input[] array assigning "minVal" the smallest value.
  for (int i = 1; i < count; i++, input++)
    minVal = (minVal < *(input+1)) ? minVal : *(input+1);

  return minVal;
}
//************************************************************************
//  Function: fMax()
//
//  Purpose:  return the smallest of input float parameter values
//
//  Parameters:
//     float *input - pointer to an array of float values
//
//  Returns: float (the largest value in the input array)
//
//***********************************************************************

float fMax(float *input, int count)
{
  float maxVal = input[0];   // holds the largest value

  // loop through the input[] array assigning "minVal" the smallest value.
  for (int i = 1; i < count; i++, input++)
    maxVal = (maxVal > *(input+1)) ? maxVal : *(input+1);
 
  return maxVal;
}


//********************************************************************
// Function:  freeSystemResources()
//
// Purpose:   release allocated memory back onto the heap and close
//            opened file(s).
//
// Parameters:
//     head_ptr   - pointer to the first employee in the Employee
//                  linked list
//     inputFile  - file pointer to the input data file
//
// Returns: void
//
//********************************************************************
void freeSystemResources(EMPLOYEE * head_ptr, FILE* inputFile)
{
  // free allocated memory
  EMPLOYEE * tmpPtr;
  
  /* clean and free up the linked list */
  while (head_ptr != NULL) {

    tmpPtr = head_ptr->next;
    free(head_ptr);
    head_ptr = tmpPtr;
  }

  fclose(inputFile);

}
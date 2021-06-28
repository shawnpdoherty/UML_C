//-----------------------------------------------------------------------------
//
// Homework: 4 
//
// Name: Shawn Doherty
//
// Template provided by : Prof. Tim Niesen.
//
// Class: C Programming, Summer 2021
//
// Date: 6/15/2021
//
// Description: Write a C program that will calculate the gross pay and 
// overtime hours for a set of employees.              
//
//
//-----------------------------------------------------------------------------
#include <stdio.h> 


/* constants */
#define NUM_EMPL 5 
#define OVERTIME_RATE 1.5f 
#define STD_WORK_WEEK 40.0f 

/* function prototypes */ 
/* I added one below to get you started */
void getHours (long int clockNumber[], float hours[], int size);


/* IMPORTANT:  Add other function prototypes here as needed */ 

int main() 
{ 

    /* Variable Declarations */ 

    long  int clockNumber[NUM_EMPL] = {98401,526488,765349,34645,127615}; /* unique ID */
    float gross[NUM_EMPL];     /* gross pay */
    float hours[NUM_EMPL];     /* hours worked in a given week */
    float overtime[NUM_EMPL];  /* overtime hours */
    float wageRate[NUM_EMPL] = {10.60,9.75,10.50,12.25,8.35}; /* hourly wage rate */

    /* Function call to get input from user. */ 
    getHours (clockNumber, hours, NUM_EMPL); 

    /* Function call to calculate overtime */ 

    /* Function call to calculate gross pay */ 

    /* Function call to output results to the screen */ 

    return (0); 

} 

//**************************************************************/ 
// Function: getHours  
// 
// Purpose: Obtains input from user, the number of hours worked 
// per employee and stores the results in an array that is 
// passed back to the calling program by reference. 
// 
// Parameters: 
//
// emp_num - Array of employee clock numbers.
// hrs - Array of number of hours worked by an employee
// size - Number of employees to process 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 

void getHours (long emp_num[], float emp_hrs[], int size) 
{ 

    int count; /* loop counter */ 

    /* Get Hours for each employee */ 
    for (count = 0; count < size; ++count) 
    { 
        printf("\nEnter hours worked by emp # %06li: ", emp_num[count]); 
        scanf ("%f", &emp_hrs[count]); 
    } 

    printf("\n\n"); 
} 

/* Add other functions here as needed */
/* ... remember your comment block headers for each function */ 


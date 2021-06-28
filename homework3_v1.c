//-----------------------------------------------------------------------------
//
// Homework: 3 
// Version 1. Base assignment 
//
// Name: Shawn Doherty
//
// Template provided by : Prof. Tim Niesen.
//
// Class: C Programming, Summer 2021
//
// Date: 6/8/2021
//
// Description: Write a C program that will calculate the gross pay and 
// overtime hours for a set of employees using arrays.              
//
//
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// constants
#define STD_HOURS 40.0      // set standard workweek hours
#define OVERTIME_RATE 1.5   // set overtime rate of pay
#define SIZE 5              // set number of employee timesheets to process

int main ( )
{
    // array to store employee clock number
    long int clock_num [SIZE] = {98401, 526488, 765349, 34645, 127615};
    float wage [SIZE] = {10.6, 9.75, 10.5, 12.25, 8.35}; // array hourly wage
    float hours_worked [SIZE];     // number of hours worked per week
    float overtime_hours [SIZE]; // array for number of hours
    float gross [SIZE];            // gross pay for week (wage * hours)
    FILE *outputfileptr;    // pointer to output file

    // open a file called home1.txt as writeable
    if ((outputfileptr = fopen("home1.txt", "w")) == (FILE *) NULL)
    {
        // stderr will print to screen
        fprintf(stderr, "Error, Unable to open file\n"); 
        exit(1);
    }
    // create file header I kept this formatted to 80 char line limit
    fprintf (outputfileptr, 
                "\n\t\tShawn Doherty, C Programming, "
                "Third Homework Assignment\n\n\n");
    fprintf (outputfileptr, "\tClock  Wage  Hours  OT  Gross Pay\n");
    fprintf (outputfileptr, 
                "\t------ ----- -----  ----  -------\n");
    
    // Prompt for num of employees to process
    printf ("***Pay Calculator (w/Overtime)***.\n");
    
    // iterate through each employee 
    for (int i = 0; i < SIZE; ++i)
    {
        // declare and initialize overtime hours and set to 0
        overtime_hours[i] = 0.0;

        // prompt user for hours for each employee
        printf ("Enter the number of hours employee %i worked: ", i + 1 );
        scanf ("%f", &hours_worked[i]);
        
        // overtime scenario handler for hours worked over standard  
        if (hours_worked[i] > STD_HOURS)
        {
            // caculate number of overtime hours
            overtime_hours[i] = hours_worked[i] - STD_HOURS;
            // calculate gross pay by adding overtime pay to standard wage at standard hours
            gross[i] = ( STD_HOURS * wage[i] ) + ( overtime_hours[i] * (OVERTIME_RATE * wage[i]));
        }
        
        // standard hourly pay
        else
        {
            gross[i] = hours_worked[i] * wage[i];
        }
        
        // print out employee information to a file 
        fprintf (outputfileptr, "\t%06i %5.2f %5.1f %5.1f %7.2f\n",
            clock_num[i], wage[i], hours_worked[i], overtime_hours[i], gross[i]);
    }
    return (0);
}

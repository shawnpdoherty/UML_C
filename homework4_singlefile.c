//-----------------------------------------------------------------------------
//
// Homework: 3 Call by reference only
// with Optional Total and Average
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
#include <stdlib.h>

// constants
#define STD_HOURS 40.0      // set standard workweek hours
#define OVERTIME_RATE 1.5   // set overtime rate of pay
#define NUM_EMPL 5          // set number of employee timesheets to process

// declare function prototypes
void getHours(long int clockNumber[], float hours[], int size);
void getOvertimeHours(float otHours[], float hours[], int size);
void getGross(float otHours[], float hours[], float rate[], float grossPay[], 
                    int size);
void createReport(long int clockNumber[], float otHours[], float hours[], 
                    float rate[], float grossPay[], int size);

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
// emp_hrs - Array of number of hours worked by an employee
// size - Number of employees to process 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 

void getHours (long emp_num[], float emp_hrs[], int size) 
{ 

    int count; /* loop counter */ 
    
    // Prompt for input
    printf ("***Pay Calculator (w/Overtime)***.\n");
    
    /* Get Hours for each employee */ 
    for (count = 0; count < size; ++count) 
    { 
        printf("\nEnter hours worked by emp # %06li: ", emp_num[count]); 
        scanf ("%f", &emp_hrs[count]); 
    } 

    printf("\n\n"); 
} 

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

//**************************************************************/ 
// Function: createReport  
// 
// Purpose: Obtains input from arguments in array form, the clock number 
// , wage, number of hours worked, overtime hours and gross pay 
// per employee and prints the results to a local file
// 
// Parameters: 
//
// emp_num - Array of employee clock numbers.
// emp_hrs - Array of number of hours worked by an employee
// ot_hrs - Array of hours of overtime worked per employee
// hourly_rate - Array of hourly rate per employee
// gross_pay - Array of gross pay per employee
// size - Number of employees to process 
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/

void createReport(long emp_num[], float emp_hrs[], float hourly_rate[], float ot_hrs[], float gross_pay[], int size)
{
    FILE *outputfileptr;    // pointer to output file
    
    // declare an array with values to count totals(wage,hour,ot,gross)
    // initialize values to 0.0
    float total [4] = {0.0, 0.0, 0.0, 0.0};
   
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
                "Fourth Homework Assignment\n\n\n");
    fprintf (outputfileptr, "\tClock#  Wage  Hours   OT    Gross\n");
    fprintf (outputfileptr, 
                "\t------  ----- -----  ----  -------\n");
    
    // iterate through array to print to file and update totals
    for (int i = 0; i < NUM_EMPL; ++i)
    {
        // print out employee information to a file 
        fprintf (outputfileptr, "\t%06i  %5.2f %5.1f %5.1f  %7.2f\n",
            emp_num[i], hourly_rate[i], emp_hrs[i], ot_hrs[i], gross_pay[i]);
        
        // update totals
        total[0] += hourly_rate[i]; // sub 0 for wage total
        total[1] += emp_hrs[i]; // sub 1 for hours total 
        total[2] += ot_hrs[i]; // sub 2 for ot total       
        total[3] += gross_pay[i]; // sub 3 for gross total    
    }

    // optional section
    fprintf (outputfileptr, 
                "\t------  ----- -----  ----  -------\n");
    // output totals
    fprintf (outputfileptr, "\tTotal   %5.2f %5.1f %5.1f  %7.2f\n",
            total[0], total[1], total[2], total[3]);  
    // output averages based on totals
    fprintf (outputfileptr, "\tAverage %5.2f %5.1f %5.1f  %7.2f\n",
            total[0]/NUM_EMPL, total[1]/NUM_EMPL, total[2]/NUM_EMPL, total[3]/NUM_EMPL);    

}

int main ( )
{
    // array to store employee clock number
    long int clock_num [NUM_EMPL] = {98401, 526488, 765349, 34645, 127615};
    float wage [NUM_EMPL] = {10.6, 9.75, 10.5, 12.25, 8.35}; // array hourly wage
    float hours_worked [NUM_EMPL];      // array for number of hours worked
    float overtime_hours [NUM_EMPL];    // array for number of overtime hours
    float gross [NUM_EMPL];             // array for gross pay

    /* Function call to get input from user. */ 
    getHours (clock_num, hours_worked, NUM_EMPL);
    
    /* Function call to populate overtime hours */
    getOvertimeHours (overtime_hours, hours_worked, NUM_EMPL);
    
    /* Function call to calculate gross pay */
    getGross (overtime_hours, hours_worked, wage, gross, NUM_EMPL);

    /* Function call to generate report */
    createReport (clock_num, hours_worked, wage, overtime_hours, gross, NUM_EMPL);
    
    return (0);
}

/* employees.h - common constants, type, and prototypes */

/* constants */
#define STD_HOURS 40.0      // set standard workweek hours
#define OVERTIME_RATE 1.5   // set overtime rate of pay
#define NUM_EMPL 5          // set number of employee timesheets to process
/* types */

/* function prototypes */
void getHours (long int clockNumber[], float hours[], int size);
void getOvertimeHours(float otHours[], float hours[], int size);
void getGross(float otHours[], float hours[], float rate[], float grossPay[], 
                    int size);
void createReport(long int clockNumber[], float otHours[], float hours[], 
                    float rate[], float grossPay[], int size);
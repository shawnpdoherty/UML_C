/* employees.h - to support common employee processing  */

/* Define Constants */
#define NUM_EMPL 5
#define STD_HOURS 40.0
#define OT_RATE 1.5

/* Define a global structure for stats */
struct stats
{
    // stats for totals
    float total_wage;
    float total_hours;
    float total_ot;
    float total_gross;
    //stats for maximum values
    float max_wage;
    float max_hours;
    float max_ot;
    float max_gross;
    //stats for minimum values
    float min_wage;
    float min_hours;
    float min_ot;
    float min_gross;
};


/* Define a global structure to pass employee data between functions */
struct employee
{
    char name[20];
    long id_number;
    float wage;
    float hours;
    float overtime;
    float gross;
};

/* define prototypes here for each function except main */
float Get_Hours (long int id_number);
float Get_Overtime_Hours (float hours);
float Get_Gross_Pay (float hours, float overtime, float wage);
void Output_Results_Screen (struct employee emp [ ], struct stats employeeStats, int size);
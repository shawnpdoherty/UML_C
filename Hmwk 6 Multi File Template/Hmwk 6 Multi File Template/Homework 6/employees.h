/* employees.h - to support common employee processing  */

/* Define Constants */
#define NUM_EMPL 5
#define STD_HOURS 40.0
#define OT_RATE 1.5

struct name
{
    char first_name[10];
    char middle_initial;
    char last_name[10];

};

/* Define a global structure to pass employee data between functions */
struct employee
{
    struct name emp_name;
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
void Output_Results_Screen (struct employee emp [ ], int size);
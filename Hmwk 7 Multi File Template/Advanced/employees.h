/* employees.h - to support common employee processing  */

/* Define Constants */
#define NUM_EMPL 5
#define STD_HOURS 40.0
#define OT_RATE 1.5

/* Define a global structure for stats */
struct stats
{
    /* stats for totals */
    float total_wage;
    float total_hours;
    float total_ot;
    float total_gross;
    /* stats for maximum values */
    float max_wage;
    float max_hours;
    float max_ot;
    float max_gross;
    /* stats for minimum values */
    float min_wage;
    float min_hours;
    float min_ot;
    float min_gross;
};

/* Define a global structure for name data */
struct name
{
    char first_name[20];
    char middle_initial;
    char last_name[10];
};


/* Define a global structure to pass employee data between functions */
struct employee
{
    long id_number;
    struct name employee_name;
    float wage;
    float hours;
    float overtime;
    float gross;
};

/* define prototypes here for each function except main */
void Get_Hours (struct employee * ptr, int size);
void Output_Results_Screen (struct employee * emp_ptr , struct stats * stats_ptr, int size);
void Get_Employee_Info (struct employee * ptr, int size);
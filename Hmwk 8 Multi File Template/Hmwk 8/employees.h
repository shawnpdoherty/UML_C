/* employees.h - common constants, types, and function prototypes */

/* define all constants here */
#define SIZE 5
#define STD_HOURS 40.0f
#define OT_RATE 1.5f

/* structure to hold stats */
struct stats
{
    /* stats for totals */
    float total_wage;
    float total_hours;
    float total_ot;
    float total_gross;
    /* stats for average */
    float avg_wage;
    float avg_hours;
    float avg_ot;
    float avg_gross;
};

/* Define a global structure for name data */
struct name
{
    char first_name[20];
    char middle_initial;
    char last_name[10];
};

/* type to hold employee information */
struct employee
     {
     int id_number;
     struct name employee_name;
     float wage;
     float hours;
     float overtime;
     float gross;
     struct employee *next;
     };

/* add function prototypes here if you wish */
void print_list(struct employee *emp1, struct stats *stats_ptr);
void Get_Ot_Gross (struct employee * emp_ptr);
void Get_Total_Average (struct employee * emp_ptr, struct stats *stats_ptr);
/* Add other fucntion prototypes here as needed */
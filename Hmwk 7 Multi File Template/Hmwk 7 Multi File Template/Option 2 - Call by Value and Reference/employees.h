/* employees.h - commmon constants, types, and function prototypes */

/* define all constants here */
#define SIZE       5
#define STD_HOURS 40.0f
#define OT_RATE 1.5f

/* type to hold employee information */
struct employee
{
     char name [20];  /* Employee first and last name */
     int id;          /* unique employee identifier */
     float wage;      /* hourly wage rate */
     float hours;     /* hours worked in a given week */
     float overtime;  /* hours worked after the standard work week */
     float gross;     /* total gross pay, standard pay + overtime pay */
};


/* add function prototypes here if you wish */
float getHours ( int id );
void printEmp ( struct employee * emp_ptr, int size );
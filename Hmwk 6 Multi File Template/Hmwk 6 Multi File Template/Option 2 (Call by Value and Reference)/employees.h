/* employees.h - to support common employee processing  */

/* Define Constants */
#define NUM_EMPL 5
#define STD_HOURS 40.0
#define OT_RATE 1.5

/* Define a global structure to pass employee data between functions */
/* Note that the structure type is global, but you don't want a variable */
/* of that type to be global. Best to declare a variable of that type */
/* in a function like main or another function and pass as needed. */

struct employee
{
    char name [20];
    long id_number;
    float wage;
    float hours;
    float overtime;
    float gross;
};

/* define prototypes here for each function except main */

float Get_Hours (long int id_number);
void Output_Results_Screen (struct employee emp [ ], int size);
/* add other function prototypes here */
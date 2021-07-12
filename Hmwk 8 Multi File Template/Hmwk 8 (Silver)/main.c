#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>    /* for toupper */
#include "employees.h"

/* Add Functions here as needed */

/*******************************************************************
** Function: Get_Ot_Gross
**
** Purpose: calculate employee Overtime and Gross Pay
**
** Parameters:
**          emp_ptr - pointer to employee node
** 
** Returns: Nothing(void)
**
*******************************************************************/
void Get_Ot_Gross (struct employee * emp_ptr)
{
if ( emp_ptr->hours > STD_HOURS)
        {
            // add any hours worked over standard hours to overtime
            emp_ptr->overtime = emp_ptr->hours - STD_HOURS;
            emp_ptr->gross = (emp_ptr->wage * STD_HOURS) + 
                (emp_ptr->overtime * (emp_ptr->wage * OT_RATE));
        } 
        else
        {
            emp_ptr->gross = emp_ptr->hours * emp_ptr->wage;
        }    
}

/*******************************************************************
** Function: Get_Total_Average
**
** Purpose: calculate total wage, hours, overtime and gross
**          calculate average wage, hours, overtime and gross
**
** Parameters:
**          emp_ptr - pointer to employee node
**          stats_ptr - pointer to stats structure
**           
** Returns: Nothing(void)
**
*******************************************************************/
void Get_Total_Average (struct employee * emp_ptr, struct stats *stats_ptr)
{
    struct employee *tmp;   /* tmp pointer value to current node */
    int i = 0;              /* counts the nodes printed          */
    for(tmp = emp_ptr; tmp ; tmp = tmp->next)
        {
            stats_ptr->total_wage += tmp->wage; // add to wage total
            stats_ptr->total_hours += tmp->hours; // add to hours total 
            stats_ptr->total_ot += tmp->overtime; // add to total                   
            stats_ptr->total_gross += tmp->gross; // add to gross total
            i++;
        }

    /* calculate averages */
    stats_ptr->avg_wage = stats_ptr->total_wage/i;
    stats_ptr->avg_hours = stats_ptr->total_hours/i;
    stats_ptr->avg_ot = stats_ptr->total_ot/i;
    stats_ptr->avg_gross = stats_ptr->total_gross/i;
}

/* Optional TODO - Add Challenge Functions here as needed */
/*******************************************************************
** Function: Get_Min_Max
**
** Purpose: calculate Minimum and Maximum for wage, hour, ot & gross
**
** Parameters:
**          emp_ptr - pointer to employee node
**          stats_ptr - pointer to stats structure    
**           
** Returns: Nothing(void)
**
*******************************************************************/
void Get_Min_Max (struct employee * emp_ptr, struct stats * stats_ptr)
{
    struct employee *tmp;   /* tmp pointer value to current node */
    
    tmp = emp_ptr; /* assign tmp to emp_ptr to init min vals */
    
    /* initialize minimum vals to the first value */ 
    stats_ptr->min_gross = tmp->gross;
    stats_ptr->min_hours = tmp->hours;
    stats_ptr->min_ot = tmp->overtime;
    stats_ptr->min_wage = tmp->wage;

    for(tmp = emp_ptr; tmp ; tmp = tmp->next)
    {
        /* CALCULATE MINIMUM VALUES */
        /* min wage */
        if( tmp->wage <= stats_ptr->min_wage)
        {
            stats_ptr->min_wage = tmp->wage;
        }
        // min hours
        if( tmp->hours <= stats_ptr->min_hours)
        {
            stats_ptr->min_hours = tmp->hours;
        }
        // min ot
        if(tmp->overtime <= stats_ptr->min_ot)
        {
            stats_ptr->min_ot = tmp->overtime;
        }      
        // min gross
        if(tmp->gross <= stats_ptr->min_gross )
        {
            stats_ptr->min_gross = tmp->gross;
        }       
        
            // Calculate Maximum values
        // max wage
        if (tmp->wage > stats_ptr->max_wage)
        {
            stats_ptr->max_wage = tmp->wage;
        }
        // max hours
        if(tmp->hours > stats_ptr->max_hours)
        {
            stats_ptr->max_hours = tmp->hours;
        }
        // max ot
        if(tmp->overtime > stats_ptr->max_ot)
        {
            stats_ptr->max_ot = tmp->overtime;
        }    
        // max gross
        if(tmp->gross > stats_ptr->max_gross)
        {
            stats_ptr->max_gross = tmp->gross;
        }      

    }
}

/*******************************************************************
** Function: Get_Employee_Info
**
** Purpose: prompts for thevarious input (name, clock, wage) 
** and then returns back the pointer
**
** Parameters:
**          current_ptr - pointer to employee node
** 
** Returns: Nothing(void)
**
*******************************************************************/
void Get_Employee_Info (struct employee * current_ptr)
{
    /* Prompt for Employee Name and Hours */
    printf("\nEnter first name for employee: ");
    scanf("%s", &current_ptr->employee_name.first_name);
    printf("\nEnter middle initial for employee: ");
    scanf(" %c", &current_ptr->employee_name.middle_initial);
    printf("\nEnter last name for employee: ");
    scanf("%s", &current_ptr->employee_name.last_name);
    printf("\nEnter hours worked: ");
    scanf ("%f", &current_ptr->hours);
    
    /* Read in Employee ID and Hourly Wage */
    printf("\nEnter employee ID: ");
    scanf("%i", & current_ptr -> id_number);

    printf("\nEnter employee hourly wage: ");
    scanf("%f", & current_ptr -> wage);
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/* FUNCTION:  main                                                            */
/*                                                                            */
/* DESCRIPTION:  This function will prompt the user for an employee           */
/*               id and wage until the user indicates they are finished.      */
/*               At that point, a list of id and wages will be                */
/*               generated.                                                   */
/*                                                                            */
/* PARAMETERS:   None                                                         */
/*                                                                            */
/* OUTPUTS:      None                                                         */
/*                                                                            */
/* CALLS:        print_list, Get_Ot_Gross, Get_Total_Average, Get_Min_Max     */
/*               Get_Employee_Info                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int main ()
{

    char   answer[80];       /* to see if the user wants to add more employees */
    int    more_data = 1;    /* flag to check if another employee is to be processed */
    char   value;            /* gets the first character of answer */

    struct employee *current_ptr,   /* pointer to current node */
                    *head_ptr;      /* always points to first node */
    
    /* Structure to store stats and initialize structure to zero values */
    struct stats employeeStats[] = {0};
    /* Pointer to the stats struct */
    struct stats *stats_ptr;
    /* set pointer to the beginning of the sats array */
    stats_ptr = employeeStats;

   /* Set up storage for first node */
    head_ptr = (struct employee *) malloc (sizeof(struct employee));
    current_ptr = head_ptr;

    /* create node and process each employee */
    while (more_data)
    {
        /* (silver)  call another function from main that prompts for the
        *  various input (name, clock, wage) and then returns back the pointer.
        */
        Get_Employee_Info(current_ptr);

        /* Call Function to calculate Overtime and Gross */
        Get_Ot_Gross(current_ptr);

        printf("\nWould you like to add another employee? (y/n): ");
        scanf("%s", answer);


        /* Ask user if they want to add another employee */
        if ((value = toupper(answer[0])) != 'Y')
        {
           current_ptr->next = (struct employee *) NULL;
           more_data = 0;
        }
        else
        {
           /* set the next pointer of the current node to point to the new node */
           current_ptr->next = (struct employee *) malloc (sizeof(struct employee));
           /* move the current node pointer to the new node */
           current_ptr = current_ptr->next;
         }
    } /* while */

    /* Call Function(s) to determine totals and averages */
    Get_Total_Average(head_ptr, stats_ptr);
    
    /* Optional TODO: Call Challenge Functions to determine min and max values */
    Get_Min_Max(head_ptr, stats_ptr);
    
    /* print out listing of all employee id's and wages that were entered */
    print_list(head_ptr, stats_ptr);

    printf ("\n\nEnd of program\n");

    return (0);

}
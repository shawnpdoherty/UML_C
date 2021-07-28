#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>    /* for toupper */
#include <string.h>   /* for strlen */
#include "employees.h"

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  print_list                                                       */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked             */
/*               list.  It will traverse the list from beginning to the        */
/*               end, printing the contents at each node.                      */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/

void print_list(struct employee *emp1, struct stats *stats_ptr)
{
    struct employee *tmp;   /* tmp pointer value to current node */
    int i = 0;              /* counts the nodes printed          */

    FILE *outputfileptr;    // pointer to output file

    // open a file called gold.txt as writeable
    if ((outputfileptr = fopen("gold.txt", "w")) == (FILE *) NULL)
    {
        // stderr will print to screen
        fprintf(stderr, "Error, Unable to open file\n"); 
        exit(1);
    }
        
    /* create file header */
    fprintf ( outputfileptr, "\n\t\tShawn Doherty, C Programming\n "
            "\t\tEighth Homework Assignment\n\n\n");
    fprintf (outputfileptr, "\t-----------------------------------------------------\n");
    fprintf (outputfileptr, "\tName                 Clock# Wage  Hours   OT    Gross\n");
    fprintf (outputfileptr, "\t-----------------------------------------------------\n");

    /* Start a beginning of list and print out each value               */
    /* loop until tmp points to null (remember null is 0 or false)      */
    for(tmp = emp1; tmp ; tmp = tmp->next)
    {
            fprintf (outputfileptr,"\t%s, %s %-*c %06li %5.2f  %4.1f %4.1f %8.2f\n",
            tmp->employee_name.last_name,
            tmp->employee_name.first_name,
            /* this formats the width of the entire name column */
            17 - (strlen(tmp->employee_name.first_name) +
            strlen(tmp->employee_name.last_name)),
            tmp->employee_name.middle_initial,
            tmp->id_number,
            tmp->wage,
            tmp->hours,
            tmp->overtime,
            tmp->gross);
        
        i++;           
    }

    /* print other members as well */
    //printf("\nEmployee ID: %6d, Wage: %8.2f\n",tmp->id_number,tmp->wage);
    fprintf (outputfileptr, "\t-----------------------------------------------------\n");
    
    // output totals
    fprintf (outputfileptr, "\tTotal:                      %5.2f %5.1f%5.1f  %7.2f\n",
        stats_ptr->total_wage,
        stats_ptr->total_hours,
        stats_ptr->total_ot, 
        stats_ptr->total_gross);  

    // output averages
    fprintf (outputfileptr, "\tAverage:                    %5.2f %5.1f%5.1f  %7.2f\n",
        stats_ptr->avg_wage, 
        stats_ptr->avg_hours, 
        stats_ptr->avg_ot, 
        stats_ptr->avg_gross); 
    
    // output minimum
    fprintf (outputfileptr, "\tMinimum:                    %5.2f %5.1f%5.1f  %7.2f\n",
        stats_ptr->min_wage, 
        stats_ptr->min_hours, 
        stats_ptr->min_ot, 
        stats_ptr->min_gross); 
    
    // output maximum
    fprintf (outputfileptr, "\tMaximum:                    %5.2f %5.1f%5.1f  %7.2f\n",
        stats_ptr->max_wage, 
        stats_ptr->max_hours, 
        stats_ptr->max_ot, 
        stats_ptr->max_gross); 
    
    
    fprintf(outputfileptr, "\n\nTotal Number of Employees = %d\n", i);

}
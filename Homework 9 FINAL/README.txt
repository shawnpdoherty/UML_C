Advanced Homework - Week 10

Each week I have asked you to do the homework assignment, this week you can relax and just
enjoy this advanced homework from Prof Tim.   Try it out after class ends if you have time.

The zip file contains all the files you need where I have taken our Homework 8 (Linked Lists) and extended it with concepts from Week 10.

See listing of files where I have incorporated 

- typedefs (for our Structure types) which I have extended with additional employee information
- extern statement (to show how to use a global variable, a file pointer,  between multiple program files)
- enum type (an employee job type can be either Exempt or Non Exempt)
- reading all data except the employee hours (which change week to week) from a file (data.txt)
- grouped functions together into logical files (instead of one file, one function)
- makefile to compile and build it

Below is a sample run so you can see how the program runs and what it would print.  Feel free
extend things even more if you wish with lots of different types.


./employeePayroll.exe
Enter Connie hours worked: 45
Enter Mary hours worked: 34.5
Enter Frank hours worked: 40.0
Enter Jeff hours worked: 23.5
Enter Anton hours worked: 39.9

Name              Clock    Wage    Hours   OT      Gross   
----------------------------------------------------------
Cobol, Connie J   098401   10.60   45.0    5.00    424.00  
Apl, Mary P       526448   9.75    34.5    0.00    336.38  
Fortran, Frank K  765349   10.50   40.0    0.00    420.00  
Ada, Jeff B       034645   12.25   23.5    0.00    287.88  
Pascal, Anton T   127615   10.00   39.9    0.00    399.00  
----------------------------------------------------------
                  Total    53.10   182.9   5.00    1867.25 
                  Average  10.62   36.6    1.00    373.45  
                  Minimum  9.75    23.5    0.00    287.88  
                  Maximum  12.25   45.0    5.00    424.00  

Do you want to see the employee personal info? (y/n): y

       Employee                          Start Date     
Name              Address               Day Mon Year  Bonus      Status    
--------------------------------------------------------------------------
Cobol, Connie J    12 Galacy Row        1   11  1968  $5000.00   Exempt  
Apl, Mary P        129 Galactica Way    3   6   1994  $1000.00   Non Exempt
Fortran, Frank K   17 Skywalker Ln.     22  7   1963  $2000.00   Exempt  
Ada, Jeff B        11 Battlefront Zone  27  12  1837  $2700.00   Non Exempt
Pascal, Anton T    16 Enterprise St.    12  12  1912  $1000.00   Exempt
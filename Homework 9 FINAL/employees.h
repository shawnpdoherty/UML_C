// employees.h - to support common employee processing

// Define constants

#define STD_HOURS 40.0
#define OT_FACTOR 0.5
#define EXEMPT    1
#define NONEXEMPT 0

#define WAGE_ID  0
#define HOURS_ID 1
#define OT_ID    2
#define GROSS_ID 3

#define MIN_VALUE 0
#define MAX_VALUE 1

// Data structures to support employee processing

enum jobClass {Exempt, NonExempt};

typedef struct date
{
  int day;                       // date - day
  int month;                     // date - month
  int year;                      // date - year
} DATE;

typedef struct name
{
  char first[20];
  char middle[20];
  char last[20];
} NAME;
	      
typedef struct employee
{
  NAME   empName;               // employee name
  char   address[30];           // employee street address
  DATE   startDate;             // employee start date
  float  bonus;                 // emploee anual cash bonus
  enum   jobClass jobType;      // EXEMPT or NONEXEMPT jobType
  long   id_number;             // employee ID number
  float  wage;                  // employee hourly wage
  float  hours;                 // number of hours worked
  float  overtime;              // number of overtime hours worked
  float  gross;                 // total weekly earnings before taxes
  struct employee  * next;      // pointer to next employee
} EMPLOYEE;

//  function prototypes

EMPLOYEE * addNode(EMPLOYEE newEmp);

int getEmployeeCount( EMPLOYEE * nodePtr);

float getTotal(EMPLOYEE * nodePtr, int id);

void formatNameString(NAME *lname, char *buffer);

float getExtremeValue(EMPLOYEE *nodePtr, int id, int value);

EMPLOYEE getEmployeeInfo(void);

void freeSystemResources(EMPLOYEE * head_ptr, FILE * inputFile);

float fMin(float *input, int count);

float fMax(float *input, int count);

void outputEmployeePersonalInfo(EMPLOYEE * nodePtr);

void outputEmployeePayrollInfo(EMPLOYEE * nodePtr);

void outputEmployeeSummaryData(EMPLOYEE * nodePtr);

float getEmployeeHours(EMPLOYEE * empDataPtr);

float getEmployeeOvertimeHours(EMPLOYEE * empDataPtr);

void calculateEmployeeGrossPay(EMPLOYEE * empDataPtr);
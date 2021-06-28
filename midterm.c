
#include <stdio.h>

struct date // structure with date information
    {
        int day; // hold day value
        int month; // hold month value
        int year; // hold year value
    };

struct name // structure for name information
    {
        char givenName[60]; //first and middle names
        char surName[60]; //last name
    };

struct holder // structure for passport holder information
    {
        struct name issuedToName; // name passport issued to
        struct date dateofBirth; // passport holder date of birth
        char gender; // single char M, F or others
        char birthPlace[100]; // location of birth
    };  

struct passport // structure for passport information
{
    char passPortnumber[10]; // Passport Number
    struct holder passportHolder; // name of passport holder
    struct date dateOfIssue; // date passport was issued
    struct date dateOfExpire; // date passport expires
    char countryOfIssue[4]; // alpha 3 code for country code       
    char passportType;  // single char "P" for personal, "S" for service, "D" for diplomatic    
};

int main()
{
    long int result = x_to_the_n(4, 10);
    printf("%li", result);


}
/*Provide the code need to DECLARE an array of structures that could store information about a group of passports.  
Do not write a program or worry about initializing the structure, all I am looking for is a set of structure types 
whose combined members would hold all the information found in a Passport, AND any supporting structures. 
Be careful on how you declare the members of a structure. 

Grading will be based on the flexibility of your design (i.e., define many structures and have structures within structures if necessary).

To figure out what information you need to collect, search on line for sample images of US Passports.  
NOTE: Don't go overboard such as having a structure with only one member just to create many structures.


*/
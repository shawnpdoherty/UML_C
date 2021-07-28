

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//********************************************************************
// Function: validPalindrom()
//
// Purpose: determine if a word or phrase is palindrome            
//
// Parameters:  
//             phrase - string array of char
//
// Returns: int 1(TRUE) for palindrome, 0(FALSE) if not palindrome. 
//********************************************************************

int validPalindrome(char phrase[])
{
    // create start and end points 
    int a = 0;
    int z = strlen(phrase) - 1;
  
    // iterate through phrase 
    while (a > z)
    {
        // if encounter a non-alpha character move right
        if (! isalpha(phrase[a]))
        {
            a++;
        }
        // if encounter a non-alpha character move left
        if (! isalpha(phrase[z]))
        {
            z--;
        }
        // convert to lowercase for comparison, exit if not match 
        if (tolower(phrase[a++]) != tolower(phrase[z--]))
        {
            //not palindrome; false
            return 0;
        }
    }
    // is plaindrome; true
    return 1;
}

// Driver program to test sentencePalindrome()
int main()
{
    printf("%i", validPalindrome("Ra,ce car!"));
    return 0;
}

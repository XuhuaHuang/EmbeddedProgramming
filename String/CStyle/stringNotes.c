/**
 * @file stringNotes.c
 * @author Xuhua Huang
 * @brief Notes on C-style strings with the string.h
 * 
 * Command to compile and run on Windows:
 * gcc -o CStringNotes.exe .\stringNotes.c
 * ./CStringNotes
 *
 * @version 1.1
 * @date 2021-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <string.h>  /* C-style string functions */

/* Function prototype - using forward declaration */
void clear(void);
void printStr(char, int);

int main(void)
{
    char name[20] = { "" }; 	// empty string
    char str1[20] = { "" }; 	// this looks more like an array to me
    char str2[20] = { "" }; 	// this is an array of 20 characters elements named str2
    char newStr[50] = { "" }; 	// temporary array for swapping demo

    // function sizeof() determines the size of the array
    printf("sizeof name = %d\n", (int)sizeof(name));
    
    
    // IMPORTANT!! When using scanf with strings, you must include the size of the array (sizeof(name)) )
    printf("Enter your name: "); 
    scanf_s("%s", &name, (unsigned int)sizeof(name)); // it might mean there is enough room for this input to go in
    clear(); // clear the input stream
    // calling the function without feeding any inputs nor receiving any feedbacks
    
    // The function puts is like printf except for strings only
    puts("Enter a noun: "); // like printf - put string (to the console)
    
    // The function gets is like scanf except for strings only
    gets_s(str1, sizeof(str1)); // scanf - get string (safe)
    //when using a gets_s, you do NOT need to put that & thing, and you don't have to clear
    puts(str1); // print the entire string
    
    puts("Enter another noun: ");
    gets_s(str2, sizeof(str2)); // scanf_s - get string (safe)
    puts(str2);

    // string length function will determine that actual number of characters in the string 
    int length = strlen(str1); // strlen(the name of the array) 
    printf("%d\n", length); //why do we need strlen function if we have already got sizeof function??

    // Convert string to lowercase one character at a time using the tolower() function
    for (int i = 0; i < strlen(str1); i++)
    {
        // convert and replace
        // one character at a time
        str1[i] = tolower(str1[i]); 
    }
    puts(str1);

    // Convert string to uppercase one character at a time using the toupper() function
    for (int i = 0; i < strlen(str1); i++)
    {
        // one character at a time
        str1[i] = toupper(str1[i]);
    }
    puts(str1);

    // Add letter 's' if necessary
    if (str1[strlen(str1) - 1] != 's')  // comparing to see if the last letter of str1 is an 's'
    // using the function strlen(string name) to determine the last character
    {
        // The function strcat() concatenates a string
        // This will add a space " " to whatever is in str1
        strcat_s(str1, sizeof(str1), " ");
        
        // This will add a the letter s to whatever is in str1
        strcat_s(str1, sizeof(str1), "s");
    }
    // Alphabetize using strcmp()
    // return value	and indication:
    //	<0	the first character that does not match has a lower value (alphabetically) in str1 than in str2
    //	==0	the contents of both strings are equal
    //	>0	the first character that does not match has a greater value (alphabetically)in str1 than in str2
    int rtnValue = strcmp(str1, str2);

    // wrong order
    if (rtnValue > 0)
    {
        // Swap Strings
        // The function strcpy_s() - string copy (safe) - will overwrite the first string with the second string
        strcpy_s(newStr, sizeof(newStr), str2); // newStr is overwritten by str2
        strcpy_s(str2, sizeof(str2), str1);		// str2 is overwritten by str1
        strcpy_s(str1, sizeof(str1), newStr);	// str1 is overwritten by newStr 
    }
    else // correct order
    {
        // Combine into one string
        // very likely the new string requires a new size as well
        // function strcat_s() - string concatenate (safe) - append string to the original
        strcpy_s(newStr, sizeof(newStr), str1); // newStr is overwritten by str1
        strcat_s(newStr, sizeof(newStr), " ");	// space " " is added to the end of newStr 
        strcat_s(newStr, sizeof(newStr), str2);	// str2 is added to the end of newStr
        puts(str1);  // print str1
        puts(str2);	 // print str2
        puts(newStr);  // print newStr
    }

    
    // function printStr() is called here passing newStr to the function
    printStr(newStr, sizeof(newStr));  

    // OR Using sprintf to combine into one string - overwrite newStr with formatted print ("str1 str2") 
    // sprintf prints to a string instead of the console (like printing to pdf instead of the printer)
    sprintf_s(newStr, sizeof(newStr), "%s %s", str1, str2);
    puts(newStr); 
        
    // function atoi() - convert string array to a number (integer) since math cannot be performed on numbers that are characters
    char numstr[5] = { '5', '1', '2', '3' };
    int number = atoi(numstr);
    //printf("number as string %d\n", atoi(numstr));
    printf("%d\n", number);

    // convert integer to string using sprintf
    int num = 20;
    sprintf_s(numstr, sizeof(numstr), "%d", num);
    puts(numstr);

    return 0;
}

// function to print a charater array
// takes a character array and the size
void printStr(char str[], int numCharacters)
{
    puts("In function printStr(char, int).\n");
    //sizeof is incorrect in the function - size of array is lost when it is passed to function
    //printf("sizeof str = %d\n", sizeof(str)); - this does not work since sizeof(str) will return 0
    printf("sizeof str = %d\n", numCharacters);
    puts(str);

    return; // returns NO value
}

void clear(void)
{
    while (getchar() != '\n');
}

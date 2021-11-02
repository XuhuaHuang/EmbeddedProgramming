/*****************************************************************//**
 * \file   stringLab.c
 * \brief  Lab 6 on C-Style strings (character array)
 *
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear(void); //function prototype for clear function

int main(void)
{
	// Q1 first name, last name and concatenate to full name using scanf_s and strcat_s
	char strFirstName[20] = { " " }; // declaring three empty strings for further usage
	char strLastName[20] = { " " }; // it looks like I have to give this char array a size, or it will simply crash. Is it true?
	char strFullName[40] = { " " };

	printf("Please enter your first name.\n");
	scanf_s("%s", &strFirstName, sizeof(strFirstName)); // it might means there is enough room for this input to go in
	clear();
	puts(strFirstName); //testing purpose. verify that the string is written in the memory

	printf("Please enter your last name.\n");
	scanf_s("%s", &strLastName, sizeof(strLastName));
	clear();
	puts(strLastName); //do NOT use quotation marks in puts or it prints the content between them

	strcat_s(strFullName, sizeof(strFullName), strFirstName); // add string first name to string first name
	strcat_s(strFullName, sizeof(strFullName), " "); // add a space between string first name and last name
	strcat_s(strFullName, sizeof(strFullName), strLastName); // add string last name to full name
	puts(strFullName); // prints the full name string with added last name

	char strFullNamev2[40] = { " " };
	strcpy_s(strFullName, sizeof(strFullName), strFullNamev2); // instructor specify "the string in question 1", strFullName will be overwritten in Q2
	// therefore, the content of the string is copied to another new string

	// Q2 using sprintf_s instead of strcat_S
	// three strings were declared before. overwrite instead of creating new ones
	printf("Please enter your first name.\n");
	scanf_s("%s", &strFirstName, sizeof(strFirstName)); // it might means there is enough room for this input to go in
	clear(); //calling the clear function to clear the input stream
	puts(strFirstName); // this line is here for testing purpose only, same applies for the next one in this section

	printf("Please enter your last name.\n");
	scanf_s("%s", &strLastName, sizeof(strLastName));
	clear();
	puts(strLastName); //do NOT use quotation marks in puts or it prints the content between them

	sprintf_s(strFullName, sizeof(strFullName), "%s %s", strFirstName, strLastName);
	// %s are place holders, double quotation marks include the space between two strings

	puts(strFullName); // prints the full name string with added last name

	// Q3 prints the length of the string strFullName
	int length = strlen(strFullNamev2) - 1;
	printf("\nThe length of your full name is %d(including spaces).\n", length);
	//QUESTION: How come there is always an extra space before my first name??? I have to go with -1 because of this
	// reply: it is counting the space between first name and last name

	// Q4 get a string from the user and convert it to all capital letters
	char newStr[999] = { " " }; // declaring a new string
	printf("\nYou just entered another section of this program xD\n\nPlease enter the string you would like to convert to upper cases.\n");
	gets_s(newStr, sizeof(newStr)); // using gets_s instead of scanf_s
	//scanf_s("%s", &newStr, sizeof(newStr)); // reference

	for (int i = 0; i < strlen(newStr); i++) // strlen() function determines the times the loop will run
	{
		newStr[i] = toupper(newStr[i]);
	} // this for loop OVERWRITES the string with upper case letters one character at a time
	puts(newStr); // this line prints the ENTIRE newStr

	// Q5 Write a program that compares “Heads" with input from a user which should be either "Heads" or Tails" (use strcmp()).
	// condition: if the user enters "Heads", print "You win" otherwise print "You lose".

	char strFixed[] = { "Heads" };
	puts(strFixed); // this line is here for testing purpose only
	char userInputStr[20] = { " " }; // declaring an empty array for further usage
	printf("\nWhat option would you use to display the first ten lines of a file?\nEnter 'Heads' or 'Tails'(case sensitive).\n\n");
	gets_s(userInputStr, sizeof(userInputStr)); // grab an input from the user and store

	int rtnValue = strcmp(userInputStr, strFixed);
	if (rtnValue == 0) // i didn't forget double equal this time
		printf("You win!\n");
	else
		printf("You entered the wrong answer ;(");
	//what does this line do?? strcmp(userInputStr, sizeof(userInputStr), strFixed); it did not give me an error

	// Q6 Have the user enter a string of numbers (store the input into a character array)
	//Write a program that converts the string into an integer (Use atoi() ). Print the string and the integer.  

	char strToInt[999] = { " " };
	printf("Please enter the string that you like to convert to an integer.\n");
	gets_s(strToInt, sizeof(strToInt)); // grab input and store

	int num = atoi(strToInt);

	printf("The resultant number is %d.\n", atoi(num)); // for some reasons it is always 0 and I couldn't figure out why
	puts(strToInt); // for testing purpose only

	/*
	//function atoi() - convert string array to a number (integer) since math cannot be performed on numbers that are characters
	char numstr[] = { "5123" };
	int number = atoi(numstr);
	//printf("number as string %d\n", atoi(numstr));
	printf("%d\n", number);
	*/

	// Q7 Have the user enter an integer.  Write a program that converts the integer into a string (Use sprintf() )
	//Print the string and the integer.  
	int num2;
	printf("Enter a number that you would like to convert to string.\n");
	scanf_s("%d", &num2);

	char numToStr[999] = { " " };
	sprintf_s(numToStr, sizeof(numToStr), "%d", num2);
	puts(numToStr);

	// convert integer to string using sprintf
	/*int num = 20;
	sprintf_s(numstr, sizeof(numstr), "%d", num);
	puts(numstr);
	*/

	// Q8 Write a program that asks the user to enter a string (use puts/gets).
	//Use a switch statement to identify a vowel and count the number of A, E, I , O and U letters that were entered.  It should not be case sensitive.
	int conf = 0;
	do
	{
		char userInput[999] = { " " };
		printf("Plese enter the string in which you would like yo count the vowel.\n");
		gets_s(userInput, sizeof(userInput));
		printf("\nThe string you just entered is listed as the following:\n");
		puts(userInput);

		int vowelCount = 0; // int declaration has to be outside of the switch cases
		for (int i = 0; i < strlen(userInput) - 1; i++)
		{
			char match = userInput[i];
			switch (match)
			{
			case 'A': // all the cases that I need to count without breaking
			case 'a': // I want the string go through each case
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
				vowelCount++;
			}
		}
		printf("The number of vowel characters in the string you just typed is %d.\n\n", vowelCount + 1); // +1 to match the right count
		printf("Would you like to continue?\nPlease enter 0 if you would like to continue and 1 to quit.\n");
		scanf_s("%d", &conf);
		clear(); // the repeating part wasn't working until I clear it. 
				//I assume it's the input stream thing again, it was skipping the gets_s part with an error message

	} while (conf == 0); // I remember to put double equal signs this time xD


	// Q bonus 1 string to Morse code
	int run = 0;
	do
	{
		char strToMorse[20] = { "" };
		//char strMorseCode[80] = { "" }; // for converted Morse Code

		printf("Please enter the string you would like to convert to Morse Code.\n");
		gets_s(strToMorse, sizeof(strToMorse));
		//puts(strToMorse); // testing purpose only, it automatically starts a new line
		//clear();

		for (int j = 0; j < strlen(strToMorse); j++)
		{
			switch (strToMorse[j])
			{
			case 'A':
				puts(".-");
				break;
			case 'B':
				puts("-...");
				break;
				/*case 'C':

				case 'D':

				case 'E':

				case 'F':

				case 'G':

				case 'H':

				case 'I':

				case 'J':

				case 'K':

				case 'L':

				case 'M':

				case 'N':

				case 'O':

				case 'P':

				case 'Q':

				case 'R':

				case 'S':

				case 'T':

				case 'U':

				case 'V':

				case 'W':

				case 'X':

				case 'Y':

				case 'Z':
				*/
				//puts(strMorseCode);
			/*
			case 0:

			case 1:

			case 2:

			case 3:

			case 4:

			case 5:

			case 6:

			case 7:

			case 8:

			case 9:

				printf("Trial.\n");
			*/
			}
		}
		printf("%d\n", strlen(strToMorse));

		printf("Would you like to continue?\nEnter 0 for yes and 1 to quit.\n");
		scanf_s("%d", &run);
		clear(); // same idea as the above

	} while (run == 0);

	int numbers[5] = { 2, 4, 6, 8, 10 };
	printf("%d", *numbers);

	return 0;
}

void clear(void) //clear function that receives nothing and returns nothing
{
	while (getchar() != '\n');
}
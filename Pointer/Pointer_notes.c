#include <stdio.h>
int my_math(int, int, int* pProduct);
// Lab 7 pointers - 1879700 Xuhua Huang

int main(void)
{
// Q1 Pointing to integers
	int x = 5;
	int y = 8;
	
	int *ptrToInt = &x; // initialize the pointer to the location of int x
	printf("The value of variable x is %d.\n", *ptrToInt);

	ptrToInt = &y; // change the pointer to the location of int y
	printf("\nThe value of variable y is %d.\n", *ptrToInt);

	*ptrToInt = 7;
	printf("\nThe value of the pointer has been changd to %d\n", *ptrToInt);
	printf("\nThe corresponding value of variable y is %d.\n", y); // note: printing the value of y should give us 7

	y = 2; // overwritting value of y
	printf("The pointer contains the address of variable of y has the value of %d.\n\n", *ptrToInt);

// Q2 Pointing to an array
	int array[10] = {0,1,2,3,4,5,6,7,8,9}; // decaring an array
	
	int index = 0;
	//ptrToInt = &array[index]; I was trying to do somthing fancier
	printf("The program lits the array below using a for loop.\n");
	for (index = 0; index < 10; index++)
	{
		printf("%d\n", array[index]);
	} // this for loop prints the int array

	int *ptrToArr = &array[0]; // declaring a pointer and initializing it to the first element in the array indexed 0
	// right side if theequal sign is equivalent to = array
	ptrToArr++; // this should increment the pointer ptrToArr to array [1]	
	printf("\nThe element in the array after the pointer has been incremented is %d.\n\n", *ptrToArr);
	
	ptrToArr = array; // ptrToArr was incremented to array[1]; this brings it back to array[0]
	// the pointer need reeeting to make the for loop work
	printf("The program lists the array by incrementing the value of pointer.\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *ptrToArr);
		ptrToArr++;
	} // this for loop prints the int array using pointer
	
// Q3 Funtions and pointers

	int userIn1; // declaring two int type variable to store user's input
	int userIn2;
	
	int product;

	printf("\nPlease enter the first integer that you want to add\n");
	scanf_s("%d", &userIn1); // asking inputs from the user
	printf("\nPlease enter the second integer that you want to add\n");
	scanf_s("%d", &userIn2);

	int result = my_math (userIn1, userIn2, &product); // calling thefunction // &product is the address of variable product
	printf("\nThe summation of these two integers is %d.\n", result); // the result is printed using the traditional method
	printf("The product of these two integers is %d\n", product);
	
	/*
	The following line is the original one to call the function without the pointer
	int result = my_math (userIn1, userIn2);
	*/
	
	return 0;
}

int my_math(int x, int y, int *pProduct)
{
	int sum = x + y; // calculating the sum of two integers
	
	*pProduct = x * y; // the product of x and y is written to the address of pProduct
	
	return sum;
}

package userInput;

import java.util.Scanner;
import java.math.BigDecimal;

public class userInput {

	public static void main(String[] args) {
		
		// creating a new scanner object with "System.in"
		Scanner scanner = new Scanner(System.in);
		
		/*** scanner ***/
		// scanner.nextLine()
		// returns a string
		System.out.print("Please enter a string: ");
		String string1 = scanner.nextLine();
		System.out.println("The string you just entered is: " + string1);
		
		// scanner.nextInt()
		// returns an integer
		System.out.print("\nPlease enter an integer: ");
		int int1 = scanner.nextInt();
		System.out.println("The integer you just entered is: " + int1);
		System.out.println("Performing action to add 1 to entered integer");
		System.out.println(int1 + " + 1 = " + (int1++));
		
		// scanner.nextBigDecimal
		// returns a fixed decimal number -> precise
		System.out.println("\nWith \"BigDecimal\"");
		System.out.print("Please enter your monthly salary: ");
		BigDecimal monthSalary = scanner.nextBigDecimal();
		System.out.println("Your salary is: " + monthSalary);
		
		// scanner.nextboolean()
		// returns a boolean value -> true or false
		// exception of errors if failed to translate user input to boolean value
		System.out.println("\nLet me ask you if you like programming in Java");
		System.out.println("Enter \"true\" for yes and \"false\" for no");
		boolean likeJava = scanner.nextBoolean();
		System.out.println("It looks like the previous statement is " + likeJava);
		
		
		/*** "Integer" class ***/
		// class properties and class methods
		System.out.println("\nWith Integer class");
		
		System.out.println("The minimum value for an Integer object is: " + Integer.MIN_VALUE);
		System.out.println("The maximum value for an Integer object is: " + Integer.MAX_VALUE);
		System.out.println("The size of an integer object in bits is: " + Integer.SIZE);
		
		// math and double class method
		System.out.println("\nWith Math and Double class method");
		
		System.out.println("Testing if the output of sqrt(-1) is a number");
		System.out.println("Will output \"true\" if it is NOT a number");
		System.out.println("The result is: " + Double.isNaN(Math.sqrt(-1)));
		// NaN stands for "not a number" -> invalid
		
		System.out.println("\nPlease enter two integers: ");
		int userInt1 = scanner.nextInt();
		int userInt2 = scanner.nextInt();
		System.out.println("The two integers you entered are: " + userInt1 + " and " + userInt2);
		System.out.println("The bigger integer among those two is: " + Integer.max(userInt1, userInt2));
		
		// Integer.valueOf(String) -> Integer object
		// Integer.parseInt -> int primitive
		System.out.println("\nUsing methods to convert a string to an integer");
		System.out.println("Please enter your first name: ");
		String userFirstName = scanner.nextLine();
		// convert user input to Integer and int
		Integer firstNameObj = Integer.valueOf(userFirstName);
		int firstNamePri = Integer.parseInt(userFirstName);
		
		// print the output
		System.out.println("With Integer object: " + firstNameObj);
		System.out.println("With int primitive: " + firstNamePri);
		
		/*** String class method ***/
		// String.concat() returns a new string
		String greeting = "Hello, world!";
		System.out.println("\nWith String class methods");
		System.out.println("Original string is: " + greeting);
		System.out.println("Printing spaced out string with charAt(index) method");
		
		for(int i = 0; i < greeting.length(); i++)
			System.out.print(greeting.charAt(i) + " ");
		
		scanner.close(); // closing scanner
	} // end main

} // end class

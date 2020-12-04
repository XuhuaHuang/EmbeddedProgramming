package helloUser;

import java.util.Scanner; // import 'default' package

public class helloUser {

		public static void main(String[] args) {
		
		// creating a new scanner of class Scanner
		Scanner scanner = new Scanner(System.in);
		// variable 'scanner'
		// Syntax:
		// type identifier = new type();
		
		System.out.println("What's your name?");
		String name = scanner.nextLine(); // get a new line
		
		// type 'sysout'
		// hold 'Ctrl' + 'Space'
		System.out.println("\nYou said your name is " + name);
		System.out.println("Hello " + name);
			
		// Creating a string with a string class constructor
		String myString = new String("\nThis is my first string.\n");
		System.out.println(myString + " :) "); // concatenate two strings
	}
	
}

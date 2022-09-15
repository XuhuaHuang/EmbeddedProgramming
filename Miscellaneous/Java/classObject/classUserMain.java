package classObject;

import java.util.Scanner;

public class classUserMain {

	public static void main(String[] args) {
		
		// creating a new scanner object with argument "System.in"
		Scanner scanner = new Scanner(System.in);
		
		// creating a new User class object
		User user1 = new User();
		
		// providing instructions and asking for user information
		System.out.println("You are registered successfully as a user.");
		
		// first name
		System.out.print("\nPlease enter you first name: ");
		String user1FirstName = scanner.nextLine();
		
		// last name
		System.out.print("\nGreat! Now Please enter your last name: ");
		String user1LastName = scanner.nextLine();

		// instantiate user1 properties with setter
		user1.setFirstName(user1FirstName);
		user1.setLastName(user1LastName);

		// output the result in the terminal with getter
		System.out.println("\nGreat! A user profile has been created!");
		System.out.println("Your profile name is: " + user1.getFullName());
		
		System.out.print("\nCalling printInfo() function");
		user1.printInfo();
		
		System.out.println("\nCurrent user count is: " + user1.getUserCount());
		
		scanner.close(); // closing created scanner
	} // end main

} // end classObjectMain

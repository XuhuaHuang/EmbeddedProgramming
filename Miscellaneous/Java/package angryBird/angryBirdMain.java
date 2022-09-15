package angryBird;

import java.util.Scanner;

public class angryBirdMain {

	public static void main(String[] args) {

		// create a new scanner object
		Scanner scanner = new Scanner(System.in);

		/*
		 * // create an object with overloaded constructor angryBird redBird = new
		 * angryBird(10, 45, 5);
		 * 
		 * // print projectile information redBird.printInfo();
		 */

		// boolean variable to validate
		// whether the user wants to play again
		boolean playAgain = true;
		// string to hold user command
		String userCommand;
		// properties required from user
		double userVel;
		double userAngle;
		double userHeight;

		// create an object with default constructor
		angryBird userPlay = new angryBird();

		// print tutorial
		printTutorial();
		System.out.println("\nYou can start placing commands now");

		do {
			// System.out.println("Waiting for further instructions");
			userCommand = scanner.nextLine();

			switch (userCommand.toLowerCase()) {
			case "start":
				System.out.println("\nWelcome to angry bird!");
				break;

			case "quit":
				System.out.println("\nHope you had some fun!");
				playAgain = false;
				break;

			case "print information":
				userPlay.printInfo();
				break;

			case "velocity":
				System.out.print("Please enter initial velocity: ");
				userVel = scanner.nextDouble();
				userPlay.setInitVel(userVel);
				break;

			case "angle":
				System.out.print("Please enter launch angle [0, 180]: ");
				userAngle = scanner.nextDouble();
				userPlay.setLaunchAngle(userAngle);
				break;

			case "height":
				System.out.print("Please enter initial height: ");
				userHeight = scanner.nextDouble();
				userPlay.setInitHeight(userHeight);
				break;

			case "tutorial":
				printTutorial();
				break;
			} // end switch

			// update when user enters a command
			userPlay.factorVelocity();
			userPlay.calcParameters();

		} while (playAgain == true);

		scanner.close(); // close created scanner
		
		return;
	} // end main

	// static member function
	// do NOT need an object to call this function
	public static void printTutorial() {

		System.out.println("Welcome to angry bird tutorial"
				+ "\nYou can place various command to customize your projectile motion"
				+ "\n\tstart - start the game"
				+ "\n\tquit - quit the game"
				+ "\n\tprint information - print parameters of the tracjectory"
				+ "\n\tvelocity - enter initial launch velocity followed by key Enter"
				+ "\n\tangle - enter initial launch angle followed by key Enter"
				+ "\n\theight - enter initial launch height followed by key Enter"
				+ "\n\ttutorial - display this tutorial again"
				+ "\nEnd of tutorial");

		return;
	}

} // end file class

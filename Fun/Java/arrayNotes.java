package arrayNotes;

import java.util.Arrays;

public class arrayNotes {

	public static void main(String[] args) {
		
		// print information
		System.out.println("Creating an array with integers 0 - 9");
		
		int[] smallInt = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // size determined to 10

		System.out.println("\nPrinting the arrat created with a for loop");
		for(int i = 0; i < 10; i++) 
			System.out.print(smallInt[i] + " "); // spaced out format
		System.out.println("\nPrinting fiished.");
		
		// Arrays.toString() for single dimension arrays
		System.out.println("\nPrinting with method \"Arrays.toString(array_name)\":");
		System.out.println(Arrays.toString(smallInt));
		System.out.println("Printing finished");
		
		System.out.println("\nRemapping original array to a new 2-D array");
		int[][] smallInt2 = {{0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}};
		
		System.out.println("\nPrinting with nested for loop:");
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 2; j++)
				System.out.print(smallInt2[i][j] + " ");
		System.out.println("Printing finished");
		
		// Arrays.deepToString() method for multi-dimension arrays
		System.out.println("\nPrinting with method \"Arrays.deepToString(array_name)\":");
		System.out.println(Arrays.deepToString(smallInt2)); 
		System.out.println("Printing finished");
		
		return;
	} // end main method

} // end file class

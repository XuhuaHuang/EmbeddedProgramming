package arrayNotes;

import java.util.Arrays;

// import array list required library
import java.util.List;
import java.util.Collections;
// import java.util.ArrayList;

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
		// notes on array end here
		
		// written on January 10, 2021, notes on Arrays to lists and printing
		// creating a list named 'smallIntList'
		System.out.println("\nCreating a list with integers 0 - 9");
		List<Integer> smallIntList = Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
		
		// print the list with method List.toString()
		System.out.println("\nPrinting with method \"List.toString()\"");
		System.out.println(smallIntList.toString());
		// some other useful methods:
		// smallIntList.add(index, element); // add the element at indicated index
		// smallIntList.toArray(); // convert the list to an array
		// smallIntList.clear(); // clear the list
		
		// iterating thorough the list and work with each element
		// methodList.size() returns an integer to indicate size
		System.out.println("\nPrinting the list with a for loop to iterate through");
		for(int i = 0; i < smallIntList.size(); i++) {
			System.out.print(smallIntList.get(i) + " "); // print the value with List.get(index) method
		}
		System.out.println("\nPrinting finished");
		
		// for-each loop, equivalent to the range-based for loop in C++
		System.out.println("\nPrintint the list with for-each loop");
		for(int integer : smallIntList) {
			System.out.print(integer + " ");
		}
		System.out.println("\nPrinting finished");
		
		// Collections method sort() to put the elements in ascending order
		System.out.println("\nSorting the list with method \"Collections.sort()\"");
		Collections.sort(smallIntList);
		System.out.println("\nReversing the list with method \"Collections.reverse()\"");
		Collections.reverse(smallIntList);
		// notes on list end here
		
		return;
	} // end main method

} // end file class

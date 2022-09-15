package relatives;

public class relativesMain {

	public static void main(String[] args) {
		
		// create myGrandfather
		Grandfather myGrandfather = new Grandfather();
		
		// create myFather
		Father myFather = new Father("Chemist", "Wenze Huang", 1973);
		
		// create mySon
		Son mySon = new Son(16, "University student", "Andy", 2001);
		
		// call printInformation() function
		// expecting default value
		myGrandfather.printInformation();
		
		// expecting custom value
		myFather.printInformation();
		
		// expecting custom value
		mySon.printInformation();
		
		return;
	} // end main method

} // end file class

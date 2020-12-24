package relatives;

public class Son extends Father{

	// private properties
	private int schoolYear;
	
	// default constructor
	public Son() {
		// call super class properties setter
		super.setOccupation("Student");
		super.setName("Son");
		super.setYearBorn(2000);
		// call sub-class property setter
		this.setSchoolYear(15);
	}
	
	// overloaded constructor
	public Son(int initSchoolYear, String initOccupation, String initName, int initYearBorn) {
		// call super class properties setter
		super.setOccupation(initOccupation);
		super.setName(initName);
		super.setYearBorn(initYearBorn);
		// call sub-class property setter
		this.setSchoolYear(initSchoolYear);
	}
	
	// setter and getter for private property 'int schoolYear'
	// setter
	public void setSchoolYear(int schoolYear) {
		this.schoolYear = schoolYear;
	}
	
	// getter
	public int getSchoolYear() {
		return this.schoolYear;
	}
	
	// print function
	public void printInformation() {
		
		System.out.println("\nSon name: " + this.getName());
		System.out.println("Son born in: " + this.getYearBorn());
		System.out.println("Son occupation: " + this.getOccupation());
		System.out.println("Son school year: " + this.getSchoolYear());
		System.out.println("End printing");
		
		return;
	}
	
} // end class 'Son'

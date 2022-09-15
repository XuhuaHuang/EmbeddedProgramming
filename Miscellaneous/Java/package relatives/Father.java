package relatives;

public class Father extends Grandfather {
	//sub-class 'Father' inherits from super class 'Grandfather' 

	// newly added private property
	private String occupation;
	
	// default constructor
	public Father() {
		// call super class properties setter
		super.setName("Dad");
		super.setYearBorn(1970);
		// call sub-class property setter
		this.setOccupation("Engineer");
	}
	
	// overloaded constructor
	public Father(String initOccupation, String initName, int initYearBorn) {
		// call super class property setter
		super.setName(initName);
		super.setYearBorn(initYearBorn);
		// call sub class property setter
		this.setOccupation(initOccupation);
	}

	// setter and getter for private property 'String occupation'
	// setter
	public void setOccupation(String occupation) {
		this.occupation = occupation;
	}
	
	// getter
	public String getOccupation() {
		return this.occupation;
	}
	
	// print function
	public void printInformation() {
		
		System.out.println("\nFather name: " + this.getName());
		System.out.println("Father born in: " + this.getYearBorn());
		System.out.println("Father occupation: " + this.getOccupation());
		System.out.println("End printing");
		
		return;
	}
	
} // end class 'Father'

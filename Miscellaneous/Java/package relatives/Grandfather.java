package relatives;

// super class 'Grandfather'
public class Grandfather {

	// private properties
	private String name;
	private int yearBorn;

	// default constructor
	public Grandfather() {
		setName("Grandpa");
		setYearBorn(1930);
	}
	
	// overloaded constructor
	public Grandfather(String initName, int initYearBorn) {
		setName(initName);
		setYearBorn(initYearBorn);
		
	}

	// setter and getter for private property 'String name'
	// setter
	public void setName(String name) {
		this.name = name;
	}

	// getter
	public String getName() {
		return this.name;
	}
	
	// setter and getter for private property 'int yearBorn'
	// setter
	public void setYearBorn(int yearBorn) {
		if (yearBorn > 1900 && yearBorn < 2020) // written in 2020
			this.yearBorn = yearBorn;
	}
	
	// getter
	public int getYearBorn() {
		return this.yearBorn;
	}
	
	// print function
	public void printInformation() {
		
		System.out.println("\nGrandfather name: " + this.getName());
		System.out.println("Grandfather born in: " + this.getYearBorn());
		System.out.println("End printing");
		
		return;
	}

} // end class 'Grandfather'

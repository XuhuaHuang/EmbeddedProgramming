package classObject;

public class User {

	// properties
	private static int userCount = 0; // in-line assignment

	// user related properties
	private String firstName;
	private String lastName;
	private String status = "Bronze"; // default argument

	// constructor
	User() {
		userCount++;
	}

	// getter for static member userCount
	public int getUserCount() {
		return userCount;
	}

	// setter:
	public void setFirstName(String userFirstName) {
		firstName = userFirstName;
	}

	public void setLastName(String userLastName) {
		lastName = userLastName;
	}

	public void setStatus(String userStatus) {
		status = userStatus;
	}

	// getter
	public String getFirstName() {
		return firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public String getFullName() {
		return firstName + " " + lastName;
	}

	public String getStatus() {
		return status;
	}

	public void printInfo() {
		System.out.println("\nUser " + getFullName() + " is of status " + (getStatus()).toLowerCase());
		// convert to lower case
	}

}

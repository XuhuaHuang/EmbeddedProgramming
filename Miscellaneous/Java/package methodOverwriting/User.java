package methodOverwriting;

public class User {

	// class properties
	private static int userCount = 0; // in-line assignment

	// user related properties
	private String firstName;
	private String lastName;
	private String status = "Bronze"; // default argument

	// constructor
	User() {
		userCount++;
	}

	// getter for static member userCount, no setter
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
	} // end printInfo() function

	@Override
	public String toString() {
		return "User [getFullName()=" + getFullName() + ", getStatus()=" + getStatus() + "]";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((firstName == null) ? 0 : firstName.hashCode());
		result = prime * result + ((lastName == null) ? 0 : lastName.hashCode());
		result = prime * result + ((status == null) ? 0 : status.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) // addresses are equal
			return true;
		if (obj == null) // argument object is null
			return false;
		if (this.getClass() != obj.getClass())
			return false;
		
		User other = (User) obj; // copy passed argument properties to another object
		if (firstName == null) {
			if (other.firstName != null)
				return false;
		} else if (!firstName.equals(other.firstName))
			return false;
		
		if (lastName == null) {
			if (other.lastName != null)
				return false;
		} else if (!lastName.equals(other.lastName))
			return false;
		
		if (status == null) {
			if (other.status != null)
				return false;
		}
		else if (!status.equals(other.status))
			return false;
		
		return true; // @Override equals(Object obj) finishes executing
	}

} // end User class

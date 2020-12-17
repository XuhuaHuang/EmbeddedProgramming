package personalBanking;

public class SavingsAccount extends Account {

	// private properties
	private double interestRate;
	private double interestEarned;

	// default constructor
	public SavingsAccount() {
		setBalance(0.00);
		setInterestRate(0.03);
		
		// print information
		System.out.println("\n[DFCONST]SavingsAccount"
				+ "\n[DFCONST][Savings]Initial balance set to: $ " + getBalance()
				+ "\n[DFCONST][Savings]Initial interest rate set to: " + getInterestRate() * 100 + " %");
		
	} // end default constructor

	// overloaded constructor
	public SavingsAccount(double initBalance, double interestRate) {
		
		super(initBalance); // superclass overloaded constructor with validation

		// validate passed interestRate
		if (interestRate >= 0) {
			this.setInterestRate(interestRate);
			
			// print information
			System.out.println("\n[OLCONST]SavingsAccount"
					+ "\n[OLCONST][Savings]Initial balance set to: $ " + getBalance()
					+ "\n[OLCONST][Savings]Initial interest rate set to: " + getInterestRate() * 100 + " %");
			
		} else {
			this.setInterestRate(0.03);
			
			// print error message
			System.out.println("\n[OLCONST]SavingsAccount"
					+ "\n[OLCONST][Savings]Initial balance set to: $ " + getBalance()
					+ "\n[OLCONST][Savings]Attempting to set negative interest rate"
					+ "\n[OLCONST][Savings]Operation abandoned"
					+ "\n[OLCONST][Savings]Initial interest rate set to: " + getInterestRate() * 100 + " %");
		} // end else
		
	} // end overloaded constructor

	// setter and getter
	public void setInterestRate(double interestRate) {
		this.interestRate = interestRate;
	} // end interestRate setter

	public double getInterestRate() {
		return interestRate;
	} // end interestRate getter

	// the following setter is hidden from the main method
	// interestEarned should not be available to set for user
	private void setInterestEarned(double interestEarned) {
		this.interestEarned = interestEarned;
	} // end interestEarned setter

	public double getInterestEarned() {
		return interestEarned;
	} // end interestEarned getter
	// end all setter and getter

	// function to calculate total interest earned
	public void calculateInterestEarned() {

		setInterestEarned(getBalance() * getInterestRate());
		
		// print information
		System.out.println("\n[fn][Savings]calculateInterestEarned(double) called"
				+ "\n[fn][Savings]Variable \"interestEarned\" updated"
				+ "\n[fn][Savings]calculateInterestEarned(double) ends executing on this line");
	}

} // end subclass SavingsAccount

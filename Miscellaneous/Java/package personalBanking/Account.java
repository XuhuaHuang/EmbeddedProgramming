package personalBanking;

// super class
// sub-class: CheckingAccount and SavingsAccount

public class Account {

	// private property
	private double balance;

	// default constructor
	public Account() {
		setBalance(0);

		// print information
		System.out.println("\n[DFCONST]Account"
				+ "\n[DFCONST][Account]Initial balance set to: $ " + getBalance());
	} // end default constructor

	// overloaded constructor
	public Account(double initBalance) {

		if (initBalance >= 0.00) {
			
			setBalance(initBalance);
			
			// print information
			System.out.println("\n[OLCONST]Account"
					+ "\n[OLCONST][Account]Valid initial balance"
					+ "\n[OLCONST][Account]Initial balance overloaded to: $ " + getBalance());
			
		} else {
			
			setBalance(0);
			
			// print error message
			System.out.println("\n[OLCONST]Account"
					+ "\n[OLCONST][Account]Invalid initial balance"
					+ "\n[OLCONST][Account]Initial balance overloaded to: $ " + getBalance());
		}

	} // end overloaded constructor

	// setter and getter
	public void setBalance(double balance) {
		this.balance = balance;
		return;
	} // end setter

	public double getBalance() {
		return balance;
	} // end getter
	// end all setter and getter
	
	// other global function for deposit and withdraw
	public void credit(double deposit) {

		if (deposit < 0) {
			
			// print error message
			System.out.println("\n[fn][Account]credit(double) called"
					+ "\n[fn][Account]Attempting to deposit negative amount"
					+ "\n[fn][Account]Operation abandoned"
					+ "\n[fn][Account]credit(double) ends executing on this line");
			
		} else if (deposit == 0) {
			
			// print error message
			System.out.println("\n[fn][Account]credit(double) called"
					+ "\n[fn][Account]Attempting to deposit $ 0.00"
					+ "\n[fn][Account]Balance not changed"
					+ "\n[fn][Account]credit(double) ends executing on this line");
			
		} else if (deposit > 0) {
			
			setBalance(getBalance() + deposit);
			
			// print information
			System.out.println("\n[fn][Account]credit(double) called"
					+ "\n[fn][Account]Deposited. Your latest account balance is: $ " + getBalance()
					+ "\n[fn][Account]credit(double) ends executing on this line");
			
		}

		return;
	} // end credit

	public boolean debit(double withdraw) {
		
		boolean withdrawSuccess = false;

		if (withdraw < 0) {
			
			// print error message
			System.out.println("\n[fn][Account]debit(double) called"
					+ "\n[fn][Account]Attempting to withdraw negative amount"
					+ "\n[fn][Account]Operation abandoned"
					+ "\n[fn][Account]Account balance remains unchanged"
					+ "\n[fn][Account]debit(double) ends executing on this line");
			
		} else if (withdraw == 0) {
			
			// print error message
			System.out.println("\n[fn][Account]debit(double) called"
					+ "\n[fn][Account]Attempting to withdraw $ 0.00"
					+ "\n[fn][Account]Operation abandoned"
					+ "\n[fn][Account]Account balance remains unchanged"
					+ "\n[fn][Account]debit(double) ends executing on this line");
			
		} else if (withdraw > 0 && getBalance() - withdraw >= 0.00) {
			
			setBalance(getBalance() - withdraw);
			withdrawSuccess = true;
			
			// print information
			System.out.println("\n[fn][Account]debit(double) called"
					+ "\n[fn][Account]Withdraw success. Account balance is recalculated"
					+ "\n[fn][Account]Your latest account balance is: $ " + getBalance()
					+ "\n[fn][Account]debit(double) ends executing on this line");
		}

		return withdrawSuccess;
	} // end debit
	
} // end public class Account

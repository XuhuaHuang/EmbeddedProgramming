package personalBanking;

public class CheckingAccount extends Account{
	
	// private properties
	private double fee;
	
	// default constructor
	public CheckingAccount() {
		setBalance(0);
		setFee(0.25); // fee default to 0.25
		
		// print information
		System.out.println("\n[DFCONST]CheckingAccount"
				+ "\n[DFCONST][Checking]Initial balance set to: $ " + getBalance()
				+ "\n[DFCONST][Checking]Initial fee set to: $ " + getFee() + " per transaction");
		
	} // end default constructor 
	
	// overloaded constructor
	public CheckingAccount(double initBalance, double initFee) {
		
		super(initBalance); // superclass overloaded constructor with validation
		
		if(initFee >= 0) {
			
			setFee(initFee);
			
			// print information
			System.out.println("\n[OLCONST]CheckingAccount"
					+ "\n[OLCONST][Checking]Initial balance set to: $ " + getBalance()
					+ "\n[OLCONST][Checking]Initial fee set to: $ " + getFee() + " per transaction");
			
		} else {
			
			setFee(0.25);
			
			// print information
			System.out.println("\n[OLCONST]CheckingAccount"
					+ "\n[OLCONST][Checking]Initial balance set to: $ " + getBalance()
					+ "\n[OLCONST][Checking]Attempting to set invalid transaction fee"
					+ "\n[OLCONST][Checking]Operation abandoned"
					+ "\n[OLCONST][Checking]Transaction fee default to $ 0.25");
		
		} // end else
		
	} // end overloaded constructor

	// setter and getter
	public void setFee(double fee) {
		this.fee = fee;
	} // end setFee(double)
	
	public double getFee() {
		return fee;
	} // end getFee()

	// other public function
	public void credit(double deposit) {
		
		// print information
		System.out.println("\n[fn][Checking]credit(double) called"
				+ "\n[fn][Checking]Invoking superclass \"Account\" method \"credit(double)\"");
		
		super.credit(deposit - getFee()); // invoke superclass credit(double) method
		
		System.out.println("\n[fn][Checking]credit(double) ends executing on this line");
	} // end credit(double)
	
	public boolean debit(double withdraw) {
		
		// print information
		System.out.println("\n[fn][Checking]debit(double) called"
				+ "\n[fn][Checking]Invoking superclass \"Account\" method \"debit(double)\"");
		
		boolean withdrawFeeStatus = super.debit(withdraw); // invoke superclass method
		
		if (withdrawFeeStatus) {
			
			// deduct transaction fee
			setBalance(getBalance() - getFee());
			
			// print information
			System.out.println("[fn][Checking]Withdraw successful. Transaction fee deducted"
					+ "\n[fn][Checking]Current balance is: $ " + getBalance());			
			
		} else {
			
			// print error message
			System.out.println("[fn][Checking]Error! Debit amount exceeded account balance."
					+ "\n[fn][Checking]Withdraw unsuccessful. Transaction fee not deducted"
					+ "\n[fn][Checking]Current balance is: $ " + getBalance());	
		
		} // end else
		
		System.out.println("[fn][Checking]debit(double) ends executing on this line");

		return withdrawFeeStatus; // boolean variable
		
	} // end debit(double)
	
} // end subclass CheckingAccount

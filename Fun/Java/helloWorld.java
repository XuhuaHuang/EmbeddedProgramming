package helloWorld;

public class helloWorld {

	// method has an identifier 'main'
	// public access modifier
	// 'String[] args' as string array argument -> argument string
	public static void main(String[] args) {
		// statement
		// System class, out member, println() method
		// static keyword -> no instance of object needed
		System.out.println("Hello, world!");
		// System.out.println("Hello " + args[0]); // comment line argument
		// first string passed when run the program from the comand line
		
		// call the 'sayHello' function 
		var helloInstance = new helloWorld(); // create a new object
		helloInstance.sayHello();
	}
	
	public void sayHello() {
		// member method
		System.out.println("[fn]Hello from public member method \'void sayHello()\'.");
	}

}

package primitiveType;

public final class primitiveType {

	/*** Global variable ***/
	public static final double PI = 3.14159265359;
	// keyword "static" means we do NOT need to 
	// create an instance of this class
	
	public static void main(String[] args) {
		
		/*** Primitives and objects ***/		
		int x = 1; // creating a primitive
		// primitive type "int"
		
		Integer y = 2; // creating an object by typing "Integer"
		// conversion called "autoboxing"
		// class type "Integer"
		
		System.out.println("Primitives and objects");
		System.out.println("Primitive x  = " + x);
		System.out.println("Object y = " + y); 
		
		
		/*** Variable declaration and initialization ***/
		int int1 = 3;
		// 2 step process: 1) declare a variable
		//				   2) initialize the variable
		int int2; // declare
		int2 = 4; // initialize
		
		final int INT1 = 5; // constant, can not be changed
		
		System.out.println("\nVariable declaration and initialization");
		System.out.println("int1 = " + int1);
		System.out.println("int2 = " + int2);
		System.out.println("constant \"INT1\" = " + INT1);
		
		
		/*** Variable type ***/
		boolean isJavaFun = true; // or false
		byte byte1 = 127; // 8 bits binary value 0b11111111
		char char1 = 'C'; // capable storing unicode - multiple language support
		
		short short1 = 32767; // highest available value in data type short
		int int3 = 43435943; // 32 bit number - bigger range
		long long1 = 50505050505050L; // 64 bit variable
		// "L" specifies "long"
		float f= 9.81f; // without the "f", compiler assumes it is a double
		double d = 20.5; // more precise
		double d2 = 20.5f; // downward compatible - float occupies less memory
	
	}

}

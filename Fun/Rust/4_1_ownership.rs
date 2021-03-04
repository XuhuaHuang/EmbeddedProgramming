/** Ownership in Rust
  * Xuhua HUANG
  * Feb 2021
  */

/**
  * Introduction
  * Rust's approach to memory management
  * System of Ownership with a set of rules that compiler checkes atcompile time
  * STACK VS. HEAP
  * Stack: Known, fixed size data type
  *        last in, first out -> pile of plates
  *        pushing onto the stack / poppinng off the stack
  * Heap:  Unknown size at compile time / size may change
  *        Allocating on the heap -> follow a pointer to find actual data
  *        Need one allocate with one free with heap variable
  * * Pushing to satck is faster than allocating on heap
  * * Accessing data on stack is faster than on the heap
  */

/** Ownership RULES
  * Each value has its own owner
  * One owner at a time
  * Value will be droped when the owner goes out of the scope
  */

fn main() {
    println!("Let's talk about ownership in Rust!");

    // the "String" type
    let greeting = "Hello"; // string literals stored on the stack, immutable, fixed size
    // string literals are hardcoded directly to the final executable

    // conver to "String" data type and allocate it to the heap
    let mut greeting = String::from("Hello");
    greeting.push_str(", world!"); // append to string

    // output
    println!("\nThe \"String\" type variale is now allocated on the heap.");
    println!("Variable \"greeting\" is now: {}", greeting);

    // String contains three parts, all on stack
    // pointer, points to the actual value on the heap; length, the memory currently used
    // capacity, the amount of memory received from the allocator
    let ptr1 = String::from("Hello");
    let ptr2 = ptr1; // only copy pointer, length and capacity on the stack to new String
    // ptr1 and ptr2 now both contaon the same address pointing to the memory contains "hello"
    // ptr1 is no longer a valid variable, it is "moved" to ptr2
    // since ptr1 is not valid, drop() will only get called when ptr2 goes out of the scope


    // CLONE
    let ptr3 = ptr2.clone();
    // both ptr2 and ptr3 are valid
    // occupying different space on the heap
    println!("\nptr1 is destroyed");
    println!("ptr2 = {}, ptr3 = {}", ptr2, ptr3);

    // COPY on stack
    // available on: all integer, float, double, char and tuple

    // Ownership and Functions
    take_ownership(ptr2);
    // "ptr2" is nolonger valid since the function dropped it before passing back control


    // Return Value and Ownership
    let ptr3 = give_ownership(); // overwrit with function String content
    let (ptr3, length) = calculate_string_length(ptr3);
    // (ptr3, length) is a tuple of type (String, i32)

    // output
    println!("\nThe length of \"{}\" is {}", ptr3, length);

    // UPCOMING: references
}

// function takes the ownership and drops it when finishing executing
fn take_ownership(some_string: String) {
    println!("\nInside function \"take_ownership(string:String)\"");
    println!("Variable is moved to the function scope and will be dropped");
    println!("Content of moved variable: {}", some_string);
}

// function gives ownership by returning a String
fn give_ownership() -> String {
    let some_string = String::from("Hello world from \"give_ownership\" function");
    return some_string // expression, no ending semicolon
}

// function returns a tuple and its ownership with the String element
fn calculate_string_length(some_string: String) -> (String, usize) {
    let length = some_string.len();
    return (some_string, length) // return expression
}

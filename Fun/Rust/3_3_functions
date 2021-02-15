/** Functions in Rust
  * Xuhua HUANG
  * Feb 2021
  */

/**
 * CONVENTION
 * snake case style for function and variable names
 * all lower case and seperated by underscores
 */

fn main() {
    println!("Hello, world!");

    another_function(); // defined later

    // PARAMETERS
    // single argument
    print_signed_32_bit_int(5);
    // multiple arguments
    print_two_i32_int(6, 7);

    // STATEMENTS & EXPRESSIONS
    // statement:
    // with ending semicolons and so NOT return any value
    let some_num = 8; // this statement does not return any value
    // let some_num = (let some_num = 8); // ERROR! no value is returned to bind

    // expresstion:
    // evaluate to something, do NOT include ending semicolons
    let some_num = { // new scope
        let other_num = 9;
        other_num + 1 // expression evaluates to 10 and returns a value to bind
                      // no semicolon to end line
    }; // close scope

    // RETURN VALUES
    // syntax: fn funtion_name(parameter_list) -> return_type { function_body }
    let five = return_five(); // equivalent to statement "let five = 5;"
    // output
    println!("\nThe value of variable \"five\" is: {}", five);

    println!("\nCalling function \"plus_one(x: i32)\" with argument 255");
    println!("The result is expected to be 256: {}", plus_one(255));
}

// function with no parameters nor return type
fn another_function() {
    println!("Another function.");
}

// function to print a signed 32-bit integer
fn print_signed_32_bit_int(x: i32) {
    println!("\n\"print_signed_32_bit_int\"");
    println!("The value of received 32-bit signed integer is: {}", x);
}

// receive two arguments specified of type "i32", followed by a colon
fn print_two_i32_int(x: i32, y:i32) {
    println!("\n\"print_two_i32_int\"");
    println!("The value of first received 32-bit signed integer is: {}", x);
    println!("The value of second received 32-bit signed integer is: {}", y);
}

// function use an expression to return an i32 type integer
fn return_five() -> i32 {
    5 // expression, evaluated to 5 without ending semicolons
}

fn plus_one(x: i64) -> i64 {
    x + 1
}

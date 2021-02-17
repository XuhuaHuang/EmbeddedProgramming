/** Control Flow in Rust
  * Xuhua HUANG
  * Feb 2021
  */

/**
  * OVERVIEW
  * if / else if / else
  * loops
  */

fn main() {
    println!("Hello, world!");

    println!("Control flow in Rust");

    // SYNTAX
    // NOTE: in Rust, if only takes bool, i.e. no if (3) as were in C++
    // Rust will not automatically try to convert non-Boolean value to a Boolean
    if true {
        println!("The \"if\" condition is true");
    } // arm assoiciated to "if"
    else if true {
        println!("The \"else if\" condition is true");
    }
    else {
        println!("The \"else\" condition is true");
    }

    let some_num = 3;
    if some_num != 0 {
        println!("Variable \"some_num\" is not equal to 0");
    }

    // NOTE: One other power branching construct is match


    // USING IF in LET STATEMENTS
    let condition = true;
    let some_num = if condition { 5 } else { 6 }; // using an expression instead of a statement
    println!("Variable \"some_num\" is now: {}", some_num); // 5
    // NOTE: if using if with expression in let statement, same type of expression is expected
    // usually expected the same type as the data type in if
    // let some_num = if condition { 5 } else { "six" }; // ERROR! compiler expected i32


    // REPETITION & LOOPS
    // inifinte loop
    // loop {
    //     // code to loop
    // }
    // RETURN IN LOOPS
    let mut counter = 0;
    let result = loop {
        counter += 1; // increment

        if counter == 10 {
            break counter * 2;
        } // end loop
    }; // end let statement
    println!("Result after looping with return: {}", result);

    // while loop
    let mut some_num = 3;
    while some_num != 0 {
        println!("Inside the while loop with value {}!", some_num);
        some_num -= 1;
    }
    println!("Exited the while loop!");

    // loop through collection with for / while loop
    let some_num = [10, 20, 30, 40, 50];
    let mut index = 0;

    // print the array with a while loop
    println!("\nPrinting with a while loop");
    while index < 5 {
        println!("The value indexed {} in the array is {}", index, some_num[index]);
        index += 1; // increment index
    }

    // print the array with a for loop
    // array_name.iter() member function
    println!("\nPrinting with a for loop");
    for num in some_num.iter() {
        println!("The value in the array is: {}", num);
    }

    // specified range for loop
    for num in(1..4).rev() {
        println!("Reversing: {}", num);
    }
    println!("\nExited the ranged for loop!");

    // EXERCISE: print the lyrics "The Twelve Days of Christmas"
    let mut day: u32 = 1;
    while day < 13 {
        println!("\nOn the {} day of Christmas my true love gave to me", change_to_order(day));

        if day >= 12 { println!("twelve drummers drumming, "); }
        if day >= 11 { println!("eleven pipers piping, "); }
        if day >= 10 { println!("ten lords a leaping, "); }
        if day >=  9 { println!("nine ladies dancing, "); }
        if day >=  8 { println!("eight maids a milking, "); }
        if day >=  7 { println!("seven swans a swimming, "); }
        if day >=  6 { println!("six geese a laying, "); }
        if day >=  5 { println!("five gold rings, "); }
        if day >=  4 { println!("four calling birds, "); }
        if day >=  3 { println!("three French hens, "); }
        if day >=  2 { print!("two turtle doves, and "); }
        if day >=  1 { println!("a partridge in a pear tree"); }

        day += 1; // increment for while loop
    } // end while loop
} // end main()

fn change_to_order(day: u32) -> String {
    if day == 12 { return "twelfth".to_string(); }
    if day == 11 { return "eleventh".to_string(); }
    if day == 10 { return "tenth".to_string(); }
    if day ==  9 { return "ninth".to_string(); }
    if day ==  8 { return "eighth".to_string(); }
    if day ==  7 { return "seventh".to_string(); }
    if day ==  6 { return "sixth".to_string(); }
    if day ==  5 { return "fifth".to_string(); }
    if day ==  4 { return "fourth".to_string(); }
    if day ==  3 { return "third".to_string(); }
    if day ==  2 { return "second".to_string(); }
    if day ==  1 { return "first".to_string(); }
    else { return "ERROR".to_string(); }
}

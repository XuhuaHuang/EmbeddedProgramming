/** 6_2_match_operator.rs
  * The match Control Flow Operator in Rust
  * a.k.a match expression
  *
  * Xuhua Huang
  * March 2021
  */

/**
  * match
  * compare a value against a series of patterns
  * execute code based on pattern matches
  * think of it as a coin-sorting machine
  * has to find a fit
  */

// since we mentioned coins
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState), // designs of 50 states pattern on one side
    // a Quarter variant also holds a 'UsState' value
}

#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
    Arizona,
    Arkansas,
    California,
    // e.t.c.
}

// takes ownership of a coin object of Enum Coin as an argument
// return equivalent value in cents in the form of 8-bit unsigned integer
fn value_in_cents(coin: Coin) -> u8 {
    // match keyword follows an expression
    // with 'match' we return the type 'Coin' as defined
    match coin {
        // Coin::Penny is the value
        // => operator separates the pattern and code to run (1 as an return expression)
        // if need to run multiple lines of code, {} are needed
        Coin::Penny => { // start of code block to run
            println!("Lucky quarter!"); // code to run
            1 // return expression
        } // end code block to run for Coin::Penny
        // other arms of match expression
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(UsState) => {
            println!("State quarter from: {:?}!", UsState);
            25
        }, // a quarter coin has to have one state minted
    } // end of match expression
}

// Matching with 'Option<T>'
// generic programming concept
// takes ownership of argument (32-bit integer) x
fn plus_one(x: Option<i32>) -> Option<i32> {
    // to minimize potential error
    // use match expression
    match x {
        None => None, // returns Option<None> is x is null
        Some(i) => Some(i + 1),
    }
    // the match expression will not work if Option<None> is not implemented
    // because match expression is exhaustive
}

// implement the '_' place holder
// takes ownership of an unsigned 8-bit integer
// returns a String
fn descriptive_u8(x:u8) -> String {
    match x {
        // suppose wo only care about 1, 3, 5, 7, 9
        1 => String::from("one"),
        3 => String::from("three"),
        5 => String::from("five"),
        7 => String::from("seven"),
        9 => String::from("nine"),
        _ => String::from(""),
        // '_' matches any value that's NOT specified above
        // typical: _ => (), while '()' is the unit value, nothing happens
    }
}

// MAIN
// test cases with various functions above
fn main() {
    println!("Let's talk about the \"match\" control flow operator in Rust!");

    // test case with Coin and UsState
    println!("\nExpected to see a quarter coming from California");
    value_in_cents(Coin::Quarter(UsState::California));

    // test case with function plus_one()
    println!("\nTesting function \"plus_one(x: Option<i32>) -> Option<i32>\":");
    let five = Some(5);
    let six = plus_one(five); // == plus_one(Some(5));
    println!("The result after calling with argument 5 is: {:#?}", six);
    let none = plus_one(None);
    println!("The result after calling with argument None is: {:#?}", none);

    // test case with function descriptive_u8()
    println!("\nTesting function \"descriptive_u8(x:u8) -> String\":");
    for i in 1..10 {
        println!("The returned description of the function is: {}", descriptive_u8(i));
    }

    // UPCOMING: if let, when only care about one of the cases
}

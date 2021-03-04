/** 6_3_if_let_control.rs
  * Concise Control Flow wit 'if let' Operator in Rust
  *
  * Xuhua Huang
  * March 2021
  */

// Coin enum and UsState from '6_2_match_operator.rs'
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

// MAIN
// Contains test cases
use crate::UsState::Alaska;

fn main() {
    println!("Let's talk about the \"if let\" operator in Rust!");

    let some_u8_value = Some(0u8);
    // with 'match'
    // practice the match expression from last note
    match some_u8_value {
        Some(3) => println!("three"),
        _ => (), // placeholder for everything else
    }

    // with 'if let'
    // if let _pattern = _expression
    // lose exhaustive checking that match expression enforces
    if let Some(3) = some_u8_value {
        println!("three");
    }

    // include an 'else' with 'if let'
    // 'else' acts like the '_' placeholder
    let mut count:u8 = 0;
    // with 'match'
    let coin = Coin::Penny;
    match coin {
        Coin::Quarter(state) => println!("State quarter from {:?}", state),
        _ => count += 1,
    }

    // with 'if let {} else {}'
    let coin = Coin::Quarter(Alaska); // uncomment this line if you want to see 'if let' executes
    // let coin = Coin::Penny;
    if let Coin::Quarter(state) = coin {
        println!("State quarter from {:?}", state);
    } else { // if coin is NOT one of the Quarters with UsState
        count += 1;
    }

    println!("Times the operator did NOT find an exact execution arm: {}", count);
}

/** 9_2_recover_error.rs
  * Recoverable errors with Result enum
  *
  * Xuhua Huang
  * May 2021
  */

/* Recall from earlier: type 'Result'
 * enum Result<T,E> {
 *     Ok(T),
 *     Err(E),
 * }
 */

use std::fs::File;
use std::io::ErrorKind;
use std::io;
use std::io::Read;

fn main() {
    println!("Let's talk about recoverable errors in Rust!");

    // attempt to open an nonexisting file
    let file: Result<File, E> = File::open("hello.txt"); // this line compiles
    // let f:u32 = File::open("hello.txt"); // this line gives a type error

    /* About File::open("__path__") */
    // Return type: Result<T, E>
    // T - generic success value, std::fs::File, file handler
    // E - error value, std::io::Error

    /* Use a 'match' expression to handle 'Result' variants */
    /*
    let f = match file {
        Ok(file) => file,
        Err(error) => panic!("With simple 'match' statement, " +
                             "problem opening the file: {:#?}", error),
    };
    */ // commented out since file borrowed after

    /* Matching on Different Errors */
    let f = match file {
        Ok(file) => file, // return file handle
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Problem creating the file: {:#?}", e),
            },
            other_error => {
                panic!("Problem opening the file: {:#?}", other_error)
            }
        }, // end handling error
    }; // end matching

    /* Shortcuts for Panic on Error: unwrap and expect */
    let f = File::open(hello.txt).unwrap();
    let f = File::open(hello.txt).expect("Failed to open hello.txt");
    // expect() takes parameter as customized error message

    /* Propagating Errors */
    // see function definition read_username_short()
}

// return type: Result<T, E>, generic parameter T and E
// T has been filled with type String
// E has been filled with type io::Error
fn read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("user_name.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(r),
    };

    let mut s: String = String::new();

    // call 'read_to_string()' method on the file handle
    // read content into String 's' Hint: mutable reference/pointer
    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

/* ? operator */
// error and values that have ? operator called on will go through 'from' function
// in the 'From' trait in the standard library
// returns the value inside an Ok to the calling variable
// if an error occurs, ? operator returns early and give any occur Err
fn read_username_from_file_short() -> Result<String, io::Error> {
    let mut f = File::open("hello.txt")?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)

    // equivalent to:
    // File::open("username.txt")?.read_to_string(&mut s)?;
}
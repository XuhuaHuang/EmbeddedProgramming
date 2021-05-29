use std::cmp::Ordering;

/** 9_3_to_panic_or_not.rs
  * Conditional panic! marco usage in Rust
  *
  * Xuhua Huang
  * May 2021
  */

fn main() {
    println!("Let's talk about panic condition in Rust!");

    /* Case in which you have more information than the compiler */
    // call 'unwrap()' and 'parse()' method
    use std::net::IpAddr; // import network programming trait
    let home_ip: IpAddr = "192.168.0.17".parse().unwrap();
    print!("{}", home_ip);
    // parse() method returns a 'Result<T, E> tuple
    // unwrap() method will return the value if there is one (i.e. the Result is Ok )
    // and it will panic when there isn't one (an Err )

    /* Guidelines for Error Handling when Designing APIs */
    // 1) condition: someone gives a value does not make sense -> call panic!
    // 2) condition: calling external code that is out of control -> panic!
    // 3) if a failure is expected, return a Result<T, E>

    /* Creating Custom Types for Validation */
    // example code:
    loop {
        // --snip--

        let guess: i32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        if guess < 1 || guess > 100 {
            println!("The secret number will be between 1 and 100.");
            continue;
        }

        match guess.cmp(&secret_number) {
            // --snip--
            Ordering::Less => { println!("Less than"); }
            Ordering::Equal => { println!("Equal"); }
            Ordering::Greater => { println!("Greater"); }
        }
    }

    // summary
    // if there is a state in the program than it can't handle
    // or needs to stop instead of trying to proceed with invalid values
    // UPCOMING: generic types, traits and lifetime specifiers
}

pub struct Guess {
    value: i32,
}

impl Guess {
    // Guess::new()
    pub fn new(value: i32) -> Guess {
        // test incoming value
        // throw a panic! if the test failed
        // condition may vary
        if value < 1 || value > 100 {
            panic!("Guess must be between 1 and 100. Got {}", value);
        }

        Guess(value)
    }

    // function to get value
    pub fn value(&self) -> i32 {
        self.value
    }
}
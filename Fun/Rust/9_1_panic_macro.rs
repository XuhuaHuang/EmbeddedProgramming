/** 9_1_panic_macro.rs
  * panic! macro in Rust
  * Unwinding the stack or aborting in response to a panic
  * Xuhua Huang
  * May 2021
  */

/* Unrecoverable error with panic!
 * Add [profile] sections in the "Cargo.toml" file
 * panic = 'abort'
 */

fn main() {
    println!("Let's talk about panic marco in Rust!");

    let v: Vec<u8> = vec![1, 2, 3];

    // panic!("With known panic");
    print!("Attempting to reach out-of-bound element: {}", v[99]);

    // throw a panic with custom error message
    panic!("Program crashed and burnt");
}

use ferris_says::say; // added to dependencies
use std::io::{stdout, BufWriter};

fn main() {
    // instantiate a output stream object with default constructor stdout
    let stdout = stdout();

    // create a string named message
    let message = String::from("Hello Rustaceans!");

    // convert to character array and count elements
    let width = message.chars().count();

    // pass stdout.lock() as parameter to constructor
    let mut writer = BufWriter::new(stdout.lock());
    say(message.as_bytes(), width, &mut writer).unwrap();
}

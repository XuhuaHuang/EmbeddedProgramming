/** 6_1_enumeration_2.rs
  * Another example with enumerations in Rust
  * With enum Message and implementation block
  *
  * Xuhua HUANG
  * March 2021
  */

// create an enum of Message
// #[derive(Debug)]
enum Message {
    Quit,
    Move{x:i32, y:i32},
    Write(String),
    Change(i32, i32, i32),
}

// implementation block for enum 'Message'
impl Message {
    // borrow self
    fn print(&self) {
        match self {
            Message::Quit => println!("Quit"),
            Message::Move{x, y} => {
                println!("Move to x: {}, y: {}", x, y);
            },
            Message::Write(string) => {
                println!("Write message = {}", string);
            },
            Message::Change(a, b, c) => {
                println!("Change a = {}, b = {}, c = {}", a, b, c);
            },
        } // end match
    } // end fn print(&self)
} // end implementation for enum Message

fn main() {
    println!("This is another example on enumeration in Rust!");

    // Quit
    println!("\nWith \"Message::Quit\"");
    let quit_msg = Message::Quit;
    quit_msg.print();

    // Move
    println!("\nWith \"Message::Move\"");
    let move_msg = Message::Move{x: 128, y: 255};
    move_msg.print();

    // Write
    println!("\nWith \"Message::Write\"");
    let write_msg = Message::Write(String::from("Hello! This is Message::Write enum!"));
    write_msg.print();

    // Change
    println!("\nWith \"Message::Change\"");
    let change_msg = Message::Change(1, 128, 255);
    change_msg.print();
}

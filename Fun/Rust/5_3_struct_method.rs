/** Implementing method in structure
  * Multiple implementation blocks, self keyword, multiple parameters and associated functions
  * with example structure Rectangle
  * Xuhua HUANG
  * Feb 2021
  */

// define struct Rectangle with method area()
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

// implementation block of struct Rectangle
// struct can have multiple 'impl' block
impl Rectangle {

    // area() borrows self immutably
    // dies NOT take ownership
    // &self == rect: &Rectangle since declared "implementing Rectangle"
    fn area(&self) -> u32 {
        self.width * self.height
    }

    // can_hold() implementation
    // immutable borrow of self and other Rectangle
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width >= other.width && self.height >= other.height // AND operator of type boolean
    }
}

// second implementation block for Rectangle
// associated function
impl Rectangle {
    fn create_square(length: u32) -> Rectangle {
        Rectangle {
            width: length,
            height: length,
        }
    }
}

fn main() {
    println!("Let's talk about implementing method in structure!");

    // instantiate a rectangle object
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    // call area() and output
    println!("\nAn instance named \"rect\" with 30 width, 50 height has been created");
    println!("The area of the rectangle is {}", rect1.area());

    // create rect2 which can be held by rect1
    let rect2 = Rectangle {
        width: 15,
        height: 25,
    };

    // create rect3 which can NOT be held by rect1
    let rect3 = Rectangle {
        width: 31,
        height: 51,
    };

    // call can_hold() and output
    println!("\nDetermining whether one rectangle can hold the other or not: ");
    println!("Calling method \"Rectangle::can_hold(&self, other: &Rectangle)\"");
    println!("[Rectangle]rect1 can hold rect2: {}", rect1.can_hold(&rect2));
    println!("[Rectangle]rect1 can hold rect2: {}", rect1.can_hold(&rect3));

    // associated functions
    // functions with the 'impl' block do NOT take self as a parameter
    // often used for constructors and return a new instance of struct
    println!("\nAssociated function \"create_square()\" has been implemented");
    let square = Rectangle::create_square(30); // square is an instance of struct
    println!("Printing instance \"square\"");
    println!("square: Rectangle = {:#?}", square); // formatted debug information

    // compare the size of square to rect1
    println!("\nDetermining whether rect1 can hold square or not: ");
    println!("[Rectangle]rect1 can hold square: {}", rect1.can_hold(&square));

    // UPCOMING: Rust's enumeration
}

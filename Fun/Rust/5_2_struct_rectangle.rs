/** Rectangle with Structure in Rust
  * Xuhua HUANG
  * Feb 2021
  */

// define a struct Rectangle
// Rust implements printing debug information
// explicitly opt in to make it available
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    println!("This is an example to program a rectangle structure!");

    // create two unsigned 8-bit integer width and height of a rectangle
    let width:u16 = 30;
    let height:u16 = 50;
    // output
    println!("The area of the rectangle is {} square pixels.",
             calculate_area(width, height)
    );

    // using structure to refactor rectangle
    // and tuple to bind width and height together
    let rect:(u16, u16) = (40, 60); // tuple
    println!("\nCalculating area with tuple: ");
    println!("The area of the rectangle is {} square pixels.",
             calculate_area_tuple(rect)
    );

    // create an instance of struct 'Rectangle'
    let rect = Rectangle {
        width: 50,
        height: 70,
    }; // keep in mind, let is ultimately a statement with ending semicolons

    // output
    println!("\nWith structure named \"Rectangle\": ");
    println!("The area of the rectangle is {} square pixels.",
             area(&rect)
    );

    // adding useful functionalities with traits
    // print with placeholder: {:?} and {:#?}
    println!("\nWith Debug derived, calling println!() with Rectangle instance: ");
    println!("Rectangle instance \"rect\" is {:#?}", rect); // print formatted debug information

    // UPCOMING: turning area() function into an area() METHOD defined in structure Rectangle
}

fn calculate_area(width:u16, height:u16) -> u16{
    width * height // safe cast to unsigned 64-bit integer
}

fn calculate_area_tuple(dimensions: (u16, u16)) -> u16 {
    // width     * height
    dimensions.0 * dimensions.1 // return the product of first and second element in the tuple
}

// function that borrows a rectangle
// a.k.a. passed by reference, ownership is not taken by the following function
fn area(rect: &Rectangle) -> u32 {
    rect.width * rect.height
}

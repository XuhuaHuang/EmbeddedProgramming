/** Data Types in Rust
  * Xuhua HUANG
  * Feb 2021
  */

fn main() {

    // two data type subsets: scalar and compound

    // INTEGER
    // could be signed or unsigned
    // signed interfer types start with "i", unsigned ingeter types start with "u"
    // length could be 8-bit, 16-bit, 32-bit, 64-bit, 128-bit
    // notice that signed numbers are stored using two's complement representation
    // relying on integer overflow's wrapping behavior is considered as an error

    // unsigned 8-bit integer
    // will overflow outside of [0,255] inclusive
    let int1: u8 = 255;
    println!("The value of an unsigned 8-bit integer \"int1\" is: {}", int1);

    // FLOATING-POINT
    // f32 and f64 -> 32-bit and 64-bit repectively
    let x = 2.0; // defaulted to f64 with double precision
    let y: f32 = 3.0; // f32 with single precision
    // output
    println!("The value of a 64-bit floating point \"x\" is: {}", x); // 2.0
    println!("The value of a 32-bit floating point \"y\" is: {}", y); // 3.0

    // NUMERIC OPERATIONS
    let sum = 5 + 10; // addition
    let difference = 95.5 - 4.3; // subtraction
    let product = 4 * 30; // multiplication
    let quotient = 56.7 / 32.2; // division
    let remainder = 43 % 5; //

    // BOOLEAN
    let t = true;
    let mut f: bool = false; // with explicit type annotation
    f = true; // success with ketword "mut", as discussed in the previous notes

    // CHARACTER
    // 4 bytes Unicode Scalar Value
    // ranged [U+0000, U+D7FF] and [U+E000 , U+10FFFF]
    let char = 'c';
    let first_name = "Xuhua";

    // COMPOUND
    // group multiple values into one type
    // 2 primitive compound types -> tuples and arrays
    // tuple has a fixed length, can not grow or shrink once declared
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    // tup is a tuple with 32-bit signed integer, 64-bit floating point, 8-bit unsigned integer
    let (x, y, z) = tup; // tie three variables to tuple tup, automatically linked
    // output
    println!("\nPrinting tuple \"tup\" elements x, y, z sequencially: {}, {}, {}", x, y, z);

    // access tuple element with "tuple_name.index" -> index the value want to access
    let five_hundred = tup.0; // 600
    let six_point_four = tup.1; // 6.4
    let one = tup.2;
    // output
    println!("\nAccessing tuple \"tup\" elements with \"tuple_name.index\": {}, {}, {}",
    five_hundred, six_point_four, one);

    // ARRAY
    // element in the array must have the same type with fixed size
    // written as comma-seperated list inside square brackets - [1, 2, 3]
    let months: [&str; 12] = ["January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"];

    // let array_name: [data_type; array_size] = [value, value, ...];
    let a: [i32; 5] = [1, 2, 3, 4, 5];
    // array_name: a
    // data_type: 32-bit signed integer
    // array_size: 5

    // let array_name = [initial_value; size];
    // array of size provided with initial_value as elements
    let a = [3; 5]; // [3, 3, 3, 3, 3]

    // access ndividual element
    // array_name[index_of_element]
    let a: [i32; 5] = [1, 2, 3, 4, 5]; // reuse the same variable name as discussed before
    let first_element = a[0];
    let second_element = a[1];

    // INVALID ARRAY ELEMENT ACCESS
    let tenth_element = a[10]; // panic at run time -> index out of bounds
    // println!("The tenth element is: {}", tenth_element); // ERROR!

    // UPCOMING - functions
}

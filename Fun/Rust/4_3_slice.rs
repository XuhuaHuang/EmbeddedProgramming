/** Slice Type in Rust
  * Xuhua HUANG
  * Feb 2021
  */

// Slice lets us to refer to a contignous sequence of elements in a collection
// rather than the whole collection

fn main() {
    println!("Let's talk about slice type in Rust!");

    let mut greeting = String::from("Hello, world!");
    let index = first_word(&greeting); // 6
    println!("\nSpace found at index {} of string \"{}\"", index, greeting);
    greeting.clear(); // greeting is gone, while index still holds the value

    // SOLUTION to floating variables: string slices
    // refer to a portion of portion
    // creat slices with brackets: [starting_index, ending_index]
    // starting_index is inclusive, ending_index is exclusive
    let mut greeting = String::from("hello world");
    let hello = &greeting[0..5]; // let hello = &greeting[..5];
    let world = &greeting[6..11]; // let world = &greeting[6..len];

    println!("\nAfter slicing with \"&greeting[]\",");
    println!("Slices \"hello\" and \"world\" contains: {}, {}", hello, world);

    // dropping
    let len = greeting.len();
    let slice = &greeting[0..len]; // complete greeting
    // equivalent to: let slice = &greeting[..]; // 0 and last byte (len()) are dropped
    println!("\nWith syntax \"&greeting[0..len]\": {}", slice);

    // with rewritten function that returns a reference
    let index = rewrite_slice(&greeting); // expected 6
    // attempting to clear Stirng
    // greeting.clear(); // ERROR! A pointer to the string is returned to "index"
    println!{"\nVariable \"index\" is returned as: \"{}\" with function \"rewrit_slice()\" as a pointer", index};


    // String Literals as Slices
    // stirng literals are automatically string slices already
    // &str is the syntax of string literals, equivalent to &String[], refer to line 66 and 67

    // UPCOMING: Struct, object oriented FINALLY!
}

// returns a bype index value into the String parameter
fn first_word(s: &String) -> usize {
    // convert String to an array of bytes using "as_bytes()" method
    let bytes = s.as_bytes();

    //  create an iterator over the array using "iter()" method
    // (i, &item) is tuple: "i" - index, returned from enumerate()
    //                      "&item" - reference to the element
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' { // if we find a spcae with byte literal syntax
            return i; // return the index
        }
    }
    // otherwise return the length of the string
    s.len() // using expression to return
}


// &str means string literals
// allows this funcntion to take both &String and &str values
fn rewrite_slice(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i]; // if found, return portion up to index
        } // end if()
    } // end enumeration

    &s[..] // otherwise, return the entire string reference
}

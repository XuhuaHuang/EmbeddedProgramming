/** 8_2_utf8_strings.rs
  * UTF-8 Encoded Strings
  *
  * Xuhua Huang
  * April 2021
  */

/** 3 major headache:
  * Rust’s propensity for exposing possible errors
  * strings being a more complicated data structure than many programmers give them credit for
  * UTF-8
  *
  * operations on String that every collection type has, such as creating, updating, and reading
  * also discuss the ways in which String is different from the other collections
  * String: growable, mutable, owned, and UTF-8 encoded
  * Rust also includes other string types: OsString, IsStr, CString and CStr
  */

fn main() {
    println!("Let's about UTF-8 Encoded Strings");

    /* CREATE A NEW STRING */
    let mut str = String::new(); // create a new, empty string
    let data = "initial contents";
    str = data.to_string();
    print_string(&str);

    // the method to_string() also works on a literal directly
    // use to_string() method to create a String object from a string literal
    str = "initial contents with to_string() method".to_string();
    print_string(&str);

    // EQUIVALENT: String::from("string literals")
    str = String::from("initial contents with String::from() method");
    print_string(&str);

    /* UTF-8 ENCODED DATA */
    let hello_mandarin = String::from("你好");
    print_string(&hello_mandarin);

    /* UPDATING A STRING */
    // grow in size and its content can change
    // + operator and format! marco to concatenate strings

    /* Append to strings with push_str and push */
    str = String::from("Waiting for appending.");
    str.push_str(" Appended to string named \"str\"");
    print_string(&str);

    let mut original_string = String::from("original string");
    let to_append: &str = " push_str() with a String object";
    original_string.push_str(to_append); // appended to String object
    print_string(&original_string);

    /* The push method takes a single character as a parameter and adds it to the String */
    let mut s = String::from("lo");
    s.push('l');
    println!("String object named \"s\" contains content \"lol\"");
    print_string(&s);

    /* Concatenation with + operator or format! marco */
    let hello = String::from("Hello, ");
    let world = String::from("world!");
    let hello_world = hello + &world;
    // added a reference of String world to the String hello
    // implicit conversion from &String to &str to fit + operator
    // hello has been moved and no longer available
    println!("Two String objects are concatenated to form Hello, world!");
    print_string(&hello_world);

    /* format! marco */
    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");

    let s = s1 + "-" + &s2 + "-" + &s3;
    println!("printing tic tac toe concatenated with + operator");
    print_string(&s);

    println!("printing tic tac toe concatenated with format! marco");
    let s1 = String::from("tic"); let s2 = String::from("tac"); let s3 = String::from("toe");
    let s = format!("{}-{}-{}", s1, s2, s3);
    print_string(&s);

    /* INDEXING INTO STRINGS */
    // let s1 = String::from("hello");
    // let h = s1[0]; // ERROR! Type String can not be indexed by integer
    //         ^^^^^ `String` cannot be indexed by `{integer}`

    /* Internal Representation of Strings */
    /* A String is a wrapper over a Vec<u8> */
    /* Slicing Strings with O(1) time complexity */
    let hello = "Здравствуйте";
    let s = &hello[0..4];
    println!("printing first two bytes in string literal \"Здравствуйте\"");
    print_string(&String::from(s));

    /* ITERATING STRING OBJECTS */
    let hello_mandarin = String::from("你好");
    println!("iterating characters in String object \"你好\"");
    for char in hello_mandarin.chars() {
        println!("{}", char);
    }
    println!("iterating bytes in String object \"你好\"");
    for byte in hello_mandarin.bytes() {
        println!("{}", byte);
    }
}

// function to print the content of a String object
// with immutable reference
fn print_string(str: &String) {
    println!("{}", str);
}

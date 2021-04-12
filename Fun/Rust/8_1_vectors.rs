/** 8_1_vectors.rs
  * Common Collections
  *
  * Xuhua Huang
  * April 2021
  */

/** vectors allow storing a variable number values next to each other
  * string is a collection of characters
  * hash map allows associating a value with a particular key
  */

fn main() {
    println!("Let's about storing values in vectors!");

    // create a new vector of type i32 on the heap
    let mut v: Vec<i32> = Vec::new();

    // vec! marco
    // create a new vector that holds the values once given
    v = vec![1, 2, 3];

    /* UPDATE A VECTOR */
    let mut v = Vec::new();
    for i in 4..11 {
        v.push(i);
    }
    {
        let v = vec![1,2 ,3, 4];
        // do stuff with v
    } // <- v goes out of scope and it is freed

    /* READING ELEMENTS OF VECTORS */
    let third: &i32 = &v[2];
    println!("The third element is {}", third);

    // retrieve element with [] operators or .get()
    match v.get(2) {
        Some(third) => println!("The third element is {}", third),
        None => println!("There is no third element"),
    }

    /* out of range err */
    // let does_not_exist: i32 = &v[100];
    // let does_not_exist: i32 = v.get[100];

    // let first: &i32 = &v[0]; // ERROR! Immutable borrow occurs here
    // v.push(11); // mutable borrow occurs here
    // println!("The first element is: {}", first);

    /* ITERATING OVER THE VALUES IN A VECTOR */
    println!("Print vector with immutable borrow");
    for i in &v {
        println!("{}", i);
    }
    println!("Print vector with mutable borrow and add 50 to each element beforehand");
    for i in &mut v {
        *i += 50;
        println!("{}", i);
    }

    /* USING ENUMS TO STORE MULTIPLE TYPES */
    #[derive(Debug)]
    enum SpreadsheetCell {
        Int(i32),
        Float(f64),
        Text(String),
    }

    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Float(11.13),
        SpreadsheetCell::Text(String::from("I want to work for ORS")),
    ];

    println!("Print with (Debug) {:?}", row);
}

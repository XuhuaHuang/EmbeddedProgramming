/** 8_3_keys_values.rs
  * Storing keys with associated values in Hash Maps
  *
  * Xuhua Huang
  * May 2021
  */

/** About this document
  * Basic API of hash maps
  * look up data by using an index
  * 'HashMap<K, V>'
  */
fn main() {
    println!("Let's talk about key-value pairs in Rust!");

    /* Create New Hash Map with new
     * Add element with insert
     */
    use std::collections::HashMap;
    // need bringing into scope
    // it is not automatically imported
    let mut scores:HashMap<String, u8> = HashMap::new();
    // all keys must have the same type of String
    // all values must have the same type of 8-bit unsigned integer
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Grey"), 50);

    /* Using 'collect' Method on vectors/tuples */
    let teams:Vec<String> = vec![String::from("Blue"), String::from("Grey")];
    let initial_scores:Vec<u8> = vec![10, 50];
    let mut scores: HashMap<String, u8> =
        teams.into_iter().zip(initial_scores.into_iter()).collect();

    /* Hash Map and Ownership */
    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");

    let mut map:HashMap<String, String> = HashMap::new();
    map.insert(field_name, field_value);
    // field_name and field_value are invalid at this point
    // println!("Attempting to read used values: {}, {}", field_name, field_value);
    // value borrowed here after move

    /* Accessing Values in a Hash Map with 'get' method */
    let team_name:String = String::from("Blue");
    let score = scores.get(&team_name); // get score for team named "Blue"
    // get() return an Option<&V> which includes Some and None
    println!("With HashMap.get() method: key:{}, value:{:?}", team_name, score);

    // print hash Map with a for-loop
    // refer to scores
    for (key, value) in &scores {
        println!("Team {} has score {}", key, value);
    }

    /* Overwriting a Value */
    scores.insert(String::from("Blue"), 25);
    // expecting blue team has updated value
    println!("{:#?}", scores);

    /* Only Insert Entry If Key Has No Value */
    scores.entry(String::from("Yellow")).or_insert(90);
    // expecting inserted team Yellow with 90 score
    println!("{:#?}", scores);

    /* Look Up a Value and Update Accordingly */
    let text = "hello world wonderful world";
    let mut map:HashMap<&str, u8> = HashMap::new();
    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1; // Note: count is an iterator
    }
    println!("{:#?}", map);
}
// UPCOMING: Error handling

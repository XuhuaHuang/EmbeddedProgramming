/** 7_2_modules_scope_doc.rs
  * Modules and control scope in Rust
  * paths: naming items (ideally consistently)
  *
  * 'use' keyword: bring path into scope
  * 'pub' keyword: make items public
  * 'as' keyword: UNKNOWN
  *
  * Xuhua Huang
  * March 2021
  */

/** MODULES
  * control the privacy of items: public/private
  * EXAMPLE: restaurant -> front house and back house
  * "cargo new --lib restaurant" command to create a library
  * module can contain multiple internal modules
  * can also hold definitions of other items: structs, enums, constants, traits
  * module tree shows the structure of the module, as "lib.rs" is called the root of crate
  */

fn main() {
    println!("Let's talk about modules and control scope in Rust!");
    pritnln!("Parent and child modules example can be found in file \"7_2_modules_scope_lib.rs\"");
}

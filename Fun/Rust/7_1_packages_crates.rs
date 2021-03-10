/** 7_1_packages_crates.rs
  * Packages and crates in Rust
  *
  * Xuhua Huang
  * March 2021
  */

/** packages: Cargo feature to build, test, and share crates
  * crates: a tree of modules that produces a library of executables
  * modules and use: control the organization, scope and privacy of paths
  * paths: a way of naming an item: struct, function, module
  */

/** PACKAGE
  * Cargo.toml indicates the folder is a package
  * Convention: src/main.rs is the crate root of a binary crate
  * src/lib.rs is the crate root for library crate -> 2 parts: library and binary
  */

 /* CRATE
  * group related functionality together in a scope
  * experience so far: rand crate to generate random number
  * trait: rand::Rng
  */

fn main() {
    println!("Hello packages and crates!");
}

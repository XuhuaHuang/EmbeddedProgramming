/** lib.rs
  * parent and child module related to the
  * context of a restaurant
  * this is brought from package learn_7_4_path_referring/src/main.rs
  *
  * Xuhua Huang
  * April 2021
  */

// module "front_of_house" contains other modules
// parent module
mod front_of_house {
    // pub keyword is necessary
    pub mod hosting {
        // without pub keyword, it will be a private function
        pub fn get_empty_space() -> bool {
            println!("front_of_house::[pub]hosting::[pub]fn get_empty_space");
            println!("If there is an empty space, return true; if not, return false");
            true
        }

        pub fn add_to_waitlist() {
            println!("front_of_house::[pub]hosting::[pub]fn add_to_waitlist");
        }

        pub fn seat_at_table() {
            println!("front_of_house::[pub]hosting::[pub]fn seat_at_table");
        }
    }
}

// parent module
mod back_of_house {
    fn fix_incorrect_order() {
        // calling private function cook_order() within the same module
        cook_order();
        // super brings the path back the file which contains module back_of_house
        // lib.rs global function
        super::serve_order();
    }

    fn cook_order() {}

    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            } // end trailing return
        } // end pub fn summer
    } // end impl breakfast

    pub enum Appetizer {
        Soup,
        Salad,
    }
}

// global function
// without keyword "pub", the following function is private
fn serve_order() {}

// pub keyword makes an item public
pub fn eat_at_restaurant() {
    // call function in crate created in 7_3_mod_restaurant
    // absolute path
    crate::front_of_house::hosting::add_to_waitlist();
    // relative path
    front_of_house::hosting::add_to_waitlist();

    // order a breakfast in the summer with Rye toast
    let mut meal = back_of_house::Breakfast::summer("Rye");
    // set bread to Whole Wheat
    meal.toast = String::from("Whole Wheat");
    // meal.seasonal_frUit = String::from("blueberries"); // ERROR! private field!
    println!("I would like {} toast please", meal.toast);
    let order1 = back_of_house::Appetizer::Soup;
    let order2 = back_of_house::Appetizer::Salad;
}

pub fn eat_at_restaurant_7_5_use()
{
    // this is an implementation restricted to this package
    // with one of the two lines listed in the following, bring crate front_of_house::hosting into
    // scope
    use crate::front_of_house::hosting; // absolute path
    // use self::front_of_house::hosting; // relative path
    hosting::add_to_waitlist();

    // idiomatic use paths
    use crate::front_of_house::hosting::add_to_waitlist;
    add_to_waitlist();
}

// re-exporting name with keyword "pub use"
pub use crate::front_of_house::hosting;
// member functions under mod hosting will be available globally
pub fn eat_at_restaurant_7_5_pub_use() {
    hosting::add_to_waitlist();
}

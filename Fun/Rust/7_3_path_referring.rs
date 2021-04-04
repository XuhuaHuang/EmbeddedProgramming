/** 7_3_path_referring.rs
  * absolute path starts from a carte root with carte name or a literal carte
  * relative path starts from current module and used self, super to refer
  * both absolute and relative path are followed by one or more identifiers separated by::
  *
  * Xuhua Huang
  * March 2021
  */

mod front_of_house {
    // pub keyword is necessary or line 21 and 23 will give error
    pub mod hosting {
        // without pub keyword, it will be a private function
        pub fn add_to_waitlist() {
            println!("front_of_house::[pub]hosting::[pub]fn add_to_waitlist");
        }
    }
}

mod back_of_house {
    fn fix_incorrect_order() {
        // calling private function cook_order() within the same module
        cook_order();
        // super brings the path back the file which contains module back_of_house
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

fn main() {
    println!("Let's talk about referring path to a module in Rust!");

    eat_at_restaurant();
}

/** 7_2_modules_scope_lib.rs
  * Parent and child module related to the
  * context of a restaurant
  *
  * Xuhua Huang
  * March 2021
  */

// module "front_of_house" contains other modules
// parent module
mod front_of_house {
    // 1/2 child module
    mod hosting {
        fn get_empty_space() -> bool {}

        fn add_to_waitlist() {}

        fn seat_at_table() {}
    } // mod hosting

    // 2/2 child module
    mod serving {
        fn take_order() {}

        fn serve_order() {}

        fn take_payment() {}
    } // mod serving

} // end front_of_house module
// UPCOMING: find our modules

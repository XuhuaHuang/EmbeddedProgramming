// use statemwnts
use std::io; // input/outpout library
use rand::Rng; // Rng trait defines methods for random number generator
use std::cmp::Ordering; // bring this to scope from standard library
						// Ordering is an enum [Less, Greater, Equal]

fn main() {
	println!("Guess the number!");

	let secret_number = rand::thread_rng().gen_range(1, 101);
	// thread_rng() is the random number generator
	// gen_range() is the method
	// gen_range(inclusive, exclusive) - first_argument <= rand_num < second_argument

	println!("The secret number is {}", secret_number);

	// allow multiple guess with looping
	loop {
		println!("Please input your guess");

		let mut guess = String::new(); // mut keyword makes the variable mutable

		io::stdin()
			.read_line(&mut guess) // pass by reference
			.expect("Failed to read line");

		// convert guess to another type - unsigned 32 bit integer
		// parse() method returns a type 'Result' to handle potential failure
		// trim() eliminate whitespace at the beginning and the end: (5\n).trim() => 5
		let guess: u32 = match guess.trim().parse() {
			Ok(num) => num,
			Err(_) => continue,
		};

		println!("You guessed: {}", guess);

		// comapre guess to secret_number
		// match statement consists arms
		// cmp() method returns an arm
		match guess.cmp(&secret_number) {
			Ordering::Less => println!("Too small!"),
			Ordering::Greater => println!("Too big!"),
			Ordering::Equal => {
				println!("You win!");
				break;
			} // end Ordering::Equal arm
		} // end match
	} // end loop
} // end main

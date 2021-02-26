/** Enumerations in Rust
  * useful enum - Option
  * match expression
  * if let construct
  *
  * Xuhua HUANG
  * Feb 2021
  */

// create an enum of IP address
// either IPv4 or IPv6
#[derive(Debug)]
enum IpAddrKind {
    V4,
    V6,
}

// create a new enum with different associated data type
#[derive(Debug)]
enum IpAddrKindType {
    V4(u8, u8, u8, u8), // interpreted as overloaded constructor
    V6(String),
}

// implementation of a enumeration IpAddrKindType
impl IpAddrKindType {
    // print IPv4
    fn print_ipv4(&self) {
        println!("\nIn function \"IpAddrKindType::print_IPv4()\"");
        // println!("IPv4 address: {:#?}", IpAddrKindType::V4); // ERROR! I can't figure out how
    }
}

// create an IP struct
#[derive(Debug)]
struct IpAddress {
    kind: IpAddrKind, // enum, either V4 or V6
    address: String,
}

fn main() {
    println!("Let's talk about enumerations in Rust!");

    // create instances of two variants of IpAddrKind
    let four = IpAddrKind::V4;
    let six = IpAddrKind::V6;

    // call function with IpAddrKind instances
    route(four);
    route(six);

    // create a home IP and loopback with IpAddress struct
    let home_ip = IpAddress {
        kind: IpAddrKind::V6,
        address: String::from("192.168.1.1"),
    };
    println!("\nThe IP address for home is: {:#?}", home_ip);

    // create a loopback address
    let loopback = IpAddress {
        kind: IpAddrKind::V6,
        address: String::from("::1"),
    };
    println!("\nThe loopback address is: {:#?}", loopback);

    // reassign value with data type specified enumeration
    let home_ip = IpAddrKindType::V4(192, 168, 1, 1);
    println!("\nThe IP address for home is: {:#?}", home_ip);

    let loopback = IpAddrKindType::V6(String::from("::1"));
    println!("\nThe loopback address is: {:#?}", loopback);

    // call function with IpAddrKindType::V4 enum instance
    home_ip.print_ipv4();

    // Option Enum
    // null and non-null
    // enum Option<T> { Some(T), None, }
    // <T> is the generic type parameter
    // do not need to prefix with "Option::"
    let some_number = Some(5);
    let some_string = Some(String::from("Hello, world!"));
    let null_number: Option<i32> = Option::None; // allocate 32-bit space for nothing

}

// empty function that takes ownership and does nothing
fn route(_ip_kind: IpAddrKind) {}

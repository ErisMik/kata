// Eric Mikulin, 15-10-2019
// Fizzbuzz

use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    let end_value: i32 = args[1].parse().unwrap();

    for n in 1..=end_value {
        if n % 3 == 0 && n % 5 == 0{
            print!("fizzbuzz")
        } else if n % 5 == 0 {
            print!("fizz")
        } else if n % 5 == 0 {
            print!("buzz")
        } else {
            print!("{}", n)
        }
        print!(" ")
    }
    println!("")
}
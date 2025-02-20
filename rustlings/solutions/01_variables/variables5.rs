fn main() {
    let mut number = "T-H-R-E-E";
    println!("Spell a number: {}", number);

    // Using variable shadowing
    // https://doc.rust-lang.org/book/ch03-01-variables-and-mutability.html#shadowing
    number = "F-I-V-E";
    println!("Number plus two is: {}", number);
}

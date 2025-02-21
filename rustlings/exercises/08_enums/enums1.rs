#[derive(Debug)]
enum Message {
    Resize = 0,
    Move = 1,
    Echo = 2,
    ChangeColor = 3,
    Quit = 4,
}

fn main() {
    println!("{:?}", Message::Resize);
    println!("{:?}", Message::Move);
    println!("{:?}", Message::Echo);
    println!("{:?}", Message::ChangeColor);
    println!("{:?}", Message::Quit);
}

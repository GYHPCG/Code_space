/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-09-29 21:04:05
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-09-29 21:23:32
 */
#[derive(Debug)]
enum Message {
    Quit,
    Move {x: i32, y: i32},
    Write(String),
    ChangeColor(u8, u8, u8),
}
impl Message {
    fn process(&self) {
        println!("TTT: {:#?}", self);
        match self {
            Message::Quit => println!("Quit"),
            Message::Move { x, y } => println!("Move to ({}, {})", x, y),
            Message::Write(text) => println!("Write: {}", text),
            // Message::ChangeColor(r, g, b) => println!("Change color to ({}, {}, {})", r, g, b),
            _ => println!("default"),
        }
    }
}


fn main() {

    let msg = Message::Write("Hello, rust".to_string());

    // 调用方法
    msg.process(); // 输出：Write: Hello, Rust!

    let some_number = Some(6);

    match some_number {
        Some(x) => println!("The number is {}", x),
        _ => println!("default"),
    }
}


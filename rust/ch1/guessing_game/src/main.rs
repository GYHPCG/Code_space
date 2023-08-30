/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2023-07-07 20:49:35
 * @LastEditors: CGPan
 * @LastEditTime: 2023-07-18 18:57:10
 */
use std::io;
use std::io::Read;
use rand::Rng; //trait

fn main() {
    println!("Guess the number!");

    let scert_number = rand::thread_rng().gen_range(1,101);
    
    println!("神秘数字是{}", scert_number);

    println!("Please input your guess.");
 
    let mut guess =  String::new();

    io::stdin().read_line(&mut guess).
        expect("Failed to read line");

    println!("You guessed: {}",guess);

    println!("fun is {}", five());

}

fn five() -> i32 {
    5
}



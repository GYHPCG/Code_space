
enum List {
    Cons(i32, Rc<List>),
    Nil,
}
use std::rc::Rc;

use crate::List::{Nil, Cons};

fn main() {
    // println!("Hello, world!");

    // let a = Rc::new(Cons(1, Rc::new(Cons(2, Rc::new(Nil)))));

    // {
    //     let b = Rc::new(Cons(3, Rc::clone(&a)));
    // }

    // println!("ref count of a is {}", Rc::strong_count(&a));

    let r1: str  = "hello";
    let hk = String::from("hello");
    

}

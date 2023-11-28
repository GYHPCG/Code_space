
trait Age {
    fn get_age(&self) -> u32;
    fn get_name(&self) -> &String;
}
struct Student {
    name: String,
    age: u32,
}
impl Age for Student {
    fn get_age(&self) -> u32 {
        self.age
    }
    fn get_name(&self) -> &String {
        &self.name
    }
}

impl Drop for Student {
    fn drop(&mut self) {
        println!("{} leave ", self.get_name());
    }
}

fn main() {

    let s1 = Student{
        name: "Jack".to_string(),
        age: 18,
    };

    let vec = vec![12,3];
    let tt = "hello";

    println!("age is {}", s1.get_age());
    println!("name is {}", s1.get_name());

    //println!("Hello, world!");
}

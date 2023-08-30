
//泛型编程，PariaOrd实现排序大小比较功能，Copy实现给larger赋值
fn largets<T: PartialOrd + Copy>(list: &[T]) ->T {
    let mut larger = list[0];

    for i in list.iter() {
        if *i > larger {
            larger = *i;
        }
    } 
    larger
} 

fn main() {
    // println!("Hello, world!");

    let ve1 = vec![6, 7, 1, 4, 89, 12, 90];
    let larger = largets(&ve1);
    println!("largest = {}", larger);

    let ve2 = vec!['q', '9', 'k', 'l'];
    let larger = largets(&ve2);

    println!("largest = {}", larger);

}

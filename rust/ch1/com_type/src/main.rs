
//计算长方形的面积和周长

#[derive(Debug)]
struct Rectangle {
    width: u32,
    length: u32,
}

impl Rectangle {
    //函数
    fn square(size: u32) ->Rectangle{
        Rectangle { width: size, length: size }
    }


    //方法
    fn area(&self) ->u32
    {
        self.width * self.length
    }
    
}


fn main() {
    
    let rect = Rectangle{
        width: 30,
        length: 50,
    };

    let square = Rectangle::square(20);
    
    println!("关联构造函数：{:?}", square);

    println!("{}", rect.area());

    let v = Some(3);

    match v {
        Some(1) => println!("Yes"),
        _ => println!("false"),
    }
    if let  Some(7) = v  {
        println!("true");
    }
    else {
        println!("false");
    }


}

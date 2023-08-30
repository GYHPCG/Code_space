/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2023-07-18 19:36:27
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-08-05 14:52:12
 */
fn main() {
   let mut s1 = String::from("hello, world");
   //let s2 = s1; // s1被移动了，要使用clone的trait
    take_ownship(&s1);

    println!("test : {}", s1);

    let ve = vec![1,2,3,4,5];
    println!("ve[0] = {}", &ve[0]);
    
    let st = "1234".to_string();
    //let s3 = String::new();
    //s1.push_str(&st);
    let s3 = s1 + &st;
    println!("{}", st);
    
    
}

fn take_ownship(str: &String)
{
    println!("ownship is moved {}", str);
}

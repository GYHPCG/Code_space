/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2023-06-28 10:53:44
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-09-29 20:27:05
 */
fn main() {
    println!("Hello, world!");

    let mut s = "hello".to_string();
    println!("{s}");

    let rs = &mut s;

    rs.push('!');

    println!("{rs}");

    let rs2 = &mut s;
    rs2.push('!');

    println!("{}", rs2);

    let us = "hello";



}

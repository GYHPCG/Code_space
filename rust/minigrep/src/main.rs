/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-07-27 15:13:59
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-07-28 18:27:14
 */

use minigrep::Config;
use std::env;
use std::process;

fn main() {
    let args: Vec<String> = env::args().collect();
    let config = Config::new(&args).unwrap_or_else(|err|{
        eprintln!("problem parsing arguments: {}", err);
        process::exit(1);
    });
    

    if let Err(e) =  minigrep::run(config){
        eprintln!("Application parsing arguments: {}", e);
        process::exit(1);
    };
     

}



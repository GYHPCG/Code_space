/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-15 12:52:11
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-07 20:32:44
 */
import axios from 'axios'
import router from "@/router";
import Cookies from 'js-cookie';
// 创建可一个新的axios对象
const request = axios.create({
    baseURL: "http://localhost:8080/api",   // 后端的接口地址  ip:port
    timeout: 30000,                          // 30s请求超时
    headers: {"Content-Type": "multipart/form-data;charset=UTF-8"},
    dataType: "json"
})

// request 拦截器
// 可以自请求发送前对请求做一些处理
// 比如统一加token，对请求参数统一加密
request.interceptors.request.use(config => {
    config.headers['Content-Type'] = 'application/json;charset=utf-8';        // 设置请求头格式
    // let user = JSON.parse(localStorage.getItem("xm-user") || '{}')  // 获取缓存的用户信息
    const user = Cookies.get("user")
    if (user) {
        // router.push("/login")
        config.headers['token'] = JSON.parse(user).token
    }
    // else {
        
    // }
    // config.headers['token'] = user.token  // 设置请求头

    return config
}, error => {
    console.error('request error: ' + error) // for debug
    return Promise.reject(error)
});

// response 拦截器
// // 可以在接口响应后统一处理结果
request.interceptors.response.use(
    // response => {
    //     // let res = response.data;
    //     let res = response;

    //     // 兼容服务端返回的字符串数据
    //     if (typeof res.data === 'string') {
    //         res.data = res.data ? JSON.parse(res.data) : res.data
    //     }
    //     if (res.data.code === '401') {
    //         router.push('/login')
    //     }
    //     return res;
    // },
    // error => {
    //     console.error('response error: ' + error) // for debug
    //     return Promise.reject(error)
    // }
)


export default request
/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-10 17:01:13
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-06 20:22:16
 */
const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true,
  lintOnSave:false,
  devServer: {
    // host: '0.0.0.0',
    // // https:true,
    // port: 6103,
    client: {
      webSocketURL: 'ws://0.0.0.0:6103/ws',
    },
    headers: {
      'Access-Control-Allow-Origin': '*',
    },
    proxy: {
      '^/api': {
        target: 'http://localhost:8080/',//接口的前缀
        ws:true,//代理websocked
        changeOrigin:true,//虚拟的站点需要更管origin
        pathRewrite:{
          '^/api':''//重写路径
        }
      }
    }
  },
})

module.exports = {
  lintOnSave: false,
}



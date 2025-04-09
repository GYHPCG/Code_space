/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-10 17:01:13
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-06 20:53:05
 */
const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true,
  lintOnSave:false,
  devServer: {
    host: '0.0.0.0',
    // https:true,
    port: 6103,
    client: {
      webSocketURL: 'ws://0.0.0.0:6103/ws',
    },
    headers: {
      'Access-Control-Allow-Origin': '*',
    }
  },
})

module.exports = {
  lintOnSave: false,
}



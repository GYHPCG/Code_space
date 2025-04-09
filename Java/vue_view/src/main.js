/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-11 17:17:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-06 20:07:42
 */
import Vue from 'vue'
import App from './App.vue'
import router from './router'
import ElementUI from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';
import  '@/assets/css/common.css'
import axios from 'axios'
import request from "@/utils/request";
// axios.defaults.baseURL = "http://localhost:9099/api"
// request.defaults.baseURL = "http://localhost:9099/api"
request.defaults.baseURL = "http://localhost:8080"
Vue.prototype.$http = request;

Vue.config.productionTip = false
Vue.use(ElementUI);
new Vue({
  router,
  render: h => h(App)
}).$mount('#app')

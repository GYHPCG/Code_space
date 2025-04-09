/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-11 17:17:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-01-15 23:29:46
 */
import Vue from 'vue'
import App from './App.vue'
import router from './router'
import ElementUI from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';
import  '@/assets/css/common.css'
import request from "@/utils/request";
// request.defaults.baseURL = "http://localhost:9099/api"
Vue.prototype.$http = request;
Vue.prototype.$baseUrl=process.env.VUE_APP_BASEURL

Vue.config.productionTip = false
Vue.use(ElementUI);
new Vue({
  router,
  render: h => h(App)
}).$mount('#app')

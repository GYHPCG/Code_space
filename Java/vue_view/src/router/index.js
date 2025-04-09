/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-11 17:17:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-06 20:42:15
 */
import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
import Cookies from 'js-cookie'
Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView,
    redirect: '/home',
    children: [
      {
         path: 'home',
         component: () => import('../views/element/front/Index.vue')
      },
      {
        path: 'user',
        component: () => import('../views/element/user/User.vue')
      },
      {
        path: 'admin',
        component: () => import('../views/element/admin/Admin.vue')
      },
      {
        path: 'book',
        component: () => import('../views/element/book/Book.vue')
      }
    ]
  },
  {
    path: '/about',
    name: 'about',
    // route level code-splitting
    // this generates a separate chunk (about.[hash].js) for this route
    // which is lazy-loaded when the route is visited.
    component: () => import(/* webpackChunkName: "about" */ '../views/AboutView.vue')
  },
  {
    path: '/login',
    component: () => import('../views/element/front/Login.vue')
  },
  {
    path: "/register",
    component: () => import('../views/element/front/Register.vue')
  },
  {
    path: "*",
    component: () => import('../views/element/front/404.vue')
  },
  {
    path: "/front",
    name: "FrontHome",
    redirect: '/front/index',
    component: () => import('@/views/element/front/FrontHome.vue'),
    children: [
      {
        path: "index",
        component: () => import('@/views/element/front/FrontIndex.vue')
      },
      // 书籍详情页面
      {
        path: "bookDetail/:id",//使用动态路由参数表示书籍的ID 
        name: "BookDetail",
        component: () => import('@/views/element/front/BookDetail.vue'),
        props: true // 将路由参数作为组件的props传递
      },
      {
        path: 'browDisc',
        component: () => import('../views/element/front/BrowDisc.vue')
      },
      {
        path: 'readPizza',
        component: () => import ('../views/element/front/ReadPizza.vue')
      },
      {
        path: 'ReadGroup',
        component: () => import ('../views/element/front/ReadGroup.vue')
    
      },
      {
        path: 'personalInfo',
        component: () => import ('../views/element/front/PersonalInfo.vue')
      },
      {
        path: "/bookList/:bookListId",
        name: "bookList",
        component: () => import('@/views/element/book/BookList.vue'),
        props: true
    
      }
      
    ],
    
  },
 
  
  
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

//路由守卫
router.beforeEach((to, from, next) => {
    if (to.path==="/login" || to.path=== "/register" || to.path === "/front/index") return next()
    // const user = Cookies.get("user")
    // if (!user && to.path !==("/login" || "/register")) return next("/login")
    next()
})
export default router

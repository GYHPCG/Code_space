/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-11 17:17:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-01-03 09:57:20
 */
import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
Vue.use(VueRouter)

const routes = [
  {
   path: '/',
   name: 'home',
   redirect: '/front/index'
  },
  {
    path: '/back',
    name: 'back',
    component: HomeView,
    redirect: '/back/home',
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
      },
      {
        path: 'author',
        component: () => import('../views/element/author/AuthorManager.vue')
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
        component: () => import('@/views/element/book/BookDetail.vue'),
        props: true // 将路由参数作为组件的props传递
      },
      {
        path: 'beAuthor',
        // redirect: '/front/author/home',
        component: () => import('../views/element/author/beAuthor.vue')
      },
      {
        path: "searchBook",
        component:() => import('@/views/element/book/SearchBook.vue')
      },
      {
        path: 'review',
        name: 'review',
        component: () => import('@/views/element/author/Review.vue')

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
    
      },
      {
        path: 'author',
        name: 'author',
        redirect: '/author/home',
        component: () => import('@/views/element/author/Author.vue'),
        children: [
          {
            path: 'home',
            name: 'authorHome',
            component: () => import('@/views/element/author/AuthorHome.vue')
          },
          {
            path: 'manager',
            name: 'managerBook',
            component: () => import('@/views/element/author/ManagerBook.vue')
          },
        ]
      },
      {
        path: '/writeBook/:bid',
        name: 'writeBook',
        component: () => import('@/views/element/author/WriteBook.vue')
      },
      {
        path: "/lookBook/:bid",
        name: 'lookBook',
        component: () => import('@/views/element/book/LookBook.vue')
      },
      {
         path: '/bookInfo',
         name: 'bookInfo',
         component: () => import('@/views/element/book/BookInfo.vue')  
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
    const user = JSON.parse(localStorage.getItem("user") || null)
    if (to.path=="/login" || to.path== "/register" || to.path == "/front/index") return next()
    if (!user && (to.path !="/login" || to.path != "/register")) return next("/login")
    if (user != null) {
       if (user.role == '读者') {
          if (to.path.startsWith('/admin')) next("front/index")
          if (to.path.startsWith('/author')) next("front/index")
          if (to.path.startsWith('/write')) next("front/index")
       }
      else if (user.role == '作家') {
        if (to.path.startsWith('/admin')) next('/front/author/home')
      }
    }
    next()
})
export default router

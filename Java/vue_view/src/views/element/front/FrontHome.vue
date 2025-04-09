<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-12-03 12:45:37
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-04 12:39:18
-->
<template>
  <div style="width: 100%; text-align: center;">
    <div  style="margin: 0 auto; width: 80%;">
        <!-- 头部 -->
        <header style="width: 100%;"> 
        <img src="@/assets/img/logo.png" alt="">
        <span>阅界，一个自由的阅读交流网站</span>
        <div class="left_tab"> 
            <router-link to="/front/index" class="router-link">首页</router-link>
            <router-link to="/front/ReadGroup" class="router-link">小组</router-link>
            <router-link to="/front/readPizza" class="router-link">阅读广场</router-link>
            <router-link to="/front/browDisc" class="router-link">浏览发现 </router-link>
            <router-link to="/login" class="router-link">登录 /</router-link>
            <router-link to="/register" class="router-link">注册</router-link>
            
        </div>
        </header>
         <router-view></router-view>
    </div>
  </div>
</template>

<script>
import Cookie from "js-cookie"
export default {
    name: "FrontHome",
   data() {
    // 新旧密码校验
    const validatePassword = (rule, confirmPass, callback) => {
        if (confirmPass === '') {
          callback(new Error('请确认密码'))
        } else if (confirmPass === this.form.password) {
          callback(new Error('旧密码和新密码一致'))
        } else {
          callback()
        }
      }
    return {
      user: Cookie.get("user")?JSON.parse(Cookie.get("user")):{},
      form: {
        
      },
      dialogVisible: false,
      rules: {
         passwd: [
            { required: true, message: '请输入密码', trigger: 'blur' },
          ],
          newPasswd: [
            { validator: validatePassword, trigger: 'blur' }
          ]
       }
    }
   },
   methods: {
    logout() {
      Cookie.remove("user")
      this.$router.push("/login")
    },
    updatePasswd() {
      this.form.name = this.user.name
      this.$refs['formRef'].validate((valid) => {
        if (valid) {
          // 验证通过
          this.$http.put('/admin/updatePasswd', this.form).then(res => {
            if (res.data.code === '200') {
              this.$message.success('修改成功')
              Cookie.remove("user")
              this.$router.push('/login')  // 跳转登录页面
            } else {
              this.$message.error("修改失败")
            }
          })
        }
      })
    },
    clear() {
      this.form = {}
    }

   }
};
</script>

<style scoped>
/* //头部 */
header {
    height: 50px;
    line-height: 50px;
    background-color: white;
    margin-bottom: 4px;
    /* border: 1px solid; */
}
header img {
    width: 40px;
    position: relative;
    left: 20px;
    top: 10px;

}
header span {
    margin-left: 30px;
    font-size: 20px;
    width: 200px;
    margin-bottom: 30px;
    font-style: normal;
    color: cornflowerblue;
}

header .left_tab {
    margin-left: 35%;

    display: inline;
    height: 30px;

}

header .router-link {
    font-size: 15px;
    color: darkgreen;
    margin-left: 10px;
}
</style>
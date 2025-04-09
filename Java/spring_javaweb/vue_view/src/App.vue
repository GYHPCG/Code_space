
<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-10 17:01:13
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-04 11:12:01
-->
<template>
  <div id='APP' style="width: 100vw;">
      <router-view/>

      <footer>

      </footer>

  </div>
</template>

<script>
import ElementTab from "./views/element/ElementTab.vue";
import AdminFunctionView from "./views/element/admin/AdminFunctionView.vue";
import Cookie from "js-cookie"
export default {
  components: { ElementTab,
    AdminFunctionView
   },
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
</style> 

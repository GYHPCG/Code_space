<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-29 19:48:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-06 22:40:48
-->
<template>
    <div class="container">
      <div style="opacity: 0.8; width: 400px; height: 400px; padding: 30px; background-color: white; border-radius: 5px;">
        <div style="text-align: center; font-size: 20px; margin-bottom: 20px; color: #333">欢迎注册</div>
        <el-form :model="form" :rules="rules" ref="formRef">
          <el-form-item prop="name">
            <el-input prefix-icon="el-icon-user" placeholder="请输入账号" v-model="form.name"></el-input>
          </el-form-item>
          <el-form-item prop="passwd">
            <el-input prefix-icon="el-icon-lock" placeholder="请输入密码" show-password  v-model="form.passwd"></el-input>
          </el-form-item>
          <el-form-item prop="confirmPass">
            <el-input prefix-icon="el-icon-lock" placeholder="请确认密码" show-password  v-model="form.confirmPass"></el-input>
          </el-form-item>
          <el-form-item>
            <el-button style="width: 100%; background-color: rgb(68, 142, 117); border-color: #333; color: white" @click="register">注 册</el-button>
          </el-form-item>
          <div style="display: flex; align-items: center">
            <div style="flex: 1"></div>
            <div style="flex: 1; text-align: right">
              已有账号？请 <a href="/login">登录</a>
            </div>
          </div>
        </el-form>
      </div>

      
    </div>
  </template>
  
  <script>
  export default {
    name: "Register",
    data() {
      // 验证码校验
      const validatePassword = (rule, confirmPass, callback) => {
        if (confirmPass === '') {
          callback(new Error('请确认密码'))
        } else if (confirmPass !== this.form.password) {
          callback(new Error('两次输入的密码不一致'))
        } else {
          callback()
        }
      }
      return {
        form: {},
        rules: {
          username: [
            { required: true, message: '请输入账号', trigger: 'blur' },
          ],
          password: [
            { required: true, message: '请输入密码', trigger: 'blur' },
          ],
          confirmPass: [
            { validator: validatePassword, trigger: 'blur' }
          ]
        }
      }
    },
    created() {
  
    },
    methods: {
      register() {
        this.$refs['formRef'].validate((valid) => {
          if (valid) {
            // 验证通过
            this.$http.post('/register', this.form).then(res => {
              if (res.code === '200') {
                this.$router.push('/login')  // 跳转登录页面
                this.$message.success('注册成功')
              } else {
                this.$message.error(res.msg)
              }
            })
          }
        })
      }
    }
  }
  </script>
  
  <style scoped>
  .container {
    height: 100vh;
    overflow: hidden;
    background-image: url("@/assets/img/3.jpg");
    background-size: 100%;
    display: flex;
    align-items: center;
    padding-right: 70px; 
   justify-content: end;  
    color: #666;
  }
  a {
    color: #2a60c9;
  }
  </style>
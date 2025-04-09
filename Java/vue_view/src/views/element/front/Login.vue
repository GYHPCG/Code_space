<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-28 18:28:33
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-07 20:07:05
-->

<template>
  <div class="container">
    <div style="opacity: 0.8; width: 400px; height: 400px; padding: 30px; background-color: white; border-radius: 5px;">
      <div style="text-align: center; font-size: 20px; margin-bottom: 20px; color: #333;">欢迎登录</div>
      <el-form :model="form" :rules="rules" ref="formRef">
        <el-form-item prop="name">
          <el-input prefix-icon="el-icon-user" placeholder="请输入账号" v-model="form.name"></el-input>
        </el-form-item>
        <el-form-item prop="passwd">
          <el-input prefix-icon="el-icon-lock" @keyup.native.enter="login" placeholder="请输入密码" show-password  v-model="form.passwd"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button style="width: 100%; background-color:rgb(68, 142, 117); border-color: #333; color: white" @click="login">登录</el-button>
        </el-form-item>
        <div style="display: flex; align-items: center">
          <div style="flex: 1">
            <el-checkbox v-model="checked" @click="remember">记住我</el-checkbox>
             <el-button type="text" @click="centerDialogVisible = true, changeColor" style="margin-left: 10px; color: fontColor;">忘记密码?</el-button>
           <el-dialog
              title="重置密码"
              :visible.sync="centerDialogVisible"
              :modal="false"
              width="30%"
              center>
              <el-input placeholder="邮箱号" style="margin-bottom: 10px;"></el-input>
              <br>
              <el-input placeholder="验证码"></el-input>
              <span slot="footer" class="dialog-footer">
                <el-button @click="centerDialogVisible = false">取 消</el-button>
                <el-button type="primary" @click="centerDialogVisible = false">确 定</el-button>
              </span>
            </el-dialog>
          </div>
           
          <div style="flex: 1; text-align: right; font-size: 14px">
            还没有账号？请先 <a href="/register">注册</a>
          </div>
        </div>
      </el-form>
    </div>
  </div>
</template>

<script>
import Cookie from "js-cookie"

export default {
  name: "Login",
  data() {
    return {
      form: {
        loginType: 1,
        
      },
      checked: false,
      centerDialogVisible: false, 
      fontColor: "#333",
      rules: {
        name: [
          { required: true, message: '请输入账号', trigger: 'blur' },
        ],
        passwd: [
          { required: true, message: '请输入密码', trigger: 'blur' },
        ]
      }
    }
  },
  created() {

  },
  methods: {
    remember() {

    },
    changeColor() {
      this.fontColor = "#0000FF"
    },
    login() {
      this.$refs['formRef'].validate((valid) => {
        if (valid) {
          // 验证通过
          this.$http.post('/login', this.form).then(res => {
            // if (res.data.code === '200') {
            //   this.$message.success('登录成功')
              
              // if (res.data.data != null) {
              //   Cookie.set("user", JSON.stringify(res.data.data))
              // }
            //   this.$router.push('/')  // 跳转登录页面
            // } else {
            //   this.$message.error(res.data.message)
            // }
            this.$message.success('登录成功')
            this.$router.push('/')
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
  background-image: url("../../../assets/img/68.png");
  background-size: 100%;
  display: flex;
  align-items: center;
  padding-right: 70px; 
  justify-content: end;
 
  margin-right: 20px;
  color: #666;
}
a {
  color: #2a60c9;
}
</style>
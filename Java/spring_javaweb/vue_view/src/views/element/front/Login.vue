<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-28 18:28:33
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-23 19:07:04
-->

<template>
  <div class="container">
    <div v-if="showLogin" key="0" style="opacity: 0.9; width: 400px; height: 400px; padding: 30px; background-color: white; border-radius: 5px;">
      <div style="text-align: center; font-size: 20px; margin-bottom: 20px; color: #333;">欢迎登录</div>
      <el-form :model="form" :rules="rules" ref="formRef">
        <el-form-item prop="name">
          <el-input prefix-icon="el-icon-user" placeholder="请输入账号" v-model="form.name"></el-input>
        </el-form-item>
        <el-form-item prop="passwd">
          <el-input prefix-icon="el-icon-lock" @keyup.native.enter="login" placeholder="请输入密码" show-password  v-model="form.passwd"></el-input>
        </el-form-item>
        <el-form-item prop="validCode">
          <div style="display: flex;">
            <el-input v-model="form.validCode" prefix-icon="el-icon-postcard" @keyup.native.enter="login" placeholder="请输入验证码" style="flex: 1"></el-input>
            <div style="flex:1; height: 36px;">
               <valid-code @update:value="getCode"></valid-code>
            </div>
          </div>
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
              <el-input v-model="resetPass.email" placeholder="邮箱号" style="margin-bottom: 10px;"></el-input>
              <br>
               <div style="display: flex;">
                <el-input style="flex: 1" v-model="resetPass.code" placeholder="验证码"></el-input>
                <el-button type="primary" style="width: 150px； margin-left: 120px" @click="sendCode">发送验证码</el-button>

               </div>
              <span slot="footer" class="dialog-footer">
                <el-button @click="centerDialogVisible = false">取 消</el-button>
                <el-button type="primary" @click="centerDialogVisible = false; resetPasswd()">确 定</el-button>
              </span>
            </el-dialog>
          </div>
           
          <div style="flex: 1; text-align: right; font-size: 14px">
            还没有账号？请先 <a href="#" @click.prevent="toggleForm">注册</a>
          </div>
        </div>
      </el-form>
    </div>

    <div v-else key="1" style="opacity: 0.9; width: 400px; height: 430px; padding: 30px; background-color: white; border-radius: 5px;">
        <div style="text-align: center; font-size: 20px; margin-bottom: 20px; color: #333">欢迎注册</div>
        <el-form :model="regForm" :rules="regRules" ref="regFormRef">
          <el-form-item prop="name">
            <el-input prefix-icon="el-icon-user" placeholder="请输入账号" v-model="regForm.name"></el-input>
          </el-form-item>
          <el-form-item prop="passwd">
            <el-input prefix-icon="el-icon-lock" placeholder="请输入密码" show-password  v-model="regForm.passwd"></el-input>
          </el-form-item>
          <el-form-item prop="confirmPass">
            <el-input prefix-icon="el-icon-lock" placeholder="请确认密码" show-password  v-model="regForm.confirmPass"></el-input>
          </el-form-item>
          <el-form-item prop="role">
             <el-radio-group v-model="regForm.role">
                <el-radio label="读者"></el-radio>
                <el-radio label="作家"></el-radio>
             </el-radio-group>
          </el-form-item>
          <el-form-item>
            <el-button style="width: 100%; background-color: rgb(68, 142, 117); border-color: #333; color: white" @click="register">注 册</el-button>
          </el-form-item>
          <div style="display: flex; align-items: center">
            <div style="flex: 1"></div>
            <div style="flex: 1; text-align: right">
              已有账号？请 <a href="#" @click.prevent="toggleForm">登录</a>
            </div>
          </div>
        </el-form>
      </div>
  </div>
</template>

<script>
import ValidCode from "@/components/ValidCode.vue"
export default {
  name: "Login",
  components: {
    ValidCode
  },
  data() {
    // 验证两次密码
    const validatePassword = (rule, confirmPass, callback) => {
        if (confirmPass === '') {
          callback(new Error('请确认密码'))
        } else if (confirmPass !== this.regForm.passwd) {
          callback(new Error('两次输入的密码不一致'))
        } else {
          callback()
        }
      }

      //验证码
      const validCodeCheck = (rule, validCode, callback) => {
        if (validCode=== '') {
          callback(new Error('验证码为空'))
        } else if (validCode !== this.code) {
          callback(new Error('验证码错误'))
        } else {
          callback()
        }
      }
    return {
      resetPass: {
        email: "",
        code: "",
      },
      code: "",
      showLogin: true,
      form: {},
      checked: false,
      centerDialogVisible: false, 
      fontColor: "#333",
      role: "",
      rules: {
        name: [
          { required: true, message: '请输入账号', trigger: 'blur' },
        ],
        passwd: [
          { required: true, message: '请输入密码', trigger: 'blur' },
        ],
        validCode: [
            { validator: validCodeCheck, trigger: 'blur' }
          ]
      },
      regForm: {
        name: "",
        passwd: "",
        confirmPass: "",
        role: ""
      },
        regRules: {
          name: [
            { required: true, message: '请输入账号', trigger: 'blur' },
          ],
          passwd: [
            { required: true, message: '请输入密码', trigger: 'blur' },
          ],
          confirmPass: [
            { validator: validatePassword, trigger: 'blur' }
          ],
          role: [
            { required: true, message: '请选择角色', trigger: 'blur' },
          ],
        }
    }
  },
  created() {

  },
  methods: {
    resetPasswd() {
     this.$http.put("/login/reset", this.resetPass).then(res => {
         if (res.data.code == '200') {
             this.$message.success(res.data.message)
             this.resetPass = {}
         }
         else {
            this.$message.error("重置密码失败")
         }
     })
    },
    sendCode() {
      const email = this.resetPass.email
      
      this.$http.get("/login/email/" + email).then(res => {
        if (res.data.code == '200') {
          this.$message.success("发送验证码成功，请注意查收")
        }
        else {
          this.$message.error("邮箱错误")
        }
      })
    },
    getCode(validCode) {
       console.log("valid_code: " + validCode);
       this.code = validCode
    },
    toggleForm() {
      // 切换登录和注册页面
      this.showLogin = !this.showLogin;
      // 其他逻辑...
    },
    remember() {

    },
    changeColor() {
      this.fontColor = "#0000FF"
    },
    register() {
        this.$refs['regFormRef'].validate((valid) => {
          
          if (valid) {
            // 验证通过
            console.log("sss: " + this.regForm)
            this.$http.post('/user/register', this.regForm).then(res => {
              if (res.data.code === '200') {
                this.$message.success('注册成功')
                // this.$router.push('/login')  // 跳转登录页面
                this.toggleForm()  // 跳转登录页面
              } else {
                this.$message.error(res.data.message)
              }
            })
          }
        })
      },
    login() {
      this.$refs['formRef'].validate((valid) => {
        if (valid) {
          // 验证通过
          this.$http.post('/login', this.form).then(res => {
            if (res.data.code === '200') {
              this.$message.success('登录成功')
              
              if (res.data.data != null) {
                localStorage.setItem("user", JSON.stringify(res.data.data))
                
              }
              // this.$router.push('/front/index')
              const userStro = JSON.parse(localStorage.getItem("user") || '{}')
              if ("读者" == userStro.role) this.$router.push('/front/index')
              else if ("作家" == userStro.role) this.$router.push('/front/author/home')
              else this.$router.push('/back/home')  // 跳转登录后台
            } else {
              this.$message.error(res.data.message)
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
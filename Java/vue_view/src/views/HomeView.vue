<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-11 17:17:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-04 13:48:06
-->
<template>
  <div style="width: 100%;position:fixed;">
     <!-- header -->
     <header style="width: 100%;"> 
      <img src="@/assets/img/logo.png" alt="">
      <span>阅界，一个自由的阅读交流网站</span>
      <div class="left_tab"> 

        <router-link to="/" class="router-link">首页</router-link>
        <router-link to="/front/ReadGroup" class="router-link">小组</router-link>
        <router-link to="/front/readPizza" class="router-link">阅读广场</router-link>
        <router-link to="/front/browDisc" class="router-link">浏览发现 </router-link>
        <el-dropdown :hide-on-click="false" style="width: 100px; display: inline;" trigger="click">
          <span class="el-dropdown-link" style="font-size: 15px; margin-right: 10px; color: darkgreen;">
            {{ user.name }}<i class="el-icon-arrow-down el-icon--right"></i>
          </span>
          <el-dropdown-menu slot="dropdown">
            <el-dropdown-item>
              <el-button type="text" @click="dialogVisible = true; clear()">修改密码</el-button>
                <el-dialog
                  title="修改密码"
                  :visible.sync="dialogVisible"
                  :model="false"
                  width="30%"
                 >
                 <el-form :model="form" :rules="rules" ref="formRef">
                  <el-form-item label="旧密码" prop="passwd" >
                    <el-input v-model="form.passwd"></el-input>
                  </el-form-item>
                  <el-form-item label="新密码" prop="confirmPass">
                    <el-input v-model="form.newPasswd" type="password" @keyup.native.enter="updatePasswd" ></el-input>
                  </el-form-item>
                </el-form>
                  <span slot="footer" class="dialog-footer">
                    <el-button @click="dialogVisible = false">取 消</el-button>
                    <el-button type="primary" @click="dialogVisible = false; updatePasswd()">确 定</el-button>
                  </span>
                </el-dialog>
            </el-dropdown-item>
            <el-dropdown-item><span >信息头像</span></el-dropdown-item>
            <el-dropdown-item><span @click="logout">退出登录</span></el-dropdown-item>
          </el-dropdown-menu>
        </el-dropdown>
      </div>
      
    </header>
    <div style="display: flex">
      <AdminFunctionView></AdminFunctionView>
      <router-view/>
    </div>
  </div>
</template>

<script>
import AdminFunctionView from './element/admin/AdminFunctionView.vue';
import User from './element/user/User.vue'
import Cookie from "js-cookie"
export default {
  name: "HomeView",
  components: {
    User,
    AdminFunctionView
  },

  data() {
    // 验证码校验
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
        name: "",
        passwd:"",
        newPasswd: ""
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
      console.log(this.user.id);
      this.form = {}
    }
  }
}
</script>

<style  scoped>
 .el-dropdown-link {
    cursor: pointer;
    color: #409EFF;
  }
  .el-icon-arrow-down {
    font-size: 10px !important;
  }


  /* //头部 */
header {
    height: 50px;
    line-height: 60px;
    background-color: white;
    margin-bottom: 4px;
    border: 1px solid;
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
    margin-left: 45%;
    display: inline;
    height: 30px;

}

header .router-link {
    font-size: 15px;
    color: darkgreen;
    margin-left: 10px;
}

</style>


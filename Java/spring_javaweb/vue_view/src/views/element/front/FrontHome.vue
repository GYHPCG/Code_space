<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-12-03 12:45:37
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-23 22:14:20
-->
<template>
  <div style="width: 100%; text-align: center;">
    <div  style="margin: 0 auto; width: 80%;">
        <!-- 头部 -->
        <header style="width: 100%; height: 60px;"> 
        <img src="@/assets/img/logo.png" alt="">
        <span style="">阅界，一个自由的阅读交流网站</span>
        <div class="left_tab"> 
            <router-link to="/front/index" class="router-link">首页</router-link>
            <router-link to="/front/ReadGroup" class="router-link">小组</router-link>
            <router-link to="/front/readPizza" class="router-link">阅读广场</router-link>
            <router-link v-if="isAuthor" to="/front/author/home" class="router-link">作者天地 </router-link>
            <router-link v-else to="/front/beAuthor" class="router-link">成为作者 </router-link>
            <router-link to="/login" class="router-link" v-if="!user">登录</router-link>

            <el-dropdown :hide-on-click="false" style="width: 100px; display: inline;" v-else trigger="click">
              <span class="el-dropdown-link" style="cursor: pointer; font-size: 15px; margin-right: 10px; color: darkgreen;">
                  <el-avatar shape="circle" :size='30' :fit="fill" :src="user.avatar" style="display: inline; margin-top: 10px;"></el-avatar>
              </span>
              <el-dropdown-menu slot="dropdown">
                <el-dropdown-item>
                  <el-button type="text" @click="dialogVisible = true; clear()">修改密码</el-button>
                    <el-dialog
                      title="修改密码"
                      :visible.sync="dialogVisible"
                      :model="false"
                      width="30%"
                      :append-to-body="true"
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
                <el-dropdown-item v-if="isAuthor == false"><span><router-link to="/front/personalInfo">个人详情</router-link></span></el-dropdown-item>
                <el-dropdown-item><span @click="logout">退出登录</span></el-dropdown-item>
              </el-dropdown-menu>
            </el-dropdown>
        </div>
        </header>
         <router-view></router-view>
    </div>
  </div>
</template>

<script>
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
      isAuthor: false,
      user: localStorage.getItem("user")?JSON.parse(localStorage.getItem("user")): null,
      form: {
        
      },
      fill: "fill",
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
   created() {
      if (this.user.role == "作家") {
          this.isAuthor = true
      }
   },
   methods: {
    logout() {
      localStorage.removeItem("user")
      console.log("frontindex: ");
      location.reload()
      console.log("reload: ");
      // this.$router.push("/login")
    },
    updatePasswd() {
      this.form.name = this.user.name
      this.$refs['formRef'].validate((valid) => {
        if (valid) {
          // 验证通过
          this.$http.put('/admin/updatePasswd', this.form).then(res => {
            if (res.data.code === '200') {
              this.$message.success('修改成功')
              localStorage.removeItem("user")
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
    height: 40px;

}

header .router-link {
    font-size: 15px;
    color: darkgreen;
    margin-left: 10px;
}
.el-popper[x-placement^=bottom] {
  margin-top: 20px !important;
}
/deep/ .el-avatar>img {
    display: inline-block !important;
    height: 40px !important;
    width: 40px;
    vertical-align: middle;
    border-radius: 50%;
}
</style>
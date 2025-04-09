<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-11 17:17:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-01-02 15:48:56
-->
<template>
  <div>
    <h2 style="font-weight: normal">加入我们，成为作者</h2>
    <div>
        <h3 style="font-weight:normal; background-color: #D1DFE4">作者信息</h3>
        <div style="padding: 20px; background-color: #eff2f3; margin-bottom: 20px">以下信息会在你的阅界阅读个人主页、作品等页面展示给你的读者。</div>
        <div style="margin-left: 25%;width: 50%; text-align: center;">
    
           <el-form :model="authorInfo" :rules="rules" ref="ruleForm" label-width="100px" class="demo-ruleForm">
              <el-form-item label="作者笔名" prop="penName">
                 <el-input v-model="authorInfo.penName" placeholder="笔名不超过20字">
                 </el-input>
              </el-form-item>
              <el-form-item label="作者简介" prop="introduce">
                 <el-input type="textarea" v-model="authorInfo.introduce" placeholder="个人介绍不超过100字"></el-input>
              </el-form-item>

              <el-form-item>
                
              </el-form-item>
            </el-form>
           
        </div>
    </div>

    <!-- //联系方式 -->
    <div>
        <h3 style="font-weight:normal; background-color: #D1DFE4">联系方式</h3>
        <div style="padding: 20px; background-color: #eff2f3; margin-bottom: 20px">阅界可能就作品审核、作品授权、作品收益等问题与你联系，请填写你的常用联系方式。</div>
        <div style="margin-left: 25%;width: 50%; text-align: center;">
             
           <div style="display: flex">
               <div style="width:100px">手机号码</div>
                <el-input
                style="flex: 1"
                autosize
                placeholder="建议填写，便于编辑快速联系到你"
                v-model="authorInfo.phone"
                >

                </el-input>
           </div>
            <div style="margin: 20px 0;"></div>
           <div style="display: flex">
               <div style="width:100px"> QQ联系</div>
               <el-input
                placeholder="建议填写，便于编辑快速联系到你"
                v-model="authorInfo.qq"
                style="flex: 1">
                </el-input>
           </div>
        </div>
    </div>

    <div style="margin-top: 20px">
        <el-button type="primary" round @click="submit('authorInfo')">确认提交</el-button>
    </div>

  </div>
</template>

<script>
export default {
  name: "beAuthor",
  data() {
    return {
      authorInfo: {
        status: 0,
        penName: "",
        introduce: "",
        avatar: "",

      },
      userStro: {},
      rules: {
          penName: [
            { required: true, message: '请输入笔名', trigger: 'blur' },
            { min: 1, max: 20, message: '长度在 1 到 20 个字符', trigger: 'blur' }
          ],
          introduce: [
            { required: true, message: '请输入个人简介', trigger: 'blur' },
            { min: 10, max: 100, message: '长度在 10 到 100 个字符', trigger: 'blur' }
          ],
      }
    }
  },
  mounted() {
    this.userStro = JSON.parse(localStorage.getItem("user") || '{}')
    this.authorInfo.name = this.userStro.name
    this.authorInfo.avatar = this.userStro.avatar
  },
  methods: {
    submit() {
      if (this.authorInfo.penName.length >= 0 && this.authorInfo.penName.length  <= 20 && this.authorInfo.introduce.length >= 10 && this.authorInfo.introduce.length <= 100)
      {
        this.$http.post("/author/addAuthor",this.authorInfo).then(res => {
             if (res.data.code == '200') {
              this.$message.success('申请提交成功')
              // this.$router.push("/front/review")
        this.$router.push({
          path: '/front/review',
          query: {
            penName: this.authorInfo.penName
          }
      });

             }
             else {
              this.$message.error('申请失败')
             }
        })
      }
      else {
        this.$message.error("填写信息不合法，请重新填写")
      } 
    }
  }
}
</script>

<style scoped>

/deep/ .sear .el-button {
  height: 30px;
  width: 100px;
  font-size: 10px;
  padding: 0 5px;
}
</style>
<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-12-12 20:52:29
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-01-02 15:52:16
-->
<template>
    <div>
        <p style="display: block; margin-top:30%"><span>{{ author.reviewProgress }}</span></p>
        <el-steps :active="active" finish-status="success">
            <el-step title="正在审核中"></el-step>
            <el-step title="正在审核中"></el-step>
            <el-step title="正在审核中"></el-step>
            </el-steps>

        <el-button style="margin-top: 12px;" @click="next">下一步</el-button>

    </div>

</template>

<script>
export default {
  name: "review",
  
  data() {
    return {
      author: {
        status: '',
        reviewProgress: '正在审核中ing'
      },
      status: "",
      active: 0,
      penName: "",
    }
  },
  created() {
   this.penName = this.$route.query.penName;
   this.getStatus()
  },
  methods: {
    next() {
       console.log("status: " + this.status);
        if (this.active++ > 2 && this.status === true) {
          this.$message.success("审核成功")
          this.$router.push("/front/author/home")
        }
        else if (this.active++ < 2) {
          this.$message.success("还在审核中，请稍等")
        }
        else this.$message.error("审核不通过，请重新填写资料")
      },
    getStatus() {
      // const userStro = JSON.parse(localStorage.getItem("user") || '{}')
       const name = this.penName
       console.log("review: " + name)
       this.$http.get("/author/getByName/" + name).then(res => {
        this.status = res.data.data.status;
        console.log("logss: " + res.data.data.status)
       })
    }
  }
}
</script>

<style scoped>

</style>
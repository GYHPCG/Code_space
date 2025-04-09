<template>
  <div style="display: flex">
        <!-- 侧边栏管理功能 -->
        <div style="width: 200px; min-height: calc(100vh - 64px); overflow: hidden; margin-right: 2px; background-color: white;">
            <el-menu :default-active="$router.path" router class="el-menu-demo">
            <el-menu-item index="/front/author/home" class="el-icon-s-tools"> 作者中心</el-menu-item>
            <el-menu-item index="/front/author/manager" class="el-icon-view"> 书籍发布</el-menu-item>
           </el-menu>
        </div>

        <!-- 主体 -->
        <div style="flex: 1; background-color: white; padding: 10px;">
            <router-view></router-view>
        </div >
        
    </div>
</template>

<script>
export default {
  name: "author",
  data() {
     return {

     }
  }
}
</script>

<style scoped>

</style>
<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-17 17:14:15
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-01-02 13:09:45
-->
<template>
    <div>
        <!-- 侧边栏管理功能 -->
        <div style="width: 200px; min-height: calc(100vh - 64px); overflow: hidden; margin-right: 2px; background-color: white;">
            <el-menu :default-active="$route.path" router class="el-menu-demo">
            <el-menu-item index="/back" class="el-icon-s-tools"> 后台主页</el-menu-item>
            <el-menu-item index="/back/user" class="el-icon-view"> 用户管理</el-menu-item>
            <el-menu-item index="/back/book" class="el-icon-reading"> 书籍管理</el-menu-item>
            <el-menu-item index="/back/author" class="el-icon-reading"> 作家管理</el-menu-item>
            <el-menu-item index="/back/admin" class="el-icon-monitor"> 管理员管理</el-menu-item>
           </el-menu>
        </div>

        <!-- 主体 -->
        <div style="flex: 1; background-color: white; padding: 10px;">
        </div>
    </div>
</template>

<script>
export default {
 name: "adminFun",
 components: {
 }
}
</script>


<style scoped>

</style>
<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-17 17:14:15
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-11-28 17:00:31
-->
<template>
    <div>
        <!-- 侧边栏管理功能 -->
        <div style="width: 200px; min-height: calc(100vh - 64px); overflow: hidden; margin-right: 2px; background-color: white;">
            <el-menu :default-active="$route.path" router class="el-menu-demo">
            <el-menu-item index="/" class="el-icon-s-tools"> 公共功能</el-menu-item>
            <el-menu-item index="/user" class="el-icon-view"> 用户管理</el-menu-item>
            <el-menu-item index="/book" class="el-icon-reading"> 图书功能</el-menu-item>
            <el-menu-item index="/admin" class="el-icon-monitor"> 管理员功能</el-menu-item>
           </el-menu>
        </div>

        <!-- 主体 -->
        <div style="flex: 1; background-color: white; padding: 10px;">
            <!-- <router-view/> -->
            <!-- <User></User> -->
        </div>
    </div>
</template>

<script>
import User from '../user/User.vue';
export default {
 name: "adminFun",
 components: {
    User
 }
}
</script>


<style scoped>

</style>
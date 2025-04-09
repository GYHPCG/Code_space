<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-11 17:17:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-11-17 18:28:20
-->
<template>
  <header>
    <h3>阅界广场</h3>
    <el-input v-model="input" placeholder="书籍"></el-input>
    <el-button type="primary" class="el-icon-search">搜索</el-button>
  </header>
</template>
  
<script>
// import SecondHeader from "@/components/SecondHeader.vue"

export default {
  name: "readPizza",
  components: {
    // SecondHeader
  },
  data() {
    return {
      input: "",
    };
  },
};
</script>
  
</style>
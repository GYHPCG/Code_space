<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-11 17:17:43
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-05 21:32:13
-->
<template>
  <div style="text-align: left;">
      <!-- 头部 -->
      <div style="height: 50px; background-color: aqua;">
         <a style="display: inline; font-size: 30px;">阅界小组</a>
         <ul  class="head" style="display: inline-block;">
             <li><a href="#">我的小组</a></li>
             <li><a href="#">个性推荐</a></li>
             <li><a href="#">文化</a></li>
             <li><a href="#">探索</a></li>
         </ul>
      </div>
     
      <!-- 小组 -->
      <div>
          <h2 style="font-weight: normal;">欢迎来到阅界空间，张三</h2>
          <p style="padding: 0; color: #0e959d;">欢迎加入特定的阅界空间，形成自己的个性化阅者形象</p>
      </div>

      <div style="width: 80%">
        <ul class="space">
          <li v-for="(item, index) in group" :key="index" @click="selectItem(index)">
             {{ item.type }}
          </li>
        </ul>

        <div v-if="selectedIndex !== null" style="background-color: aqua; width: 88%; height: 100px;" class="fade-effect" >
           <!-- {{ group[selectedIndex].content }} -->
           <ul class="group_info">
            <li>11</li>
            <li>22</li>
            <li>33</li>
            <li>44</li>
            <li>55</li>
            <li>66</li>
           </ul>
        </div>


      </div>


  </div>
</template>

<script>

export default {
  name: "readGroup",
  components: {
  },
  data() {
      return {
         group: [
          {type: "文学", content: 1},
          {type: "文学", content: 2},
          {type: "文学", content: 3},
          {type: "文学", content: 4},
          {type: "文学", content: 5},
          {type: "文学", content: 6}
         ],
         selectedIndex: null
      };
    },
    methods: {
      selectItem(index) {
      // 点击时更新选中的索引
      this.selectedIndex = index;
    },
    }
};
</script>

<style scoped>
ul > li {
  display: inline-block;
  margin-left: 10px;
}
.head li:hover {
  background-color: #07a;
}
.space {
  padding-left: 0px;
}
.space li {
  margin-left: 0px;
  margin-right: 10px;
  margin-bottom: 10px;
  text-align: center;
  width: 120px;
  height: 80px;
  background-color: rgb(115, 190, 147);
  cursor: pointer;
  transition: transform 0.3s ease-in-out, box-shadow 0.3s ease-in-out;
}

.space li:hover {
     transform: translateY(5px);  
     box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1); 
}

.el_button {
  border: none;
  background-color: rgb(115, 190, 147);
}

.fade-effect {
  opacity: 0.5;
  transition: opacity 0.5s ease-in-out;
}

.fade-effect.active {
  opacity: 1;
}
.group_info {
  padding-left: 0;
}
.group_info li {
  width: 100px;
  margin-left: 0;
  margin-right: 10px;
  background-color: aquamarine;
  height: 100px;
}
</style>
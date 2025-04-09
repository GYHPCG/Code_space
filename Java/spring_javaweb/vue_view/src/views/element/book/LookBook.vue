<template>
    <div :class="'page-css background-color'+colorGet">
      <div class="page-top">
        <el-page-header @back="showInfo()"  title="目录"></el-page-header>
        <div class="color-change">
          <span style="font-size:12px">切换颜色：</span>
          <div
            :class="'color-dix  color'+item"
            v-for="item in 6"
            :key="item"
            @click="getColor(item)"
          >
            <i v-if="item==colorGet">✓</i>
          </div>
        </div>
      </div>
      <!-- //主要内容 -->
      <div style="display: flex; width: 100%;">
        <transition name="slide">
          <div v-if="show" class="slide-box">
             <ul style="height: 100vh;">
                <li v-for="chapterts in allChapter" :key="chapterts.chapterId">
                  <span @click="goToChapter(chapterts.chapterId)">第{{chapterts.chapterId}}章：{{ chapterts.chapter }}</span>
                </li>
             </ul>
          </div>
        </transition>
           <div :style="dynamic">
            <div :class="'chapter-info color'+colorGet">
              <div class="chapter-title">
                <p>第{{oneChapter.chapterId}}章 {{oneChapter.chapter}}</p>
                <div class="chapter-book">
                  <div class="chapter-book-info">
                    <span>{{oneChapter.name}}</span>
                  </div>
                  <div class="chapter-book-info">
                    <span>{{oneChapter.createdTime}}</span>
                  </div>
                </div>
              </div>
              <div v-html="oneChapter.content" class="chapter-content"></div>
            </div>
            <div :class="'chapter-next color'+colorGet">
              <div
                :class="oneChapter.chapterId==1?'chapter-next-item chapter-next-item-no':'chapter-next-item'"
                @click="getPreviousChapter(oneChapter.chapterId),readHistory(oneChapter.chapterId)"
              >上一章</div>
              <span>|</span>
              <div class="chapter-next-item" @click="showInfo">目录</div>
              <span>|</span>
              <div
                :class="oneChapter.chapterId==this.allChapter.length?'chapter-next-item  chapter-next-item-no':'chapter-next-item'"
                @click="getNextChapter(oneChapter.chapterId),readHistory(oneChapter.chapterId)"
              >下一章</div>
            </div>
          </div>
      </div>
      <template>
        <el-backtop @click="handleBackTop"></el-backtop>
      </template>
    </div>
  </template>
  
  <script>
  export default {
    name: "lookBook",
    data() {
      return {
        show: false,
        tabPosition: 'left',
        user: JSON.parse(localStorage.getItem("user") || '{}'),
        oneChapter: {
          chapterId: 0,
        },
        isStart: "",
        bookId: "",
        nextOrUpChapter: {},
        colorGet: 1,
        allChapter: []
      };
     
    },
    created() {
      this.bookId = this.$route.params.bid;
      console.log('Received bid:', this.bookId );
      this.getAllChapter()
      this.getLastReadChapter()
    },
    computed: {
      dynamic() {
        return {
          flex: '1',
          'margin-left': this.show ? '0px' : '200px',
        }
      }
    },
    methods: {
      goToChapter(chapterId) {
        this.oneChapter = this.allChapter[chapterId - 1]
        this.readHistory(chapterId)
      },
      handleBackTop() {
        document.body.scrollTop = 0; // 兼容 Chrome、Firefox、IE 和 Safari
        document.documentElement.scrollTop = 0; // 兼容 Edge
      },
      getLastReadChapter() {
         this.$http.get("/write/getLastReadChapter",{ params: { userId: this.user.id, role: this.user.role, bookId: this.bookId } }).then(res => {
           if (res.data.code == '200') {
               this.oneChapter = res.data.data
           }
         })
      },
      showInfo(){
        this.show = !this.show;
      },
      readHistory(chapterId) {
        const readParam = {
          bookId: this.bookId,
          chapterId: chapterId,
          userId: this.user.id,
          role: this.user.role
        }
        this.$http.post("/write/readHistory", readParam).then(res => {
          if (res.data.code == '200') {
            // this.$message.success("更新阅读记录")
          }
        })

      },
      getAllChapter() {
         this.$http.get("/write/userGetContent/" + this.bookId).then(res => {
             if (res.data.code == '200') {
                this.allChapter = res.data.data.chapters
             }
         })
      },
      getColor(num) {
        this.colorGet = num;
      },
      getPreviousChapter(previous) {
        let num = previous
        num = num - 1
        if (num - 1 >= 0) {
          this.oneChapter = this.allChapter[num - 1]
        }
      },
      getNextChapter(Next) {
        let num = Next
        num = num - 1
        if (num + 1 < this.allChapter.length) {
          this.oneChapter = this.allChapter[num + 1]
        }
      },
    }
  };
  </script>
  
<style  scoped>

.slide-box {
  width: 200px;
  transform: translateX(0);
  transition: transform 0.5s ease-in-out;
}
.slide-box ul li{
  text-align: left;
  background-color: #cfdde1;
  border-bottom: 1px solid;
  cursor: pointer;
  padding-bottom: 10px;
} 
.slide-box ul li:hover {
  background-color: rgb(166, 218, 184);
}
.slide-enter-active,
.slide-leave-active {
  transition: transform 0.5s ease-in-out;
}

.slide-enter, .slide-leave-to {
  transform: translateX(-200px);
}

  .page-css {
    display: flex;
    justify-content: center;
    flex-direction: column;
    align-items: center;
    width: 100%;
    min-height: 720px;
    background: #e9e3d6;
  }
  .chapter-info {
    margin-top: 20px;
    background-color: #f6f1e7;
    width: 80%;
    min-height: 700px;
    margin-bottom: 20px;
    padding: 60px 64px;
  }
  .chapter-title {
    display: flex;
    flex-direction: column;
  }
  .chapter-title p {
    font: 24px/32px PingFangSC-Regular, HelveticaNeue-Light,
      "Helvetica Neue Light", "Microsoft YaHei", sans-serif;
    overflow: hidden;
    height: 32px;
    margin-bottom: 12px;
    text-align: left;
    margin-top: 0px;
  }
  .chapter-book-info {
    display: flex;
    align-items: center;
    margin-right: 16px;
  }
  .chapter-book {
    display: flex;
  }
  .chapter-book-info span {
    font-family: PingFangSC-Regular, HelveticaNeue-Light, "Helvetica Neue Light",
      "Microsoft YaHei", sans-serif;
    color: #746060;
    font-size: 13px;
  }
  .chapter-content {
    margin-top: 15px;
    text-align: left;
  }
  .chapter-next {
    margin-top: 20px;
    background-color: #f6f1e7;
    width: 80%;
    height: 70px;
    margin-bottom: 20px;
    display: flex;
    padding: 0px 64px;
  }
  .chapter-next-item {
    height: 70px;
    line-height: 70px;
    text-align: center;
    width: 33.33%;
    cursor: pointer;
  }
  .chapter-next-item-no {
    color: #cccccc;
    pointer-events: none;
  }
  .chapter-next span {
    height: 70px;
    line-height: 70px;
    color: #d8d8d8;
  }
  .page-top {
    margin-top: 15px;
    display: flex;
    align-items: center;
    width: 72%;
    justify-content: space-between;
  }
 .el-page-header {
    width: 65%;
    font-size: 20px;
  }
  /deep/ .el-page-header__title {
    font-size: 18px;
  }
  .color-change {
    display: flex;
    align-items: center;
    width: 30%;
    justify-content: space-between;
  }
  .color-dix {
    width: 22px;
    height: 22px;
    border: 1px solid #cccccc;
  }
  .color1 {
    background-color: #faf5ebcc;
  }
  .color2 {
    background-color: #f5eacccc;
  }
  .color3 {
    background-color: #e6f2e6cc;
  }
  .color4 {
    background-color: #e4f1f5cc;
  }
  .color5 {
    background-color: #f5e4e4cc;
  }
  .color6 {
    background-color: #e0e0e0cc;
  }
  .background-color1 {
    background-color: #ede7da;
  }
  .background-color2 {
    background-color: #e0ce9e;
  }
  .background-color3 {
    background-color: #cddfcd;
  }
  .background-color4 {
    background-color: #cfdde1;
  }
  .background-color5 {
    background-color: #ebcece;
  }
  .background-color6 {
    background-color: #d0d0d0;
  }
  </style>
  
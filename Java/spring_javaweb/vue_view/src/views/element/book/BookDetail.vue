<template>
    <div >
        <div style="display: flex; height: 60px; line-height: 60px;">
            <div style="width:300px; font-size: 24px; color: darkgreen;">
             阅界，自由阅读
            </div>
            <div style="flex: 1;">
              <el-input
               placeholder="图书种类、作者、出版日期、IBSN"
                v-model="searchInfo"
                clearable
                style="width: 60%; height: 50px;"
                @keyup.native.enter="searchBook"
                >
                </el-input>
                <el-button type="primary" class="el-icon-search" @click="searchBook"></el-button>
            </div>
            <div style="width: 300px;">年度阅读榜单</div>
        </div>
        
       <!-- //书籍信息 -->
       
        <div style="height: 350px; display: flex;">
            <div style="flex: 1; height: 350px; text-align: left;">
                 <h2 style="font-weight: normal; font-size: 20px; width: 140px;  white-space: nowrap;
      overflow: hidden; text-overflow: ellipsis;">{{ book.introduction }}</h2>
                 <div style="display: flex;">
                    <div style="height:250px;" @click="readBook()">
                        <el-image :src="'https://images.weserv.nl/?url=' + book.imgUrl" :preview-src-list="['https://images.weserv.nl/?url=' + book.imgUrl]" style="width: 140px; height:auto; margin-top: 10px;"></el-image>
                    </div>
                    <div class="book_info" style="flex:1;padding: 10px; margin-left: 10px;background-color: antiquewhite;" >
                          <span class="book_detail">书名：<span style="color:#07a"> {{ book.name }}</span> </span>
                          <span class="book_detail">作者：<span style="color:#07a">{{ book.author }}</span></span>
                          <span class="book_detail">简介：<span style="color: #07a;">{{ book.introduction }}</span></span>
                          <span class="book_detail">类型：<span style="color: #07a;"> {{ book.type }}</span></span>
                          <span class="book_detail">发布时间：<span style="color: #07a;"> {{ book.createDate }}</span></span>
                    </div>
                    <!-- 书籍评分 -->
                    <div style="width:250px; margin-left: 80px; margin-right: 60px;" >
                         <span>阅界评分</span>
                         <div class="block">
                            <el-rate
                                disabled
                                v-model="value"
                                text-color="#ff9900"
                                show-score
                                score-template="{value}"
                                :colors="colors">
                            </el-rate>
                             
                            <!-- 人数占比 -->
                            <div>
                              <span>5星</span>  <el-progress :percentage="percentage5" :color="customColor"></el-progress>
                              <span>4星</span> <el-progress :percentage="percentage4" :color="customColorMethod"></el-progress>
                              <span>3星</span> <el-progress :percentage="percentage3" :color="customColors"></el-progress>
                              <span>2星</span>  <el-progress :percentage="percentage2" :color="customColors"></el-progress>
                              <span>1星</span> <el-progress :percentage="percentage1" :color="customColors"></el-progress>
                            </div>

                        </div>
                    </div>
                 </div>
            </div>

         <div style="width: 300px; background-color: aquargb(177, 181, 181)rgin-top: 50px;">
            <div style="background-color: antiquewhite; height: 120px;">
                <p>个性书单推荐……（<a href="#" style="color:#37a">全部</a>）</p>
                <ul style="padding-left: 0;">
                  <li v-for="(book_list, index) in Personalized_book_list" :key="index" class="book_list" @click="goToBookList(book_list)">
                     <span style="color: #37a; font-size: 14px; cursor: pointer;">{{book_list.bookList}}</span>  <span style="color: #666; cursor: pointer;"> ({{book_list.bookUser}})</span>
                  </li>
                </ul>
            </div>
             
        </div>
       </div>

       <div style="width: 700px; text-align: left; ">
            <el-button type="text" class="button_mod" @click="readBook()">想读</el-button>
            <el-button type="text" class="button_mod">在读</el-button>
            <el-button type="text" class="button_mod">已读</el-button>
            <el-button type="text" class="el-icon-collection-tag" @click="addToList(book.id)">添加到我的书架</el-button>
            <span style="margin-left: 50px;">评价: </span>
            <el-rate
                style="display: inline-block;"
                v-model="score"
                allow-half
                :texts="['很差', '较差', '还行','推荐', '力荐']"
                @change="bookRate"
                show-text>
                
            </el-rate>
            <el-button type="text" class="button_mod el-icon-s-promotion" style="float:right;" @click="recommand">推荐</el-button>
        </div>
        
        
        <!-- 书评 -->
        <div style="text-align: left; width:700px">
            <h2 style="border-bottom: 1px solid;">
                <span>阅友评价</span>
                <el-button type="text" @click="dialogVisible = true" style="float: right;" class="el-icon-edit">我来说两句</el-button>
                <el-dialog
                    title="欢迎评论"
                    :visible.sync="dialogVisible"
                    width="30%"
                    :before-close="handleClose">
                    <el-input type="textarea" v-model="comment.content"></el-input>
                    <span slot="footer" class="dialog-footer" >
                        <el-button @click="dialogVisible = false">取 消</el-button>
                        <el-button type="primary" @click="dialogVisible = false; submit()">确 定</el-button>
                    </span>
                </el-dialog>
            </h2>

            <div style="">
                 <div style="padding: 10px;" v-for="item in comments" :key="item.id">
                   <div style="display: flex;">
                        <div style="width: 80px">
                         <!-- <el-avatar src="https://cube.elemecdn.com/0/88/03b0d39583f48206768a7534e55bcpng.png"></el-avatar> -->
                         <el-avatar :src="item.avatar"></el-avatar>
                        </div>
                      <div style="flex: 1;">
                            <div style="color: #07a;"> <span style="font-size: 20px;">{{ item.userName }} </span> <span style="font-size: 10px;">{{ item.commentTime }} </span></div>
                            <div style="font-size: 15px; margin-top: 10px;">{{ item.content }}</div>
                      </div>
                   </div>
                   <!-- 多级回复 -->
                    <div style="padding: 10px; margin-left: 70px;">
                      <el-button type="text" @click="replyDialogy = true; reply(item.id, item.userName)">回复</el-button>
                    </div>
                    
                    <div v-if="item.children.length" style="font-size: 15px; margin-left: 100px; background-color: aliceblue; padding: 5px;">
                      <div v-for="childRepy in item.children" :key="childRepy.id">
                        <div> <span style="cursor: pointer;" @click="replyDialogy = true; reply(childRepy.pid, childRepy.userName)">{{ childRepy.userName }} </span> <span>回复</span> <span style="color:cadetblue">@{{ childRepy.target }} </span>
                           <span>： {{ childRepy.content }}</span> <span style="font-size: 10px; margin-left: 50px;"> {{ childRepy.commentTime }}</span> 
                        </div>
                      </div>
                    </div>
                </div>

                     
            </div>
        </div>

         <!-- 回复谈话框 -->
        <el-dialog
          title="回复"
          :visible.sync="replyDialogy"
          width="30%"
          :before-close="handleClose">
          <el-input type="textarea" v-model="replyComment.content" style="display: inline-block;ertical-align: middle; margin-left: 20px;"></el-input>
          <span slot="footer" class="dialog-footer">
            <el-button @click="replyDialogy = false">取 消</el-button>
            <el-button type="primary" @click="replyDialogy = false; saveReply()">确 定</el-button>
          </span>
        </el-dialog>
    </div>
</template>

<script>
export default {
    name: "bookDetail",
    data() {
       return {
        user: JSON.parse(localStorage.getItem("user") || '{}'),
        book: {},
        Personalized_book_list: [
          {bookUser: "zgh", bookList: "天堂的样子", id: 1},
          {bookUser: "zxx", bookList: "温暖的港湾", id: 2},
          {bookUser: "xxx", bookList: "天堂的模样", id: 3}
        ],
        searchInfo: "",
        value: 4.5,
        score: 0,
        dialogVisible: false,
        replyDialogy: false,
        colors: ['#99A9BF', '#F7BA2A', '#FF9900'] ,
        replyComment: {},
        // 评分比分数占比
        percentage5: 20,
        percentage4: 25.1,
        percentage3: 31.4,
        percentage2: 20.5,
        percentage1: 8.9,
        customColor: '#409eff',
        customColors: [
          {color: '#f56c6c', percentage: 20},
          {color: '#e6a23c', percentage: 40},
          {color: '#5cb87a', percentage: 60},
          {color: '#1989fa', percentage: 80},
          {color: '#6f7ad3', percentage: 100}
        ],
        comment: {
          rate: 0,
          content: ''
        },
        comments: [],
         // 搜索表单信息
         params: {
                name: "",
                type: "",
                author: "",
                createDate: "",
                pageNumber: 1,
                pageSize: 8,
            },
        bookId: "",
        top10Params: {
                name: "",
                type: "",
                author: "",
                pageNumber: 1,
                pageSize: 10,
            },
       }
    },
    created() {
        const bookString = this.$route.query.book;
        console.log("bookId: " + JSON.parse(bookString).id)
        if (bookString) {
        try {
            this.book = JSON.parse(bookString);
            this.bookId = this.book.id;
            // 现在，book 变量包含了传递过来的书籍信息
        } catch (error) {
            console.error('Error parsing book JSON:', error);
        }
        }

        this.load()
        this.getRate()
        this.getPersonalRate()
        
    },
    methods: {
      readBook() {
        this.$router.push({name: 'lookBook', params: { bid: this.book.id } })
      },
      bookRate() {
        const rateContent = {pid: null, userId: this.user.id, userName: this.user.name, bookId: this.book.id, target: null, rate: this.score}
        this.$http.post("/comment/rate", rateContent).then(res => {
          if (res.data.code == '200') {
            this.$message.success("评分成功")
            this.getRate()
          }
          else {
            this.$message.error("评分失败")
          }
        }) 
      },
      getPersonalRate() {
        const rateContent = {pid: null, userId: this.user.id, userName: this.user.name, bookId: this.book.id, target: null, rate: this.score}
        this.$http.post("/comment/personal_rate", rateContent).then(res => {
          if (res.data.code == '200') {
             this.score = res.data.data
          }
        }) 
      },
      getRate() {
          this.$http.get("/comment/rate?bookId="+this.book.id).then(res => {
            if (res.data.code == '200') {
              this.value = res.data.data.rate
            }
          })

      },
      addToList(id) {
         const addParams = {
          userId: this.user.id,
          bookId: id
         }
         this.$http.post("/book/addToShelf", addParams).then(res => {
            if (res.data.code == '200') {
              this.$message.success("添加成功")
            }
            else if (res.data.code == '400') {
              this.$message.error(res.data.message)
          }
            else {
              this.$message.error("添加失败")
            }
         })
      },
      goToBookList(bookListData) {
         // 导航到 book_list 组件
      // 可以使用 Vue Router 的 push 方法来导航并传递数据
      console.log("hhhh: " + bookListData.id );
      this.$router.push({ name: 'bookList', params:{bookListId:  bookListData.id}  });
      },
      reply(pid, userName) {
        this.replyComment = {pid: pid, userId: this.user.id, userName: this.user.name, bookId: this.book.id, target: userName}
      },
      saveReply() {
        this.$http.post("/comment", this.replyComment).then(res => {
          if (res.data.code == '200') {
            this.$message.success("回复成功")
            this.load()
            this.replyComment = {}
          }
          else {
            this.$message.error("回复失败")
          }
        }) 
      },
      load() {
        this.$http.get("/comment?bookId=" + this.book.id).then(res => {
          if (res.data.code == '200'){
              this.comments = res.data.data.comments

          }
          else {
            this.$message.error("加载数据失败")
          }
        })

      },
       //提交评论
       submit() {
         this.comment.userId = this.user.id;
         this.comment.userName = this.user.name
         this.comment.bookId = this.book.id
         this.$http.post("/comment", this.comment).then(res => {
          if (res.data.code == "200") {
            this.$message.success("评论成功")
            this.load()
            this.comment = {}
          }
          else {
            this.$message.error("评论失败")
          }
         })
       },
        searchBook() {
          this.params.author = this.searchInfo
            this.params.type = this.seacrhInfo
            this.params.name = this.seacrhInfo
            this.params.createDate = ""
            this.params.pageSize = 100
            this.$router.push({
                path: '/front/searchBook',
                query: {
                    author: this.params.author,
                    type: this.params.type,
                    name: this.params.name,
                    createDate: this.params.createDate,
                    pageSize: this.params.pageSize
                }
            })
        },
        recommand() {
          console.log("recom: " + this.book.id);
        },
        handleClose(done) {
        this.$confirm('确认关闭？')
          .then(_ => {
            done();
          })
          .catch(_ => {});
      },
        customColorMethod(percentage) {
        if (percentage < 30) {
          return '#909399';
        } else if (percentage < 70) {
          return '#e6a23c';
        } else {
          return '#67c23a';
        }
      },
      increase() {
        this.percentage += 10;
        if (this.percentage > 100) {
          this.percentage = 100;
        }
      },
      decrease() {
        this.percentage -= 10;
        if (this.percentage < 0) {
          this.percentage = 0;
        }
      }
    }

}
</script>

<style scoped>
.book_info > span {
    display: block;
}
.button_mod {
    background-color: antiquewhite;
    border: 1px solid; 
    width: 50px; 
    height: 2px; 
    display: inline-flex;
    align-items: center; justify-content: center;
}
.book_detail {
  font-size: 14px;
  margin-bottom: 10px;
}
.book_list {
  margin-bottom: 5px;
  padding: 2px;
  border-bottom: 1px dotted;
}
</style>
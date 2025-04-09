<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-12-06 10:53:10
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-01-02 13:40:41
-->
<!-- 书单书架 -->

<template>
    <div style="text-align: left;">
        <div style="display: flex; height: 60px; line-height: 60px;">
            <div style="width:300px; font-size: 24px; color: darkgreen;">
             个性化书单，天堂的模样
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
        
        <!-- 书单个人信息部分 -->
        <div style="background-color: whitesmoke; height: 120px; margin-top: 10px; display: flex;">
            <div style="display: flex; align-items: center; background-color: blue;">
                <div style="width: 120px;">
                    <el-avatar shape="circle" :size="100" :fit="fit" :src="url"></el-avatar>
                </div>
                <div style="background-color: brown; width: 500px; height: 100%; padding: 5px;">
                    <h2 style="display: inline;">{{ bookShelf.userName }}</h2>
                    <div style="margin-left: 50px; font-size: 12px;"> <span>创建时间：{{ bookShelf.createTime }}</span> <span style="margin-left: 50px;">更新时间：{{ bookShelf.updateTime }}</span> </div>
                </div>
            </div>

            <div style="width:300px; background-color:rgb(235, 231, 231); margin-left: 150px;">右边</div>
        </div>
        
        <div style="display: flex;">
             
            <div style="flex: 1;">
                <ul style="padding-left: 0;">
                    <li>
                    <div style="width:80%;background-color: rgb(223, 218, 218);; padding: 10px;">
                            <li v-for="(book, index) in booksDetail" :key="index" style="margin-bottom: 20px; background-color: white; padding: 10px; position: relative;">
                                
                                <div style="display: inline-block;">
                                    <router-link  :to="{ name: 'BookDetail', params: { id: book.id }, query: { book: JSON.stringify(book)  } }">
                                        <div style="height: 160px; display: inline-block;">
                                        <el-image :src="'https://images.weserv.nl/?url=' + book.imgUrl" :preview-src-list="['https://images.weserv.nl/?url=' + book.imgUrl]" style="width:100px; height:140px; margin-top: 10px;"></el-image>
                                        </div>
                                    </router-link>
                                    <div style="display: inline-block; vertical-align: top ;margin-left: 10px; margin-top: 10px;">
                                        <span class="book_detail">书名：<span style="color:#07a"> {{ book.name }}</span> </span>
                                        <span class="book_detail">作者：<span style="color:#07a">{{ book.author }}</span></span>
                                        <span class="book_detail">简介：<span style="color: #07a;">{{ book.introduction }}</span></span>
                                        <span class="book_detail">类型：<span style="color: #07a;"> {{ book.type }}</span></span>
                                        <span class="book_detail">发布时间：<span style="color: #07a;"> {{ book.createDate }}</span></span>
                                    </div>
                                    
                                </div> 
                                <div style="display:inline-block; vertical-align: top; position: absolute; ;right: 50px; ">
                                    <el-button type="text" class="el-icon-collection-tag" @click="addToList(book.id)">添加到书单</el-button>
                                </div>
                            </li>
                    </div>
                    </li>
                </ul>
           </div>
             
           <div style="width:310px; padding: 10px;">
              <h2 style="font-weight: normal; font-size: 18px; color: #072;">什么是书单……</h2>
              <p style="color: #c2c0c0; background-color: #f8f3f3;">书单是收集图书的工具，创建书单后，在豆瓣看到符合书单主题的图书时可以将它放入书单，方便以后找到。</p>
              <p style="color: #c2c0c0; background-color: #f8f3f3;">你还可以看看其他人的收集，关注你感兴趣的书单。</p>
              
              <div class="tag">
                <h2 style="font-weight: normal; font-size: 18px; color: #072;">
                    这个书单的标签
                </h2>

                <a v-for="(tag, index) in tags" :key="index" href="#">{{ tag }}</a>

              </div>
              
            </div>
        </div>
        
    </div>
</template>

<script>

export default {
   name: "bookList",
   props: {
      booksDetail: Array
    },
   data() {
      return {
        user: JSON.parse(localStorage.getItem("user") || '{}'),
        tags: [
            "文学",
            "古典",
            "诗词"
        ],
        book: {},
        books: {},
        params: {
            name: "",
            type: "",
            author: "",
            pageNumber: 1,
            pageSize: 100,
            id: 0
        },
        searchInfo: "",
        value: '',
        id: '',
        fit: 'fill',
        url: "",
        bookShelf: {
            userName: "hhh",
            userImgUrl: "dd",
            createTime: "2023-09-17",
            updateTime: "2023-09-18",
            bookList: [
                {ImgUrl: "sfdd", bookName: "你好世界"},
                {ImgUrl: "sfdd", bookName: "你好世界"},
                {ImgUrl: "sfdd", bookName: "你好世界"},
                {ImgUrl: "sfdd", bookName: "你好世界"},
                {ImgUrl: "sfdd", bookName: "你好世界"},
                {ImgUrl: "sfdd", bookName: "你好世界"},
                {ImgUrl: "sfdd", bookName: "你好世界"},
            ]
        }
      }
   },
   created() {
        
    const bookString = this.$route.query.book;
    this.url = this.user.avatar
    this.bookShelf.userName = this.user.name
        if (bookString) {
        try {
            this.book = JSON.parse(bookString);
            console.log(book);
            console.log("de: " + book.imgUrl)
            // 现在，book 变量包含了传递过来的书籍信息
        } catch (error) {
            console.error('Error parsing book JSON:', error);
        }
        }
        console.log(this.$route.params.bookListId);
        this.id = this.$route.params.bookListId
        this.getBookShelf(this.id)
        this.load();
   },
   methods: {
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
        getBookShelf(id) {
      
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
        load() {
            this.params.id = this.user.id
            this.$http.get("/book/bookPubShelf", { params: this.params }).then((res) => {
                this.books = res.data.data.list;
                this.booksDetail = this.books
                this.length = res.data.data.total;
            });
        },
   }
}
</script>

<style scoped>

.book_detail {
  font-size: 14px;
  margin-bottom: 10px;
  display: block;
  white-space: nowrap; 
  overflow: hidden; 
  text-overflow: ellipsis; 
  max-width: 200px;
}
.tag a {
    text-align: center;
    line-height: 30px;
    display: inline-block;
    margin-right: 10px;
    width: 50px;
    height: 30px;
    color: #37a;
    background-color: #d2d1d1;
}
.tag a:hover {
    background-color: #ccc9c9;
} 
/deep/ .el-avatar>img {
    display: inline-block !important;
    height: 100px !important;
    width: 100px;
    vertical-align: middle;
    border-radius: 50%;
}
</style>
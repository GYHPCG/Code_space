<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-12-03 13:06:29
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-05 22:34:53
-->
<template>
  <div>
    <div>  
        <div style="display: flex; height: 60px; line-height: 60px;">
            <div style="width:300px; font-size: 24px; color: darkgreen;">
             阅界，自由阅读
            </div>
            <div style="flex: 1;">
              <el-input
               placeholder="图书种类、作者、出版日期、IBSN"
                v-model="form"
                clearable
                style="width: 60%; height: 50px;"
                >
                </el-input>
                <el-button type="primary" class="el-icon-search" @click="searchBook"></el-button>
            </div>
            <div style="width: 300px;">年度阅读榜单</div>
        </div>
         
      <!-- 书籍展示 -->
       <div style="height: 500px; display: flex;">
        <div style="flex: 1; text-align: left;">
            <div> 
                <h3 style="display: inline;">书籍推荐</h3>
                <ul class="ul_head" style="display: inline-block;">
                    <li><a href="#">文学</a></li>
                    <li><a href="#">科幻</a></li>
                    <li><a href="#">古典</a></li>
                    <li><a href="#">计算机</a></li>
                    <li><a href="#">数学</a></li>
                </ul>
            </div>
        <!-- 书籍 -->
            <div>
                <ul class="book_list">
                    <router-link v-for="(book, index) in books" :key="index" :to="{ name: 'BookDetail', params: { id: book.id }, query: { book: JSON.stringify(book) } }">
                        <li class="book_info">
                        <!-- 显示书籍封面-->
                        <div style="height: 160px;">
                            <el-image :src="'https://images.weserv.nl/?url=' + book.imgUrl" :preview-src-list="['https://images.weserv.nl/?url=' + book.imgUrl]" style="width:100px; height:140px; margin-top: 10px;"></el-image>
                        </div>
                        <div>{{ book.name }}</div>
                        </li>
                    </router-link>
                </ul>
                <!-- 分页查询 -->
                 <div style="text-align: center;">
                      <!-- 分页上下查找  -->
                        <el-pagination
                            style="margin-top: 10px"
                            :background="true"
                            :current-page="params.pageNumber"
                            :page-size="params.pageSize"
                            @current-change="changePage"
                            layout="prev, pager, next"
                            :total="length"
                            >
                        </el-pagination>
                 </div>
            </div>
        </div>


         <div style="width: 300px;">
           <h3>阅界月度TOP10排名</h3>
           <ul class="book_top10">
                <li v-for="(book, index) in top10Books" :key="index" style="">
                        <div style="color: rgb(71, 134, 134); font-size: 18px; ">{{ rank = rank + 1 }}. {{ book.name }} <br>
                          <span style="display: block; margin-top: 3px ;color: gray; font-size: 14px; height: 25px;">{{ book.author }}</span>
                        </div>
                        
                    </li>
                </ul>
        </div>
      </div>

        <div>
            <ul>
            <router-link v-for="(book, index) in booksDetail" :key="index" :to="{ name: 'BookDetail', params: { id: book.id }, query: { name: book.name } }">
                <li>
                <div style="height: 160px;">
                    <el-image :src="'https://images.weserv.nl/?url=' + book.imgUrl" :preview-src-list="['https://images.weserv.nl/?url=' + book.imgUrl]" style="width:100px; height:140px; margin-top: 10px;"></el-image>
                </div>
                <div>{{ book.name }}</div>
                </li>
            </router-link>
            </ul>
        </div>
    </div>
      
  </div>
</template>

<script>
export default {
    name: "index",
    props: {
      booksDetail: Array
    },
    data() {
        return {
            length: 0,
            form: "",
            rank: 0,
            books: [
           ],
           top10Books: [],
           // 搜索表单信息
           params: {
                name: "",
                type: "",
                author: "",
                pageNumber: 1,
                pageSize: 8,
            },
            top10Params: {
                name: "",
                type: "",
                author: "",
                pageNumber: 1,
                pageSize: 10,
            },
        }
    },
    computed: {

    },
    created() {
        this.load()
        this.top10Load()
    },
    methods: {
        searchBook() {

        },
        changePage(pageNumber) {
            this.params.pageNumber = pageNumber;
            this.load();
        },
        load() {
            this.$http.get("/book/page", { params: this.params }).then((res) => {
                this.books = res.data.data.list;
                this.booksDetail = this.books
                console.log("img: " + this.books[0].imgUrl)
                this.length = res.data.data.total;
            });
        },
        top10Load() {
            this.$http.get("/book/page", { params: this.top10Params }).then((res) => {
                this.top10Books = res.data.data.list;
                this.length = res.data.data.total;
            });
        }
    }
}
</script>

<style scoped>
.ul_head li {
    display: inline-block;
    margin-left: 15px;
    font-size: 12px;
}
.book_list li {
    text-align: center;
    margin-left: 10px;
    margin-top: 20px;
    /* background-color: red; */
    display: inline-block;
    width: 160px;
    height: 200px;
}
.book_list {
    height: 450px;
    overflow: hidden;
}

/* 书籍top10排名 */
.book_top10 {
    text-align: left;
    height: 500px;
}
.book_top10 li {
  height: 45px;
  display: block;
  border-bottom: 1px dashed;
  /* margin-bottom: 5px; */
  padding-bottom: 1px;
}
.book_info {
    transition: transform 0.3s ease-in-out, box-shadow 0.3s ease-in-out;
}
.book_info:hover {
    transform: translateY(-5px);  
     box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1); 
}
</style>
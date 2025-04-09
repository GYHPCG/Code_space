<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-12-03 13:06:29
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-01-02 18:13:24
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
                v-model="seacrhInfo"
                clearable
                style="width: 60%; height: 50px;"
                @keyup.native.enter="searchBook"
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
                    <li @click="getBookByType('')"><a href="#">全部</a></li>
                    <li @click="getBookByType('文学')"><a href="#">文学</a></li>
                    <li @click="getBookByType('科幻')"><a href="#">科幻</a></li>
                    <li @click="getBookByType('古典')"><a href="#">古典</a></li>
                    <li @click="getBookByType('计算机')"><a href="#">计算机</a></li>
                    <li @click="getBookByType('历史')"><a href="#">历史</a></li>
                    <li @click="getBookByType('军事')"><a href="#">军事</a></li>
                </ul>
            </div>
        <!-- 书籍 -->
            <div class="books_item">
                <ul class="book_list">
                    <router-link v-for="(book) in books" :key="book.id" :to="{ name: 'BookDetail', params: { id: book.id }, query: { book: JSON.stringify(book) } }">
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
                               <router-link :to="{ name: 'BookDetail', params: { id: book.id }, query: { book: JSON.stringify(book) } }">
                                 <div style="color: rgb(71, 134, 134); font-size: 18px; ">{{ getRank(index) }}. {{ book.name }} <br> </div>
                                </router-link>
                                <div>
                                  <span style="display: block; margin-top: 3px; padding-left: 20px ;color: gray; font-size: 14px; height: 25px;">{{ book.author }}</span>
                                </div>   
                        </li>
                    </ul>
            </div>
        </div>

      <!-- 书籍展示 -->
      <div style="height: 500px; display: flex; margin-bottom: 100px; margin-top: 100px;">
        <div style="flex: 1; text-align: left;">
            <div> 
                <h3 style="display: inline;">阅友评分推荐</h3>
                <ul class="ul_head" style="display: inline-block;">
                    <li @click="getBookByRate('')"><a href="#9">全部</a></li>
                    <li @click="getBookByRate('文学')"><a href="#9">文学</a></li>
                    <li @click="getBookByRate('科幻')"><a href="#9">科幻</a></li>
                    <li @click="getBookByRate('古典')"><a href="#9">古典</a></li>
                    <li @click="getBookByRate('计算机')"><a href="#9">计算机</a></li>
                    <li @click="getBookByRate('数学')"><a href="#9">数学</a></li>
                </ul>
            </div>
        <!-- 书籍 -->
            <div class="books_item">
                <ul class="book_list">
                    <router-link v-for="(book) in  rateBooks" :key="book.id" :to="{ name: 'BookDetail', params: { id: book.id }, query: { book: JSON.stringify(book) } }">
                        <li class="book_info">
                      
                        <div style="height: 160px;">
                            <el-image :src="'https://images.weserv.nl/?url=' + book.imgUrl" :preview-src-list="['https://images.weserv.nl/?url=' + book.imgUrl]" style="width:100px; height:140px; margin-top: 10px;"></el-image>
                        </div>
                        <div>{{ book.name }}</div>
                        </li>
                    </router-link>
                </ul>
               
                 <div style="text-align: center;">
                     
                        <el-pagination
                            style="margin-top: 10px"
                            :background="true"
                            :current-page="rateParams.pageNumber"
                            :page-size="rateParams.pageSize"
                            @current-change="rateChangePage"
                            layout="prev, pager, next"
                            :total="ratelength"
                            >
                        </el-pagination>
                 </div>
            </div>

        </div>
        
            <div style="width: 300px;">
            </div>
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
            ratelength: 0,
            length: 0,
            seacrhInfo: "",
            rank: 0,
            books: [
           ],
           rateBooks: [],
           top10Books: [],
           // 搜索表单信息
           params: {
                name: "",
                type: "",
                author: "",
                createDate: "",
                pageNumber: 1,
                pageSize: 8,
            },
            rateParams: {
                name: "",
                type: "",
                author: "",
                createDate: "",
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
        // 计算属性，用于获取书籍的排名
    rankedBooks() {
      return this.top10Books.map((book, index) => ({ ...book, rank: index + 1 }));
    },
    },
    created() {
        this.load()
        this.top10Load()
        this.rateLoad()
    },
  
    methods: {
        getRank(index) {
            return this.rankedBooks[index].rank;
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
        getBookByRate(type) {
            this.rateParams.type = type;
            this.rateLoad()
            
        },
        getBookByType(type) {
             this.params.type = type;
             console.log("类型：" + this.params.type);
             this.load();
        },
        rateChangePage(pageNumber) {
            this.rateParams.pageNumber = pageNumber;
            this.rateLoad();
        },
        changePage(pageNumber) {
            this.params.pageNumber = pageNumber;
            this.load();
        },
        load() {
            this.$http.get("/book/page", { params: this.params }).then((res) => {
                this.books = res.data.data.list;
                this.booksDetail = this.books
                this.length = res.data.data.total;
            });
        },
        rateLoad() {
            this.$http.get("/book/pageByRate", { params: this.rateParams }).then((res) => {
                this.rateBooks = res.data.data.list;
                // this.booksDetail = this.books
                this.ratelength = res.data.data.total;
            });
        },
        top10Load() {
            console.log('top10Load start');
            this.$http.get("/book/pageByRate", { params: this.top10Params }).then((res) => {
                console.log('top10Load response received');
                 // 使用临时变量保存数据
                const top10Books = res.data.data.list;
                const length = res.data.data.total;
                this.top10Books = top10Books;
                // 修改响应式数据时，避免在同一更新周期内多次修改
                if(this.length !== length) {
                    this.$nextTick(() => {
                    // 更新响应式数据
                    this.length = length;
                });
                }
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
    background-color: rgb(232, 228, 228);
    display: inline-block;
    width: 160px;
    height: 200px;
}
.book_list {
    /* width: 80%; */
    margin-bottom: 20px;
    height: 450px;
    overflow: hidden;
    padding-left: 0;
    /* background-color: rgb(218, 216, 216); */
}
.books_item {
    margin-bottom: 100px;
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
h3 {
    padding-left: 40px;
}
</style>
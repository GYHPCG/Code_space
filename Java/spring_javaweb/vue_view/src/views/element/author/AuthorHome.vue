
  <template>
    <div class="personalCenter">
      <el-container>
        <el-container>
          <el-aside width="300px;">
            <el-col :span="12">
              <div class="sub-title"></div>
              <div class="demo-basic--circle">
                <div class="img">
                  <el-avatar
                    :size="100"
                    :src="circleUrl"
                    align="left"
                  ></el-avatar>
                </div>
                <div class="block">
                  <span>{{ authorInfo.penName }}</span>
                </div>
              </div>
                <div>
                  <el-button type="info" @click="dialogVisible = true">修改头像</el-button>
                </div>
                <!-- action="http://localhost:9099/api/file/upload" -->
                <el-dialog
                  title="提示"
                  :visible.sync="dialogVisible"
                  width="30%"
                  :before-close="handleClose">
                  <el-upload
                  class="avatar-uploader"
                  :action="$baseUrl + '/file/upload'"
                  :headers="{token:  user.token}"
                  :show-file-list="false"
                  :on-success="handleAvatarSuccess"
                  list-type="picture"
                  :moral="false"
                  >
                  <img v-if="circleUrl" :src="circleUrl" class="avatar">
                  <i v-else class="el-icon-plus avatar-uploader-icon"></i>
                  </el-upload>
                  <span slot="footer" class="dialog-footer">
                    <el-button @click="dialogVisible = false">取 消</el-button>
                    <el-button type="primary" @click="dialogVisible = false">确 定</el-button>
                  </span>
                </el-dialog>
            </el-col>
            
            <el-form :model="authorInfo" ref="userForm" label-width="80px" style="margin-top: 250px; padding-right: 10px;">
             <el-form-item label="作者笔名">
                <el-input v-model="authorInfo.penName" type="text" placeholder="用户昵称" show-word-limit></el-input>
              </el-form-item>
              <el-form-item label="密码">
                <el-input v-model="authorInfo.passwd" placeholder="请输入密码" show-password></el-input>
              </el-form-item>
              <el-form-item label="作者姓名">
                <el-input v-model="authorInfo.name" type="text" placeholder="用户姓名" show-word-limit></el-input>
              </el-form-item>
              <el-form-item label="邮箱">
                <el-input v-model="authorInfo.qq" placeholder="邮箱"></el-input>
              </el-form-item>
              <el-form-item label="手机号码">
                <el-input v-model="authorInfo.phone" type="text" placeholder="手机号码" maxlength="20" show-word-limit></el-input>
              </el-form-item>
            </el-form>
            <el-button-group style="float: right; padding: 3px 0" type="text">
              <el-button type="primary" size="medium" round @click="save">保存</el-button>
            </el-button-group>
          </el-aside>
  
            <el-main style="height: 100vh;">
              <el-card class="box-card">
                <div>
                  <span style="float: left" shadow="hover"><b>个人说明</b></span>
                  {{ authorInfo.introduce }}
                </div>
              </el-card>
              <h2>我的书架</h2>
                <div style="height: 100vh; background-color: aliceblue;">
                  <div class="books_item" v-if="books.length > 0">
                   <ul class="book_list">
                          <li class="book_info" v-for="book in books" :key="book.id">
                          <!-- 显示书籍封面-->
                          <router-link :to="{ name: 'BookDetail', params: { id: book.id }, query: { book: JSON.stringify(book) } }">
                          <div style="height: 160px;">
                              <el-image :src="'https://images.weserv.nl/?url=' + book.imgUrl" :preview-src-list="['https://images.weserv.nl/?url=' + book.imgUrl]" style="width:100px; height:140px; margin-top: 10px;"></el-image>
                          </div>
                        </router-link>
                          <div>{{ book.name }}
                            <el-button type="danger" icon="el-icon-delete" circle size="small" @click="deleteBook(book.id)"></el-button>
                          </div>
                          
                          </li>
                      
                   </ul>
                    <!-- 分页查询 -->
                    <div style="text-align: center;">
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
                  <div v-else> <el-empty description="书架为空，欢迎添加书籍到你的书架"></el-empty></div>
                </div>
            </el-main>
        </el-container>
      </el-container>
    </div>
  </template>
  <script>
  export default {
    name: "PersonalCenter",
    props: {
        booksDetail: Array
      },
    data() {
      return {
        dialogVisible: false,
        user: JSON.parse(localStorage.getItem("user") || '{}'),
        length: 0,
        books: [],
        circleUrl: "",
        sizeList: ["large"],
        authorInfo: {
  
        },
        params: {
          name: "",
          type: "",
          author: "",
          pageNumber: 1,
          pageSize: 8,
          id: 0,
        },
      };
    },
    created() {
       this.getauthorInfo()
       this.load()
    },
    methods: {
      // 文件上传处理
      handleAvatarSuccess(res) {
          console.log(res)
          if(res.code == "200") {
            this.circleUrl = res.message
            this.$forceUpdate()
            this.authorInfo.avatar = this.circleUrl
            this.save()
            let localUser =  JSON.parse(localStorage.getItem("user") || '{}')
            localUser.avatar = this.circleUrl
            localStorage.setItem("user", JSON.stringify(localUser))
            this.user = JSON.parse(localStorage.getItem("user") || '{}') 
          }
          else {
            this.$message.error("上传失败")
          }
        },
      handleClose(done) {
          this.$confirm('确认关闭？')
            .then(_ => {
              done();
            })
            .catch(_ => {});
          },
      deleteBook(bookId) {
  
         const deleteParams = {
          userId: this.user.id,
          bookId: bookId
         }
         this.$http.post("/book/delFromShelf", deleteParams).then(res => {
            if (res.data.code == '200') {
                this.$message.success("书籍移除成功")
                this.load()
            }
            else {
              this.$message.error("删除失败，请重新删除")
              console.log("err: " + res.data.message);
            }
         })
      },
      save() {
        this.$http.put("/author/updateInfo", this.authorInfo).then(res => {
          if (res.data.code == '200') {
              this.$message.success("修改信息成功")
          }
          else {
            this.$message.error("修改失败")
          }
        })
      },
      changePage(pageNumber) {
              this.params.pageNumber = pageNumber;
              this.load();
          },
      load() {
              this.params.id = this.user.id
              this.$http.get("/book/bookshelf", { params: this.params }).then((res) => {
                  this.books = res.data.data.list;
                  this.length = res.data.data.total;
                  console.log("length: " + this.length)
              });
          },
      getauthorInfo() {
        this.$http.get("/author/getInfo/"+this.user.id).then(res => {
          if (res.data.code == '200') {
              this.authorInfo = res.data.data
              console.log("img: " + this.authorInfo.avatar )
              this.circleUrl = this.authorInfo.avatar
          }
        })
      }
    },
  };
  </script>
  <style scoped>
  .el-header {
    line-height: 60px;
    text-align: center;
    background-color: #b3c0d1;
  }
  .el-aside {
    line-height: 44px;
    text-align: center;
    background-color: #d3dce6;
  }
  .el-main {
    line-height: 36px;
    text-align: center;
    background-color: #e9eef3;
  }
  
  .demo-basic--circle {
    margin-top: 30px;
    margin-left: 60%;
  }
  .block {
    margin-left: 25px;
    font-weight: bold;
  }
  .text {
    font-size: 14px;
  }
  .item {
    margin-bottom: 18px;
  }
  .clearfix:before,
  .clearfix:after {
    display: table;
    content: "";
  }
  .clearfix:after {
    clear: both;
  }
  
  .box-card {
    width: 100%;
    margin-bottom: 10px;
    border-radius: 30px;
    height: 100px;
  }
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
  
  /deep/ .el-avatar>img {
      display: inline-block !important;
      height: 100px !important;
      width: 100px;
      vertical-align: middle;
      border-radius: 50%;
  }
  </style>
  
  
<template>
    <div>
      <el-tabs v-model="activeName">
        <el-tab-pane label="作品管理" name="作品管理">
          <div v-if="!listIsNull">
            <el-row v-for="(item, index) in bookList" :key="index" style="margin-bottom: 20px; border-bottom: 1px solid; text-align: left;">
              <el-col :span="12">
                <el-row>
                  <el-col :span="12">
                    <router-link :to="{ name: 'BookDetail', params: { id: item.id }, query: { book: JSON.stringify(item) } }">
                    
                      <img style="width:150px;height:180px;" :src="item.imgUrl" />
                  </router-link>
                  </el-col>
                  <el-col :span="12">
                    <div>
                      <p>
                        书名：   <strong>{{item.name}}</strong>
                      </p>
                      <p style="padding-top: 10px;">收藏量：100</p>
                      <p>创建时间：{{ item.createDate }}</p>
                      <p>最近更新时间：{{ item.updateTime }}</p>
                    </div>
                  </el-col>
                </el-row>
              </el-col>
              <el-col :span="12" style="text-align: right;">
                <el-row>
                    <el-button type="info" plain @click="chapterManager(item.id)">章节管理</el-button>
                </el-row>                                                                                                                                                                                                               
                <el-row style="margin-top: 6pc;">
                  <el-button  type="danger" icon="el-icon-delete"  @click="delBook(item.id)">删除</el-button>
                  <el-button plain v-if="item.end==false"  @click="endBook(item.id)">点击完结</el-button>
                  <el-button plain v-else disabled>已完结</el-button>
                  <el-button v-if="!item.end" type="primary" plain>
                    <router-link :to="{name: 'writeBook', params: {'bid': item.id}}">去写作</router-link>
                   </el-button>
                  <el-button v-else type="primary" plain disabled>已结束</el-button>
                </el-row>
              </el-col>
            </el-row>
          </div>
          <div v-if="listIsNull">
            <el-empty ></el-empty>
          </div>
        </el-tab-pane>
        <el-tab-pane label="新建作品" name="新建作品">
          <el-form ref="bookForm" :model="bookForm" label-width="80">
            <el-form-item label="作品名称">
              <el-input v-model="bookForm.name" style="width: 50%;float: left;"></el-input>
            </el-form-item>
            <!-- :label-width="10"  -->
            <el-form-item label="作品封面" style="text-align: left;">
            <!-- 上传文件 -->
            <el-upload
              class="avatar-uploader"
              :action="$baseUrl + '/file/upload'"
              :headers="{token:  user.token}"
              :show-file-list="false"
              :on-success="handleAvatarSuccess"
              list-type="picture"
              :moral="false"
              >
               <img v-if="bookForm.imgUrl" :src="bookForm.imgUrl" class="avatar">
               <i v-else class="el-icon-plus avatar-uploader-icon"></i>
              </el-upload>
            </el-form-item>
            <el-form-item label="作品类型">
              <el-select v-model="bookType" multiple placeholder="请选择" style="float: left;">
                <el-option v-for="(item) in typeOptions" :key="item.value" :label="item.label" :value="item.value">
                </el-option>
              </el-select>
            </el-form-item>
            <el-form-item label="作品介绍">
              <el-input type="textarea" v-model="bookForm.introduction"></el-input>
            </el-form-item>
            <el-form-item>
              <el-button type="primary" @click="onSubmit">立即创建</el-button>
              <el-button>取消</el-button>
            </el-form-item>
          </el-form>
        </el-tab-pane>

        <el-tab-pane label="章节管理" name="章节管理">
          <el-table
          :data="chapters"
          border
          style="width: 100%">
          <el-table-column 
          label="书籍名"
          prop="name"
          width="120">
          </el-table-column>
          <el-table-column 
          prop="chapter"
          label="章节名称"
          width="120">
          </el-table-column>
          <el-table-column 
          prop="chapterId"
          label="章节数"
          width="100">
          </el-table-column>
          <el-table-column 
          prop="updatedTime"
          label="更新时间"
          width="100">
          </el-table-column>
          <el-table-column
            label="操作"
            width="350">
            <template v-slot="scope">
              <el-button type="primary" icon="el-icon-edit" circle="" @click="modify(scope.row)"></el-button>
              <el-button type="danger" icon="el-icon-delete" circle="" @click="del(scope.row)"></el-button>
              <el-switch
                  style="margin-left: 30px;"
                  v-model="scope.row.status"
                  @change="enable(scope.row)"
                  active-text="发布"
                  inactive-text="下架">
                </el-switch>
            </template>
          </el-table-column>
        </el-table>
        </el-tab-pane>
      </el-tabs>
    </div>
  </template>
  
  <script>
  export default {
    name: "managerBook",
    data() {
      return {
        user: JSON.parse(localStorage.getItem("user") || '{}'),
        activeName: "作品管理",
        // formLabelWidth: "120px",
        bookList: [],
        url: "../../../assets/img/default_book.png",
        newChapter: [{}],
        chapters: [],
        listIsNull: false,
        bookForm: {
          author: "",
          name: "",
          type: "",
          introduction: "",
          imgUrl: '',
        },
        bookId: '',
        bookType: [],
        typeOptions: [{value: '文学', label: '文学' },{value: '古典', label:'古典'},
        {value: '科幻', label:'科幻'}, {value: '诗词', label: '诗词'}, {value: '历史', label: '历史'},
        {value: '军事', label: '军事'},{value: '计算机', label: '计算机'}, {value: '数学', label: '数学'}
        ]
      };
    },
    created() {
      this.getBookByAuthor()
    },
    methods: {
      delBook(id) {
         this.$http.delete('/book/del/' + id).then(res => {
          if (res.data.code == '200') {
            this.$message.success("删除成功")
            this.getBookByAuthor()
          }
         })
      },
      getBookByAuthor() {
          const url = "/authorManager/book?authorName=";
           this.$http.get(url + this.user.name).then(res => {
              if (res.data.code == '200') {
                this.bookList = res.data.data
                if (this.bookList.length == 0) this.listIsNull = true
                console.log("empty: " + this.listIsNull);
              }
           })
      },
      // 文件上传处理
      handleAvatarSuccess(res) {
        console.log(res)
        if(res.code == "200") {
          this.bookForm.imgUrl = res.message
          console.log("img22: " + this.bookForm.imgUrl)
          this.$forceUpdate()
        }
        else {
          this.$message.error("上传失败")
        }
      },
      endBook (id) {
        this.$http.put("/book/end/" + id).then(res => {
          if (res.data.code == '200') {
            this.$message.success("操作成功")
            this.getBookByAuthor()
          }
        })
      },
      modify(row){
        const param = {
          bookId: this.bookId,
          chapter: row.chapter,
          status: row.status,
          chapterId: row.chapterId
        }
        console.log("modify: " + JSON.stringify(row));
        this.$router.push({name:"writeBook", query: {param: JSON.stringify(param)}})
      },
      del(row) {
        const params = {
          bookId: this.bookId,
          chapter: row.chapter,
          status: row.status
        }
        this.$http.put("/write/delChapter", params).then(res =>{
          if (res.data.code == '200') {
            this.$message.success("删除本章节成功")
            this.chapterManager(this.bookId)
          }
          else {
            this.$message.error("删除失败")
          }
        })
      },
      enable(row) {
        const param = {
          bookId: this.bookId,
          chapter: row.chapter,
          status: row.status
        }
          console.log("enable: " + JSON.stringify(param));
          this.$http.put("/write/enable", param).then(res => {
               if (res.data.code == '200') {
                this.$message.success("操作成功")
                  this.chapterManager(this.bookId)
               } 
               else {
                this.$message.error("操作失败")
               }
          })
      },
      chapterManager(id) {
        this.activeName='章节管理',
        this.chapters = []
        this.$http.get("/write/getContent/" + id).then(res => {
          if (res.data.code == '200') {
             this.bookId = res.data.data.bookId
             this.chapters = res.data.data.chapters
          }
          else {
            this.$message.error("获取章节内容失败")
          }
        })
      },
      onSubmit() {
        this.bookForm.wid = localStorage.getItem("wid");
        this.bookForm.author = this.user.name;
        this.bookForm.type = this.bookType.toString();
        this.$http.post("/book/addBook", this.bookForm).then(res => {
          if (res.data.code == '200') {
            this.$message.success("恭喜你，创建成功");
            this.bookForm = {}
            this.bookType = []
            this.getBookByAuthor()
            this.$router.push("/writeBook/" + res.data.data.id)
          }
          else {
            this.$message.error("添加失败")
          }
          
        });
      }
    }
  };
  </script>
  
  <style scoped>
  </style>
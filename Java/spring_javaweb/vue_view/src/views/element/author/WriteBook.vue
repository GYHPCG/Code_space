<template>
    <div>
      <el-card style="height: 45pc;">
          <el-container style="45pc;">
              <el-header style="hight: 6pc;">
                  <el-row>
                      <el-col :span="20">
                          <el-card shadow="hover">
                              {{chapterForm.name}}
                          </el-card>
                      </el-col>
                      <el-col :span="4">
                          <el-button type="primary" style="margin-top: 8px;" @click="publish()">发布最新章节</el-button>
                      </el-col>
                  </el-row>
              </el-header>
              <el-container>
                  <el-aside width="15pc" style="margin-top: 1pc">
                      <el-form :model="chapterForm" :rules="rules" ref="chapterForm" label-width="100px" class="demo-ruleForm">
                      <el-form-item label="章节名称" prop="name">
                          <el-input v-model="chapterForm.chapter"></el-input>
                      </el-form-item>
                      <el-form-item label="章节数" prop="chapterId">
                
                              <el-input v-model="chapterForm.chapterId"></el-input>
      
                      </el-form-item>
                      <el-form-item label="章节是否完结" prop="end">
                          <el-switch v-model="chapterForm.end"></el-switch>
                      </el-form-item>
                      <el-form-item>
                          <el-button @click="resetForm('chapterForm')" style="margin-bottom: 5px;">重置</el-button>
                          <el-button type="primary" @click="saveEdit(chapterForm)" style="margin-bottom: 5px;">保存该进度</el-button>
                          <el-button type="primary" @click="newChapterClear()" style="margin-bottom: 5px;">创建新章节</el-button>
                          <el-button type="primary" @click="newChapter()" style="margin-bottom: 5px;">保存新章节</el-button>
                      </el-form-item>
                      </el-form>
                  </el-aside>
                  <el-main style="height: 40pc;">
                      <quill-editor v-model="chapterForm.content" ref="myQuillEditor" style="height: 36pc;
                                                                                      width: 100%;
                                                                                      float: right;" 
                              :options="editorOption">
                      </quill-editor>
                  </el-main>
              </el-container>
          </el-container>
        
      </el-card>
    </div>
  </template>
  
  <script>
    import {
      quillEditor
    } 
    from 'vue-quill-editor'
    import 'quill/dist/quill.core.css'
    import 'quill/dist/quill.snow.css'
    import 'quill/dist/quill.bubble.css'
    export default {
      name: 'FuncFormsEdit',
      components: {
        quillEditor
      },
      data() {
        return {
          editorOption: {},
          bid: '',
          chapterForm: {
            articleId: "",
            bookId: '',
            name: '',
            chapter: "",
            chapterId: '',
            lastChapter: '',
            end: false,
            content: null,
            status: false,
          },
          newChapterForm: {
            articleId: "",
            bookId: '',
            name: '',
            chapterId: '',
            lastChapter: '',
            end: false,
            content: null,
            status: false,
          },
          rules: {
  
          },
          param: {},
          bookId: "",
        }
      },
      created () {
          this.bid = this.$route.params.bid
          let param = this.$route.query.param
          if (this.bid) {
            console.log("writebook: " + this.bid);
            this.bookId = this.bid;
            this.getBook();
          } else if (param) {
            param = JSON.parse(param)
            this.param = param
            this.bookId = param.bookId
            this.getChapter(param);
          } else {
            console.warn("No bid or param found.");
          }

      },
      methods: {
        getChapter(param) {
          this.$http.post('/write/getBookNameAndContent', param).then(res => {
            if (res.data.code == '200') {
                console.log("getChapter: " + JSON.stringify(res.data))
                this.chapterForm = res.data.data
            }
          })
        },
        getBook() {
          this.$http.get('/write/getLatestChap/'+ this.bookId).then(res => {
               if (res.data.code == '200') {
                this.chapterForm = res.data.data
               }
          })
        },
        saveEdit(formName) {
          console.log("save: " + JSON.stringify(formName));
          this.$http.post('/write/edit', formName).then(res => {
             if(res.data.code == '200') {
                  this.$message.success("保存成功")
                  this.getChapter(this.param)
             }
         })
        },
        newChapterClear() {
           this.chapterForm = {}
           this.$message.success("请填写新章节相关信息")
        },
        newChapter() {
           this.chapterForm.bookId = this.bookId
           this.chapterForm.end = false;
           this.chapterForm.status = false;
           this.$http.post("/write/newChapter", this.chapterForm).then(res => {
            if(res.data.code == '200') {
              this.$message.success("创建新章节成功，可以开始写作了")
              
            }
           })
           
        },
        resetForm(formName) {
          this.$refs[formName].resetFields();
        },
        publish () {
          console.log("publish log: " + JSON.stringify(this.chapterForm))
           this.$http.post("/write/publish", this.chapterForm).then(res => {
               if (res.data.code == '200') {
                  this.$message.success("发布章节成功")

               }
           })
        }
      }
    }
  
  </script>
  
  <style scoped>
  </style>
  
  
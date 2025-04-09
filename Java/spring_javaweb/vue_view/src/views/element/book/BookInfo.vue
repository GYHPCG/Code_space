<template>
    <div class="book-info-home">
      <div class="page-home">
        <div class="background-class book-info">
          <img class="book-img" :src="bookInfo.bookImg" />
          <div class="book-info-easy">
            <h1>
              {{bookInfo.bookName}}
              <span>{{bookInfo.bookAuthor}} 著</span>
            </h1>
            <div class="book-type-div">
              <span
                v-if="bookInfo.isEnd?bookIsEnd='已完结':bookIsEnd='连载中'"
                class="is-end is-end-color"
              >{{bookIsEnd}}</span>
              <div v-for="item in labels" :key="item.id">
                <span class="is-end label-color">{{item.labelName}}</span>
              </div>
            </div>
            <div class="book-click">
              <div style="margin-right: 15px;padding-right: 15px;border-right: 1px solid #A6A6A6;">
                <span class="book-click-word">{{bookInfo.bookClick}}</span>
                <span style="font: 12px/20px PingFangSC-Regular,'-apple-system',Simsun;">总点击</span>
              </div>
              <div>
                <span class="book-click-word">{{bookInfo.bookCollection}}</span>
                <span style="font: 12px/20px PingFangSC-Regular,'-apple-system',Simsun;">总收藏</span>
              </div>
            </div>
            <div class="book-introduction">
              <el-collapse-transition name="el-zoom-in-top">
                <div :class="show ? '':'text-overflow'">
                  <div v-html="text" class="transition-box"></div>
                </div>
              </el-collapse-transition>
              <div style="display: flex;justify-content: flex-end;">
                <el-button type="text" @click="show = !show" style="color:#E6A23C;text-align: right;">
                  展开
                  <i :class="show? 'el-icon-arrow-up':'el-icon-arrow-down'"></i>
                </el-button>
              </div>
            </div>
            <div>
              <el-button type="warning" round plain @click="goToLookBook(bookId,1);">免费试读</el-button>
              <el-button type="warning" round @click="addToMyBook" v-if="!isMyBook">加入书架</el-button>
              <el-button type="warning" round @click="addToMyBook" v-else>已在书架</el-button>
            </div>
          </div>
        </div>
        <div class="specific-info">
          <el-tabs v-model="activeName">
            <el-tab-pane label="作品信息" name="first">
              <div class="work-info">
                <div class="work-info-reader">
                  <div class="work-info-reader-title">作品互动区</div>
                  <div class="gift">
                    <h4>礼物</h4>
                    <span>写的怎么样？支持一下作者吧！</span>
                  </div>
                  <div class="work-info-reader-gift">
                    <div class="gift-info" @click="openSendGift(99, '捧花')">
                      <!-- <img src="../../assets/flower.png" /> -->
                      <p class="money">99阅读币</p>
                      <p class="gift-name">捧花</p>
                    </div>
                    <div class="gift-info" @click="openSendGift(199, '肉腿')">
                      <!-- <img style="width: 70px;" src="../../assets/meat.png" /> -->
                      <p class="money">199阅读币</p>
                      <p class="gift-name">肉腿</p>
                    </div>
                    <div class="gift-info" @click="openSendGift(520, '牛奶')">
                      <!-- <img src="../../assets/milkTea.png" /> -->
                      <p class="money">520阅读币</p>
                      <p class="gift-name">牛奶</p>
                    </div>
                    <div class="gift-info" @click="openSendGift(999, '乳猪')">
                      <!-- <img src="../../assets/pig.png" /> -->
                      <p class="money">999阅读币</p>
                      <p class="gift-name">乳猪</p>
                    </div>
                    <div class="gift-info" @click="openSendGift(199, '刀片')">
                      <!-- <img src="../../assets/knife.png" /> -->
                      <p class="money">199阅读币</p>
                      <p class="gift-name">刀片</p>
                    </div>
                  </div>
                </div>
                <div class="work-discuss-reader">
                  <div class="work-info-reader-title">作品讨论区</div>
                  <div class="reader-biscuss">
                    <div>
                      <!-- <img style="width: 44px;border-radius: 20px;" src="../../assets/noHead.jpg" /> -->
                    </div>
                    <div class="more-input">
                      <el-input
                        placeholder="输入标题（选填，最多25个字）"
                        maxlength="25"
                        @input="searchInput"
                        @focus="textarea=true"
                        v-model="inputBiscuss"
                      >
                        <span
                          slot="suffix"
                          style="font-size: 12px;line-height: 34px;"
                        >{{inputBiscussLen}}/25字</span>
                      </el-input>
                      <el-input
                        v-if="textarea"
                        type="textarea"
                        :autosize="{ minRows: 3, maxRows: 7}"
                        placeholder="请输入评论内容"
                        v-model="inputTextarea"
                        @input="searchTextarea"
                        maxlength="500"
                      ></el-input>
                      <span v-if="textarea" class="textarea-word">{{inputTextareaLen}}/500字</span>
                      <div v-if="textarea" class="biscuss-button">
                        <el-button type="text" @click="textarea = false" style="color:#E6A23C;">取消</el-button>
                        <el-button type="warning" round @click="insertEvaluate()">确定发布</el-button>
                      </div>
                    </div>
                  </div>
                  <div class="work-info-reader-content">最新</div>
                  <div v-for="item in evaluateData" :key="item.id" class="eva-info">
                    <!-- <img
                      style="width: 44px;height: 44px;border-radius: 20px;"
                      src="../../assets/noHead.jpg"
                    /> -->
                    <div class="eva-info-div">
                      <div>
                        <span>{{item.title}}</span>
                        <span>{{item.date}}</span>
                      </div>
                      <span style="margin-top: 15px;font-size: 14px;">{{item.content}}</span>
                    </div>
                  </div>
                </div>
              </div>
              <div class="writer-info">
                <div class="writer-info-reader">
                  <!-- <img style="width: 100px;border-radius: 100px;" src="../../assets/noHead.jpg" /> -->
                  <h3>{{bookInfo.bookAuthor}}</h3>
                </div>
              </div>
            </el-tab-pane>
            <el-tab-pane name="second">
              <div slot="label" style="display: flex;align-items: center;">
                目录
                <span
                  class="chapter-num"
                >更新至 第{{newChapter.chapterBookId}}章 {{newChapter.chapterName}}</span>
              </div>
              <div class="book-chapter-info">
                <div class="book-chapter-info-title" v-if="isChapter">正文(共更{{chapterBook.length}}章)</div>
                <div class="book-chapter-info-title" v-else>正文(共更0章)</div>
                <div class="chapter-name-div">
                  <div v-for="n in chapterDivNum" :key="n" class="chapter-for-div">
                    <div
                      v-for="(item,index) in chapterBook.slice((n-1)*3,n*3)"
                      :key="index"
                      style="width: 265px;display: flex;align-items: center;"
                    >
                      <div
                        class="chapter-name"
                        v-if="item.vip"
                        @click="isChapterPay(item.id,item.chapterBookId)"
                      >
                        <span>第{{item.chapterBookId}}章 {{item.chapterName}}</span>
                      </div>
                      <div
                        class="chapter-name"
                        v-else
                        @click="goToLookBook(bookId,item.chapterBookId)"
                      >
                        <span>第{{item.chapterBookId}}章 {{item.chapterName}}</span>
                      </div>
                      <!-- <img v-if="item.vip" src="../../assets/VIP.png" /> -->
                    </div>
                  </div>
                </div>
              </div>
            </el-tab-pane>
          </el-tabs>
        </div>
        <el-dialog title="提示" :visible.sync="sendGiftDialog" width="30%">
          <span>确定要打赏这位作者吗？</span>
          <span slot="footer" class="dialog-footer">
            <el-button @click="sendGiftDialog = false">取 消</el-button>
            <el-button type="primary" @click="sendGift()">确 定</el-button>
          </span>
        </el-dialog>
        <el-dialog title="提示" :visible.sync="payChapterDialog" width="30%">
          <span>确定要花10个阅读币买下这章吗？</span>
          <span slot="footer" class="dialog-footer">
            <el-button @click="payChapterDialog = false">取 消</el-button>
            <el-button type="primary" @click="payChapter()">确 定</el-button>
          </span>
        </el-dialog>
      </div>
    </div>
  </template>
  
  <script>
  export default {
    inject: ["reload"],
    name: "bookInfoHome",
    data() {
      return {
        sendGiftDialog: false,
        bookInfo: {},
        bookIsEnd: "",
        labels: [],
        show: false,
        text: "",
        activeName: "first",
        inputBiscuss: "",
        inputBiscussLen: 0,
        textarea: false,
        inputTextareaLen: 0,
        inputTextarea: "",
        isMyBook: false,
        chapterBook: [
          {
            id: "",
            chapterBookId: "",
            chapterName: "",
            vip: false
          }
        ],
        newChapter: {
          chapterBookId: "",
          chapterName: ""
        },
        bookId: "",
        chapterDivNum: 0,
        giftName: "",
        giftNum: 0,
        isChapter: true,
        payChapterDialog: false,
        payChapterId: "",
        flag: false,
        evaluateData: []
      };
    },
    created() {
      this.bookId = this.$route.query.id;
      this.getBookById(this.$route.query.id);
      this.getLabelByBookId(this.$route.query.id);
      this.getChapterByBookId(this.$route.query.id);
      this.selectByBookId(this.$route.query.id);
      this.flag = this.$store.state.username != null ? true : false;
      if (this.flag) {
        this.util
          .request("/public/loadUserBookByUidBookid", {
            uid: localStorage.getItem("uid"),
            bookid: this.bookId
          })
          .then(res => {
            this.isMyBook = res.data;
          });
      }
    },
    methods: {
      noLogin() {
        this.$message({
          message: "还没有登录哦,请先登录",
          type: "warning"
        });
      },
      insertEvaluate() {
        if (this.flag) {
          let data = {
            bookId: this.$route.query.id,
            userId: localStorage.getItem("uid"),
            title: this.inputBiscuss,
            content: this.inputTextarea
          };
          this.util.request("/public/insertEvaluate", data).then(res => {
            this.reload();
          });
        } else {
          this.noLogin();
        }
      },
      selectByBookId(bookId) {
        let data = {
          bookId: bookId
        };
        this.util.request("/public/selectByBookId", data).then(res => {
          this.evaluateData = res.data;
        });
      },
      payChapter() {
        let data = {
          bookId: this.$route.query.id,
          userId: localStorage.getItem("uid"),
          chapterId: this.payChapterId
        };
        this.util.request("/public/insertPayChapter", data).then(res => {
          this.payChapterDialog = false;
          if (res.data == 200) {
            this.$message({
              type: "success",
              message: "购买成功!"
            });
          } else {
            this.$message.error("余额不足，请充值。");
          }
        });
      },
      isChapterPay(chapterId, bookChapterId) {
        if (this.flag) {
          this.payChapterId = chapterId;
          let data = {
            chapterId: chapterId,
            userId: localStorage.getItem("uid")
          };
          this.util.request("/public/selectPayChapter", data).then(res => {
            if (res.data) {
              this.goToLookBook(this.bookId, bookChapterId);
            } else {
              this.payChapterDialog = true;
            }
          });
        } else {
          this.noLogin();
        }
      },
      addToMyBook() {
        if (this.flag) {
          this.util
            .request("/public/insertUserBook", {
              uid: localStorage.getItem("uid"),
              bookid: this.bookId
            })
            .then(res => {
              this.isMyBook = true;
              this.$message({
                message: "恭喜你，加入成功",
                type: "success"
              });
            });
        } else {
          this.noLogin();
        }
      },
      openSendGift(number, giftName) {
        if (this.flag) {
          this.giftNum = number;
          this.giftName = giftName;
          this.sendGiftDialog = true;
        } else {
          this.noLogin();
        }
      },
      sendGift() {
        this.sendGiftDialog = false;
        let reward = {
          bookId: this.$route.query.id,
          userId: localStorage.getItem("uid"),
          giftCount: this.giftNum,
          giftName: this.giftName
        };
        this.util.request("/public/insertReward", reward).then(res => {
          if (res.data == 200) {
            this.$message({
              type: "success",
              message: "打赏成功!"
            });
          } else {
            this.$message.error("余额不足，请充值。");
          }
        });
      },
      getBookById(bookId) {
        let data = {
          id: bookId
        };
        this.util.request("/public/loadBookById", data).then(res => {
          this.bookInfo = res.data;
          this.text = res.data.bookIntroduction.replace(/\n/g, "<br>");
        });
      },
      getLabelByBookId(bookId) {
        let data = {
          id: bookId
        };
        this.util.request("/public/getLabelByBookId", data).then(res => {
          this.labels = res.data;
        });
      },
      searchInput() {
        this.inputBiscussLen = this.inputBiscuss.length;
      },
      searchTextarea() {
        this.inputTextareaLen = this.inputTextarea.length;
      },
      getChapterByBookId(id) {
        let data = {
          bookId: id
        };
        this.util.request("/public/getChapterByBookId", data).then(res => {
          if (res.data.length > 0) {
            this.chapterBook = res.data;
            this.newChapter = this.chapterBook[this.chapterBook.length - 1];
            console.log(this.chapterBook);
            if (this.chapterBook.length % 3 == 0) {
              this.chapterDivNum = parseInt(this.chapterBook.length / 3);
            } else {
              this.chapterDivNum = parseInt(this.chapterBook.length / 3) + 1;
            }
          } else {
            this.chapterBook = [
              {
                id: 0,
                chapterBookId: 0,
                chapterName: "还没有章节哦",
                vip: false
              }
            ];
            this.newChapter = this.chapterBook[0];
            this.isChapter = false;
          }
        });
      },
      goToLookBook(bookId, chapterId) {
        this.$router.push({
          path: "/lookBookChapter",
          query: {
            isStart: this.chapterBook.length,
            bookId: bookId,
            chapterId: chapterId
          }
        });
      }
    }
  };
  </script>
  
  <style scoped>
  body {
    width: 100%;
    height: 100%;
    background-color: #fff8e1;
  }
  .page-home {
    display: flex;
    flex-direction: column;
    width: 70%;
    height: 100%;
  }
  .book-info-home {
    display: flex;
    flex-direction: column;
    align-items: center;
    width: 100%;
    height: 100%;
  }
  .background-class {
    width: 100%;
    height: 100%;
    background-color: #fff;
    padding: 15px;
    border-radius: 10px;
  }
  h1 {
    font: 700 28px/38px PingFangSC-Regular, HelveticaNeue-Light,
      "Helvetica Neue Light", "Microsoft YaHei", sans-serif;
    overflow: hidden;
    height: 38px;
    margin-bottom: 8px;
  }
  h1 span {
    font: 14px/38px PingFangSC-Regular, "-apple-system", Simsun;
    margin-left: 3px;
  }
  .book-img {
    height: 240px;
    width: 180px;
    box-shadow: 0 1px 6px rgba(0, 0, 0, 0.3), 0 0 5px #f9f2e9 inset;
  }
  .book-info {
    display: flex;
    justify-content: space-between;
    width: 100%;
  }
  .book-info-easy {
    width: 77%;
    text-align: left;
  }
  .is-end {
    font: 12px/18px PingFangSC-Regular, "-apple-system", Simsun;
    display: inline-block;
    height: 18px;
    margin-right: 6px;
    padding: 0 4px;
    border-radius: 2px;
  }
  .is-end-color {
    color: #e6a23c;
    border: 1px solid #e6a23c;
  }
  .label-color {
    color: #f01742;
    border: 1px solid #f01742;
  }
  .book-type-div {
    display: flex;
    align-items: center;
  }
  .book-click-word {
    font: 18px/20px Arial;
    margin-top: -2px;
    margin-right: 5px;
    color: #1a1a1a;
  }
  .book-click {
    display: flex;
    margin-top: 15px;
    margin-bottom: 15px;
  }
  
  .normal-expand-enter-active,
  .normal-expand-leave-active {
    transition: all 1s ease;
    height: 368px !important;
  }
  .normal-expand-enter,
  .normal-expand-leave-to {
    height: 0px !important;
  }
  .text-overflow {
    overflow: hidden;
    -webkit-line-clamp: 3;
    text-overflow: ellipsis;
    display: -webkit-box;
    -webkit-box-orient: vertical;
  }
  .book-introduction {
    font: 14px/24px PingFangSC-Regular, "-apple-system", Simsun;
  }
  .el-button.is-round {
    padding: 10px 33px;
  }
  .chapter-num {
    font: 14px/48px PingFangSC-Regular, "-apple-system", Simsun;
    float: left;
    padding-left: 30px;
    color: #2972cc;
  }
  >>> .el-tabs__item {
    font: 22px/26px FZZCYSK;
  }
  >>> .el-tabs__item:hover {
    color: #e6a23c;
  }
  >>> .el-tabs__item.is-active {
    color: #e6a23c;
  }
  >>> .el-tabs__active-bar {
    background-color: #e6a23c;
  }
  .specific-info {
    width: 100%;
    padding: 15px;
  }
  .work-info-reader {
    width: 100%;
    height: 100%;
    background-color: #fff;
    padding: 15px;
    border-radius: 10px;
  }
  .writer-info-reader {
    width: 100%;
    background-color: #fff;
    padding: 15px;
    border-radius: 10px;
  }
  .work-discuss-reader {
    width: 100%;
    height: 100%;
    background-color: #fff;
    padding: 15px;
    border-radius: 10px;
    margin-top: 20px;
  }
  .work-info-reader-content {
    width: 100%;
    font-size: 18px;
    border-bottom: 1px solid #e6e6e6;
    color: #e6a23c;
    text-align: left;
    margin-top: 20px;
  }
  .work-info-reader-title {
    width: 100%;
    font-size: 23px;
    font-weight: bold;
    border-bottom: 1px solid #e6e6e6;
    text-align: left;
  }
  .work-info-reader-gift {
    display: flex;
    justify-content: space-around;
  }
  .money {
    font: 14px/1 PingFangSC-Regular, "-apple-system", Simsun;
    margin-top: 0px;
    margin-bottom: 10px;
    color: #ddce8e;
  }
  .gift-name {
    margin-top: 0px;
    font: 12px/1 PingFangSC-Regular, "-apple-system", Simsun;
    color: #444;
  }
  .gift-info {
    cursor: pointer;
    width: 100px;
    padding: 10px 0 10px 0;
  }
  .gift-info:hover {
    box-shadow: 0 0 5px #e6e6e6;
    background-color: #fff8e1;
  }
  .gift-info:hover img {
    transform: translate(0, -6px);
  }
  .gift {
    display: flex;
    align-items: center;
    height: 40px;
  }
  .gift h4 {
    font-family: PingFangSC-Regular, HelveticaNeue-Light, "Helvetica Neue Light",
      "Microsoft YaHei", sans-serif;
    font-size: 18px;
    margin-right: 4px;
    color: #f01742;
  }
  .gift span {
    font-family: PingFangSC-Regular, "-apple-system", Simsun;
    font-size: 13px;
    margin: 8px 4px 0 0;
    color: #a6a6a6;
  }
  >>> .el-input__inner {
    border-width: 1px;
    border-color: #bdbdbd;
    height: 34px;
    border-radius: 0;
  }
  .reader-biscuss {
    display: flex;
    justify-content: space-around;
    margin-top: 15px;
  }
  >>> .el-input {
    width: 100%;
    cursor: pointer;
  }
  .more-input {
    width: 85%;
    display: flex;
    flex-direction: column;
  }
  >>> .el-textarea {
    width: 100%;
    margin-top: 20px;
  }
  .textarea-word {
    font-size: 12px;
    color: #9e9e9e;
    line-height: 34px;
    text-align: end;
  }
  .biscuss-button {
    display: flex;
    justify-content: flex-end;
    margin-top: 10px;
    width: 96%;
  }
  .work-info {
    width: 70%;
    display: flex;
    flex-direction: column;
  }
  .writer-info {
    width: 20%;
  }
  .book-chapter-info {
    width: 96%;
    height: 100%;
    background-color: #fff;
    padding: 15px;
    border-radius: 10px;
  }
  .book-chapter-info-title {
    width: 100%;
    font-size: 18px;
    font-weight: bold;
    border-bottom: 1px solid #e6e6e6;
    text-align: left;
  }
  .chapter-name {
    overflow: hidden;
    width: 240px;
    white-space: nowrap;
    text-overflow: ellipsis;
    color: #262626;
    text-align: left;
    cursor: pointer;
  }
  .chapter-for-div {
    display: flex;
    justify-content: space-between;
    padding: 10px;
    border-bottom: 1px solid #e6e6e6;
  }
  .el-tab-pane {
    display: flex;
    justify-content: space-around;
  }
  .chapter-name :hover {
    color: #e6a23c;
  }
  .eva-info {
    display: flex;
    justify-content: space-around;
    padding: 10px;
    border-bottom: 1px dashed #e6e6e6;
    margin-top: 15px;
  }
  .eva-info-div {
    width: 75%;
    display: flex;
    flex-direction: column;
    align-items: flex-start;
  }
  .eva-info-div div {
    display: flex;
    width: 80%;
    justify-content: space-between;
    align-items: center;
    font-size: 14px;
    color: #e6a23c;
    font-weight: bold;
  }
  </style>
  
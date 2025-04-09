<template>
  <div style="width: 100%">
    <!-- 搜索框 -->
    <div style="margin-bottom: 20px" class="sear">
      <el-input
        placeholder="书籍名称"
        class="el_input"
        v-model="params.name"
      ></el-input>
      <el-input
        placeholder="类型"
        class="el_input"
        v-model="params.type"
      ></el-input>
      <el-input
        placeholder="作家"
        class="el_input"
        v-model="params.author"
      ></el-input>
      <el-button type="primary" class="el-icon-search" @click="search"
        >搜索</el-button
      >
      <el-button type="primary" class="el-icon-refresh" @click="reset"
        >重置</el-button
      >

      <!-- 添加暑假 -->
      <el-button
        type="primary"
        @click="
          addDialogFormVisible = true;
          clear();
        "
        class="el-icon-circle-plus-outline"
        style="height: 30px width: 100px"
        >添加书籍</el-button
      >
      <el-dialog title="上传书籍" :visible.sync="addDialogFormVisible" :append-to-body="true">
        <el-form :model="form" :rules="rules" ref="ruleForm">
          <el-form-item label="书籍名称" :label-width="formLabelWidth" prop="name">
            <el-input v-model="form.name" autocomplete="off"></el-input>
          </el-form-item>
          <el-form-item label="作家" :label-width="formLabelWidth" prop="age">
            <el-input v-model="form.author" autocomplete="off"></el-input>
          </el-form-item>
          <el-form-item label="简介" :label-width="formLabelWidth" prop="phoneNumber">
            <el-input v-model="form.introduction" autocomplete="off"></el-input>
          </el-form-item>
          <el-form-item label="类型" :label-width="formLabelWidth">
            <el-input v-model="form.type" autocomplete="off"></el-input>
          </el-form-item>
          <el-form-item label="封面" :label-width="formLabelWidth">
            <!-- <el-input v-model="form.imgUrl" autocomplete="off"></el-input> -->
            <!-- 上传文件 -->
            <el-upload
              class="avatar-uploader"
              action="http://localhost:9099/api/file/upload"
              :show-file-list="false"
              :on-success="handleAvatarSuccess"
              :moral="false"
              >
              <img v-if="form.imgUrl" :src="form.imgUrl" class="avatar">
              <i v-else class="el-icon-plus avatar-uploader-icon"></i>
            </el-upload>
          </el-form-item>
        </el-form>
        <div slot="footer" class="dialog-footer">
          <el-button @click="addDialogFormVisible = false">取 消</el-button>
          <el-button
            type="primary"
            @click="
              addDialogFormVisible = false;
              addBook('ruleForm');
            "
            >确 定</el-button
          >
        </div>
      </el-dialog>
    </div>

    <!-- eslint-disable-next-line -->
    <el-table :data="book_info" stripe>
      <el-table-column prop="id" label="编号"></el-table-column>
      <el-table-column  prop="imgUrl" label="书籍封面">
        <template v-slot="scope">
          <el-image :src="'https://images.weserv.nl/?url=' + scope.row.imgUrl" :preview-src-list="[scope.row.imgUrl]" style="width:60px;"></el-image>
        </template>
      </el-table-column>
      <el-table-column prop="name" label="书籍名称"></el-table-column>
      <el-table-column prop="author" label="作家"></el-table-column>
      <el-table-column prop="introduction" label="简介"></el-table-column>
      <el-table-column prop="type" label="类型"></el-table-column>
      <el-table-column prop="createDate" label="创建时间"></el-table-column>
      <el-table-column prop="updateTime" label="更新时间"></el-table-column>
      <el-table-column  label="禁用">
          <template v-slot="scope">
            <el-switch
              v-model="scope.row.status"
              @change="enable(scope.row)"
              active-color="#13ce66"
              inactive-color="#ff4949">
            </el-switch>
          </template>
      </el-table-column>
      <el-table-column width="200px" label="编辑">
        <template v-slot="scope">
          <el-button
            type="primary"
            @click="
              dialogFormVisible = true;
              getInfo(scope.row.id);
            "
            class="el-icon-info"
            style="height: 30px width: 100px;"
            >编辑书籍</el-button
          >
          <el-dialog title="编辑书籍" :visible.sync="dialogFormVisible" width="40%" :append-to-body="true"
>
            <el-form :model="form" :rules="rules" ref="ruleForm">
              <el-form-item
                label="书籍名称"
                :label-width="formLabelWidth"
                prop="name"
              >
                <el-input v-model="form.name" autocomplete="off"></el-input>
              </el-form-item>
              <el-form-item label="作者" :label-width="formLabelWidth" prop="age">
                <el-input v-model="form.author" autocomplete="off"></el-input>
              </el-form-item>
              <el-form-item label="简介" :label-width="formLabelWidth" prop="phoneNumber">
                <el-input
                  v-model="form.introduction"
                  autocomplete="off"
                ></el-input>
              </el-form-item>
              <el-form-item label="类型" :label-width="formLabelWidth">
                <el-input v-model="form.type" autocomplete="off"></el-input>
              </el-form-item>
              <el-form-item label="封面" :label-width="formLabelWidth">
                <el-input v-model="form.imgUrl" autocomplete="off"></el-input>
              </el-form-item>
            </el-form>
            <div slot="footer" class="dialog-footer">
              <el-button @click="dialogFormVisible = false">取 消</el-button>
              <el-button
                type="primary"
                @click="
                  dialogFormVisible = false;
                  updateInfo();
                "
                >确 定</el-button
              >
            </div>
          </el-dialog>
          
          <el-popconfirm
            title="确定删除该书籍吗？"
            @confirm="del(scope.row.id)"
            style="margin-left: 5px"
          >
            <el-button type="danger" slot="reference">删除</el-button>
          </el-popconfirm>
        </template>
      </el-table-column>
    </el-table>

    <!-- 分页上下查找  -->
    <el-pagination
      style="margin-top: 20px"
      :background="true"
      :current-page="params.pageNumber"
      :page-size="params.pageSize"
      @current-change="changePage"
      layout="prev, pager, next"
      :total="length"
    >
    </el-pagination>
  </div>
</template>


<script>
import Cookie from "js-cookie"
export default {
    name: "Book",
    data() {
        return {
            user: Cookie.get("user") ? JSON.parse(Cookie.get("user")) : {},
            book_info: [],
            length: 0,
            // 搜索表单信息
            params: {
                name: "",
                type: "",
                author: "",
                pageNumber: 1,
                pageSize: 4,
            },
            formLabelWidth: "120px",
            dialogTableVisible: false,
            dialogFormVisible: false,
            addDialogTableVisible: false,
            addDialogFormVisible: false,
            dialogUpdatePass: false,
            form: {
                name: "",
                author: "",
                introduction: "",
                type: "",
                imgUrl:"",
                status: ""
            },
            newForm: {},
            newRules: {
                newPasswd: [
                    { required: true, message: '请输入密码', trigger: 'blur' },
                    { min: 3, max: 10, message: "长度在 3 到 10 个字符", trigger: "blur" }
                ],
            },
            formLabelWidth: "120px",
            id: "",
            value: true,
            rules: {
                name: [
                    { required: true, message: "请输入书籍名称", trigger: "blur" },
                    { min: 1, max: 10, message: "长度在 1 到 100个字符", trigger: "blur" },
                ]
            },
        };
    },
    created() {
        this.load();
    },
    methods: {
      // 文件上传处理
      handleAvatarSuccess(res) {
        console.log(res)
        if(res.code == "200") {
          console.log("img11: " + res.data)
          this.form.imgUrl = res.data
          console.log("img22: " + this.form.imgUrl)
          this.$forceUpdate()
        }
        else {
          this.$message.error("上传失败")
        }
      },
        parseScope(row) {
            this.newForm = JSON.parse(JSON.stringify(row));
        },
        load() {
            this.$http.get("/book/page", { params: this.params }).then((res) => {
                this.book_info = res.data.data.list;
                console.log("img: " + this.book_info[0].imgUrl)
                this.length = res.data.data.total;
            });
        },
        search() {
            this.load();
        },
        reset() {
            this.params = {
                name: "",
                age: "",
                phoneNumber: "",
                address: "",
                sex: "",
                pageNumber: 1,
                pageSize: 10,
            };
            this.load();
        },
        changePage(pageNumber) {
            this.params.pageNumber = pageNumber;
            this.load();
        },
        clear() {
            this.form = {};
            this.newForm = {};
        },
        addBook(formName) {
            this.$refs[formName].validate((valid) => {
                if (valid) {
                    this.$http.post("/book/addBook", this.form).then((res) => {
                        if (res.data.code === "200") {
                            this.$message.success("添加书籍成功");
                            this.load();
                        }
                        else {
                            this.$message.error("添加失败");
                        }
                    });
                }
                else {
                    this.$message.error("添加内容不符合要求");
                }
            });
        },
        // 删除书籍
        del(id) {
            this.$http.delete("/book/del/" + id).then((res) => {
                if (res.data.code === "200") {
                    this.$message.success("删除用户成功");
                    this.load();
                }
                else {
                    this.$message.error("删除用户失败");
                }
            });
        },
        // 获取书籍
        getInfo(id) {
            this.id = id;
            this.$http.get("/book/getInfo/" + id).then((res) => {
                this.form = res.data.data;
            });
        },
        // 修改书籍信息
        updateInfo() {
            this.form.id = this.id;
            this.$http.put("/book/updateInfo", this.form).then((res) => {
                if (res.data.code === "200") {
                    this.$message.success("修改用户成功");
                    this.load();
                }
                else {
                    this.$message.error("修改失败");
                }
            });
        },
        // 书籍状态
        enable(row) {
            this.$http.put("/book/updateInfo", row).then((res) => {
                if (res.data.code === "200") {
                    this.$message.success("修改状态成功");
                    this.load();
                }
                else {
                    this.$message.error("修改状态失败");
                }
            });
        }
    },
};
</script>

<style scoped>
div .el-input {
  width: 10em;
  margin-right: 3px;
}
/deep/ .el-input__inner {
  height: 30px;
}
/deep/ .sear .el-button {
  height: 30px;
  font-size: 10px;
  padding: 0 5px;
}
/deep/ div.cell {
  width: 274px;
  padding: 2px !important;
}
/deep/ .el-button {
  height: 20px;
  font-size: 10px;
  padding: 0 5px;
}

.avatar-uploader .el-upload {
    border: 1px dashed #d9d9d9;
    border-radius: 6px;
    cursor: pointer;
    position: relative;
    overflow: hidden;
  }
  .avatar-uploader .el-upload:hover {
    border-color: #409EFF;
  }
  .avatar-uploader-icon {
    font-size: 28px;
    color: #8c939d;
    width: 178px;
    height: 178px;
    line-height: 178px;
    text-align: center;
  }
  .avatar {
    width: 178px;
    height: 178px;
    display: block;
  }

</style>
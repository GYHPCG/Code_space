<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-25 14:54:12
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-24 18:40:04
-->
<template>
    <div style="width: 100%">
      <!-- 搜索框 -->
      <div style="margin-bottom: 20px" class="sear">
        <el-input
          placeholder="输入笔名"
          class="el_input"
          v-model="params.penName"
        ></el-input>
        <el-input
          placeholder="输入作家姓名"
          class="el_input"
          v-model="params.name"
        ></el-input>
        <el-input
          placeholder="联系方式"
          class="el_input"
          v-model="params.phone"
        ></el-input>
        <el-input
          placeholder="地址"
          class="el_input"
          v-model="params.address"
        ></el-input>
        <el-button type="primary" class="el-icon-search" @click="search"
          >搜索</el-button
        >
        <el-button type="primary" class="el-icon-refresh" @click="reset"
          >重置</el-button
        >
  
        <!-- 添加用户 -->
        <el-button
          type="primary"
          @click="
            addDialogFormVisible = true;
            clear();
          "
          class="el-icon-circle-plus-outline"
          style="height: 30px width: 100px"
          >添加作家</el-button
        >
        <el-dialog title="添加作家" :visible.sync="addDialogFormVisible" :append-to-body="true">
          <el-form :model="form" :rules="rules" ref="ruleForm">
            <el-form-item label="笔名" :label-width="formLabelWidth">
              <el-input v-model="form.penName" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item label="姓名" :label-width="formLabelWidth" prop="name">
              <el-input v-model="form.name" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item label="联系方式" :label-width="formLabelWidth" prop="phone">
              <el-input v-model="form.phone" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item label="作家简介" :label-width="formLabelWidth">
                <el-input v-model="form.introduce" autocomplete="off"></el-input>
            </el-form-item>
            <el-form-item
              label="地址"
              :label-width="formLabelWidth"
              prop="address"
            >
              <el-input v-model="form.address" autocomplete="off"></el-input>
            </el-form-item>
          </el-form>
          <div slot="footer" class="dialog-footer">
            <el-button @click="addDialogFormVisible = false">取 消</el-button>
            <el-button
              type="primary"
              @click="
                addDialogFormVisible = false;
                addAuthor('ruleForm');
              "
              >确 定</el-button
            >
          </div>
        </el-dialog>
      </div>
  
      <!-- eslint-disable-next-line -->
      <el-table :data="person_info" stripe>
        <!-- <el-table-column prop="id" label="编号"></el-table-column> -->
        <el-table-column prop="penName" label="笔名"></el-table-column>
        <el-table-column prop="name" label="姓名"></el-table-column>
        <el-table-column prop="phone" label="电话"></el-table-column>
        <el-table-column prop="address" label="地址"></el-table-column>
        <el-table-column prop="introduce" label="大神介绍"></el-table-column>
        <el-table-column prop="joinTime" label="入站时间"></el-table-column>
        <el-table-column  label="作家审核状态">
          <template v-slot="scope">
              <el-switch
                v-model="scope.row.status"
                @change="enable(scope.row)"
                active-color="#13ce66"
                inactive-color="#ff4949">
              </el-switch>
            </template>
        </el-table-column>
        <el-table-column  label="编辑" width="200px">
          <template v-slot="scope">
            <el-button
              type="primary"
              @click="
                dialogFormVisible = true;
                getInfo(scope.row.id);
              "
              class="el-icon-info"
              style="height: 30px width: 100px;"
              >编辑</el-button
            >
            <el-dialog title="修改作家信息" :visible.sync="dialogFormVisible" width="40%" :append-to-body="true">
              <el-form :model="form" :rules="rules" ref="ruleForm">
                <el-form-item
                  label="笔名"
                  :label-width="formLabelWidth"
                  prop="penName"
                >
                  <el-input v-model="form.penName" autocomplete="off"></el-input>
                </el-form-item>
                <el-form-item label="姓名" :label-width="formLabelWidth" prop="age">
                  <el-input v-model="form.name" autocomplete="off"></el-input>
                </el-form-item>
                <el-form-item label="联系方式" :label-width="formLabelWidth" prop="phone">
                  <el-input
                    v-model="form.phone"
                    autocomplete="off"
                  ></el-input>
                </el-form-item>
                <el-form-item label="作家简介" :label-width="formLabelWidth">
                    <el-input
                    v-model="form.introduce"
                    autocomplete="off"
                  ></el-input>
                </el-form-item>
                <el-form-item label="地址" :label-width="formLabelWidth">
                  <el-input v-model="form.address" autocomplete="off"></el-input>
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
  
            <el-button
              type="primary"
              @click="
                dialogUpdatePass = true;
                clear();
                parseScope(scope.row)
              "
              class="el-icon-info"
              style="height: 30px width: 100px; margin-left: 2px"
              >重置密码</el-button
            >
              <el-dialog title="重置密码" :visible.sync="dialogUpdatePass" width="30%" :append-to-body="true">
              <el-form :model="newForm" :rules="newRules" ref="newFormRef">
                <el-form-item label="新密码" :label-width="formLabelWidth" prop="newPasswd">
                  <el-input
                    v-model="newForm.newPasswd" show-password
                    @keyup.native.enter="updatePasswd"
                  ></el-input>
                </el-form-item>
              </el-form>
              <div slot="footer" class="dialog-footer">
                <el-button @click="dialogUpdatePass= false">取 消</el-button>
                <el-button
                  type="primary"
                  @click="
                   updatePasswd();
                   dialogUpdatePass = false
                  "
                  >确 定</el-button
                >
              </div>
            </el-dialog>
            
            <el-popconfirm
              title="确定删除该用户吗？"
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
  export default {
    name: "AuthorManager",
    data() {
      //验证年龄
      var checkAge = (rule, value, callback) => {
          setTimeout(() => {
            if (!/^[0-9]+$/.test(value)) {
              callback(new Error('请输入数字值'));
            } else {
              if (parseInt(value) <= 0 || parseInt(value) >= 140) {
                callback(new Error('输入的年龄不合理，请重新输入'));
              } else {
                callback();
              }
            }
          }, 1000);
      };
      //验证手机号码
      var checkPhone = (rule, value, callback) => {
          setTimeout(() => {
            if (!/^(13[0-9]|14[01456879]|15[0-35-9]|16[2567]|17[0-8]|18[0-9]|19[0-35-9])\d{8}$/
  .test(value)) {
              callback(new Error('输入的手机号码不符合要求，请重新输入'));
            } else {
                callback();  
            }
          }, 1000);
      };
      return {
        person_info: [],
        length: 0,
        params: {
          penName: "",
          name: "",
          phone: "",
          address: "",
          pageNumber: 1,
          pageSize: 10,
        },
        dialogTableVisible: false,
        dialogFormVisible: false,
        addDialogTableVisible: false,
        addDialogFormVisible: false,
        dialogUpdatePass : false,
        formLabelWidth: "120px",
        form: {
          penName: "",
          name: "",
          phone: "",
          address: "",
          introduce: "",
          status:""
        },
        newForm: {
  
        },
        id: "",
        newRules: {
           newPasswd: [
              { required: true, message: '请输入密码', trigger: 'blur' },
              { min: 3, max: 10, message: "长度在 3 到 10 个字符", trigger: "blur" }
            ],
         },
        rules: {
          name: [
            { required: true, message: "请输入姓名", trigger: "blur" },
            { min: 1, max: 10, message: "长度在 1 到 10 个字符", trigger: "blur" },
          ],
          address: [
            { required: true, message: "请选择活动区域", trigger: "change" },
          ],
          age: [
              { validator: checkAge, trigger: 'blur' }
            ],
          phone: [
            { validator: checkPhone, trigger: 'blur' }
          ]
        },
      };
    },
    created() {
      this.load();
    },
    methods: {
      parseScope(row) {
         this.newForm = JSON.parse(JSON.stringify(row))
      },
      load() {
        this.$http.get("/author/page", { params: this.params }).then((res) => {
          this.person_info = res.data.data.list;
          this.length = res.data.data.total;
          console.log(res);
        });
      },
      search() {
        this.load();
      },
      reset() {
        this.params = {
          penName: "",
          name: "",
          phone: "",
          address: "",
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
      },
      addAuthor(formName) {
        this.$refs[formName].validate((valid) => {
          if (valid) {
            this.$http.post("/author/addAuthor", this.form).then((res) => {
              if (res.data.code === "200") {
                this.$message.success("添加用户成功");
                this.load()
              } else {
                this.$message.error("添加失败");
              }
            })
          }
          else {
            this.$message.error("添加内容不符合要求");
          }
        })
      },
  
      // 删除用户, 路径错误
      del(id) {
        this.$http.delete("/author/del/" + id).then((res) => {
          if (res.data.code === "200") {
            this.$message.success("删除作家成功");
            this.load();
          } else {
            this.$message.error("删除作家失败");
          }
        });
      },
      // 获取用户
      getInfo(id) {
        console.log(id);
        this.id = id;
        this.$http.get("/author/getInfo/" + id).then((res) => {
          this.form = res.data.data;
        });
      },
      // 修改用户信息
      updateInfo() {
        this.form.id = this.id;
        this.$http.put("/author/updateInfo", this.form).then((res) => {
          if (res.data.code === "200") {
            this.$message.success("修改作家信息成功");
            this.load();
          } else {
            this.$message.error("修改失败");
          }
        });
      },
      enable(row) {
        this.$http.put("/author/updateInfo", row).then((res) => {
          if (res.data.code === "200") {
            this.$message.success("审核成功");
            this.load();
          } else {
            this.$message.error("审核失败");
          }
        });
      },
      updatePasswd() {
        this.$refs['newFormRef'].validate((valid) => {
          if (valid) {
            // 验证通过
            this.$http.put('/author/updatePasswd', this.newForm).then(res => {
              if (res.data.code === '200') {
                this.$message.success('修改密码成功')
              } else {
                this.$message.error("修改密码失败")
              }
            })
          }
        })
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
  }
  /deep/ .el-button {
    height: 20px;
    font-size: 10px;
    padding: 0 5px;
  }
  </style> 
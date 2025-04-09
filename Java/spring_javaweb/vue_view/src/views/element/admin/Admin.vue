<!--
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2023-11-25 14:54:12
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2023-12-24 18:40:25
-->
<template>
  <div style="width: 100%">
    <!-- 搜索框 -->
    <div style="margin-bottom: 20px" class="sear">
      <el-input
        placeholder="输入昵称"
        class="el_input"
        v-model="params.name"
      ></el-input>
      <el-input
        placeholder="输入年龄"
        class="el_input"
        v-model="params.age"
      ></el-input>
      <el-input
        placeholder="联系方式"
        class="el_input"
        v-model="params.phoneNumber"
      ></el-input>
      <el-input
        placeholder="邮箱"
        class="el_input"
        v-model="params.email"
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
        >添加用户</el-button
      >
      <el-dialog title="添加用户" :visible.sync="addDialogFormVisible" :append-to-body="true"
>
        <el-form :model="form" :rules="rules" ref="ruleForm">
          <el-form-item label="名称" :label-width="formLabelWidth" prop="name">
            <el-input v-model="form.name" autocomplete="off"></el-input>
          </el-form-item>
          <el-form-item label="年龄" :label-width="formLabelWidth" prop="age">
            <el-input v-model="form.age" autocomplete="off"></el-input>
          </el-form-item>
          <el-form-item label="联系方式" :label-width="formLabelWidth" prop="phoneNumber">
            <el-input v-model="form.phoneNumber" autocomplete="off"></el-input>
          </el-form-item>
          <el-form-item label="性别" :label-width="formLabelWidth">
            <el-radio v-model="form.sex" label="男">男</el-radio>
            <el-radio v-model="form.sex" label="女">女</el-radio>
          </el-form-item>
          <el-form-item
            label="地址"
            :label-width="formLabelWidth"
            prop="address"
          >
            <el-input v-model="form.address" autocomplete="off"></el-input>
          </el-form-item>
          <el-form-item label="邮箱" :label-width="formLabelWidth" prop="email">
            <el-input v-model="form.email" autocomplete="off"></el-input>
          </el-form-item>
        </el-form>
        <div slot="footer" class="dialog-footer">
          <el-button @click="addDialogFormVisible = false">取 消</el-button>
          <el-button
            type="primary"
            @click="
              addDialogFormVisible = false;
              addUser('ruleForm');
            "
            >确 定</el-button
          >
        </div>
      </el-dialog>
    </div>

    <!-- eslint-disable-next-line -->
    <el-table :data="person_info" stripe>
      <!-- <el-table-column prop="id" label="编号"></el-table-column> -->
      <el-table-column prop="name" label="昵称"></el-table-column>
      <el-table-column prop="age" label="年龄"></el-table-column>
      <el-table-column prop="phoneNumber" label="电话"></el-table-column>
      <el-table-column prop="address" label="地址"></el-table-column>
      <el-table-column prop="sex" label="性别"></el-table-column>
      <el-table-column prop="email" label="邮箱"></el-table-column>
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
            >编辑</el-button
          >
          <el-dialog title="修改用户" :visible.sync="dialogFormVisible" width="40%" :append-to-body="true"
>
            <el-form :model="form" :rules="rules" ref="ruleForm">
              <el-form-item
                label="名称"
                :label-width="formLabelWidth"
                prop="name"
              >
                <el-input v-model="form.name" autocomplete="off"></el-input>
              </el-form-item>
              <el-form-item label="年龄" :label-width="formLabelWidth" prop="age">
                <el-input v-model="form.age" autocomplete="off"></el-input>
              </el-form-item>
              <el-form-item label="联系方式" :label-width="formLabelWidth" prop="phoneNumber">
                <el-input
                  v-model="form.phoneNumber"
                  autocomplete="off"
                ></el-input>
              </el-form-item>
              <el-form-item label="性别" :label-width="formLabelWidth">
                <el-radio v-model="form.sex" label="男">男</el-radio>
                <el-radio v-model="form.sex" label="女">女</el-radio>
              </el-form-item>
              <el-form-item label="地址" :label-width="formLabelWidth">
                <el-input v-model="form.address" autocomplete="off"></el-input>
              </el-form-item>
              <el-form-item label="邮箱" :label-width="formLabelWidth">
                <el-input v-model="form.email" autocomplete="off"></el-input>
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
            <el-dialog title="重置密码" :visible.sync="dialogUpdatePass" width="30%" :append-to-body="true"
>
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
  name: "Admin",
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
      user: localStorage.getItem("user")?JSON.parse(localStorage.getItem("user")):{},
      person_info: [],
      length: 0,
      params: {
        name: "",
        age: "",
        phoneNumber: "",
        address: "",
        sex: "",
        email: "",
        pageNumber: 1,
        pageSize: 10,
      },
      dialogTableVisible: false,
      dialogFormVisible: false,
      addDialogTableVisible: false,
      addDialogFormVisible: false,
      dialogUpdatePass: false,
      form: {
        name: "",
        age: 0,
        phoneNumber: "",
        address: "",
        sex: "",
        email: "",
        status: ""
      },
      newForm: {
        //  name: "",
        //  passwd: "",
        //  newPasswd: ""
      },
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
          { required: true, message: "请输入姓名", trigger: "blur" },
          { min: 1, max: 10, message: "长度在 1 到 10 个字符", trigger: "blur" },
        ],
        address: [
          { required: true, message: "请选择活动区域", trigger: "change" },
        ],
        age: [
            { validator: checkAge, trigger: 'blur' }
          ],
        phoneNumber: [
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
      this.$http.get("/admin/page", { params: this.params }).then((res) => {
        this.person_info = res.data.data.list;
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
      this.newForm = {}
    },
    addUser(formName) {
      this.$refs[formName].validate((valid) => {
        if (valid) {
          this.$http.post("/admin/addUser", this.form).then((res) => {
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
      this.$http.delete("/admin/del/" + id).then((res) => {
        if (res.data.code === "200") {
          this.$message.success("删除用户成功");
          this.load();
        } else {
          this.$message.error("删除用户失败");
        }
      });
    },
    // 获取用户
    getInfo(id) {
      this.id = id
      this.$http.get("/admin/getInfo/" + id).then((res) => {
        this.form = res.data.data;
      });
    },
    // 修改用户信息
    updateInfo() {
      this.form.id = this.id;
  
      this.$http.put("/admin/updateInfo", this.form).then((res) => {
        if (res.data.code === "200") {
          this.$message.success("修改用户成功");
          this.load();
        } else {
          this.$message.error("修改失败");
        }
      });
    },
    // 修改用户状态
    enable(row) {
      console.log("enable: "+ row.id)
      this.$http.put("/admin/updateInfo", row).then((res) => {
        if (res.data.code === "200") {
          this.$message.success("修改状态成功");
          this.load();
        } else {
          this.$message.error("修改状态失败");
        }
      });
    },

    updatePasswd() {
      this.$refs['newFormRef'].validate((valid) => {
        if (valid) {
          // 验证通过
          console.log("pp: "+ this.newForm.passwd)
          console.log("pp: "+ this.newForm.newPasswd)
          this.$http.put('/admin/updatePasswd', this.newForm).then(res => {
            if (res.data.code === '200') {
              this.$message.success('修改密码成功')
              if (this.newForm.id === this.user.id) {
                // Cookie.remove("user")
                localStorage.removeItem("user")
                this.$router.push("/login")
              }
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
  padding: 2px !important;
}
/deep/ .el-button {
  height: 20px;
  font-size: 10px;
  padding: 0 5px;
}

</style> 
<%--
  Created by IntelliJ IDEA.
  User: 86183
  Date: 2023/8/22
  Time: 15:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>登录页面</title>
    <style>
        body {
            background-image: url("img/70.png");
            background-repeat: no-repeat;
            background-size: 100% 100%;
            background-attachment: fixed;      /*图片铺满整个页面*/

        }
        .main {
            width: 500px;
            height: 300px;
            box-shadow: 0 5px 20px 0 #e8e8e8;
            background-color: rgba(255,255,255, 0.5);
            border-radius: 10px;
            position: absolute;
            top: 0;
            right: 0;
            bottom: 0;
            left: 0;
            margin: auto;
        }
        .main h2 {
            /*//margin-left: auto;*/
            color: lightseagreen;
            margin-left: 200px;
        }
        .form {
            margin-top: 30px;
            margin-left: 60px;
        }
        .form input {
            width: 300px;
            height: 25px;
            border: 1px solid lightgray;
            outline: none;      /*输入内容时不显示边框*/
            background-color: rgba(255,255,255, 0.7);
        }
        .form .check {
            margin-left: 150px;
            margin-top: 10px;
            width:20px;
            height: 15px;
        }
        .form button {
            width: 150px;
            height: 30px;
            color: white;
            background-color: lightseagreen;
            border-style: none;
            border-radius: 5px;
            font-size: 15px;
            margin-top: 15px;
            margin-left: 130px;
            outline: none;
            cursor: pointer;    /*光标放到上面有小手*/
        }
        .repa {
            margin-left: 8px;
        }
    </style>
</head>
<body>
    <div class="main">
        <h2>欢迎登录</h2>
        <form action="/login" method="post" class="form">
            姓名: <input type="text" class="repa" , name="username"><br>    <!--输入的用户名保存到username变量，传回后端-->
            密码：<input type="password", name="password"> <br>
            学号：<input type="text", name="id"> <br>
            <label>
            <input type="checkbox" value="Remember" name="remember" class="check"> Remember me <br>
            </label>
            <button type="submit">登录</button><br>
        </form>

    </div>
</body>
</html>
<script>
    const ERROR = '<%=request.getParameter("error")%>'
    if (ERROR === "fail") {
        alert("密码或用户名错误！请重新登录。")
    }

</script>

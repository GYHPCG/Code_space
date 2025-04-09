<%--
  Created by IntelliJ IDEA.
  User: 86183
  Date: 7/11/2023
  Time: 15:35
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <form action="/DownLoadServlet" method="post" enctype="multipart/form-data">
        <input type="text" name="username"/><br>
        <input type="file" name="MyImage"/><br>
        <input type="submit" value="上传"/>
    </form>
</body>
</html>

<%--
  Created by IntelliJ IDEA.
  User: 86183
  Date: 15/10/2023
  Time: 22:20
  To change this template use File | Settings | File Templates.
--%>

<%@ page isELIgnored="false" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ include file="header.jsp"%>
<%@ page errorPage="error.jsp" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>>
<%--<jsp:include page="error.jsp"></jsp:include>--%>

<%
int a = 1 /  1;
%>
<html>
<head>
    <title>书籍查询</title>

    <style>
        p {
            color: chocolate;
        }
    </style>
</head>
<body>
<form action="/getBookList" method="get">
    <label>
        书籍名称
        <input type="text" name="bookName"> <br/>
    </label>

    <label>
        作者名
        <input type="text", name="author"> <br/>
    </label>
    <br/>

    <label>
        书籍类型
        <select name="type">
            <option value=""></option>
            <option value="计算机">计算机</option>
            <option value="文学">文学</option>
            <option value="漫画">漫画</option>
            <option value="数学">数学</option>
            <option value="恐怖">恐怖</option>
            <option value="科技">科技</option>
        </select>
    </label>
    <br/>


    <label>
        书籍形容
        <input type="text" name="desc"> <br/>
    </label>
    <br/>

    <label>
        <input type="submit" value="搜索">
    </label>
</form>
<div>
    <c:forEach items="${list}" var="lit">
        <p>
            ${lit.bookName}
        </p>
    </c:forEach>
</div>
</body>
</html>
<%@include file="footer.jsp"%>

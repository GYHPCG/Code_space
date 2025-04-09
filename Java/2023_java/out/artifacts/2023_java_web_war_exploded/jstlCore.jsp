<%@ page import="java.util.ArrayList" %>
<%@ page import="guida.pojo.Person" %><%--
  Created by IntelliJ IDEA.
  User: 86183
  Date: 24/10/2023
  Time: 16:01
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    ArrayList<Person> people = new ArrayList<>();
    people.add(new Person("jack", 23));
    people.add(new Person("kily", 24));
    people.add(new Person("nike", 12));
    people.add(new Person("ppp", 90));
%>
<%--    <th board="1">--%>
<%--        <c:forEach items="people" var="peo">--%>
<%--            <tr><c:out value="姓名： ${peo.getName()} --> 年龄：${peo.getAge()}"></c:out> </tr>--%>
<%--    </th>--%>
<h1>&lt;c:forEach&gt; 实例</h1>
<c:forEach var="i" begin="1" end="5">
    <p><c:out value="${i}"/></p>
</c:forEach>

</body>
</html>

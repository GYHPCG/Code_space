package guida.day05;

import org.apache.commons.dbutils.ResultSetHandler;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class BaseDao {
    // 优化查询
    public static Object query(String sql, ResultSetHandler<?> rsh,
                               Object... params) throws SQLException {
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        try {
            // 获得连接
            conn = JDBCUtil.getConnection();
            // 预编译sql
            pstmt = conn.prepareStatement(sql);
            // 将参数设置进去
            for (int i = 0; params != null && i < params.length; i++) {
                pstmt.setObject(i + 1, params[i]);
            }
            // 发送sql
            rs = pstmt.executeQuery();
            // 让调用者去实现对结果集的处理
            Object obj = rsh.handle(rs);
            return obj;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // 释放资源
            JDBCUtil.close(conn, pstmt, rs);
        }
        return rs;
    }
}

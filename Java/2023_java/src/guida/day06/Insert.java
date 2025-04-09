package guida.day06;

import org.apache.commons.dbutils.QueryRunner;

import java.sql.SQLException;
public class Insert {
    public static void main(String[] args)throws SQLException{
        // 创建QueryRunner对象
        QueryRunner runner = new QueryRunner(C3P0Utils.getDataSource());
        String sql = "insert into user (name,password) values ('jack',123456)";
        int num = runner.update(sql);
        if (num > 0){
            System.out.println("添加成功！");
        }else{
            System.out.println("添加失败！");
        }
    }
}

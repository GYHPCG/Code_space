package com.itheima.mapper;

import org.apache.ibatis.annotations.*;

@Mapper
public interface EmpMapper {
       @Delete("delete from emp where id = #{id}")
       public void delete(Integer id);
}

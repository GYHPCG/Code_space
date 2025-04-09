package week1;

import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.http.HttpHost;
import org.elasticsearch.action.index.IndexRequest;
import org.elasticsearch.action.index.IndexResponse;
import org.elasticsearch.action.update.UpdateRequest;
import org.elasticsearch.action.update.UpdateResponse;
import org.elasticsearch.client.RequestOptions;
import org.elasticsearch.client.RestClient;
import org.elasticsearch.client.RestHighLevelClient;
import org.elasticsearch.common.xcontent.XContentType;
import org.junit.Test;

import java.io.IOException;

public class Junit_test {
    @Test
    public void client() throws IOException {
        RestHighLevelClient client = new RestHighLevelClient(RestClient.builder(
                new HttpHost("localhost", 9200)
        ));
        System.out.println(client);
        client.close();
    }

    @Test
    public void add_doc_User() throws IOException {

          RestHighLevelClient client = new RestHighLevelClient(RestClient.builder(
                new HttpHost("localhost", 9200)
        ));

        //新增文档，增添请求对象
        IndexRequest Request = new IndexRequest();
        // 设置索引及唯一性标识
        Request.index("user3").id("2005");

        // 创建数据对象
        User user = new User();
        user.setName("zhangsan");
        user.setAge(30);
        user.setSex("男");
        ObjectMapper objectMapper = new ObjectMapper();
        String productJson = objectMapper.writeValueAsString(user);
        //System.out.println(productJson);

        // 添加文档数据，数据格式为JSON格式
       Request.source(productJson, XContentType.JSON);

        // 客户端发送请求，获取响应对象
        IndexResponse response = client.index(Request, RequestOptions.DEFAULT);

        ////3.打印结果信息
        System.out.println("_index:" + response.getIndex());
        System.out.println("_id:" + response.getId());
        System.out.println("_result:" + response.getResult());

        // 修改文档 - 请求对象
//        UpdateRequest Request = new UpdateRequest();
//        //设置信息，id等
//        Request.index("user3").id("2005");
//        //设置请求体，对数据进行修改
//        Request.doc(XContentType.JSON, "sex", "女", "age", 45);
//        // 客户端发送请求，获取响应对象
//        UpdateResponse response = client.update(Request, RequestOptions.DEFAULT);
//        System.out.println("_index:" + response.getIndex());
//        System.out.println("_id:" + response.getId());
//        System.out.println("_result:" + response.getResult());
        client.close();
    }


}

package week1;

import org.apache.http.HttpHost;
import org.elasticsearch.action.index.IndexRequest;
import org.elasticsearch.action.index.IndexResponse;
import org.elasticsearch.client.RequestOptions;
import org.elasticsearch.client.RestClient;
import org.elasticsearch.client.RestHighLevelClient;
import org.elasticsearch.client.indices.CreateIndexRequest;
import org.elasticsearch.client.indices.CreateIndexResponse;
import org.elasticsearch.client.indices.GetIndexRequest;
import org.elasticsearch.client.indices.GetIndexResponse;

import java.io.IOException;

public class index_search {
    public static void main(String[] args) throws IOException {
        // 创建客户端对象
        RestHighLevelClient client = new RestHighLevelClient(
                RestClient.builder(new HttpHost("localhost", 9200, "http"))
        );
        // 获取索引 - 请求对象
        GetIndexRequest request = new GetIndexRequest("user3");
        // 发送请求，获取响应
        GetIndexResponse getIndexResponse = client.indices().get(request, RequestOptions.DEFAULT);

        //打印结果

        System.out.println(getIndexResponse.getAliases());
        System.out.println(getIndexResponse.getMappings());
        //System.out.println(getIndexResponse.getSetting());

        // 关闭客户端连接
        client.close();
    }
}

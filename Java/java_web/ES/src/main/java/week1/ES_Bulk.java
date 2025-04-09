package week1;

import org.apache.http.HttpHost;
import org.elasticsearch.action.bulk.BulkRequest;
import org.elasticsearch.action.bulk.BulkResponse;
import org.elasticsearch.action.index.IndexRequest;
import org.elasticsearch.action.update.UpdateRequest;
import org.elasticsearch.client.RequestOptions;
import org.elasticsearch.client.RestClient;
import org.elasticsearch.client.RestHighLevelClient;
import org.elasticsearch.common.xcontent.XContentType;
import org.junit.Test;

import java.io.IOException;

public class ES_Bulk {
    @Test
    public void BulkInsert() throws IOException {
        RestHighLevelClient client = new RestHighLevelClient(RestClient.builder(new HttpHost("localhost", 9200)));

        BulkRequest bulkRequest = new BulkRequest();

        bulkRequest.add(new IndexRequest("stu_new").id("201").source(XContentType.JSON, "name", "wangwu", "age", 18));
        bulkRequest.add(new IndexRequest("stu_new").id("202").source(XContentType.JSON, "name", "wangwu1", "age", 19));
        bulkRequest.add(new IndexRequest("stu_new").id("203").source(XContentType.JSON, "name", "wangwu2", "age", 11));
        bulkRequest.add(new IndexRequest("stu_new").id("204").source(XContentType.JSON, "name", "wangwu3", "age", 13));
        bulkRequest.add(new IndexRequest("stu_new").id("205").source(XContentType.JSON, "name", "wangwu4", "age", 98));

        BulkResponse bulkResponses = client.bulk(bulkRequest, RequestOptions.DEFAULT);

        System.out.println(bulkResponses.getItems());

        client.close();

    }

    @Test
     public void BulkUpdated() throws IOException {
        RestHighLevelClient client = new RestHighLevelClient(RestClient.builder(new HttpHost("localhost", 9200)));

        BulkRequest bulkRequest = new BulkRequest();

//        bulkRequest.add(new IndexRequest("stu_new").id("201").source(XContentType.JSON, "name", "wangwu", "age", 18));
//        bulkRequest.add(new IndexRequest("stu_new").id("202").source(XContentType.JSON, "name", "wangwu1", "age", 19));
//        bulkRequest.add(new IndexRequest("stu_new").id("203").source(XContentType.JSON, "name", "wangwu2", "age", 11));
//        bulkRequest.add(new IndexRequest("stu_new").id("204").source(XContentType.JSON, "name", "wangwu3", "age", 13));
//        bulkRequest.add(new IndexRequest("stu_new").id("205").source(XContentType.JSON, "name", "wangwu4", "age", 98));

        bulkRequest.add(new UpdateRequest("stu_new", "201").doc(XContentType.JSON, "name", "wangwu", "age", 20));
        bulkRequest.add(new UpdateRequest("stu_new", "202").doc(XContentType.JSON, "name", "zhangsan", "age", 78));



        BulkResponse bulkResponses = client.bulk(bulkRequest, RequestOptions.DEFAULT);

        System.out.println(bulkResponses.getItems());

        client.close();
    }
}

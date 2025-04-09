package week2.search;

import org.apache.http.HttpHost;
import org.elasticsearch.action.search.SearchRequest;
import org.elasticsearch.action.search.SearchRequestBuilder;
import org.elasticsearch.action.search.SearchResponse;
import org.elasticsearch.client.RequestOptions;
import org.elasticsearch.client.RestClient;
import org.elasticsearch.client.RestHighLevelClient;
import org.elasticsearch.index.query.QueryBuilders;
import org.elasticsearch.index.query.RangeQueryBuilder;
import org.elasticsearch.search.SearchHit;
import org.elasticsearch.search.builder.SearchSourceBuilder;
import org.junit.Test;

import java.io.IOException;

public class ES_search {
    @Test
    public void SearchMatchAll() throws IOException {
        RestHighLevelClient client = new RestHighLevelClient(RestClient.builder(new HttpHost("localhost", 9200)));
        SearchRequest stu_new = new SearchRequest("stu_new");

        SearchSourceBuilder searchSourceBuilder = new SearchSourceBuilder();
        searchSourceBuilder.query(QueryBuilders.matchAllQuery());

        stu_new.source(searchSourceBuilder);

        SearchResponse search = client.search(stu_new, RequestOptions.DEFAULT);

        System.out.println(search.status());
        System.out.println(search.getTook());
        System.out.println(search.getHits().getTotalHits());

        SearchHit[] hits = search.getHits().getHits();

        for (SearchHit hit : hits) {
            System.out.println(hit);
        }
        client.close();
    }

    @Test
    public void SearchRange() throws IOException {

        RestHighLevelClient client = new RestHighLevelClient(RestClient.builder(new HttpHost("localhost", 9200)));

        SearchRequest searchRequest = new SearchRequest("stu_new");

        SearchSourceBuilder searchSourceBuilder = new SearchSourceBuilder();

        //构建一个查询条件
        RangeQueryBuilder age = QueryBuilders.rangeQuery("age");
        age.lte(50);
        age.gte(19);

        searchSourceBuilder.query(age);

        //查询条件
        searchRequest.source(searchSourceBuilder);

        SearchResponse search = client.search(searchRequest, RequestOptions.DEFAULT);

        SearchHit[] hits = search.getHits().getHits();

        for (SearchHit hit : hits) {
            System.out.println(hit);
        }

        client.close();
    }

    @Test
    public void SearchInclude() throws IOException {
        RestHighLevelClient client = new RestHighLevelClient(RestClient.builder(new HttpHost("localhost", 9200)));

        SearchRequest searchRequest = new SearchRequest("stu_new");

        SearchSourceBuilder query = new SearchSourceBuilder().query(QueryBuilders.matchAllQuery());

        //查询条件
        String[] includes = {"name", "age"};


        // client.search()

        client.close();
    }

    //请求体查询
    @Test
    public void searchIndex() throws IOException {
        RestHighLevelClient client = new RestHighLevelClient(RestClient.builder(new HttpHost("localhost", 9200)));


        client.close();
    }
}

package hive3.udf;

import com.hankcs.hanlp.HanLP;
import com.hankcs.hanlp.seg.common.Term;
import org.apache.hadoop.hive.ql.exec.UDF;
import org.junit.Test;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class WordFrequency extends UDF {

    public Map<String, Integer> evaluate(String text) {

        Map<String, Integer> wordFrequencyMap = new HashMap<>();

        if (text != null) {
            // 分词
            List<Term> termList = HanLP.segment(text);

            // 统计词频
            for (Term term : termList) {
                String word = term.word;
                // 过滤掉标点符号等无关词汇
                if (!word.matches("[\\pP\\p{Punct}\\s]+")) {
                    wordFrequencyMap.put(word, wordFrequencyMap.getOrDefault(word, 0) + 1);
                }
            }
        }

        return wordFrequencyMap;
    }
    @Test
    public void test() {
        String reader = "我们万岁，澎湃系统，14Pro";
        System.out.println(evaluate(reader));
    }
}



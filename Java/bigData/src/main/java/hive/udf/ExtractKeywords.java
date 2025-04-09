package hive.udf;

import org.apache.hadoop.hive.ql.exec.UDF;
import org.apache.hadoop.io.Text;
import org.junit.Test;

public class ExtractKeywords extends UDF {
    public String evaluate(String content, String keywords) {
        if (content == null || keywords == null) {
            return null;
        }

        String contentString = content.toString();

        StringBuilder resultBuilder = new StringBuilder();

            if (contentString.contains(keywords)) {
                resultBuilder.append(contentString).append(" ");
            }

        String result = resultBuilder.toString().trim();

        return (result.isEmpty()) ? null : new String(result);
    }

    @Test
    public void Test() {
        String con = "哈桑贷款的华为大沙发";
        String an = "adasdasdad";
        String res = "";
        res = evaluate(an, "ll");
        System.out.println(res);
    }
}

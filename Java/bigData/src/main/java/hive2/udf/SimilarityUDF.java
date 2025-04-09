package hive2.udf;

import org.apache.hadoop.hive.ql.exec.Description;
import org.apache.hadoop.hive.ql.exec.UDF;
import org.junit.Test;

@Description(
        name = "chinese_similarity",
        value = "_FUNC_(str1, str2) - Calculate Chinese text similarity based on edit distance",
        extended = "Example:\n"
                + "  SELECT chinese_similarity('你好', '你好吗') FROM table"
)
public class SimilarityUDF extends UDF {

    public Double evaluate(String str1, String str2) {
        if (str1 == null || str2 == null) {
            return null;
        }

        String s1 = str1;
        String s2 = str2;


        int distance = calculateLevenshteinDistance(s1, s2);


        double maxLen = Math.max(s1.length(), s2.length());
        if (maxLen == 0.0) {
            return 1.0;  // Both strings are empty, consider them similar
        }

        double similarity = 1.0 - distance / maxLen;
        return similarity;
    }

    private int calculateLevenshteinDistance(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();

        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    @Test
    public void test() {
        String st = "我们";
        String kl = "他们";
        Double evaluate = evaluate(st, kl);
        System.out.println(evaluate);
    }
}

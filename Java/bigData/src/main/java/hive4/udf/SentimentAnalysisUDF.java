//package hive4.udf;
//
//import org.apache.hadoop.hive.ql.exec.Description;
//import org.apache.hadoop.hive.ql.exec.UDF;
//import org.junit.Test;
//
//@Description(
//        name = "SentimentAnalysis",
//        value = "_FUNC_(text) - Perform sentiment analysis on the input text",
//        extended = "Example:\n"
//                + "  SELECT SentimentAnalysis(text) FROM your_table"
//)
//public class SentimentAnalysisUDF extends UDF {
//    public int evaluate(String text) {
//        if (text == null || text.trim().isEmpty()) {
//            return 0; // or handle accordingly
//        }
//
//        SentimentResult sentimentResult = SentimentAnalyzer.analyze(text);
//
//        // 根据积极和消极概率判断情感分类
//        double positiveProb = sentimentResult.positive;
//        double negativeProb = sentimentResult.negative;
//
//        // 返回情感分类，你可以根据具体的情感概率设置阈值
//        if (positiveProb > negativeProb) {
//            return 1; // Positive
//        } else if (negativeProb > positiveProb) {
//            return -1; // Negative
//        } else {
//            return 0; // Neutral
//        }
//     }
//     @Test
//    public void test() {
//         String kk = "完美";
//         int evaluate = evaluate(kk);
//         System.out.println(evaluate);
//     }
//}

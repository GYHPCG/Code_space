//package hive.udf;
//
//import org.ansj.splitWord.analysis.ToAnalysis;
//import org.junit.Test;
//
//import java.io.IOException;
//import java.util.*;
//
//public class WordCountAnalysis {
//
//    public static void wordFrequency() throws IOException {
//        Map<String, Integer> map = new HashMap<>();
//
//        String article = getString();
//        String result = ToAnalysis.parse(article).toStringWithOutNature();
//        String[] words = result.split(",");
//
//
//        for(String word: words){
//            String str = word.trim();
//            // 过滤空白字符
//            if (str.equals(""))
//                continue;
//                // 过滤一些高频率的符号
//            else if(str.matches("[）|（|.|，|。|+|-|“|”|：|？|\\s]"))
//                continue;
//                // 此处过滤长度为1的str
//            else if (str.length() < 2)
//                continue;
//
//            if (!map.containsKey(word)){
//                map.put(word, 1);
//            } else {
//                int n = map.get(word);
//                map.put(word, ++n);
//            }
//        }
//
//        Iterator<Map.Entry<String, Integer>> iterator = map.entrySet().iterator();
//        while (iterator.hasNext()){
//            Map.Entry<String, Integer> entry = iterator.next();
//            System.out.println(entry.getKey() + ": " + entry.getValue());
//        }
//        List<Map.Entry<String, Integer>> list = new ArrayList<>();
//        Map.Entry<String, Integer> entry;
//        while ((entry = getMax(map)) != null){
//            list.add(entry);
//        }
//
//        System.out.println(Arrays.toString(list.toArray()));
//
//    }
//
//
//    /**
//     * 找出map中value最大的entry, 返回此entry, 并在map删除此entry
//     * @param map
//     * @return
//     */
//    public static Map.Entry<String, Integer> getMax(Map<String, Integer> map){
//        if (map.size() == 0){
//            return null;
//        }
//        Map.Entry<String, Integer> maxEntry = null;
//        boolean flag = false;
//        Iterator<Map.Entry<String, Integer>> iterator = map.entrySet().iterator();
//        while (iterator.hasNext()){
//            Map.Entry<String, Integer> entry = iterator.next();
//            if (!flag){
//                maxEntry = entry;
//                flag = true;
//            }
//            if (entry.getValue() > maxEntry.getValue()){
//                maxEntry = entry;
//            }
//        }
//        map.remove(maxEntry.getKey());
//        return maxEntry;
//    }
//
//    public static String getString() throws IOException {
//        String reader = "我们是中国人，我哎中国, 遥遥领先";
//        StringBuilder strBuilder = new StringBuilder();
//        strBuilder.append(reader);
//        return strBuilder.toString();
//    }
//
//    @Test
//    public void test() throws IOException {
//      wordFrequency();
//    }
//}

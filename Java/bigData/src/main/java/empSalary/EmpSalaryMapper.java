package empSalary;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;


public class EmpSalaryMapper extends Mapper<LongWritable, Text, IntWritable, LongWritable> {
    //Text k = new Text();
    //IntWritable v = new IntWritable(1);

    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        String line = value.toString(); //将每一行的数据转为 String
        String[] words = line.split(","); //按 ， 进行分割

//        for (String word : words) {
//            k.set(word);
//            context.write(k, v);
//        }

        //按部分id切
        IntWritable mapKey = new IntWritable();
        mapKey.set(Integer.parseInt(words[7]));

        LongWritable mapValue = new LongWritable();
        //工资+绩效
        mapValue.set(Long.parseLong(words[5]) + Long.parseLong(words[6]));
        context.write(mapKey, mapValue);

    }
}

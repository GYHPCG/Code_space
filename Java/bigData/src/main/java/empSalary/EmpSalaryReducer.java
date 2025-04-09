package empSalary;


import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.Writable;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class EmpSalaryReducer extends Reducer<IntWritable, LongWritable, IntWritable, LongWritable> {
//    int sum;
//    IntWritable v = new IntWritable();

    @Override
    protected void reduce(IntWritable key, Iterable<LongWritable> values, Context context) throws IOException, InterruptedException {
        long sum = 0;
        long peo = 0;
        for (LongWritable value : values) {
            sum += value.get();
            peo++;
        }
        //v.set(sum);
        LongWritable avg = new LongWritable();
        avg.set(sum / peo);
        context.write(key, avg);
    }
}

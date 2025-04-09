package API;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import  org.apache.hadoop.fs.Path;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

public class HDFS {
    public static void mkdir() throws URISyntaxException, IOException, InterruptedException {
        Configuration configuration = new Configuration();
        FileSystem FS = FileSystem.get(new URI("hdfs://192.168.92.136:8020"), configuration, "gyh");
        FS.mkdirs(new Path("/path"));
        FS.close();
    }

    public static void testput() throws URISyntaxException, IOException, InterruptedException {
        Configuration configuration = new Configuration();
        FileSystem FS = FileSystem.get(new URI("hdfs://192.168.92.136:8020"), configuration, "gyh");
        FS.copyFromLocalFile(new Path("D:/test2.txt"), new Path("/"));
        FS.close();
    }
    public static void main(String[] args) throws URISyntaxException, IOException, InterruptedException {
        mkdir();
        //testput();

    }
}


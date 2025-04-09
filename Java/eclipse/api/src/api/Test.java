package api;

import java.io.IOException;

public class Test {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//system类
		//1.System.exit():0,正常退出，非0，异常退出
//		System.exit(0);
//		System.out.println("看看我执行了吗？");
		
		//查看计算机的时间
		//System.out.println(System.currentTimeMillis());
		
		//runtime类
		Runtime r = Runtime.getRuntime();
		//查看电脑核数
//		System.out.println(r.availableProcessors());
		
		//查看jvm能获得的系统的最大内存
		System.out.println(r.maxMemory() / 1024 / 1024);
		
		//以获得的总内存
		System.out.println(r.totalMemory() / 1024 / 1024);
		
		//剩余的内存
		System.out.println(r.freeMemory() / 1024 / 1024);
		
		//运行cmd命令
		System.out.println(r.exec("shutdown -a"));
		
	}

}

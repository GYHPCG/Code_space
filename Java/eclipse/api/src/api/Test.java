package api;

import java.io.IOException;

public class Test {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//system��
		//1.System.exit():0,�����˳�����0���쳣�˳�
//		System.exit(0);
//		System.out.println("������ִ������");
		
		//�鿴�������ʱ��
		//System.out.println(System.currentTimeMillis());
		
		//runtime��
		Runtime r = Runtime.getRuntime();
		//�鿴���Ժ���
//		System.out.println(r.availableProcessors());
		
		//�鿴jvm�ܻ�õ�ϵͳ������ڴ�
		System.out.println(r.maxMemory() / 1024 / 1024);
		
		//�Ի�õ����ڴ�
		System.out.println(r.totalMemory() / 1024 / 1024);
		
		//ʣ����ڴ�
		System.out.println(r.freeMemory() / 1024 / 1024);
		
		//����cmd����
		System.out.println(r.exec("shutdown -a"));
		
	}

}

package game;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class RegisterFrame extends JFrame{
	public RegisterFrame() {
		initJframe();
		
		initView();
		this.setVisible(true);
	}

	private void initView() {
		// TODO Auto-generated method stub
		//���ע���û���
		JLabel user = new JLabel(new ImageIcon("./image/register/ע���û���.png"));
		user.setBounds(100, 125, 79, 17);
		this.getContentPane().add(user);
		
		//��ӿ�
		JLabel k = new JLabel(new ImageIcon("./image/register/�Ի���.png"));
		k.setBounds(190,115,198,40);
		this.getContentPane().add(k);
		
		
		//��������
		JLabel passw = new JLabel(new ImageIcon("./image/register/ע������.png"));
		passw.setBounds(115, 180, 64, 16);
		this.getContentPane().add(passw);
		
		//��ӿ�
		JLabel k1 = new JLabel(new ImageIcon("./image/register/�Ի���.png"));
		k1.setBounds(190,170,198,40);
		this.getContentPane().add(k1);
		
		JLabel passw1 = new JLabel(new ImageIcon("./image/register/�ٴ���������.png"));
		passw1.setBounds(82, 240, 96, 17);
		this.getContentPane().add(passw1);
		
		JLabel k2 = new JLabel(new ImageIcon("./image/register/�Ի���.png"));
		k2.setBounds(190,230,198,40);
		this.getContentPane().add(k2);
		
		//��ӱ���ͼƬ
		ImageIcon bg = new ImageIcon("./image/register/background.png");
		JLabel bg1 = new JLabel(bg);
		bg1.setBounds(2, 0, 470, 390);
		this.getContentPane().add(bg1);
	}

	private void initJframe() {
		// TODO Auto-generated method stub
		this.setSize(488, 430);
		
		this.setTitle("ƴͼ������Ϸ v1.0ע��");
		
		this.setAlwaysOnTop(true);
		
		//���ý������
		
		this.setLocationRelativeTo(null);
		
		//����ֹͣ
		this.setDefaultCloseOperation(3);
		this.setLayout(null);
	}
}

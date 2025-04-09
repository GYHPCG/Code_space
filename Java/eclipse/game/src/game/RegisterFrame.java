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
		//添加注册用户名
		JLabel user = new JLabel(new ImageIcon("./image/register/注册用户名.png"));
		user.setBounds(100, 125, 79, 17);
		this.getContentPane().add(user);
		
		//添加框
		JLabel k = new JLabel(new ImageIcon("./image/register/对话框.png"));
		k.setBounds(190,115,198,40);
		this.getContentPane().add(k);
		
		
		//添加密码框
		JLabel passw = new JLabel(new ImageIcon("./image/register/注册密码.png"));
		passw.setBounds(115, 180, 64, 16);
		this.getContentPane().add(passw);
		
		//添加框
		JLabel k1 = new JLabel(new ImageIcon("./image/register/对话框.png"));
		k1.setBounds(190,170,198,40);
		this.getContentPane().add(k1);
		
		JLabel passw1 = new JLabel(new ImageIcon("./image/register/再次输入密码.png"));
		passw1.setBounds(82, 240, 96, 17);
		this.getContentPane().add(passw1);
		
		JLabel k2 = new JLabel(new ImageIcon("./image/register/对话框.png"));
		k2.setBounds(190,230,198,40);
		this.getContentPane().add(k2);
		
		//添加背景图片
		ImageIcon bg = new ImageIcon("./image/register/background.png");
		JLabel bg1 = new JLabel(bg);
		bg1.setBounds(2, 0, 470, 390);
		this.getContentPane().add(bg1);
	}

	private void initJframe() {
		// TODO Auto-generated method stub
		this.setSize(488, 430);
		
		this.setTitle("拼图单机游戏 v1.0注册");
		
		this.setAlwaysOnTop(true);
		
		//设置界面居中
		
		this.setLocationRelativeTo(null);
		
		//设置停止
		this.setDefaultCloseOperation(3);
		this.setLayout(null);
	}
}

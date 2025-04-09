package game;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.border.BevelBorder;

public class Game_UI extends JFrame implements KeyListener,ActionListener{

	private int[][] data = new int[4][4];
	//设置图片空白的位置
	int x = 0;
	int y = 0;
	//判断胜利的数组
	int[][] win = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,0}
	};
	//定义变量记录步数
	int step = 0;
	String path = "./image/animal/animal3/";
	
	//条目对象
	JMenu renewPho = new JMenu("更新图片");
	JMenuItem replayItem = new JMenuItem("重新游戏");
	JMenuItem reloginItem = new JMenuItem("重新登录");
	JMenuItem close  = new JMenuItem("关闭游戏");
			
	JMenuItem aboutusItem = new JMenuItem("公众号");
	JMenuItem girl = new JMenuItem("美女");
	JMenuItem animal = new JMenuItem("动物");
	JMenuItem sport = new JMenuItem("运动");
	public Game_UI() {
		 initJframe();
		//设置菜单
		 initJmenuBar();
		
		 //打乱图片
		 initData();
		 
		 //图形初始化		 
		 initImage();
		this.setVisible(true);
	}
	Random r1 = new Random();
	private void initData() {
		// TODO Auto-generated method stub
		int[] temp = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
		Random r = new Random();
		for (int i = 0; i < temp.length; i++) {
			int index = r.nextInt(temp.length);
			int k = temp[i];
			temp[i] = temp[index];
			temp[index] = k;
		}
		for (int i = 0; i <temp.length; i++) {
			
			if (temp[i] == 0) {
				x = i / 4;
				y = i % 4;
			}
			data[i / 4][i % 4] = temp[i];
		}
		
	}
	private void initImage() {
		
		this.getContentPane().removeAll();
		
		if (vicitory()) {
			ImageIcon vic = new ImageIcon("./image/win.png");
			JLabel v = new JLabel(vic);
			v.setBounds(203, 283, 197, 73);
			this.getContentPane().add(v);
			
		}
		
		JLabel stepCount = new JLabel("步数："+step);
		stepCount.setBounds(50, 30, 100, 20);
		this.getContentPane().add(stepCount);
		
		//创建一个img对象
		int number = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				
				number = data[i][j];
				
				ImageIcon icon = new ImageIcon(path+number+".jpg");
			
				//建立一个jlable容器
				JLabel jlabel = new JLabel(icon);
				
				//设置图片位置
				jlabel.setBounds(105*j + 83, 105*i + 134, 105, 105);
				
				//设置图片边框
				jlabel.setBorder(new BevelBorder(1));
				
				//添加到界面
				//this.add(jlabel);
				this.getContentPane().add(jlabel);
			}
		}
		//建立背景图片
				ImageIcon bg = new ImageIcon("./image/background.png");
				
				JLabel backg = new JLabel(bg);
				
				backg.setBounds(40, 40, 508, 560);
				
				this.getContentPane().add(backg);
				this.getContentPane().repaint();
	}
	private void initJmenuBar() {
		// TODO Auto-generated method stub
		JMenuBar jmenuBar = new JMenuBar();
		
		//设置功能
		JMenu function = new JMenu("功能");
		JMenu aboutus  = new JMenu("关于我们");
		
		//建立条目对象
		
		//添加到一起去
		function.add(renewPho);
		function.add(replayItem);
		function.add(reloginItem);
		function.add(close);
		renewPho.add(girl);
		renewPho.add(animal);
		renewPho.add(sport);
		aboutus.add(aboutusItem);
		
		//给条目绑定事件
		replayItem.addActionListener(this);
		reloginItem.addActionListener(this);
		close.addActionListener(this);
		aboutusItem.addActionListener(this);
		girl.addActionListener(this);
		animal.addActionListener(this);
		sport.addActionListener(this);
		jmenuBar.add(function);
		jmenuBar.add(aboutus);
		
		this.setJMenuBar(jmenuBar);
		
	}
	private void initJframe() {
		this.setSize(603, 680);
		
		this.setTitle("拼图单机游戏 v1.0");
		
		this.setAlwaysOnTop(true);
		
		//设置界面居中
		
		this.setLocationRelativeTo(null);
		
		//设置停止
		this.setDefaultCloseOperation(3);
		
		//修改布局方式
		this.setLayout(null);
		
		//给整个界面设置监听事件
		this.addKeyListener(this);
	}
	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		int code = e.getKeyCode();
		
		if (code == 65) {
			this.getContentPane().removeAll();
			ImageIcon all = new ImageIcon(path+"all.jpg");
			JLabel a = new JLabel(all);
			a.setBounds(83, 134, 420, 420);
			this.getContentPane().add(a);
			
			ImageIcon bg = new ImageIcon("./image/background.png");
			
			JLabel backg = new JLabel(bg);
			
			backg.setBounds(40, 40, 508, 560);
			
			this.getContentPane().add(backg);
			
			this.getContentPane().repaint();
			
			
		}
		
	}
	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		//对上下左右位置进行判断
		//左：37，上：38 右：39 下：40
		if (vicitory()) {
			return ;
		}
		int code  = e.getKeyCode();
		if (code == 37 && y != 3) {
			step++;
			System.out.println("向左移动");
			data[x][y] = data[x][y + 1];
			data[x][y + 1] = 0;
			y++;
		}else if (code == 38 && x!= 3) {
			step++;
			System.out.println("向上移动");
			data[x][y] = data[x+1][y];
			data[x+1][y] = 0;
			x++;
		}else if (code == 39 && y != 0) {
			step++;
			System.out.println("向右移动");
			data[x][y] = data[x][y-1];
			data[x][y-1] = 0;
			y--;
		}else if (code == 40 && x != 0){
			step++;
			System.out.println("向下移动");
			data[x][y] = data[x-1][y];
			data[x-1][y] = 0;
			x--;
		}else if (code == 87) {
			data = new int[][] {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,0}
			};
		}
		initImage();
	}
	public boolean vicitory() {
		for (int i = 0; i < data.length; i++) {
			for (int j = 0; j < data[i].length; j++) {
				if (data[i][j] != win[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		Object obj = e.getSource();
		
		if (obj == replayItem) {
			step = 0;
			initData();
			initImage();
			
			
		}else if (obj == reloginItem) {
			this.setVisible(false);
			new LoginFrame();
		}else if (obj == aboutusItem) {
			//建立一个弹窗
			JDialog jdialog = new JDialog();
			JLabel jlabel = new JLabel(new ImageIcon("./image/about.png"));
			jlabel.setBounds(0,0,258,258);
			
			jdialog.getContentPane().add(jlabel);
			jdialog.setSize(344,344);
			jdialog.setAlwaysOnTop(true);
			jdialog.setLocationRelativeTo(null);
			//弹窗不消失，不可操作
			jdialog.setModal(true);
			jdialog.setVisible(true);
			
		}else if (obj == close) {
			System.exit(0);
		}else if (obj == girl) {
			int index = r1.nextInt(13) + 1;
			path = "./image/girl/girl"+index+"/";
			step = 0;
			initData();
			initImage();
			
		}else if (obj == animal) {
			int index = r1.nextInt(8) + 1;
			path = "./image/animal/animal"+index+"/";
			step = 0;
			initData();
			initImage();
		}else if (obj == sport) {
			int index = r1.nextInt(10) + 1;
			path = "./image/sport/sport"+index+"/";
			step = 0;
			initData();
			initImage();
		}
	}

}

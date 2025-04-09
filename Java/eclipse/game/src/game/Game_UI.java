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
	//����ͼƬ�հ׵�λ��
	int x = 0;
	int y = 0;
	//�ж�ʤ��������
	int[][] win = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,0}
	};
	//���������¼����
	int step = 0;
	String path = "./image/animal/animal3/";
	
	//��Ŀ����
	JMenu renewPho = new JMenu("����ͼƬ");
	JMenuItem replayItem = new JMenuItem("������Ϸ");
	JMenuItem reloginItem = new JMenuItem("���µ�¼");
	JMenuItem close  = new JMenuItem("�ر���Ϸ");
			
	JMenuItem aboutusItem = new JMenuItem("���ں�");
	JMenuItem girl = new JMenuItem("��Ů");
	JMenuItem animal = new JMenuItem("����");
	JMenuItem sport = new JMenuItem("�˶�");
	public Game_UI() {
		 initJframe();
		//���ò˵�
		 initJmenuBar();
		
		 //����ͼƬ
		 initData();
		 
		 //ͼ�γ�ʼ��		 
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
		
		JLabel stepCount = new JLabel("������"+step);
		stepCount.setBounds(50, 30, 100, 20);
		this.getContentPane().add(stepCount);
		
		//����һ��img����
		int number = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				
				number = data[i][j];
				
				ImageIcon icon = new ImageIcon(path+number+".jpg");
			
				//����һ��jlable����
				JLabel jlabel = new JLabel(icon);
				
				//����ͼƬλ��
				jlabel.setBounds(105*j + 83, 105*i + 134, 105, 105);
				
				//����ͼƬ�߿�
				jlabel.setBorder(new BevelBorder(1));
				
				//��ӵ�����
				//this.add(jlabel);
				this.getContentPane().add(jlabel);
			}
		}
		//��������ͼƬ
				ImageIcon bg = new ImageIcon("./image/background.png");
				
				JLabel backg = new JLabel(bg);
				
				backg.setBounds(40, 40, 508, 560);
				
				this.getContentPane().add(backg);
				this.getContentPane().repaint();
	}
	private void initJmenuBar() {
		// TODO Auto-generated method stub
		JMenuBar jmenuBar = new JMenuBar();
		
		//���ù���
		JMenu function = new JMenu("����");
		JMenu aboutus  = new JMenu("��������");
		
		//������Ŀ����
		
		//��ӵ�һ��ȥ
		function.add(renewPho);
		function.add(replayItem);
		function.add(reloginItem);
		function.add(close);
		renewPho.add(girl);
		renewPho.add(animal);
		renewPho.add(sport);
		aboutus.add(aboutusItem);
		
		//����Ŀ���¼�
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
		
		this.setTitle("ƴͼ������Ϸ v1.0");
		
		this.setAlwaysOnTop(true);
		
		//���ý������
		
		this.setLocationRelativeTo(null);
		
		//����ֹͣ
		this.setDefaultCloseOperation(3);
		
		//�޸Ĳ��ַ�ʽ
		this.setLayout(null);
		
		//�������������ü����¼�
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
		//����������λ�ý����ж�
		//��37���ϣ�38 �ң�39 �£�40
		if (vicitory()) {
			return ;
		}
		int code  = e.getKeyCode();
		if (code == 37 && y != 3) {
			step++;
			System.out.println("�����ƶ�");
			data[x][y] = data[x][y + 1];
			data[x][y + 1] = 0;
			y++;
		}else if (code == 38 && x!= 3) {
			step++;
			System.out.println("�����ƶ�");
			data[x][y] = data[x+1][y];
			data[x+1][y] = 0;
			x++;
		}else if (code == 39 && y != 0) {
			step++;
			System.out.println("�����ƶ�");
			data[x][y] = data[x][y-1];
			data[x][y-1] = 0;
			y--;
		}else if (code == 40 && x != 0){
			step++;
			System.out.println("�����ƶ�");
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
			//����һ������
			JDialog jdialog = new JDialog();
			JLabel jlabel = new JLabel(new ImageIcon("./image/about.png"));
			jlabel.setBounds(0,0,258,258);
			
			jdialog.getContentPane().add(jlabel);
			jdialog.setSize(344,344);
			jdialog.setAlwaysOnTop(true);
			jdialog.setLocationRelativeTo(null);
			//��������ʧ�����ɲ���
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

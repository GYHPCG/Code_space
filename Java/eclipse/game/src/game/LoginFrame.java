package game;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

@SuppressWarnings("serial")
public class LoginFrame extends JFrame implements MouseListener{
	
	static ArrayList<User> list = new ArrayList<>();
	static {
		list.add(new User("zhangsan","123"));
		list.add(new User("lisi","1234"));
	}
	
	JButton jbutton = new JButton();
	JButton j = new JButton();
	JTextField uname = new JTextField();
	JPasswordField pass = new JPasswordField();
	JTextField codeText = new JTextField();
	JLabel rightCode = new JLabel();
	public LoginFrame() {
		initJframe();
		
		initView();
		//显示背景图片
		backgound();
		
		
		this.setVisible(true);
	}
	public void initJframe() {
		// TODO Auto-generated method stub
		this.setSize(488, 430);
		
		this.setTitle("拼图游戏 V1.0登录");
		
		this.setAlwaysOnTop(true);
		
		//设置界面居中
		
		this.setLocationRelativeTo(null);
		
		//设置停止
		this.setDefaultCloseOperation(3);
		
		this.setLayout(null);
	}
	public void backgound() {
		ImageIcon bg = new ImageIcon("./image/login/background.png");
		JLabel jl = new JLabel(bg);
		jl.setBounds(0, 0, 470, 390);
		this.getContentPane().add(jl);
		
	}
	public void initView() {

		//添加用户文字名
		JLabel nameText = new JLabel(new ImageIcon("./image/login/用户名.png"));
		nameText.setBounds(116, 115, 47, 17);
		this.getContentPane().add(nameText);
		
		//添加用户名输入框
		
		uname.setBounds(195, 113, 200, 30);
		this.getContentPane().add(uname);
		
		//添加用户密码框
		JLabel passPho = new JLabel(new ImageIcon("./image/login/密码.png"));
		passPho.setBounds(130, 175, 32, 16);
		this.getContentPane().add(passPho);
		
		//框
		pass.setBounds(195, 173, 200, 30);
		this.getContentPane().add(pass);
		
		//验证码
		JLabel code = new JLabel(new ImageIcon("./image/login/验证码.png"));
		code.setBounds(116,236 ,50 , 30);
		this.getContentPane().add(code);
		
		//框
		
		codeText.setBounds(195, 235, 100, 30);
		this.getContentPane().add(codeText);
		
		String codeStr = codeUtil.getCode();
		
		rightCode.setText(codeStr);
		rightCode.setBounds(300, 235, 50, 30);
		rightCode.addMouseListener(this);
		this.getContentPane().add(rightCode);
		
		//添加登录框
		jbutton.setBounds(123, 310, 128, 47);
		jbutton.setIcon(new ImageIcon("./image/login/登录按钮.png"));
		//去除边框
		jbutton.setBorderPainted(false);
		//去除背景
		jbutton.setContentAreaFilled(false);
		jbutton.addMouseListener(this);
		this.getContentPane().add(jbutton);
		
		//添加注册
		
		j.setBounds(255, 310, 128, 47);
		j.setIcon(new ImageIcon("./image/login/注册按钮.png"));
		//去除边框
		j.setBorderPainted(false);
		//去除背景
		j.setContentAreaFilled(false);
		j.addMouseListener(this);
		this.getContentPane().add(j);
	}
	
	public void showDialog(String content) {
		JDialog jdialog = new JDialog();
		
		jdialog.setSize(200, 150);
		
		jdialog.setAlwaysOnTop(true);
		
		jdialog.setLocationRelativeTo(null);
		
		jdialog.setModal(true);
		
		jdialog.setLayout(null);
		JLabel warning = new JLabel(content);
		
		warning.setBounds(50,-30,250,150);
		
		jdialog.getContentPane().add(warning);
		
		jdialog.setVisible(true);
		
	}
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == jbutton) {
            System.out.println("点击了登录按钮");
            //获取两个文本输入框中的内容
            String usernameInput = uname.getText();
            @SuppressWarnings("deprecation")
			String passwordInput = pass.getText();
            //获取用户输入的验证码
            String codeInput = codeText.getText();

            //创建一个User对象
            User userInfo = new User(usernameInput, passwordInput);
            System.out.println("用户输入的用户名为" + usernameInput);
            System.out.println("用户输入的密码为" + passwordInput);

            if (codeInput.length() == 0) {
                showDialog("验证码不能为空");
            } else if (usernameInput.length() == 0 || passwordInput.length() == 0) {
                //校验用户名和密码是否为空
                System.out.println("用户名或者密码为空");

                //调用showJDialog方法并展示弹框
                showDialog("用户名或者密码为空");


            } else if (!codeInput.equalsIgnoreCase(rightCode.getText())) {
                showDialog("验证码输入错误");
            } else if (contains(userInfo)) {
                System.out.println("用户名和密码正确可以开始玩游戏了");
                //关闭当前登录界面
                this.setVisible(false);
                //打开游戏的主界面
                //需要把当前登录的用户名传递给游戏界面
                new Game_UI();
            } else {
                System.out.println("用户名或密码错误");
                showDialog("用户名或密码错误");
            }
        } else if (e.getSource() == j) {
            System.out.println("点击了注册按钮");
            this.setVisible(false);
            new RegisterFrame();
        } else if (e.getSource() == rightCode) {
            System.out.println("更换验证码");
            //获取一个新的验证码
            String code = codeUtil.getCode();
            rightCode.setText(code);
        }
	}
	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == jbutton) {
			jbutton.setIcon(new ImageIcon("./image/login/登录按下.png"));
        } else if (e.getSource() == j) {
            j.setIcon(new ImageIcon("./image/login/注册按下.png"));
        }
	}
	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == jbutton) {
            jbutton.setIcon(new ImageIcon("./image/login/登录按钮.png"));
        } else if (e.getSource() == j) {
            j.setIcon(new ImageIcon("./image/login/注册按钮.png"));
        }
	}
	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

    //判断用户在集合中是否存在
    public boolean contains(User userInput){
        for (int i = 0; i < list.size(); i++) {
            User rightUser = list.get(i);
            if(userInput.getName().equals(rightUser.getName()) && userInput.getPass().equals(rightUser.getPass())){
                //有相同的代表存在，返回true，后面的不需要再比了
                return true;
            }
        }
        //循环结束之后还没有找到就表示不存在
        return false;
    }
}
	

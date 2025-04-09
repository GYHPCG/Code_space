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
		//��ʾ����ͼƬ
		backgound();
		
		
		this.setVisible(true);
	}
	public void initJframe() {
		// TODO Auto-generated method stub
		this.setSize(488, 430);
		
		this.setTitle("ƴͼ��Ϸ V1.0��¼");
		
		this.setAlwaysOnTop(true);
		
		//���ý������
		
		this.setLocationRelativeTo(null);
		
		//����ֹͣ
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

		//����û�������
		JLabel nameText = new JLabel(new ImageIcon("./image/login/�û���.png"));
		nameText.setBounds(116, 115, 47, 17);
		this.getContentPane().add(nameText);
		
		//����û��������
		
		uname.setBounds(195, 113, 200, 30);
		this.getContentPane().add(uname);
		
		//����û������
		JLabel passPho = new JLabel(new ImageIcon("./image/login/����.png"));
		passPho.setBounds(130, 175, 32, 16);
		this.getContentPane().add(passPho);
		
		//��
		pass.setBounds(195, 173, 200, 30);
		this.getContentPane().add(pass);
		
		//��֤��
		JLabel code = new JLabel(new ImageIcon("./image/login/��֤��.png"));
		code.setBounds(116,236 ,50 , 30);
		this.getContentPane().add(code);
		
		//��
		
		codeText.setBounds(195, 235, 100, 30);
		this.getContentPane().add(codeText);
		
		String codeStr = codeUtil.getCode();
		
		rightCode.setText(codeStr);
		rightCode.setBounds(300, 235, 50, 30);
		rightCode.addMouseListener(this);
		this.getContentPane().add(rightCode);
		
		//��ӵ�¼��
		jbutton.setBounds(123, 310, 128, 47);
		jbutton.setIcon(new ImageIcon("./image/login/��¼��ť.png"));
		//ȥ���߿�
		jbutton.setBorderPainted(false);
		//ȥ������
		jbutton.setContentAreaFilled(false);
		jbutton.addMouseListener(this);
		this.getContentPane().add(jbutton);
		
		//���ע��
		
		j.setBounds(255, 310, 128, 47);
		j.setIcon(new ImageIcon("./image/login/ע�ᰴť.png"));
		//ȥ���߿�
		j.setBorderPainted(false);
		//ȥ������
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
            System.out.println("����˵�¼��ť");
            //��ȡ�����ı�������е�����
            String usernameInput = uname.getText();
            @SuppressWarnings("deprecation")
			String passwordInput = pass.getText();
            //��ȡ�û��������֤��
            String codeInput = codeText.getText();

            //����һ��User����
            User userInfo = new User(usernameInput, passwordInput);
            System.out.println("�û�������û���Ϊ" + usernameInput);
            System.out.println("�û����������Ϊ" + passwordInput);

            if (codeInput.length() == 0) {
                showDialog("��֤�벻��Ϊ��");
            } else if (usernameInput.length() == 0 || passwordInput.length() == 0) {
                //У���û����������Ƿ�Ϊ��
                System.out.println("�û�����������Ϊ��");

                //����showJDialog������չʾ����
                showDialog("�û�����������Ϊ��");


            } else if (!codeInput.equalsIgnoreCase(rightCode.getText())) {
                showDialog("��֤���������");
            } else if (contains(userInfo)) {
                System.out.println("�û�����������ȷ���Կ�ʼ����Ϸ��");
                //�رյ�ǰ��¼����
                this.setVisible(false);
                //����Ϸ��������
                //��Ҫ�ѵ�ǰ��¼���û������ݸ���Ϸ����
                new Game_UI();
            } else {
                System.out.println("�û������������");
                showDialog("�û������������");
            }
        } else if (e.getSource() == j) {
            System.out.println("�����ע�ᰴť");
            this.setVisible(false);
            new RegisterFrame();
        } else if (e.getSource() == rightCode) {
            System.out.println("������֤��");
            //��ȡһ���µ���֤��
            String code = codeUtil.getCode();
            rightCode.setText(code);
        }
	}
	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == jbutton) {
			jbutton.setIcon(new ImageIcon("./image/login/��¼����.png"));
        } else if (e.getSource() == j) {
            j.setIcon(new ImageIcon("./image/login/ע�ᰴ��.png"));
        }
	}
	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		if (e.getSource() == jbutton) {
            jbutton.setIcon(new ImageIcon("./image/login/��¼��ť.png"));
        } else if (e.getSource() == j) {
            j.setIcon(new ImageIcon("./image/login/ע�ᰴť.png"));
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

    //�ж��û��ڼ������Ƿ����
    public boolean contains(User userInput){
        for (int i = 0; i < list.size(); i++) {
            User rightUser = list.get(i);
            if(userInput.getName().equals(rightUser.getName()) && userInput.getPass().equals(rightUser.getPass())){
                //����ͬ�Ĵ�����ڣ�����true������Ĳ���Ҫ�ٱ���
                return true;
            }
        }
        //ѭ������֮��û���ҵ��ͱ�ʾ������
        return false;
    }
}
	

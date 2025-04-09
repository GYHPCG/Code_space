package game;

public class User {
	
	private String name;
	private String pass;
	
	public User() {
		
	}
	public User(String string, String string2) {
		// TODO Auto-generated constructor stub
		name = string;
		pass = string2;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getPass() {
		return pass;
	}
	public void setPass(String pass) {
		this.pass = pass;
	}
	
}

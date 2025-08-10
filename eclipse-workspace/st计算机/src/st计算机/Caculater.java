package st计算机;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

public class Caculater {
	public JFrame frame;
	public JTextField textField;
	private String num1= "0";
	private String num2 = "";
	private String op = "+";
	
	public Caculater() {
		frame = new JFrame();
		frame.setSize(300,500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());
		
		textField = new JTextField();
		textField.setHorizontalAlignment(SwingConstants.RIGHT);
		textField.setFont(new Font("幼圆", Font.BOLD, 50));
		frame.add(textField, BorderLayout.NORTH);
		
		JPanel panel=new JPanel();
		panel.setBackground(Color.PINK);
		frame.add(panel, BorderLayout.CENTER);
		
		panel.setLayout(new GridLayout(4, 4, 3, 3));
		
		String [] txtStrings = {
				"7","8","9","/",
				"4","5","6","*",
				"1","2","3","+",
				"0",".","=","-",
		};
		for (int i = 0; i < 16; i++) {
			JButton button = new JButton(txtStrings[i]);
			button.setFont(new Font("幼圆", Font.BOLD, 60));
			
			button.addActionListener(newAction());
			
			panel.add(button);
			
		}
		
		frame.setVisible(true);
	}
	
	private ActionListener newAction() {
		ActionListener actionListener = new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				String cmd = e.getActionCommand();
				if("+-*/".contains(cmd)) {
					caculate(op);
					op = cmd;
				}
				else if(cmd.equals("=")) {
					caculate(op);
				}
				else if(cmd.equals(".")) {
					if(num2.equals("."))
						return;
					num2 += cmd;
					textField.setText(num2);
				}
				else {
					num2 = num2 + cmd;
					textField.setText(num2);
				}
				
			}
			private void caculate(String op) {
				double n1 = Double.valueOf(num1);
				double n2 = 0;
				if (num2.equals("")) {
					return;
				}
				n2 = Double.valueOf(num2);
				String re = "";
				switch (op) {
				case "+": 
					re = String.valueOf(n1 + n2);break;
				case "-": 
					re = String.valueOf(n1 - n2);break;
				case "*": 
					re = String.valueOf(n1 * n2);break;
				case "/": 
					re = String.valueOf(n1 / n2);break;
				}
				num1 = re;
				num2 = "";
				textField.setText(re);
			}
			
			
		};
		return actionListener;
	}
	
	public static void main(String[] args) {
		Caculater caculater = new Caculater();
	}
	
}
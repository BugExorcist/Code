package exp1;

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
	public JTextField outFiled;
	private String num1 = "0";
	private String num2 = "";
	private String op = "+";
	
	public Caculater() {
		frame = new JFrame();
		frame.setSize(500, 500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame.setLayout(new BorderLayout());
		
		outFiled = new JTextField();
		outFiled.setHorizontalAlignment(SwingConstants.RIGHT);
		outFiled.setFont(new Font("幼圆",Font.BOLD, 60));//字体 加粗 字号
		frame.add(outFiled, BorderLayout.NORTH);
		
		JPanel panel = new JPanel();
		panel.setBackground(Color.green);
		frame.add(panel, BorderLayout.CENTER);
		
		panel.setLayout(new GridLayout(4, 4, 5, 5));
		
		String [] txt = {"7","8","9","/",
						 "4","5","6","*",
						 "1","2","3","-",
						 "0",".","=","+"};
		for (int i = 0; i < 16; i++) {
			JButton btn = new JButton(txt[i]);
			btn.setFont(new Font("幼圆",Font.BOLD, 60));
			
			//添加事件
			btn.addActionListener(newAction());
			
			panel.add(btn);
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
				else if (cmd.equals("=")) {
					caculate(op);
				}
				else if (cmd.equals(".")) {
					if(num2.contains(".")) {
						return;
					}
					num2 = num2 + cmd;
					outFiled.setText(num2);
				}
				else {
					num2 = num2 + cmd;
					outFiled.setText(num2);
				}
				
				
			}
			private void caculate(String op) {
				double d1 = Double.valueOf(num1);
				double d2 = 0;
				if(num2.equals("")) {//num2为空
					return;
				}
				d2 = Double.valueOf(num2);
				String result = "";
				switch(op) {
				case "+":result = String.valueOf(d1 + d2);break;
				case "-":result = String.valueOf(d1 - d2);break;
				case "*":result = String.valueOf(d1 * d2);break;
				case "/":result = String.valueOf(d1 / d2);break;
				}
				num1 = result;
				num2 = "";
				outFiled.setText(result);
				
			}
		};
		return actionListener;
	}
	
	public static void main(String[] args) {
		Caculater caculater = new Caculater();
	}
}

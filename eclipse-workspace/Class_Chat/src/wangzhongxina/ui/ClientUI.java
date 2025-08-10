package wangzhongxina.ui;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.math.BigInteger;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import wangzhongxina.net.Client;
import wangzhongxina.net.MessageAble;
import wangzhongxina.net.Sever;

public class ClientUI {
	private JTextArea chatArea;
	private JTextField messagrField;
	private Client client;
	private JTextField adressField;
	
	public ClientUI() {
		JFrame frame=new JFrame("客户端");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(400, 500);
		
		frame.setLayout(new BorderLayout());
		chatArea = new JTextArea();
		chatArea.setFont(new Font("微软雅黑", Font.BOLD, 20));
		frame.add(chatArea, BorderLayout.CENTER);
		
		
		JPanel panel = new JPanel();
		messagrField = new JTextField();
		messagrField.setColumns(15);
		messagrField.setFont(new Font("微软雅黑", Font.BOLD, 20));
		JButton sentBtn = new JButton("发送");
		sentBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String msg =  messagrField.getText();
				chatArea.append("客户端：" + msg + "\n");
				client.sendMessage(msg);
				messagrField.setText("");
			}
		});
		panel.add(messagrField);
		panel.add(sentBtn);
		frame.add(panel, BorderLayout.SOUTH);
		
		JPanel northPan = new JPanel();
		northPan.add(new JLabel("连接："));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
		adressField = new JTextField("127.0.0.1:1024");
		adressField.setColumns(15);
		JButton startBtn = new JButton("连接");
		startBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				startConnect();
			}
		});
		northPan.add(adressField);
		northPan.add(startBtn);
		frame.add(northPan, BorderLayout.NORTH);
		
		frame.setVisible(true);
		
	}
	
	private void startConnect() {
		String address = adressField.getText();
		String[] strs = address.split(":");
		String host = strs[0];
		int port = Integer.parseInt(strs[1]);
		client = new Client(host, port, new MessageAble() {
			public void dealMessage(String msg) {
				//处理接收到的消息
				chatArea.append("服务端：" + msg + "\n");
			}
		});
	}
	
	public static void main(String[] args) {
		new ClientUI();
	}
}

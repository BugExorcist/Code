package wangzhongxina.ui;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import wangzhongxina.net.MessageAble;
import wangzhongxina.net.Sever;

public class ServerUI {
	private JTextArea chatArea;
	private JTextField messagrField;
	private Sever sever;
	private JTextField portField;
	
	public ServerUI() {
		JFrame frame=new JFrame("服务器");
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
				chatArea.append("服务端：" + msg + "\n");
				sever.sendMessage(msg);
				messagrField.setText("");
			}
		});
		panel.add(messagrField);
		panel.add(sentBtn);
		frame.add(panel, BorderLayout.SOUTH);
		
		JPanel northPan = new JPanel();
		northPan.add(new JLabel("监听端口："));
		portField = new JTextField("1024");
		portField.setColumns(5);
		JButton startBtn = new JButton("监听");
		startBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				startServer();
			}
		});
		northPan.add(portField);
		northPan.add(startBtn);
		frame.add(northPan, BorderLayout.NORTH);
		
		frame.setVisible(true);
		
	}
	
	private void startServer() {
		int port = Integer.parseInt(portField.getText());
		sever = new Sever(port, new MessageAble() {
			public void dealMessage(String msg) {
				//处理接收到的消息
				chatArea.append("客户端：" + msg + "\n");
			}
		});
	}
	
	public static void main(String[] args) {
		new ServerUI();
	}
}

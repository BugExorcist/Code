package wangzhongxian.ui;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import wangzhongxian.alg.Calculate;

public class ThreadUI {
	private JTextField textField;
	private JTextArea consoleArea;
	private Calculate cal;
	
	public ThreadUI() {
		JFrame frame=new JFrame("阶乘计算程序");
		frame.setSize(600,400);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//北侧 操作栏
		frame.setLayout(new BorderLayout());
		JPanel northPan = new JPanel();
		JLabel label = new JLabel("输入值N：");
		textField =new JTextField(10);
		
		JButton startButton=new JButton("开始计算");
		startAction(startButton);
		JButton pauseButton=new JButton("暂停计算");
		pauseAction(pauseButton);
		JButton stopButton=new JButton("停止计算");
		stopAction(stopButton);
		
		northPan.add(label);
		northPan.add(textField);
		northPan.add(startButton);
		northPan.add(pauseButton);
		northPan.add(stopButton);
		frame.add(northPan,BorderLayout.NORTH);
		//中间 记录计算过程、结果
		consoleArea = new JTextArea();
		JScrollPane scrollPane = new JScrollPane(consoleArea);
		frame.add(scrollPane,BorderLayout.CENTER);
		
		frame.setVisible(true);
	}
	
	private void stopAction(JButton stopButton) {
		stopButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				cal.stop();
			}
		});
	}

	private void pauseAction(JButton pauseButton) {
		pauseButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String pauseText = pauseButton.getText();
				if (pauseText.equals("暂停计算")) {
					cal.suspend();
					pauseButton.setText("继续计算");
				}else {
					cal.resume();
					pauseButton.setText("暂停计算");
				}				
			}
		});
	}
	
	private void startAction (JButton startButton) {
		startButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				consoleArea.setText(null);
				String input = textField.getText();
				int n = Integer.valueOf(input);
				cal = new Calculate(n, new Logable() {
					public void log(String content) {
						consoleArea.append(content+"\n");
					}
				});
				cal.start();
			}
		});
	}
	
	public static void main(String[] args) {
		new ThreadUI();
	}
}

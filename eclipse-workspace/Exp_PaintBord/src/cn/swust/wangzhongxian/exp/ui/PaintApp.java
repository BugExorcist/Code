package cn.swust.wangzhongxian.exp.ui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;


public class PaintApp {
	public static void main(String[] args) {
		
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException | InstantiationException | IllegalAccessException
				| UnsupportedLookAndFeelException e) {
			e.printStackTrace();
		}
		
		JFrame frame= new JFrame("画图板");
		frame.setSize(500, 500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());
		
		MyCanvas canvas = new MyCanvas();
		canvas.setBackground(Color.white);
		frame.add(canvas, BorderLayout.CENTER);
		
		JMenuBar  meunbar = new JMenuBar();
		JButton rectBtn = new JButton("矩形");
		meunbar.add(rectBtn);
		rectBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				canvas.setFigType("rectangle");
			}
		});
		JButton lineBtn = new JButton("直线");
		meunbar.add(lineBtn);
		lineBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				canvas.setFigType("line");
			}
		});
		JButton isotBtn = new JButton("等腰三角形");
		meunbar.add(isotBtn);
		isotBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				canvas.setFigType("isotriangel");
			}
		});
		JButton rigBtn = new JButton("直角三角形");
		meunbar.add(rigBtn);
		rigBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				canvas.setFigType("rigtriangel");
			}
		});
		JButton eclBtn = new JButton("椭圆");
		meunbar.add(eclBtn);
		eclBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				canvas.setFigType("eclipse");
			}
		});
		JButton colorBtn = new JButton("⬛");
		colorBtn.setForeground(Color.BLACK);
		meunbar.add(colorBtn);
		colorBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				Color color = JColorChooser.showDialog(frame, "绘制颜色", colorBtn.getForeground());
				colorBtn.setForeground(color);
				canvas.setColor(color);
			}
		});
		
		JButton saveBtn = new JButton("保存");
		saveBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JFileChooser chooser=new JFileChooser();
				if (chooser.showSaveDialog(frame) == JFileChooser.APPROVE_OPTION) {
					File file = chooser.getSelectedFile();
					canvas.savePic(file);
				}
			}
		});
		meunbar.add(saveBtn);
		frame.add(meunbar, BorderLayout.NORTH);
		frame.setVisible(true);
		
	}
}

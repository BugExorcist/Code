package ui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;

public class APP {
	public static void main(String[] args) {
		JFrame frame = new JFrame("画图");
		frame.setSize(600, 500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());
		
		MyCanvas canvas = new MyCanvas();
		canvas.setBackground(Color.WHITE);
		frame.add(canvas, BorderLayout.CENTER);
		
		JMenuBar menuBar = new JMenuBar();
		JButton lineBtn = new JButton("直线");
		menuBar.add(lineBtn);
		lineBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setFigtype("Line");
			}
		});
		JButton rectBtn = new JButton("矩形");
		menuBar.add(rectBtn);
		rectBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				canvas.setFigtype("Rectangle");
			}
		});
		JButton colorBtn = new JButton("颜色");
		colorBtn.setForeground(Color.black);
		menuBar.add(colorBtn);
		colorBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				Color color = JColorChooser.showDialog(colorBtn, "颜色", colorBtn.getForeground()); 
				colorBtn.setForeground(color);
				canvas.setColor(color);
			}
		});
		JButton saveBtn = new JButton("保存");
		menuBar.add(saveBtn);
		saveBtn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				JFileChooser chooser = new JFileChooser();
				if(chooser.showSaveDialog(frame) == JFileChooser.APPROVE_OPTION) {
					File file = chooser.getSelectedFile();
					canvas.SavePic(file);
				}
			}
		});
		frame.add(menuBar, BorderLayout.NORTH);
		
		
		frame.add(menuBar, BorderLayout.NORTH);
		frame.setVisible(true);
		
	}
}

		
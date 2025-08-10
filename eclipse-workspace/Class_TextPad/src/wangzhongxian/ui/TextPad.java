package wangzhongxian.ui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GraphicsEnvironment;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JColorChooser;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.filechooser.FileNameExtensionFilter;

import wangzhongxian.io.TextTool;

public class TextPad {
	private JTextArea contentArea;
	private JFrame frame;
	private String filename;
	
	public TextPad() {
		frame = new JFrame("记事本");
		frame.setSize(700,600);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JMenuBar menubar = new JMenuBar();
		JMenu menu = new JMenu("文件");
		menubar.add(menu);
		JMenuItem newItem = new JMenuItem("新建");
		newAction(newItem);
		menu.add(newItem);
		JMenuItem openItem = new JMenuItem("打开");
		openAction(openItem);
		menu.add(openItem);
		JMenuItem saveItem = new JMenuItem("保存");
		saveAction(saveItem);
		menu.add(saveItem);
		frame.setJMenuBar(menubar);
		//布局
		frame.setLayout(new BorderLayout());
		//增加工具条
		JToolBar toorBar = new JToolBar();
		JComboBox<String> fontCom = fontAction();
		toorBar.add(fontCom);
		JComboBox<String> fontSizeCom = fontSizeAction();
		toorBar.add(fontSizeCom);
		
		fontStyleAction(toorBar);
		
		JButton colorBtn = fontColorAction();
		toorBar.add(colorBtn);
		frame.add(toorBar, BorderLayout.NORTH);
		//文字编辑区
		contentArea = new JTextArea();
		JScrollPane pane = new JScrollPane(contentArea);
		frame.add(pane);
		
		frame.setVisible(true);
	}
	
	//记事本 工具栏 字体颜色
	private JButton fontColorAction() {
		JButton colorBtn = new JButton("⬛");
		colorBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Color color = colorBtn.getForeground();
				Color color2 = JColorChooser.showDialog(TextPad.this.frame,"设置字体颜色", color);
				colorBtn.setForeground(color2);
				contentArea.setForeground(color2);
				
			}
		});
		return colorBtn;
	}
	
	//记事本 工具栏 字体样式
	private void fontStyleAction(JToolBar toorBar) {
		JCheckBox boldBox = new JCheckBox("粗体");
		JCheckBox itBox = new JCheckBox("斜体");
		
		ActionListener actionListener = new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				boolean bold = boldBox.isSelected();
				boolean ital = itBox.isSelected();
				Font font = contentArea.getFont();
				int style = (bold ? Font.BOLD:font.PLAIN) | (ital ? Font.ITALIC:Font.PLAIN);
				
				contentArea.setFont(new Font(font.getName(), style, font.getSize()));
				
			}
		};
		boldBox.addActionListener(actionListener);
		itBox.addActionListener(actionListener);
		toorBar.add(boldBox);
		toorBar.add(itBox);
	}

	//记事本 工具栏 字号大小
	private JComboBox<String> fontSizeAction() {
		String[] fontSizes = new String[] {"10","20","30","50"};
		JComboBox<String> fontSizeCom = new JComboBox<String>(fontSizes);
		fontSizeCom.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int size = Integer.valueOf((String)fontSizeCom.getSelectedItem());
				Font font = TextPad.this.contentArea.getFont();
				TextPad.this.contentArea.setFont(new Font(font.getName(), font.getStyle(), size));
				
			}
		});
		
		return fontSizeCom;
	}
	
	
	//记事本 工具栏 字体设置
	private JComboBox<String> fontAction() {
		GraphicsEnvironment ent = GraphicsEnvironment.getLocalGraphicsEnvironment();
		String[] fontNames = ent.getAvailableFontFamilyNames();
//		String[] fontNames = new String[] {"宋体","微软雅黑"};
		JComboBox<String> fontCom = new JComboBox<String>(fontNames);
		fontCom.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String fontName = (String)fontCom.getSelectedItem();
				Font font = TextPad.this.contentArea.getFont();
				TextPad.this.contentArea.setFont(new Font(fontName,font.getStyle(),font.getSize()));

			}
		});
		return fontCom;
	}
	
	//记事本 菜单 新建操作
	private void newAction(JMenuItem newItem) {
		newItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				TextPad.this.contentArea.setText("");
				TextPad.this.frame.setTitle("新建 - 记事本");
				TextPad.this.filename = null;
			}
		});
	}
	
	//记事本 菜单 打开操作
	private void openAction(JMenuItem openItem) {
		openItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JFileChooser chooser = new JFileChooser();
			    FileNameExtensionFilter filter = new FileNameExtensionFilter(
			        "Text & dat", "txt", "dat");
			    chooser.setFileFilter(filter);
			    int returnVal = chooser.showOpenDialog(TextPad.this.frame);
			    if(returnVal == JFileChooser.APPROVE_OPTION) {
			    	String filename = chooser.getSelectedFile().getPath();
			    	String content = TextTool.read(filename);
			    	TextPad.this.filename = filename;
			        contentArea.setText(content);
			        TextPad.this.frame.setTitle(filename+ " - 记事本");
			    }
			}
		});
	}
	
	//菜单 保存
	private void saveAction(JMenuItem saveItem) {
		saveItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(TextPad.this.filename != null) {
					String content = TextPad.this.contentArea.getText();
					TextTool.write(TextPad.this.filename, content);
				}else {
					JFileChooser chooser = new JFileChooser();
				    FileNameExtensionFilter filter = new FileNameExtensionFilter(
				        "Text & dat", "txt", "dat");
				    chooser.setFileFilter(filter);
				    int returnVal = chooser.showSaveDialog(TextPad.this.frame);
				    if(returnVal == JFileChooser.APPROVE_OPTION) {
				    	String filename = chooser.getSelectedFile().getPath();
				    	String content = TextPad.this.contentArea.getText();
				    	TextTool.write(filename, content);
				    	TextPad.this.frame.setTitle(filename+" = 记事本");
				    	TextPad.this.filename = filename;
				    }
				}
			}
		});
		
	}
	
	
	public static void main(String[] args) {
		new TextPad();
	}
	
}

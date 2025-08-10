package ui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GraphicsEnvironment;
import java.awt.TextArea;
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

import ContentTool.ContentTool;

public class TextPad {
	private JFrame frame;
	private JTextArea textArea;
	private String filename;
	
	public TextPad() {
		frame = new JFrame("记事本");
		frame.setSize(600, 500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(new BorderLayout());
			
		JMenuBar menubar = new JMenuBar();
		JMenu menu = new JMenu("文件");
		menubar.add(menu);
		JMenuItem newItem = new JMenuItem("新建");
		newItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				textArea.setText("");
				filename = null;
			}
		});
		menu.add(newItem);
		JMenuItem openItem = new JMenuItem("打开");
		openItem.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JFileChooser chooser = new JFileChooser();
				FileNameExtensionFilter filter = new FileNameExtensionFilter(
						"Text & dat", "txt" , "dat");
				chooser.setFileFilter(filter);
				int returnVal = chooser.showOpenDialog(frame);
				if (returnVal == JFileChooser.APPROVE_OPTION) {
					String filePath = chooser.getSelectedFile().getPath();
					String content = ContentTool.read(filePath);
					filename = filePath;
					textArea.setText(content);
				}
				
			}
		});
		menu.add(openItem);
		JMenuItem saveItem = new JMenuItem("保存");
		menu.add(saveItem);
		frame.setJMenuBar(menubar);
		
		//工具条
		JToolBar toolBar = new JToolBar();
		JComboBox<String> fontcom = fontAction();
		toolBar.add(fontcom);
		JComboBox<String> sizebox = fontsizeAction();
		toolBar.add(sizebox);
		
		//字体样式
		fontstyleAction(toolBar);
		
		JButton colorBtn = fontcolorAction();
		toolBar.add(colorBtn);
		frame.add(toolBar, BorderLayout.NORTH);
		
		textArea = new JTextArea();
		JScrollPane pane = new JScrollPane(textArea);
		frame.add(pane);
		
		frame.setVisible(true);
	}
	

	private JButton fontcolorAction() {
		JButton colorButton = new JButton();
		colorButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Color color = colorButton.getForeground();
				Color color2 = JColorChooser.showDialog(TextPad.this.frame, "设置字体颜色", color);
				colorButton.setForeground(color2);
				textArea.setForeground(color2);
			}
		});
		return colorButton;
	}


	private void fontstyleAction(JToolBar toolBar) {
		JCheckBox boldBox = new JCheckBox("加粗");
		JCheckBox itBox = new JCheckBox("斜体");
		
		ActionListener actionListener = new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				boolean bold = boldBox.isSelected();
				boolean it = itBox.isSelected();
				Font font = textArea.getFont();
				int style = (bold ? Font.BOLD : Font.PLAIN) | (it ? font.ITALIC:Font.PLAIN);
				
				textArea.setFont(new Font(font.getName(), style,font.getSize()));
			}
		};
		boldBox.addActionListener(actionListener);
		itBox.addActionListener(actionListener);
		toolBar.add(boldBox);
		toolBar.add(itBox);
	}

	private JComboBox<String> fontsizeAction() {
		String[] fontSizes = new String[] {"10", "20", "30", "40", "50"};
		JComboBox<String> combox = new JComboBox<String>(fontSizes);
		combox.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				int size = Integer.valueOf((String)combox.getSelectedItem());
				Font font = textArea.getFont();
				textArea.setFont(new Font(font.getName(), font.getStyle(), size));
			}
		});
		return combox;
	}

	private JComboBox<String> fontAction() {
		GraphicsEnvironment evn = GraphicsEnvironment.getLocalGraphicsEnvironment();
		String[] fontname = evn.getAvailableFontFamilyNames();
		JComboBox<String> fontBox = new JComboBox<String>(fontname);
		fontBox.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String fontname = (String)fontBox.getSelectedItem();
				Font font = textArea.getFont();
				textArea.setFont(new Font(fontname, font.getStyle(), font.getSize()));
			}
		});
		return fontBox;
	}

	public static void main(String[] args) {
		new TextPad();
	}
}



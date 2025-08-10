package wangzhongxian.io;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;

import javax.swing.JOptionPane;

public class TextTool {
	public static String read(String filename) {
		try {
			Reader reader = new FileReader(filename);
			BufferedReader bf = new BufferedReader(reader);
			StringBuilder sb = new StringBuilder();
			String str;
			while ((str = bf.readLine())!= null) {
				sb.append(str + "\n");
			}
			
			bf.close();
			return sb.toString();
		} catch (FileNotFoundException e) {
			JOptionPane.showMessageDialog(null, "打开的文件不存在：" + filename);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	public static void write(String filename, String content) {
		try {
			Writer writer = new FileWriter(filename);
			writer.write(content);
			writer.flush();
			writer.close();
			
		} catch (IOException e) {
			JOptionPane.showMessageDialog(null, "写文件失败：" + filename);
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
//		String str = TextTool.read("f:\\file.txt");
////		System.out.println(str);
//		TextTool.write("f:\\file2.txt", str);
		
	}

}

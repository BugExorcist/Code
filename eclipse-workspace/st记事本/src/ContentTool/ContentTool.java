package ContentTool;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;

public class ContentTool {
	public static String read(String filename) {
		Reader reader;
		try {
			reader = new FileReader(filename);
			BufferedReader bf = new BufferedReader(reader);
			StringBuilder sb = new StringBuilder();
			String str;
			while((str = bf.readLine()) != null) {
				sb.append(str);
			}
			bf.close();
			return sb.toString();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public static void write(String filename, String content) {
		Writer writer;
		try {
			writer = new FileWriter(filename);
			writer.write(content);
			writer.flush();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
	}
}

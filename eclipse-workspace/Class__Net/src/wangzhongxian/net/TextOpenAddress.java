package wangzhongxian.net;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

public class TextOpenAddress {
	public static void main(String[] args) throws IOException {
		URL url = new URL("https://www.baidu.com");
		URLConnection con = url.openConnection();
		InputStream in = con.getInputStream();
		BufferedReader reader= new BufferedReader(new InputStreamReader(in));
		String line;
		while((line=reader.readLine())!= null) {
			System.out.print(line);
		}
	}
}

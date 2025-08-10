package wangzhongxina.net;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Client {
	private Socket socket;
	private InputStream in;
	private OutputStream out;
	private PrintWriter writer;
	private BufferedReader reader;
	private MessageAble msgAble;
	
	public Client(String host, int port, MessageAble msgAble) {
		this.msgAble = msgAble;
		try {
			socket = new Socket(host, port);
			in = socket.getInputStream();
			out = socket.getOutputStream();
			writer = new PrintWriter(out);
			reader = new BufferedReader(new InputStreamReader(in));
			startReciveMsg();
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public void sendMessage(String msg) {
		writer.println(msg);
		writer.flush();
	}
	
//	private void startReciveMsg() {
//		new Thread(
//				new Runnable() {
//					public void run() {
//						String line;
//						while(line = reader.readLine() != null) {
//							msgAble.dealMessage(line);
//						}
//					}
//				}
//				).start();
//			
//	}
	
	
	private void startReciveMsg()  {
		new Thread(
			new Runnable() {
				public void run() {
					try {
						String line;
						while((line=reader.readLine()) != null) {
							msgAble.dealMessage(line);
							//System.out.println(line);
						}
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
			).start();
	}
	
	public void colse() {
		try {
			socket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
}

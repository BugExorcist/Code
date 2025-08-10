package wangzhongxina.net;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Sever {
	private ServerSocket serverSocket;
	private InputStream in;
	private OutputStream out;
	private PrintWriter writer;
	private BufferedReader reader;
	private MessageAble messageAble;
	
	public Sever(int port, MessageAble messageAble) {
		this.messageAble = messageAble;
		try {
			serverSocket = new ServerSocket(port);
			Socket socket = serverSocket.accept();
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
	
	private void startReciveMsg()  {
		new Thread(
			new Runnable() {
				public void run() {
					try {
						String line;
						while((line=reader.readLine()) != null) {
							messageAble.dealMessage(line);
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
			serverSocket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
}

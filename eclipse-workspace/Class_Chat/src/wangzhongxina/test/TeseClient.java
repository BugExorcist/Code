package wangzhongxina.test;

import wangzhongxina.net.Client;

public class TeseClient {
	public static void main(String[] args) throws Exception {
		Client c = new Client("127.0.0.1", 1024); 
		for(int i = 0; i < 10; i++) {
			c.sendMessage("ClientMessage" + i);
			Thread.sleep(1000);
		}
	}
}

package wangzhongxina.test;

import wangzhongxina.net.Sever;

public class Test {
	public static void main(String[] args) throws Exception {
		Sever s = new Sever(1024);
		for(int i = 0; i < 10; i++) {
			s.sendMessage("SeverMessage" + i);
			Thread.sleep(1000);
		}
	}
	
	
	
}

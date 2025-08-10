package wangzhongxian.alg;

import java.math.BigInteger;

import wangzhongxian.ui.Logable;

public class Calculate extends Thread{
	private int n;
	private Logable logable;
	public Calculate(int n, Logable logable) {
		this.n = n;
		this.logable = logable;
	}

	private void calculate() {
		BigInteger result = BigInteger.valueOf(1);
		BigInteger sum= BigInteger.valueOf(0);
		StringBuilder sb=new StringBuilder();
		for(int i = 1; i <= n; i++) {
			try {
				result = result.multiply(BigInteger.valueOf(i));
				sum=sum.add(result);
				sb.append((i==1?"":"+")+i+"!");
				//System.out.println((sb.toString()+"="+sum));
				logable.log(sb.toString()+"="+sum);
				Thread.sleep((int)(500+Math.random()*500));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	
	
	public void run() {
		calculate();
		
	}

//	public static void main(String[] args) {
//		Calculate ca=new Calculate(20);
//		ca.start();
//	}
}

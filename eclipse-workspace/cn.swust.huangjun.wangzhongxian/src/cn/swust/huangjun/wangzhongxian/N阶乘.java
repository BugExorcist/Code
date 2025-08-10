package cn.swust.huangjun.wangzhongxian;

import java.util.Scanner;
public class N阶乘 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("请输入一个正整数求阶乘：");
		int n = scanner.nextInt();
		
		System.out.print("While的结果是："+ While(n)+"\n");
		System.out.print("Do While的结果是："+ DoWhile(n)+"\n");
		System.out.print("For的结果是："+ For(n)+"\n");
	}
	
	public static int While(int n) {
		int i = 1;
		int total = 1;
		while(i <= n){
			total *= i;
			i++;
		}
		return total;
	}
	
	public static int DoWhile(int n) {
		int i = 1;
		int total = 1;
		do {
			total *= i;
			i++;
		}while(i <= n);
		return total;
	}
	
	public static int For(int n) {
		int total = 1;
		for(int i = 1; i <= n; i++){
			total *= i;
		}
		return total;
	}
}

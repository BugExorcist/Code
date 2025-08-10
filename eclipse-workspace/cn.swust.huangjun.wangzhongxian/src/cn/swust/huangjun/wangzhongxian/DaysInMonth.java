package cn.swust.huangjun.wangzhongxian;

import java.util.Scanner;
public class DaysInMonth {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int[] moon_list = {31,28,31,30,31,30,31,31,30,31,30,31};
		System.out.print("请输入年份和月份， 空格隔开：");
		int year = scanner.nextInt();
		int mooth = scanner.nextInt();
		
		if(mooth == 2 && isLeepYear(year)) {
			System.out.print(moon_list[mooth - 1] + 1);
		}
		else {
			System.out.print(moon_list[mooth - 1]);
		}
		
	}
	
	public static boolean isLeepYear(int year) {
		if(year % 100 != 0 && year % 4 == 0 || year % 400 == 0) {
			return true;
		}
		return false;
	}

}

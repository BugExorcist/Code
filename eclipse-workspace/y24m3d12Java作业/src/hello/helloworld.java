package hello;

public class helloworld {
    public static void main(String[] args) {
    	//处理byte类型
//		System.out.println("byte的bit数:"+Byte.SIZE);
//		System.out.println("byte的字节数："+Byte.BYTES);
//		System.out.println("最大值："+Byte.MAX_VALUE);
//		System.out.println("最小值："+Byte.MIN_VALUE);
//		/*处理short类型*/
//		System.out.println("short的bit数:"+Short.SIZE);
//		System.out.println("short的字节数："+Short.BYTES);
//		System.out.println("最大值："+Short.MAX_VALUE);
//		System.out.println("最小值："+Short.MIN_VALUE);
//		int a=0;
//		System.out.println("int的bit数:"+Integer.SIZE);
//		System.out.println("int的字节数："+Integer.BYTES);
//		System.out.println("最大值："+Integer.MAX_VALUE);
//		System.out.println("最小值："+Integer.MIN_VALUE);
//		
//		System.out.println("long的bit数:"+Long.SIZE);
//		System.out.println("long的字节数："+Long.BYTES);
//		System.out.println("最大值："+Long.MAX_VALUE);
//		System.out.println("最小值："+Long.MIN_VALUE);
//		
//		System.out.println("folat的bit数:"+Float.SIZE);
//		System.out.println("folat的字节数："+Float.BYTES);
//		System.out.println("最大值："+Float.MAX_VALUE);
//		System.out.println("最小值："+Float.MIN_VALUE);
//		
//		System.out.println("double的bit数:"+Double.SIZE);
//		System.out.println("double的字节数："+Double.BYTES);
//		System.out.println("最大值："+Double.MAX_VALUE);
//		System.out.println("最小值："+Double.MIN_VALUE);
//		
//		System.out.println("char的bit数:"+Character.SIZE);
//		System.out.println("char的字节数："+Character.BYTES);
//		System.out.println("最大值："+(int)Character.MAX_VALUE);
//		System.out.println("最小值："+(int)Character.MIN_VALUE);
//		
    	String str = toString(41656461.13);
		System.out.println(str);
    }
    
    public static String toString(double x) {
    	String result ="";
    	String yvan = "亿千百拾万千百拾元角分";
    	String digit = "零壹贰叄肆伍陆柒捌玖";
    	int y = (int)(x*100);
    	for(int i = yvan.length()-1; y > 0 && i >= 0; i--) {
    		result=""+digit.charAt(y%10)+yvan.charAt(i) + result;
    		y /= 10;
    	}
    	return result;
    }
}










package cn.swust.huangjun.wangzhongxian;

public class Main {  
    public static void main(String[] args) {  
        ComplexNumber c1 = new ComplexNumber(1, 2);  
        ComplexNumber c2 = new ComplexNumber(3, 4);  
  
        System.out.println("c1: " + c1);  
        System.out.println("c2: " + c2);  
  
        ComplexNumber sum = c1.add(c2);  
        System.out.println("c1 + c2: " + sum);  
  
        ComplexNumber difference = c1.subtract(c2);  
        System.out.println("c1 - c2: " + difference);  
  
        ComplexNumber product = c1.multiply(c2);  
        System.out.println("c1 * c2: " + product);  
  
        ComplexNumber quotient = c1.divide(c2);  
        System.out.println("c1 / c2: " + quotient);  
    }  
}
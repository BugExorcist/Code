package cn.swust.huangjun.wangzhongxian;

public class ComplexNumber {  
    private double real; // 实数部分  
    private double imaginary; // 虚数部分  
  
    // 构造函数  
    public ComplexNumber(double real, double imaginary) {  
        this.real = real;  
        this.imaginary = imaginary;  
    }  
  
    // 获取实数部分  
    public double getReal() {  
        return real;  
    }  
  
    // 获取虚数部分  
    public double getImaginary() {  
        return imaginary;  
    }  
  
    // 复数加法  
    public ComplexNumber add(ComplexNumber other) {  
        double newReal = this.real + other.real;  
        double newImaginary = this.imaginary + other.imaginary;  
        return new ComplexNumber(newReal, newImaginary);  
    }  
  
    // 复数减法  
    public ComplexNumber subtract(ComplexNumber other) {  
        double newReal = this.real - other.real;  
        double newImaginary = this.imaginary - other.imaginary;  
        return new ComplexNumber(newReal, newImaginary);  
    }  
  
    // 复数乘法  
    public ComplexNumber multiply(ComplexNumber other) {  
        double newReal = this.real * other.real - this.imaginary * other.imaginary;  
        double newImaginary = this.real * other.imaginary + this.imaginary * other.real;  
        return new ComplexNumber(newReal, newImaginary);  
    }  
  
    // 复数除法
    public ComplexNumber divide(ComplexNumber other) {  
        double denominator = other.real * other.real + other.imaginary * other.imaginary;  
        double newReal = (this.real * other.real + this.imaginary * other.imaginary) / denominator;  
        double newImaginary = (this.imaginary * other.real - this.real * other.imaginary) / denominator;  
        return new ComplexNumber(newReal, newImaginary);  
    }  
  
    // 重写toString方法，方便打印复数  
    public String toString() {  
        if (imaginary < 0) {  
            return real + " - " + (-imaginary) + "i";  
        } else {  
            return real + " + " + imaginary + "i";  
        }  
    }  
}
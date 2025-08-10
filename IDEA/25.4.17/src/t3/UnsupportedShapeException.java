package t3;

// 自定义异常类
public class UnsupportedShapeException extends Exception {
    public UnsupportedShapeException(String message) {
        super(message);
    }
}
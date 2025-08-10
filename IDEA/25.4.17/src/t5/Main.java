package t5;

public class Main {
    public static void main(String[] args) {
        String format = "gif"; // 假设我们需要根据某种逻辑确定图片格式

        ImageReaderFactory factory;
        if (format.equalsIgnoreCase("gif")) {
            factory = new GifReaderFactory();
        } else if (format.equalsIgnoreCase("jpg")) {
            factory = new JpgReaderFactory();
        } else {
            throw new IllegalArgumentException("Unsupported image format: " + format);
        }

        factory.readImage();
    }
}
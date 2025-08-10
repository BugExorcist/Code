package t5;

// JPG图片读取器工厂
public class JpgReaderFactory extends ImageReaderFactory {
    @Override
    public ImageReader createImageReader() {
        return new JpgReader();
    }
}

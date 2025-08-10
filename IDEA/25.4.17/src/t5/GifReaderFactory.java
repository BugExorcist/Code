package t5;

// GIF图片读取器工厂
public class GifReaderFactory extends ImageReaderFactory {
    @Override
    public ImageReader createImageReader() {
        return new GifReader();
    }
}


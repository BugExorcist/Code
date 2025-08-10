package t5;

public abstract class ImageReaderFactory {
    public abstract ImageReader createImageReader();

    public void readImage() {
        ImageReader reader = createImageReader();
        reader.read();
    }
}

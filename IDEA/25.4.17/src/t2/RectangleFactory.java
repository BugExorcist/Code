package t2;

public class RectangleFactory implements ShapeFactory {
    @Override
    public IShape createShape() {
        return new Rectangle();
    }
}

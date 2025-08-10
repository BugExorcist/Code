package t2;

public class TriangleFactory implements ShapeFactory {
    @Override
    public IShape createShape() {
        return new Triangle();
    }
}

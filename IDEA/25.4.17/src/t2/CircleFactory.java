package t2;

public class CircleFactory implements ShapeFactory {
    @Override
    public IShape createShape() {
        return new Circle();
    }
}


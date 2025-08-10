package t3;

// 形状工厂类
public class ShapeFactory {
    public static IShape createShape(String type) throws UnsupportedShapeException {
        switch (type.toLowerCase()) {
            case "circle":
                return new Circle();
            case "rectangle":
                return new Rectangle();
            case "triangle":
                return new Triangle();
            default:
                throw new UnsupportedShapeException("Shape '" + type + "' is not supported.");
        }
    }
}
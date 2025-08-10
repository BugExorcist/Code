package t3;

public class Main {
    public static void main(String[] args) {
        try {
            IShape shape = ShapeFactory.createShape("Circle");
            shape.draw();
            shape.erase();

            // 尝试创建一个不支持的菱形
            IShape rhombus = ShapeFactory.createShape("rhombus");
        } catch (UnsupportedShapeException e) {
            System.err.println(e.getMessage());
        }
    }
}
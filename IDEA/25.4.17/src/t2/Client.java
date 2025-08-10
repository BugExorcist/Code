package t2;

import java.awt.*;

public class Client {
    private IShape shape;

    public Client(ShapeFactory factory) {
        this.shape = factory.createShape();
    }

    public void setShapeColor(Color color) {
        shape.setColor(color);
    }

    public void setShapeFill(Color color) {
        shape.fill(color);
    }

    public void setShapeSize(int size) {
        shape.setSize(size);
    }

    public void displayShape() {
        shape.display();
    }
}
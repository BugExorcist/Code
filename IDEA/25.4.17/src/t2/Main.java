package t2;

import java.awt.*;

public class Main {
    public static void main(String[] args) {
        Client client = new Client(new CircleFactory());
        client.setShapeColor(Color.BLUE);
        client.setShapeFill(Color.RED);
        client.setShapeSize(100);
        client.displayShape();
    }
}
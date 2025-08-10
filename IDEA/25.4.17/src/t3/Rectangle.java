package t3;

public class Rectangle implements IShape {
    @Override
    public void draw() {
        System.out.println("Drawing a Rectangle.");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a Rectangle.");
    }
}

package t3;

// 三角形类
public class Triangle implements IShape {
    @Override
    public void draw() {
        System.out.println("Drawing a Triangle.");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a Triangle.");
    }
}
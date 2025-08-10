package t3;

// 圆形类
public class Circle implements IShape {
    @Override
    public void draw(){
        System.out.println("Drawing a Circle.");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a Circle.");
    }
}
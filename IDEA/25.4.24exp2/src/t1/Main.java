package t1;

public class Main {
    public static void main(String[] args) {
        // 创建不同颜色和大小的笔
        Pen blackSmallPen = new SmallPen(new Black());
        Pen redMiddlePen = new MiddlePen(new Blue());
        Pen blackLargePen = new LargePen(new Black());

        // 使用笔
        blackSmallPen.draw();
        redMiddlePen.draw();
        blackLargePen.draw();
    }
}

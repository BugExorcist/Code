package t1;

public abstract class Pen {
    protected Color color;

    public Pen(Color color) {
        this.color = color;
    }

    public abstract void draw();
}
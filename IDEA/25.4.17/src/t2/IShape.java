package t2;

import java.awt.*;

public interface IShape {
    void init();
    void setColor(Color color);
    void fill(Color color);
    void setSize(int size);
    void display();
}
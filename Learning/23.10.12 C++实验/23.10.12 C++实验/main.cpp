#include "Canvas.h"

int main() {
    Canvas canvas;

    canvas.addCircle(50, 50, 30, 1, RED);
    canvas.addCircle(100, 100, 20, 2, BLUE);
    canvas.addEllipse(130, 60, 300, 150, 3, YELLOW);
    canvas.addRectangle(300, 200, 100, 100, 2, MAGENTA);
    canvas.addRectangle(5, 5, 250, 300, 1, WHITE);

    canvas.displayShapes();
    canvas.drawShapes();

    
    return 0;
}
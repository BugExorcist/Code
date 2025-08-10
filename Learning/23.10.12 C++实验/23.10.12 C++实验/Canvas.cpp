#include "Canvas.h"

void Canvas::addCircle(double x, double y, double r, double lw, COLORREF lf) {
    Shape* shape = new myCircle(x, y, r, lw, lf);
    shapes.push_back(shape);
}

void Canvas::addEllipse(double x, double y, double rx, double ry, double lw, COLORREF lf) {
    Shape* shape = new myEllipse(x, y, rx, ry, lw, lf);
    shapes.push_back(shape);
}

void Canvas::addRectangle(double x, double y, double w, double h, double lw, COLORREF lf) {
    Shape* shape = new myRectangle(x, y, w, h ,lw, lf);
    shapes.push_back(shape);
}

void Canvas::displayShapes() const {
    for (const auto& shape : shapes) {
        shape->display();
        cout << endl;
    }
}
void Canvas::drawShapes() const {
    initgraph(640, 480);
    for (const auto& shape : shapes) {
        shape->draw();
    }
    getchar();
    closegraph();
}

Canvas::~Canvas() {
    for (const auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();
}
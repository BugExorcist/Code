package t1;

class SmallPen extends Pen {
    public SmallPen(Color color) {
        super(color);
    }

    @Override
    public void draw() {
        System.out.println("用 " + color.getColor() + " Small Pen");
    }
}

class MiddlePen extends Pen {
    public MiddlePen(Color color) {
        super(color);
    }

    @Override
    public void draw() {
        System.out.println("用 " + color.getColor() + " Middle Pen");
    }
}

class LargePen extends Pen {
    public LargePen(Color color) {
        super(color);
    }

    @Override
    public void draw() {
        System.out.println("用 " + color.getColor() + " Large Pen");
    }
}



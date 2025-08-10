package cn.swust.wangzhongxian.exp;

import java.awt.Graphics;
import java.awt.Point;

public class Eclipse extends ClosedFigure{
	private int width;
	private int heigth;
	
	@Override
	public double area() {
		return Math.PI*width*heigth/4;
	}

	@Override
	public double perimeter() {
		double a = Math.max(width, heigth)/2;
		double b = Math.min(width, heigth)/2;
		return 2*Math.PI*b+4*(a - b);
	}

	@Override
	public void drawFiguer(Graphics g) {
		g.setColor(getColor());
		int x = Math.min(getStart().x, getEnd().x);
		int y = Math.min(getStart().y, getEnd().y);
		g.drawArc(x, y, width, heigth, 0, 360);
	}

	@Override
	public void setEnd(Point end) {
		super.setEnd(end);
		this.width = Math.abs(getEnd().x - getStart().x);
		this.heigth = Math.abs(getEnd().y - getStart().y);
	}

}

package cn.swust.wangzhongxian.exp;

import java.awt.Graphics;
import java.awt.Point;

public class Rectangle extends ClosedFigure{
	private int width;
	private int heigth;
	
	@Override
	public double area() {
		return width * heigth;
	}

	@Override
	public double perimeter() {
		return (width + heigth)*2;
	}

	@Override
	public void drawFiguer(Graphics g) {
		g.setColor(getColor());
		
		int x = Math.min(getStart().x, getEnd().x);
		int y = Math.min(getStart().y, getEnd().y);
		g.drawRect(x, y, width, heigth);
	}

	@Override
	public void setEnd(Point end) {
		super.setEnd(end);
		this.width = Math.abs(getEnd().x - getStart().x);
		this.heigth = Math.abs(getEnd().y - getStart().y);
	}

}

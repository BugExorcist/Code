package cn.swust.wangzhongxian.exp;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;

public abstract class Figure {
	private Color color = Color.BLACK;
	private Point start;
	private Point end;
	
	public abstract void drawFiguer(Graphics g);
	public Color getColor() {
		return color;
	}
	public void setColor(Color color) {
		this.color = color;
	}
	public Point getStart() {
		return start;
	}
	public void setStart(Point start) {
		this.start = start;
	}
	public Point getEnd() {
		return end;
	}
	public void setEnd(Point end) {
		this.end = end;
	}
}

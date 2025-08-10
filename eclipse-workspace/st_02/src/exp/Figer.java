package exp;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;

public abstract class Figer {
	private Color color;
	private Point p1;
	private Point P2;
	
	public abstract void drawFiger(Graphics i);
	public Color getColor() {
		return color;
	}
	public void setColor(Color color) {
		this.color = color;
	}
	public Point getP1() {
		return p1;
	}
	public void setP1(Point p1) {
		this.p1 = p1;
	}
	public Point getP2() {
		return P2;
	}
	public void setP2(Point p2) {
		P2 = p2;
	}
	
	
}

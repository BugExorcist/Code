package cn.swust.wangzhongxian.exp;

import java.awt.Graphics;
import java.awt.Point;

public class Triangle extends ClosedFigure{
	private Point topPoint;
	private Point leftPoint;
	private Point rightPoint;
	
	private double l1;//三条边长
	private double l2;
	private double l3;
	
	@Override
	public double area() {
		double s = (l1 + l2 + l3)/2;
		return Math.sqrt(s*(s - l1) * (s - l2) * (s - l3));
	}
	@Override
	public double perimeter() {
		return l1 + l2 + l3;
	}
	@Override
	public void drawFiguer(Graphics g) {
		g.setColor(getColor());
		g.drawLine(topPoint.x,topPoint.y, leftPoint.x, leftPoint.y);
		g.drawLine(leftPoint.x, leftPoint.y, rightPoint.x, rightPoint.y);
		g.drawLine(rightPoint.x, rightPoint.y, topPoint.x, topPoint.y);
	}
	
	public void  setPoint(Point topPoint, Point leftPoint, Point rightPoint) {
		this.topPoint = topPoint;
		this.leftPoint = leftPoint;
		this.rightPoint = rightPoint;
		
		l1 = Math.sqrt(Math.pow((topPoint.x - leftPoint.x),2)+Math.pow((topPoint.y - leftPoint.y),2));
		l2 = Math.sqrt(Math.pow((topPoint.x - rightPoint.x),2)+Math.pow((topPoint.y - rightPoint.y),2));
		l3 = Math.sqrt(Math.pow((leftPoint.x - rightPoint.x),2)+Math.pow((leftPoint.y - rightPoint.y),2));
	}
	
}

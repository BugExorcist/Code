package exp;

import java.awt.Graphics;
import java.awt.Point;
import java.awt.geom.AffineTransform;

import interf.area;
import interf.zhouchang;

public class Rectangle extends Figer implements area, zhouchang{

	@Override
	public double zhouchang() {
		Point start = this.getP1();
		Point end= this.getP2();
		
		double ans= (Math.abs(start.x - end.x) + Math.abs(start.y - end.y)) * 2;
		return ans;
	}

	@Override
	public double area() {
		Point start = this.getP1();
		Point end= this.getP2();
		
		double ans= Math.abs(start.x - end.x) * Math.abs(start.y - end.y);
		return ans;
	}

	@Override
	public void drawFiger(Graphics i) {
		Point start = this.getP1();
		Point end= this.getP2();
		i.setColor(this.getColor());
		
		i.drawRect(start.x, start.y, end.x-start.x, end.y-start.y);
	}

}

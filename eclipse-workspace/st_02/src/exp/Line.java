package exp;

import java.awt.Graphics;
import java.awt.Point;

import interf.length;

public class Line extends Figer implements length{

	@Override
	public void drawFiger(Graphics i) {
		i.setColor(this.getColor());
		Point start = this.getP1();
		Point end = this.getP2();
		
		i.drawLine(start.x, start.y, end.x , end.y);
	}

	@Override
	public double length() {
		Point start = this.getP1();
		Point end = this.getP2();
		
		double ans= Math.sqrt(Math.pow(start.x - end.x, 2)+Math.pow(start.y - end.y, 2));
		return ans;
	}
	
	

}

package cn.swust.wangzhongxian.exp;

import java.awt.Graphics;
import java.awt.Point;
import cn.swust.wangzhongxian.exp.interf.Lengthable;

public class Line extends Figure implements Lengthable{

	@Override
	public void drawFiguer(Graphics g) {
		g.setColor(this.getColor());
		Point startPoint = this.getStart();
		Point endPoint = this.getEnd();
		
		g.drawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
	}
	
	@Override
	public double length() {
		Point startPoint = this.getStart();
		Point endPoint = this.getEnd();
		
		return Math.sqrt(Math.pow((endPoint.x - startPoint.x),2)+Math.pow((endPoint.y - startPoint.y),2));
	}
	
	
}

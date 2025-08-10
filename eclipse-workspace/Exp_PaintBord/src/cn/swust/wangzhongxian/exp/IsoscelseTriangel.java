package cn.swust.wangzhongxian.exp;

import java.awt.Point;

public class IsoscelseTriangel extends Triangle{
	
	@Override
	public void setEnd(Point endPoint) {
		super.setEnd(endPoint);
		Point startPoint = getStart();
		
		int x1 = Math.min(startPoint.x, endPoint.x);
		int y1 = Math.min(startPoint.y, endPoint.y);
		
		int x2 = Math.max(startPoint.x, endPoint.x);
		int y2 = Math.max(startPoint.y, endPoint.y);
		
		Point topPoint = new Point((x1+x2)/2, y1);
		Point leftPoint = new Point(x1,y2);
		Point rightPoint = new Point(x2,y2);
		
		setPoint(topPoint, leftPoint, rightPoint);
	}
}

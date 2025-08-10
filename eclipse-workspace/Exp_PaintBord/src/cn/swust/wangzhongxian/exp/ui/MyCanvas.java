package cn.swust.wangzhongxian.exp.ui;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.List;
import java.util.Properties;
import java.util.ArrayList;
import javax.imageio.ImageIO;
//import java.util.Map;
//import java.util.HashMap;

import cn.swust.wangzhongxian.exp.Figure;
/*import cn.swust.wangzhongxian.exp.IsoscelseTriangel;
import cn.swust.wangzhongxian.exp.Line;
import cn.swust.wangzhongxian.exp.Eclipse;
import cn.swust.wangzhongxian.exp.Rectangle;
import cn.swust.wangzhongxian.exp.RightTriangel;*/

import cn.swust.wangzhongxian.exp.interf.Areable;
import cn.swust.wangzhongxian.exp.interf.Lengthable;
import cn.swust.wangzhongxian.exp.interf.Perimeterable;

public class MyCanvas extends Canvas{
	List<Figure> figs = new ArrayList<>();
	private Figure fig;
	static Properties config;
	
	static {
		try {
			config = new Properties();
			config.load(MyCanvas.class.getResourceAsStream("config.properties"));
		} catch (IOException e) {
			System.out.println("读取文件失败");
			e.printStackTrace();
		}
		/*config.put("line", "cn.swust.wangzhongxian.exp.Line");
		config.put("rectangle", "cn.swust.wangzhongxian.exp.Rectangle");
		config.put("eclipse", "cn.swust.wangzhongxian.exp.Eclipse");
		config.put("isotriangel", "cn.swust.wangzhongxian.exp.IsoscelseTriangel");
		config.put("rigtriangel", "cn.swust.wangzhongxian.exp.RightTriangel");*/
	}
	private String figType = "rectangle";
	private Color color = Color.BLACK;
	public MyCanvas() {
		
		MouseAdapter mouseAdapter = new MouseAdapter() {
			@Override
			
			public void mousePressed(MouseEvent e) {
				try {
					//String className =config.get(figType); 
					String className =config.getProperty(figType); 
					Class clz = Class.forName(className);
					Constructor con = clz.getConstructor();
					fig =(Figure)con.newInstance();
				} catch (ClassNotFoundException | NoSuchMethodException | SecurityException | InstantiationException
						| IllegalAccessException | IllegalArgumentException | InvocationTargetException e1) {
					e1.printStackTrace();
				}
				
				/*switch (figType) {
					case "line": {
						fig = new Line();
						break;
					}
					case "rectangle": {
						fig = new Rectangle();
						break;
					}
					case "eclipse": {
						fig = new Eclipse();
						break;
					}
					case "isotriangel": {
						fig = new IsoscelseTriangel();
						break;
					}
					case "rigtriangel": {
						fig = new RightTriangel();
						break;
					}
				}*/
				fig.setColor(color);
				fig.setStart(new Point(e.getX(), e.getY()));
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				figs.add(fig);
			}

			@Override
			public void mouseDragged(MouseEvent e) {
				fig.setEnd(new Point(e.getX(), e.getY()));
				MyCanvas.this.repaint();
			}
		
		};
		
		this.addMouseListener(mouseAdapter);
		this.addMouseMotionListener(mouseAdapter);
	}


	@Override
	public void paint(Graphics g) {
		super.paint(g);//清空画布
		
		g.setColor(Color.WHITE);//设置背景白色
		g.fillRect(0, 0, getWidth(), getHeight());
		
		
		for(Figure fig : figs) {
			fig.drawFiguer(g);
		}
		if (fig!=null) {
			fig.drawFiguer(g);
			
			Point start = fig.getStart();
			Point end = fig.getEnd();
			StringBuilder sb = new StringBuilder();
			sb.append("起点：（"+start.x+","+start.y+"）");
			sb.append("|终点：（"+end.x+","+end.y+"）");
			
			if(fig instanceof Lengthable) {
				Lengthable la = (Lengthable) fig;
				sb.append("|长："+la.length());
			}
			if(fig instanceof Perimeterable) {
				Perimeterable pe = (Perimeterable)fig;
				sb.append("|周长："+pe.perimeter());
			}
			if(fig instanceof Areable) {
				Areable ar = (Areable)fig;
				sb.append("|面积："+ar.area());
			}
			
			g.setColor(Color.BLACK);
			g.drawString(sb.toString(), 10, getHeight()-10);
		}
		
	}

	public void setFigType(String figType) {
		this.figType = figType;
	}
	
	public void setColor(Color color) {
		this.color = color;
	}
	
	public void savePic(File file) {
		BufferedImage image= new BufferedImage(this.getWidth(), this.getHeight(), BufferedImage.TYPE_INT_BGR);
		Graphics g=image.createGraphics();

		this.paint(g);
		g.dispose();
		try {
			if(file.exists()) {
				file.createNewFile();
			}
			ImageIO.write(image, "jpg", file);
		} catch (IOException e) {
			//e.printStackTrace();
			System.out.println("写文件错误");
		}
		
	}

}

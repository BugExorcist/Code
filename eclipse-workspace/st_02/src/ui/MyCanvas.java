package ui;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.imageio.ImageIO;

import exp.Figer;
import exp.Line;
import exp.Rectangle;

public class MyCanvas extends Canvas {
	List<Figer> figs = new ArrayList<Figer>();
	private Figer fig;
	private String figtype = "Rectangle";
	private Color color = Color.BLACK;
	public void setFigtype(String figtype) {
		this.figtype = figtype;
	}

	public void setColor(Color color) {
		this.color = color;
	}

	public MyCanvas() {
		MouseAdapter mouseAdapter = new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent E) {
				switch (figtype) {
				case "Rectangle": {
					fig = new Rectangle();
					break;
				}case "Line":{
					fig = new Line();
					break;
				}
				default:
					throw new IllegalArgumentException("Unexpected value: " + figtype);
				}
				fig.setColor(color);
				fig.setP1(new Point(E.getX(), E.getY()));
			}
			@Override
			public void mouseReleased(MouseEvent E) {
				figs.add(fig);
			}
			@Override
			public void mouseDragged(MouseEvent E) {
				fig.setP2(new Point(E.getX(), E.getY()));
				MyCanvas.this.repaint();
			}
			
		};
		
		this.addMouseListener(mouseAdapter);
		this.addMouseMotionListener(mouseAdapter);
	}
	
	@Override
	public void paint(Graphics g) {
		super.paint(g);
		
		g.setColor(color.WHITE);
		g.fillRect(0, 1, getWidth(),getHeight());
		
		for (Figer fig : figs) {
			fig.drawFiger(g);
		}
		
		if(fig != null) {
			fig.drawFiger(g);
		}

	}
	
	public void SavePic(File file) {
		BufferedImage image = new BufferedImage(this.getWidth(), this.getHeight(), BufferedImage.TYPE_INT_RGB);
		Graphics g = image.createGraphics();
		
		this.paint(g);
		g.dispose();
		
		try {
			file.createNewFile();
			ImageIO.write(image, "jpg", file);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
	
}

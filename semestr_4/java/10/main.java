import java.applet.*;
import java.awt.*;
import java.util.*;
import java.awt.event.*; 

public class main extends Applet implements AdjustmentListener 
{

   int width, height;

   public void init() {

	Scrollbar sb=new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 255); 
	sb.setLocation(0 ,0); 
	add(sb);
	  resize(640,480);
      width = 400;
      height = 400;
      setBackground( Color.black );


	  

}

   public void paint( Graphics g ) {
	  
      g.setColor( Color.green );
		Plyta a=new Plyta();
		Plyta b=new Plyta();
		a.SetPos(100,50);
		b.SetPos(400,50);
   		a.paint(g);
		b.paint(g);
		Biedronka c,d;
		Biedronka.speed=1;
		c=new Biedronka();
		d=new Biedronka();
		c.Once();
		c.SetPos(100+100,50+100);
		d.SetPos(400+100,50+100);
		int x=0;
		boolean quit=false;
		while(true)
		{
			x=10;
			c.paint(g);
			d.paint(g);
			c.Rot(x);
			d.Rot(x);
			try
			{
				Thread.sleep(100);
			}
			catch(Exception e)
			{
			};
			c.Step();
			d.Step();
		}
   }
   public void adjustmentValueChanged(AdjustmentEvent e)
   {

         repaint( ); 

		 } 
}
class Plyta
{
	public void SetPos(int x,int y)
	{
		itsX=x;
		itsY=y;
	};
	public void paint(Graphics g)
	{
		g.setColor(Color.green);
		g.fillOval(itsX,itsY,200,200);
	};
	int itsX,itsY;
};
class Biedronka
{
	public void Once()
	{
		itsOnce=true;
	};
	public void SetPos(int x,int y)
	{
		itsStartX=x;
		itsStartY=y;
	};
	public void Step()
	{
		itsR+=speed;
		itsX=itsR*(float)Math.cos(itsRot*3.14/180);
		itsY=itsR*(float)Math.sin(itsRot*3.14/180);
//		itsX+=Math.cos(itsRot*3.14/180);
//		itsY+=Math.sin(itsRot*3.14/180);
		if(itsOnce) itsRot=0;
	};
	public void Rot(int angle)
	{
		itsRot+=angle;
	};
	public void paint(Graphics g)
	{
		g.setColor(Color.red);
		g.fillOval((int)(1*itsX+itsStartX),(int)(1*itsY+itsStartY),2,2);
	};
	float itsX;
	float itsY;
	float itsStartX;
	float itsStartY;
	float itsR;
	float itsRot;
	boolean itsOnce;
	static float speed;
};

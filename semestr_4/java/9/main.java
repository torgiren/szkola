public class main
{
	public static void main(String[] args)
	{
		System.out.println(args[0]);
		int watki=(int)Double.parseDouble(args[0]);
		//Watek wat[Double.parseDouble(args[0])];
//		Watek wat[Double.parseDouble(args[0])];
		Watek wat[]=new Watek[watki];
		int x=0;
		int y=0;
		for(y=0;y<watki;y++)
		{
			wat[y]=new Watek();
			wat[y].SetStart(x++);
			wat[y].start();
		};
		boolean quit=false;
		while(!quit)
		{
			for(y=0;y<watki;y++)
			{
				if(x>=100)
				{
					quit=true;
					break;
				}
				if(!wat[y].isAlive())
				{
					wat[y]=new Watek();
					wat[y].SetStart(x++);
					wat[y].start();
				};
			};
		};
		for(y=0;y<watki;y++)
		{
			try
			{
				if(wat[y].isAlive()) wat[y].join();
			}
			catch(Exception e)
			{
			};
		};
		System.out.println("Wynik to: "+Watek.suma+"\n");
	};
};
class Watek extends Thread
{
	public static void Watek()
	{
	};
	public void SetStart(int x)
	{
		itsX=x;
	};
	public void run()
	{
		System.out.println("Przedzial: "+itsX+" - "+(itsX+1));
		double x=0;
		double sum=0;
		double dokladnosc=10000000;
		for(x=0;x<dokladnosc+1;x++)
		{
//			sum+=(1/x)*(((itsX+x/5)*(itsX+x/5)*(itsX+5/x)-10*((itsX+x/5)*(itsX+5/x))+2)/((itsX+x/5)*(itsX+5/x)+1));
			sum+=(1/dokladnosc)*f(itsX+x/dokladnosc);
		};
		suma+=sum;
	};
	double f(double x)
	{
		return ((itsX*itsX*itsX)-10*(itsX*itsX)+2)/((itsX)*(itsX)+1);
	};
	private double itsX;
	static double suma=0;
};

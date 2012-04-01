class ThreadT extends Thread
{
	public void run()
	{
		for(int i = 0;i<100;i++)
		{
			System.out.println("1: " + i);
		}
	}
}
class ThreadR implements Runnable
{
	public void run()
	{
		for(int i = 0;i<100;i++)
		{
			System.out.println("2: " + i);
		}
	}
}
public class Main
{
	public static void main(String[] args)
	{
		ThreadT T = new ThreadT();
		ThreadR R = new ThreadR();
		Thread w = new Thread(R);
		T.start();
		w.start();         
		} 
}

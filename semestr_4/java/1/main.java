import java.io.*;
public class main
{	
	static int sizeX=50,sizeY=20;
	static int holeX=10;
	static char tab[][]=new char[sizeX][sizeY];
	static int x=0;
	public static void main(String [] args)
	{
		MakeWalls();
		BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
		boolean quit=false;
		while(x<200)
		{
//			PrintMap();
/*
		try
			{
				String input=stdin.readLine();
				if(input.equals("q")) quit=true;
				if(input.equals("s")) Step();
				if(input.equals("i")) InsertSeed();
			}
			catch(Throwable e)
			{
				System.out.println("blad");
			};
		};
*/
		x++;
		InsertSeed();
		Step();
		Step();
		Step();
		Step();
		PrintMap();
//		Step();
		};
	};
	static void PrintMap()
	{
		int x,y;
		for(y=0;y<sizeY;y++)
		{
			for(x=0;x<sizeX;x++)
			{
				System.out.print(tab[x][y]);
			};
			System.out.println();
		};
		
	};
	static void MakeWalls()
	{
		int x=0,y=0;
		for(y=0;y<sizeY;y++)
		{
			for(x=0;x<sizeX;x++)
			{
				tab[x][y]=' ';
			};
		};
		for(x=0;x<sizeX;x++)
		{
			tab[x][sizeY-1]='-';
			tab[x][0]='-';
		};
		for(y=0;y<sizeY;y++)
		{
			tab[0][y]='|';
			tab[sizeX-1][y]='|';
		};
		tab[holeX][0]=' ';
	};
	static void InsertSeed()
	{
		tab[holeX][1]='*';
	};
	static void Step()
	{
		int x,y;
		for(y=sizeY-2;y>0;y--)
		{
			for(x=1;x<sizeX-2;x++)
			{
				if(tab[x][y]=='*')
				{
					if(tab[x][y+1]==' ')
					{
						tab[x][y]=' ';
						tab[x][y+1]='*';
					}
					else
					{
						if(tab[x-1][y+1]==' ')
						{
							tab[x][y]=' ';
							tab[x-1][y+1]='*';
						}
						else if(tab[x+1][y+1]==' ')
						{
							tab[x][y]=' ';
							tab[x+1][y+1]='*';
						}
					};

				};
			};
		};
	};
}

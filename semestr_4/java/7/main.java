import java.io.*;
import java.lang.*;
import java.util.*;
public class main
{
	public static void main(String args[])
	{
		ArrayList<pair> lista=new ArrayList<pair>();
		System.out.println("Wczytywanie slownika...");
		try
		{
			FileReader read=new FileReader("ang-pol.dic");
			BufferedReader buf=new BufferedReader(read);
			String linia;
			while((linia=buf.readLine())!=null)
			{
				pair tmp=new pair();
				tmp.itsPol=linia.split(" ")[0];
				tmp.itsAng=linia.split(" ")[1];
				lista.add(tmp);
			}
			read.close();
		}
		catch(Exception wyj)
		{
			System.out.println(wyj.toString());
		};
		System.out.println("Wczytalem slownik");
		boolean quit=false;
		String cmd;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while(!quit)
		{
			try
			{
				System.out.println("*******************");
				cmd=in.readLine();
				if(cmd.compareTo("!quit")==0)
				{
					quit=true;
				}
				else if(cmd.compareTo("!add")==0)
				{
					pair tmp=new pair();
					System.out.println("Podaj polskie znaczenie: ");
					tmp.itsPol=in.readLine();
					System.out.println("Podaj angielskie znaczenie: ");
					tmp.itsAng=in.readLine();
					lista.add(tmp);
				}
				else if(cmd.compareTo("!remove")==0)
				{
					Iterator it=lista.iterator();	
					System.out.println("Podaj wyraz do usuniecia");
					cmd=in.readLine();
					while(it.hasNext())
					{
						pair tmp=(pair)it.next();
						if((tmp.itsPol.compareTo(cmd)==0) || (tmp.itsAng.compareTo(cmd)==0))
						{
							it.remove();
						};
					};
					
				}
				else if(cmd.compareTo("!all")==0)
				{
					Iterator it=lista.iterator();	
					while(it.hasNext())
					{
						pair tmp=(pair)it.next();
						System.out.println(tmp.itsPol+" - "+tmp.itsAng);
					};
				}
				else
				{
					Iterator it=lista.iterator();	
					while(it.hasNext())
					{
						pair tmp=(pair)it.next();
						if((tmp.itsPol.compareTo(cmd)==0) || (tmp.itsAng.compareTo(cmd)==0))
						{
							System.out.println(tmp.itsPol+" - "+tmp.itsAng);
						};
					};
				};
			}
			catch(Exception wyj)
			{
				System.out.println(wyj.toString());
			};
		};
		try
		{
			FileWriter write=new FileWriter("ang-pol.dic");
			Iterator it=lista.iterator();	
			while(it.hasNext())
			{
				pair tmp=(pair)it.next();
				write.write(tmp.itsPol+" "+tmp.itsAng+"\n");
			};
			write.close();

		}
		catch(Exception wyj)
		{
			System.out.println(wyj.toString());
		};

	};
};
class pair
{
	public String itsPol;
	public String itsAng;
};

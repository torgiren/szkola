import java.io.*;
import java.lang.*;
public class main
{
	public static void main(String[] args)
	{
		FileReader read;
		FileWriter write;
		BufferedReader buf;
		try
		{
			read=new FileReader(args[0]);
			buf=new BufferedReader(read);
			write=new FileWriter(args[1]);
			
			String linia;
			int x=0;
			while((linia=buf.readLine())!=null)
			{
				x++;
				String[] tab=new String[3];
				tab=linia.split(" ");
				Double a,b,c;
				a=Double.parseDouble(tab[0]);
				b=Double.parseDouble(tab[1]);
				c=Double.parseDouble(tab[2]);
				if(c==0) throw new Exception("Dzielenie przez zero w linijce: "+x);
				write.write(a+" "+(b/c)+"\n");
			};
			read.close();
			write.close();
		}
		catch(FileNotFoundException wyj)
		{
			System.out.println("Problem z plikiem");
			System.out.println(wyj.toString());
		}
		catch(ArrayIndexOutOfBoundsException wyj)
		{
			System.out.println("Nie podano parametrow");
			System.out.println(wyj.toString());
		}
		catch(NumberFormatException wyj)
		{
			System.out.println("Bledny format danych");
			System.out.println(wyj.toString());
		}
		catch(Exception wyj)
		{
			System.out.println(wyj.toString());
		};
	};
};

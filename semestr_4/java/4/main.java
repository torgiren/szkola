import java.io.*;
import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;

public class main
{
	public class Osoba
	{
		public void Osoba()
		{
		};
		String itsImie;
		String itsNazwisko;
	};
	public class Kontakt extends Osoba
	{
		public void Kontakt()
		{
		};
		String itsEmail;
	};
	private List<Kontakt> itsLista;
	private Kontakt osobnik;
	static public void main(String args[]) throws IOException
	{
		main a=new main();
		a.run();
	};

	public void run()  throws IOException
	{

		List<Kontakt> itsLista=new ArrayList<Kontakt>();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    String s;
	
		System.out.println("1: Dodaj\n2: Usub\n3: Znajdz\n4: Wyswietl\n5: Wyjdz");
	    while ((s = in.readLine()) != null )
		{
			if(s.compareTo(new String("1"))==0)
		  	{
				osobnik=new Kontakt();
				System.out.print("Podaj imie: ");
				s=in.readLine();
				osobnik.itsImie=new String(s);
				System.out.print("Podaj nazwisko: ");
				s=in.readLine();
				osobnik.itsNazwisko=new String(s);
				System.out.print("Podaj email: ");
				s=in.readLine();
				osobnik.itsEmail=new String(s);
				itsLista.add(osobnik);
			} else
			if(s.compareTo(new String("2"))==0)
			{
				System.out.println("Podaj id: ");
				s=in.readLine();
				itsLista.remove((int)Double.parseDouble(s));
			} else
			if(s.compareTo(new String("3"))==0)
			{
				System.out.println("Podaj nazwisko");
				s=in.readLine();
				Iterator it=itsLista.iterator();
				int x=0;
			 	while(it.hasNext())
			    {
					Kontakt ktos=(Kontakt)it.next();
					if(ktos.itsNazwisko.compareTo(s)==0)
					{
						System.out.println("Imie: "+ktos.itsImie);
						System.out.println("Nazwisko: "+ktos.itsNazwisko);
						System.out.println("Email: "+ktos.itsEmail);
						System.out.println("");
					}
				}
			} else
			if(s.compareTo(new String("4"))==0)
			{
				Iterator it=itsLista.iterator();
				int x=0;
			 	while(it.hasNext())
			    {
					Kontakt ktos=(Kontakt)it.next();
					System.out.println("Id; "+x++);
					System.out.println("Imie: "+ktos.itsImie);
					System.out.println("Nazwisko: "+ktos.itsNazwisko);
					System.out.println("Email: "+ktos.itsEmail);
					System.out.println("");
				}
			} else
			if(s.compareTo(new String("5"))==0)
			{
				break;
			};
			System.out.println("1: Dodaj\n2: Usub\n3: Znajdz\n4: Wyswietl\n5: Wyjdz");
		};
	};

};

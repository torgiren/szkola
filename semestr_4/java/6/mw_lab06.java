public class mw_lab06
 {
  public static void main(String[] args)
   {
    Stos<Integer> stos = new Stos<Integer>();
    stos.push(10);
    stos.push(20);
    System.out.println(stos);
    stos.push(30);
    stos.push(40);
    System.out.println(stos);
    stos.pop();
    stos.pop();
    System.out.println(stos);

    Stos<String> stos2 = new Stos<String>();
    stos2.push("a");
    stos2.push("b");
    System.out.println(stos2);
    stos2.push("c");
    stos2.push("d");
    System.out.println(stos2);
    stos2.pop();
    stos2.pop();
    System.out.println(stos2);
  }
}
class Stos<T>
{
	public void Stos()
	{
		itsHead=null;
	}
	public void push(T elem)
	{
		if(itsHead==null)
		{
			itsHead=new Element<T>();
			itsHead.itsData=elem;
		}
		else
		{
			Element<T> tmp=itsHead;
			while(tmp.itsNext!=null)
				tmp=tmp.itsNext;
			tmp.itsNext=new Element<T>();
			tmp=tmp.itsNext;
			tmp.itsData=elem;
		};
	};
	public void pop()
	{
		if(itsHead==null) return;
		Element<T> tmp=itsHead;
		while(tmp.itsNext.itsNext!=null)
			tmp=tmp.itsNext;
		tmp.itsNext=null;
	};
	public String toString()
	{
		String wynik="";
		Element<T> tmp=itsHead;
		if(itsHead==null) return "Pusto";
		while(tmp.itsNext!=null)
		{
			wynik+=tmp.itsData;
			wynik+=",";
			tmp=tmp.itsNext;
		};
		wynik+=tmp.itsData;

		return wynik;
	};
	private Element<T> itsHead;
}
class Element<T>
{
	public void Element()
	{
		itsNext=null;
	};
	public T itsData;
	public Element<T> itsNext;

}

import java.io.*;
import  java.net.*;
import java.util.*;
public class main
{
	public static void PrintMails(String line)
	{
			int start=line.indexOf("mailto:");
//			System.out.println(start);
			if(start!=-1)
			{
				int end=line.indexOf("\"",start);
				if(end!=-1)
				{
					System.out.println("Mail: "+line.substring(start+7,end));
				};
			};
	};
	public static BufferedReader OpenSite(String strona)
	{
		BufferedReader in=null;
		try
		{
//			System.out.println("mam adres "+strona);
			int x=strona.indexOf("/");
			InetAddress addr=null;
			if(x!=-1)
			{
				addr= InetAddress.getByName(strona.substring(0,x));
			}			
			else
			{
				addr = InetAddress.getByName(strona);
			};			
//			System.out.println("punkt posredni...");
			byte[] ipAddr = addr.getAddress();
			String ipAddrStr = "";
//			System.out.println("przetwarzanie domeny na ip");
	      	for (int i=0; i<ipAddr.length; i++)
		    {
					if (i > 0)
			{
				   	ipAddrStr += ".";
				}
				ipAddrStr += ipAddr[i]&0xFF;
			}
			System.out.println("Ip: "+ipAddrStr);
			sock=new Socket(ipAddrStr,80);
			DataOutputStream out=new DataOutputStream(sock.getOutputStream());
			in=new BufferedReader(new InputStreamReader(sock.getInputStream()));
			String cmd;
			cmd="GET / HTTP/1.1\nHost: "+strona+"\n\n";
			out.writeBytes(cmd);
		}
		catch(Exception e)
		{
			System.out.println("wyjatek: "+e);
		};
		return in;
	};
	public static void main(String argv[])
	{
		String line;
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		try
		{
			System.out.println("podaj strone: ");
			String strona=input.readLine();
			BufferedReader in=OpenSite(strona);
			List<String> adresy=new ArrayList<String>();
			while((line=in.readLine())!=null)
			{
//				System.out.println(line);
				PrintMails(line);
				int start=line.indexOf("http:");
//				System.out.println(start);
				if(start!=-1)
				{
					int end=line.indexOf("\"",start);
					if(end!=-1)
					{
//						System.out.println(line.substring(start,end));
//						if(line[end-1]=="/") end--;
						adresy.add(line.substring(start+7,end));
					};
				};
			};
			sock.close();
			
			Iterator it=adresy.iterator();

			while(it.hasNext())
        	{
          		String value=(String)it.next();
		        System.out.println("\tLink: "+value);
				in=OpenSite(value);
				while((line=in.readLine())!=null)
					PrintMails(line);
				sock.close();
        	}

		}
		catch(Exception e)
		{
			System.out.println("wyjatek w glownym: "+e);
		};

	};
	private static Socket sock;
};

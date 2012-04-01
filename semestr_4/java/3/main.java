import java.lang.Math;
import java.awt.*;
public class main extends javax.swing.JFrame {
    
    public main() {
        initComponents();
    }
	int CalcX(Double A,Double W1,Double T,Double V)
	{
		return (int)(100*A*Math.sin((W1*T+V)));
	};
	int CalcY(Double B,Double W2,Double T)
	{
		return (int)(100*B*Math.sin(W2*T));
	};
    public void paint(Graphics g)
	{
		g.clearRect(0,0,640,480);
		Double x,y,t,t1,t2,tstep,A,B,W1,W2,V;
		t1=Double.parseDouble(itsTextT1.getText());
		t2=Double.parseDouble(itsTextT2.getText());
		tstep=Double.parseDouble(itsTextStep.getText());
		W2=Double.parseDouble(itsTextW2.getText());
		W1=Double.parseDouble(itsTextW1.getText());
		A=Double.parseDouble(itsTextA.getText());
		B=Double.parseDouble(itsTextB.getText());
		V=Double.parseDouble(itsTextV.getText());
		t=t1;
			g.translate(200,300);
		while(t<t2)
		{
			
			int x1,x2,y1,y2;
			x1=CalcX(A,W1,t,V);
			x2=CalcX(A,W1,t+tstep,V);
			y1=CalcY(B,W2,t);
			y2=CalcY(B,W2,t+tstep);
			System.out.println(x1+" "+y1+" "+x2+" "+y2);
			if(itsLine.getState())
				g.drawLine(x1,y1,x2,y2);
			else
				g.drawLine(x1,y1,x1+1,y1+1);

			t=t+tstep;
			System.out.println(t);
		};

		System.out.println(tstep);
/*
                Insets b = getInsets();
                g.translate (b.left, b.top);
                g.drawLine( 20, 10, 70, 10);
                g.fillRect( 50,50 ,100, 70 );
                g.fillRoundRect( 50, 130, 50, 50, 20, 20 );
                int tabX [ ] = { 40, 60, 80 ,40 };
                int tabY [ ] = { 40, 20, 40 ,40 };
                int n = tabX.length;
                g.fillPolygon( tabX, tabY, n-1 );
                g.translate(100,300);
                g.drawPolyline(tabX, tabY, n);
//                g.translate(-100,0);
                g.drawOval( 200, 50, 50, 50 );
                g.fillOval( 280, 50, 70, 50 );

*/
	}

    private void initComponents() {

/*
	itsPolicz=new javax.swing.JButton();
	itsPlus=new javax.swing.JButton();
	itsMinus=new javax.swing.JButton();
	itsRazy=new javax.swing.JButton();
	itsPodzielic=new javax.swing.JButton();
	itsSin=new javax.swing.JButton();
	itsCos=new javax.swing.JButton();
	itsOperacja=new javax.swing.JLabel();
	itsRowne=new javax.swing.JLabel();
	itsWynik=new javax.swing.JLabel();
	itsPierwsza=new javax.swing.JTextField();
	itsDruga=new javax.swing.JTextField();
*/
        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Kalkulator");
        setSize(650, 480);
		setLocationRelativeTo(null);
		setLayout(null);

/*
	private TextField itsTextA,itsTextB,itsTextT1,itsTextT2,itsTextW1,itsTextW2,itsTextV,itsTextStep;
	private Label itsLabelA, itsLabelB,itsLabelT1,itsLabelT2,itsLabelW1,itsLabelW2,itsLabelV,itsLabelStep;
	private Checkbox itsLine;
	private Button itsRysuj;
*/	
	itsTextA=new TextField();
	itsTextB=new TextField();
	itsTextT1=new TextField();
	itsTextT2=new TextField();
	itsTextW1=new TextField();
	itsTextW2=new TextField();
	itsTextV=new TextField();
	itsTextStep=new TextField();
	itsTextLine=new TextField();
	itsRysuj=new Button();
	itsLine=new Checkbox();
	itsLabelA=new Label();
	itsLabelB=new Label();
	itsLabelT1=new Label();
	itsLabelT2=new Label();
	itsLabelW1=new Label();
	itsLabelW2=new Label();
	itsLabelV=new Label();
	itsLabelStep=new Label();


	itsLabelA.setText("A:");
	itsLabelB.setText("B:");
	itsLabelT1.setText("T1:");
	itsLabelT2.setText("T2:");
	itsLabelW1.setText("W1");
	itsLabelW2.setText("W2");
	itsLabelV.setText("V");
	itsLabelStep.setText("Step");
//	itsRysuj.setText("Rysuj");

//		itsPolicz.setText("Policz");
/*
		itsPlus.setText("+");
		itsMinus.setText("-");
		itsRazy.setText("*");
		itsPodzielic.setText("/");
		itsSin.setText("sin");
		itsCos.setText("cos");
		itsOperacja.setText("tu bedzie operacja");
		itsRowne.setText("=");
		itsWynik.setText("tu bedzie wynik");
		itsPierwsza.setText("pierwsza liczba");
		itsDruga.setText("druga liczba");

		itsPierwsza.setBounds(10,10,100,20);
		itsOperacja.setBounds(10,30,100,20);
		itsDruga.setBounds(10,50,100,20);
		itsRowne.setBounds(10,70,100,20);
		itsWynik.setBounds(10,90,100,20);
		itsPlus.setBounds(10,140,50,50);
		itsMinus.setBounds(70,140,50,50);
		itsRazy.setBounds(130,140,50,50);
		itsPodzielic.setBounds(190,140,50,50);
		itsCos.setBounds(130,190,100,50);
		itsSin.setBounds(10,190,100,50);

		itsPlus.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent evt) {
					Dodaj(evt);
				};
			});
		itsMinus.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent evt) {
					Odejmij(evt);
				};
			});
		itsRazy.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent evt) {
		//			Pomnoz(evt);
					repaint();
				};
			});
		itsPodzielic.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent evt) {
					Podziel(evt);
				};
			});
		itsSin.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent evt) {
					Sinusuj(evt);
				};
			});
		itsCos.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent evt) {
					Cosinusuj(evt);
				};
			});

		add(itsPierwsza);
		add(itsOperacja);
		add(itsDruga);
		add(itsWynik);
		add(itsCos);
		add(itsPlus);
		add(itsMinus);
		add(itsRazy);
		add(itsPodzielic);
		add(itsSin);
*/
		itsLabelA.setBounds(10,10,40,20);
		itsTextA.setBounds(30,10,20,20);
		itsLabelB.setBounds(10,30,40,20);
		itsTextB.setBounds(30,30,20,20);
		itsLabelW1.setBounds(60,10,40,20);
		itsTextW1.setBounds(90,10,20,20);
		itsLabelW2.setBounds(60,30,40,20);
		itsTextW2.setBounds(90,30,20,20);
		itsLabelT1.setBounds(10,50,40,20);
		itsTextT1.setBounds(30,50,20,20);
		itsLabelT2.setBounds(60,50,40,20);
		itsTextT2.setBounds(90,50,20,20);
		itsLabelV.setBounds(130,10,40,20);
		itsTextV.setBounds(150,10,20,20);
		itsLabelStep.setBounds(130,50,40,20);
		itsTextStep.setBounds(150,50,20,20);
		itsLine.setBounds(10,80,20,20);
		itsRysuj.setBounds(60,80,20,20);

		itsRysuj.addActionListener(new java.awt.event.ActionListener() {
				public void actionPerformed(java.awt.event.ActionEvent evt) {

					repaint();
				};
			});

	 add(itsTextA);add(itsTextB);add(itsTextT1);add(itsTextT2);add(itsTextW1);add(itsTextW2);add(itsTextV);add(itsTextStep);
	add(itsLabelA);add(itsLabelB);add(itsLabelT1);add(itsLabelT2);add(itsLabelW1);add(itsLabelW2);add(itsLabelV);add(itsLabelStep);
	add(itsLine);
	 add(itsRysuj);
    }
/*
	private void Dodaj(java.awt.event.ActionEvent evt)
	{
		itsWynik.setText(""+(double)((double)(Double.parseDouble(itsPierwsza.getText()))+(double)Double.parseDouble(itsDruga.getText())));
		itsOperacja.setText("+");
	};
	private void Odejmij(java.awt.event.ActionEvent evt)
	{
		itsWynik.setText(""+(double)((double)(Double.parseDouble(itsPierwsza.getText()))-(double)Double.parseDouble(itsDruga.getText())));
		itsOperacja.setText("-");
	};
	private void Pomnoz(java.awt.event.ActionEvent evt)
	{
		itsWynik.setText(""+(double)((double)(Double.parseDouble(itsPierwsza.getText()))*(double)Double.parseDouble(itsDruga.getText())));
		itsOperacja.setText("*");
	};
	private void Podziel(java.awt.event.ActionEvent evt)
	{
		itsWynik.setText(""+(double)(Double.parseDouble(itsPierwsza.getText())/Double.parseDouble(itsDruga.getText())));
		itsOperacja.setText("/");
	};
	private void Sinusuj(java.awt.event.ActionEvent evt)
	{
		itsWynik.setText(""+Math.sin(Double.parseDouble(itsPierwsza.getText())));
		itsOperacja.setText("sin");
	};
	private void Cosinusuj(java.awt.event.ActionEvent evt)
	{
		itsWynik.setText(""+Math.cos(Double.parseDouble(itsPierwsza.getText())));
		itsOperacja.setText("cos");
	};
*/
/*
    private void convertButtonActionPerformed(java.awt.event.ActionEvent evt) {
        int tempFahr = (int)((Double.parseDouble(tempTextField.getText()))
            * 1.8 + 32);
        fahrenheitLabel.setText(tempFahr + " Fahrenheit");
	}
  */  
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new main().setVisible(true);
            }
        });
    }
 /* 
	private javax.swing.JButton itsPolicz,itsPlus,itsMinus,itsRazy,itsPodzielic,itsSin,itsCos;
	private javax.swing.JLabel itsOperacja,itsRowne,itsWynik;
	private javax.swing.JTextField itsPierwsza;
	private javax.swing.JTextField itsDruga;
*/
	private TextField itsTextA,itsTextB,itsTextT1,itsTextT2,itsTextW1,itsTextW2,itsTextV,itsTextStep,itsTextLine;
	private Label itsLabelA, itsLabelB,itsLabelT1,itsLabelT2,itsLabelW1,itsLabelW2,itsLabelV,itsLabelStep;
	private Checkbox itsLine;
	private Button itsRysuj;
    
}

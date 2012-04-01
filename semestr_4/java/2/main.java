import java.lang.Math;
public class main extends javax.swing.JFrame {
    
    public main() {
        initComponents();
    }
    
    private void initComponents() {

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

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Kalkulator");
        setSize(650, 480);
		setLocationRelativeTo(null);
		setLayout(null);

//		itsPolicz.setText("Policz");
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
					Pomnoz(evt);
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

    }

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
    
	private javax.swing.JButton itsPolicz,itsPlus,itsMinus,itsRazy,itsPodzielic,itsSin,itsCos;
	private javax.swing.JLabel itsOperacja,itsRowne,itsWynik;
	private javax.swing.JTextField itsPierwsza;
	private javax.swing.JTextField itsDruga;
    
}

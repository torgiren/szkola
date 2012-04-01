#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot_2_2.jpg"
set xlabel "t"
set ylabel "wartosc"
set yrange [-1:3]
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "zad2_02_0.txt" using 1:2 title "u(0)=0" w l,\
"zad2_02_2.txt" using 1:2 title "u(0)=0.2" w l,\
"zad2_02_4.txt" using 1:2 title "u(0)=0.4" w l,\
"zad2_02_6.txt" using 1:2 title "u(0)=0.6" w l,\
"zad2_02_8.txt" using 1:2 title "u(0)=0.8" w l,\
"zad2_02_10.txt" using 1:2 title "u(0)=1.0" w l,\
"zad2_02_12.txt" using 1:2 title "u(0)=1.2" w l,\
"zad2_02_14.txt" using 1:2 title "u(0)=1.4" w l,\
"zad2_02_16.txt" using 1:2 title "u(0)=1.6" w l,\
"zad2_02_18.txt" using 1:2 title "u(0)=1.8" w l,\
"zad2_02_20.txt" using 1:2 title "u(0)=2.0" w l
replot

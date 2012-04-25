#!/usr/bin/gnuplot
set term jpeg
set out "plot_2_1.jpg"
set xlabel "iter"
set ylabel "ak"
set title "zestawienie"
plot "zad2_1_1.dat" using 1:2 w l, "zad2_2_1.dat" using 1:2 w l, "zad2_4_1.dat" using 1:2 w l, "zad2_8_1.dat" using 1:2 w l, "zad2_16_1.dat" using 1:2 w l

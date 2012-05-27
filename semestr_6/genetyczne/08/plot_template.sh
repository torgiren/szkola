#!/usr/bin/gnuplot
# set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 500, 350 
# set output 'candlesticks.5.png'
set term png nocrop enhanced font arial 14 size 1920,1080
set out "__OUT__"
set boxwidth 0.2 absolute
set bars 4.0
set grid
set nokey
set multiplot layout 3,2 title "__TITLE__"
 set style fill empty
set title "najlepszy"
plot "data___PATH__.1.dat" using 1:3:2:6:5 with candlesticks lt 3 lw 2 title 'Quartiles',\
	'' using 1:4:4:4:4 with candlesticks lt -1 lw 2
set title "mediana"
plot "data___PATH__.2.dat" using 1:3:2:6:5 with candlesticks lt 3 lw 2 title 'Quartiles',\
	'' using 1:4:4:4:4 with candlesticks lt -1 lw 2
set title "offline min"
plot "data___PATH__.3.dat" using 1:3:2:6:5 with candlesticks lt 3 lw 2 title 'Quartiles',\
	'' using 1:4:4:4:4 with candlesticks lt -1 lw 2
set title "offline max"
plot "data___PATH__.4.dat" using 1:3:2:6:5 with candlesticks lt 3 lw 2 title 'Quartiles',\
	'' using 1:4:4:4:4 with candlesticks lt -1 lw 2
set title "online"
plot "data___PATH__.5.dat" using 1:3:2:6:5 with candlesticks lt 3 lw 2 title 'Quartiles',\
	'' using 1:4:4:4:4 with candlesticks lt -1 lw 2
set title "rozklad wynikow"
plot "wynik___PATH__.dat"


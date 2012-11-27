#!/usr/bin/env gnuplot
set terminal jpeg
set out "350.jpg"
f(x) = a*x + b
fit f(x) "350.dat" via a,b
plot "350.dat" w lp, f(x) title "regresja"


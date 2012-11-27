#!/usr/bin/env gnuplot
set terminal jpeg
set out "410.jpg"
f(x) = a*x + b
fit f(x) "410.dat" via a,b
plot "410.dat" w lp, f(x) title "regresja"


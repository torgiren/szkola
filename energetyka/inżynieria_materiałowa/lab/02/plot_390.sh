#!/usr/bin/env gnuplot
set terminal jpeg
set out "390.jpg"
f(x) = a*x + b
fit f(x) "390.dat" via a,b
plot "390.dat" w lp, f(x) title "regresja"


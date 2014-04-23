set terminal postscript portrait
set output "ASpeed.eps"
plot 'MatrixAB.dat' using 1:2 title 'ASpeed'
set terminal gif
set output "ASpeed.gif"
plot 'MatrixAB.dat' using 1:2 title 'ASpeed'
set terminal postscript portrait
set output "LSpeed.eps"
plot 'MatrixAB.dat' using 1:3 title 'LSpeed'
set terminal gif
set output "LSpeed.gif"
plot 'MatrixAB.dat' using 1:3 title 'LSpeed'
set terminal postscript portrait
set output "USpeed.eps"
plot 'MatrixAB.dat' using 1:4 title 'USpeed'
set terminal gif
set output "USpeed.gif"
plot 'MatrixAB.dat' using 1:4 title 'USpeed'

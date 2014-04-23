set terminal postscript portrait
set output "ASpeed.eps"
plot 'ToolGraphAB.dat' using 1:2 title 'ASpeed'
set terminal gif
set output "ASpeed.gif"
plot 'ToolGraphAB.dat' using 1:2 title 'ASpeed'

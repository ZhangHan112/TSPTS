reset
set term wxt enhanced persist raise
set output "runtime.png"
set xlabel "Iteration"
set ylabel "Best"
set title "TSPTS"
plot [0:20000][400:1800]'output.dat' using 1:2  with line lw 1.5 title ""
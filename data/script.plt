#!/usr/bin/gnuplot

set terminal jpeg font arial 8 size 640,480
set output "data.jpg"
set grid x y y2
set xlabel "Days"
set ylabel "Infected have been identified"


plot 'result.txt' using 1:2 title "People" with lines

## This script plots data in the 'log' file
set datafile separator ','
# Set the output to a png file
set terminal png size 1000,1000
# The file we'll write to
set output 'AverageSpeed.png'
#Setting labels and title:
set xlabel 'Duration [s]'
set ylabel 'Average Velocity [km/h]'
plot 'averageSpeed' using 1:2 with lines notitle


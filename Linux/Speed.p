## This script plots data of the current speed.
set datafile separator ','
# Set the output to a png file
set terminal png size 1000,1000
# The file we'll write to
set output 'Speed.png'
#Setting labels and title:
set xlabel 'Duration [s]'
set ylabel 'Velocity [km/h]'
plot 'data' using 1:2 with lines notitle


/*
Martin and Mathias 
Bikecomputer (Physical Interactive Systems)


*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>
#include "mylib.h"	//Contains time_diff and kbhit
int main() 
{
	char input,last_input=' ';	// The pressed key
	int is_over=0;	// A variable that we set to 1 when we want to exit the program
	// Some instructions for the user
	printf("Press Enter to open the port and start the program.\n\nWhile the program is running, press:\n1. to turn on the heater\n0. To turn off the heater\na. to turn on the fan (pin 8)\ns. to turn the fan (pin 8) off\nx. To turn the motor clock-wise\nz. To stop the motor\nc To turn the motor counter clock-wise\n q to exit\n");
	// With this while, we make so that nothing happens until we press Enter
	while (input!='\n')
		if(kbhit())
			input=getchar();
	printf("Starting...\n");

	//Serial port stuff
	char *portname="/dev/ttyS3";			//IMPORTANT: If you use this file, make sure you change the portname with your portname
	char line[100];					// A string that we use as command to set the port baudrate
	sprintf(line,"stty -F %s 9600",portname);
	system(line);
	int tty_fd;					// We need a file descriptor for writing to the port (a file pointer is not enough)
	FILE *tty;
	// Variables for speed, average speed, distance and duration
	double speed = 0;
	double average = 0;
	double distance = 0;
	double duration = 0;
	double wheelCircumferrence = 2.23;   // in meters

	//Data and file logging stuff
	int rotationTime;
	int turns = 0;
	FILE *fptr;					// The pointer for writing to a file
	FILE *fptr2;
	fptr = fopen("./data", "w");			// opened with write so that it replaces existing values
	fptr2 = fopen("./averageSpeed", "w");

	// Starting the serial port connection
	tty_fd=open(portname,O_RDWR);                      
	if (tty_fd<0) 
	{
    		printf("Cannot open port: %s\n",portname);
		return -1;
	}

  	tty=fdopen(tty_fd,"rw");                        // Converting file descriptor to pointer
	fflush(tty);                                    // Empty buffer

	// The main loop
	while(is_over==0) 				// is_over is 0 unless the x key is pressed
	{
		// Read and handle the input
		input=' ';                               // Every execution, input is "empty"
		if(kbhit())				// If a key has been pressed we write which key in input
		{
			input=getchar();
			last_input=input;
		}	
		if(input=='x')
			is_over=1;

		// Read data from the serial and convert
		fscanf(tty,"%d",&rotationTime);

		if(rotationTime==65535)				
			speed = 0;	
		else{
		 	turns++;
		 	if(turns>1){
		 		duration += rotationTime*0.005;
	 			speed = (wheelCircumferrence/(rotationTime*0.005))*3.6;		// Speed in km/h.
				distance += (speed/3.6) * (rotationTime*0.005); // distance [m] covered 
				average = (distance / duration) * 3.6; // average speed [km/t]
				
				// Print to screen and write to file - you can change these strings, adding/removing data as you like
				printf("Duration: %.3f s. Speed: %.3f km/h  Average Speed: %.3f km/h  Distance: %.3f m.\n",duration, speed, average, distance);	// Print the values
				fprintf(fptr,"%.3f,%.3f\n",duration,speed);  				// Print values to the file 
				fprintf(fptr2,"%.3f,%.3f\n",duration, average);
				// Wait 10ms
				sleep(.01);
			 }
		}


  	}
	// Close the serial port and the files for logging data
	fclose(fptr);
	fclose(fptr2);
	close(tty_fd);
}

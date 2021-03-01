#include <wiringPi.h>
#include <stdio.h>

#define LedPin		0
#define ButtonPin 	1

int main(void){
	// When initialize wiring failed, print message to screen
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(LedPin, OUTPUT); 
	pinMode(ButtonPin, INPUT);
	digitalWrite(LedPin, HIGH);
	
	while(1){
		// Indicate that button has pressed down
		if(digitalRead(ButtonPin) == 0){
			// Led on
			digitalWrite(LedPin, LOW);
		//	printf("...LED on\n");
		}
		else{
			// Led off
			digitalWrite(LedPin, HIGH);
		//	printf("LED off...\n");
		}
	}
	return 0;
}


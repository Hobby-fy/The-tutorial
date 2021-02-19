#include <wiringPi.h>
#include <stdio.h>

#define MotorPin1		0
#define MotorPin2		2
#define MotorEnable		3

int main(void){
	int i;
	if(wiringPiSetup() == -1){ //when initialize wiring failed, print message to screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(MotorPin1, OUTPUT);
	pinMode(MotorPin2, OUTPUT);
	pinMode(MotorEnable, OUTPUT);

	while(1){
		printf("Clockwise\n");
		digitalWrite(MotorEnable, HIGH);
		digitalWrite(MotorPin1, HIGH);
		digitalWrite(MotorPin2, LOW);
		for(i=0;i<3;i++){
			delay(1000);
		}

		printf("Stop\n");
		digitalWrite(MotorEnable, LOW);
		for(i=0;i<3;i++){
			delay(1000);
		}

		printf("Anti-clockwise\n");
		digitalWrite(MotorEnable, HIGH);
		digitalWrite(MotorPin1, LOW);
		digitalWrite(MotorPin2, HIGH);
		for(i=0;i<3;i++){
			delay(1000);
		}

		printf("Stop\n");
		digitalWrite(MotorEnable, LOW);
		for(i=0;i<3;i++){
			delay(1000);
		}
	}
	return 0;
}


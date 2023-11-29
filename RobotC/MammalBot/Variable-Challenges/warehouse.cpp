#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void da(char* dirorstraight, int l, int s, bool ua) //Do Action Specified
{
	if (dirorstraight == "f") { // If it wants to go straight
		motor(motorB) = s;
		motor(motorC) = s;
	}
	else if (dirorstraight == "l") { // If it wants turn left
		motor(motorB) = s;
		motor(motorC) = -s;
	}
	else if (dirorstraight == "r") { // If it wants turn right
		motor(motorB) = -s;
		motor(motorC) = s;
	}
	else if (dirorstraight == "b") { // If it wants go backwards
		motor(motorB) = -s;
		motor(motorC) = -s;
	}

	if (ua == true) { // If i specify to change duration to the angle to turn at, then
		delay((14.25 * (((s-50)*-1)+50)/100)*l); // Angle Script
	}

	else if (ua == false) { // If I dont specify to convert duration to angle
		delay(l); // Wait duration
	}
}

/* 
Instructions for future use:

Set the first parameter "dirorstraight" to any of these values: 
f: Bot will move forward.
r: Bot will reverse.
l: Bot will turn left.
r: Bot will turn right.

** if you set the value to r or l, set the fourth parameter to true.

Second parameter is either the angle or duration, depending on what the first parameter is.

Third parameter is the speed, independent and doesn't get influenced by other parameters.
*/

int Lines;

void detectWall() {
	while (SensorValue[S4] >= 15) {
		motor[motorB] = 50;
		motor[motorC] = 50;
	}
	
	motor[motorB] = 0;
	motor[motorC] = 0;
}

void detectLine() {
	while (SensorValue[S3] >= 30) {
		motor[motorB] = 20;
		motor[motorC] = 20;
		
		
		delay(50);
	}
	
	motor[motorB] = 0;
	motor[motorC] = 0;
	Lines++;
	
	displayTextLine(2, "%d", Lines);
	
	delay(500);
	da("f",500,50,false);
}

task main() {
	int i;
	displayTextLine(1, "Lines: ");
	da("f",1800,50,false);
	for (i=0;i<2;i++) {
		
		da("l",90,50,true);
		detectLine();
		detectLine();
		detectWall();
		da("r",90,50,true);
		detectLine();
		detectLine();
		da("f",1000,50,false);
		da("r",95,50,true);
		detectLine();
		detectLine();
		detectWall();
		da("l",90,50,true);
		
		da("f",3000,50,false);
	}
	
	da("b",1000,50,false);
	da("r",170,50,true);
	da("f",10000,50,false);
}
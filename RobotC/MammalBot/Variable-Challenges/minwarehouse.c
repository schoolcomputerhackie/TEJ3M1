#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
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
int Lines;
void detectWall() { // This function will move until it detects a wall.
	while (SensorValue[S4] >= 15) {
		motor[motorB] = 50;
		motor[motorC] = 50;
	}
	motor[motorB] = 0;
	motor[motorC] = 0;
}
void detectLine() { // this function will move until it detects a line, then move a bit forward to not detect the same line again.
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
	displayTextLine(1, "Lines: "); // this will not change; it simply displays the text "Lines:" on the first line.
	da("f",1800,50,false);	
	da("l",90,50,true); // this will get you to the first area
	detectLine();
	detectLine(); // detect 2 lines
	detectWall(); // detect the first wall
	da("r",90,50,true); // turn right 90 degrees after you detect the wall
	detectLine(); // detect 2 lines
	detectLine();
	da("f",1000,50,false); // move for one second
	da("r",95,50,true); // turn right for 95 degrees (95 because of RNG of the robot but it tends to be more undershot so I adjusted for it.)
	detectLine();
	detectLine(); // detect 2 more lines (this is getting boring)
	detectWall(); // detect WALL #2 WOOHOO
	da("l",90,50,true); // turn left 90 degrees
	detectLine();
	detectLine(); // yup we're detecting 2 more lines
	da("f",800,50,false); // move forward for .8 seconds
	da("l",95,50,true); // turn left 95 degrees to offput the adjustment we did earlier
	detectLine();
	detectLine(); // wow would you look at that we're detecting 2 more lines again
	detectWall(); // WALL # 3 YAYAYA
	da("r",90,50,true); // turn right 90 degrees
	detectLine();
	detectLine(); // do i even have to say it anymore
	da("f",1000,50,false); // move forward for 1 second
	da("b",250,50,false); // move backwards for .25 seconds
	da("r",90,50,true); // turn right 90 degrees
	detectLine();
	detectLine(); // detect yet another 2 lines
	detectWall(); // detect the final wall
	da("l",90,50,true); // Turn left 90 degrees
	da("f",1000,50,false); // Move forward for 1 second
	da("b",250,50,false); // Move backwards for .25 seconds
	da("r",170,50,true); // Turn right for 170 degrees
	detectLine();
	detectLine();
	detectLine();
	detectLine();
	da("b",500,50,false);
	da("r",95,50,true);
	da("f",3500,50,false);
	da("r",90,50,true);
	da("f",3500,50,false);
}

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
		delay((16 * (((s-50)*-1)+50)/100)*l); // Angle Script
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

task main()
{
	da("f",4500,50,false);
	da("l",90,50,true);
	da("f",4000,50,false);
	da("r",90,50,true);
	da("f",3200,50,false);
	da("r",90,50,true);
	da("f",1500,50,false);
}

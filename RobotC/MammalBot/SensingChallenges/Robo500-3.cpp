#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,          mA,            tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          mB,            tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          mC,            tmotorNXT, PIDControl, encoder)

void turn(char* direction) {
	if (direction == "r") {
		motor[motorB] = -50;
		motor[motorC] = 50;
		delay(636);
	}
	else if (direction == "l") {
		motor[motorB] = 50;
		motor[motorC] = -50;
		delay(636);
	}
}

task main() {
	while (true) {
		while (SensorValue[S4]>12) {
		motor[motorB] = 100;
		motor[motorC] = 100;
		}
		turn("r");
	}
}

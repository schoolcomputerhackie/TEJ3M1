#pragma config(Sensor, S3,     light,          sensorLightActive)

int lightval;

void move() {
	motor[motorB] = 70;
	motor[motorC] = 70;
	delay(10);
}
	
void action() {
	while (true) {
		lightval = SensorValue[S3];
		if (lightval > 35) {
			motor[motorB] = -70;
			motor[motorC] = 70;
			delay(10);
		}
		else {
			motor[motorB] = 70;
			motor[motorC] = -70;
			delay(10);
		}
		move();
	}
}

// robot function
task main() {
	action();
}

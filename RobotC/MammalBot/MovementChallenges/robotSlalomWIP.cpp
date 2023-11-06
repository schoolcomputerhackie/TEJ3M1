void da(char* dirorstraight, int l, int s, bool ua)
{
	if (dirorstraight	== "f") {
		motor(motorB) = s;
		motor(motorC) = s;
	}
	else if (dirorstraight == "l") {
		motor(motorB) = s;
		motor(motorC) = -s;
	}
	else if (dirorstraight == "r") {
		motor(motorB) = -s;
		motor(motorC) = s;

	}
	else if (dirorstraight == "b") {
		motor(motorB) = -s;
		motor(motorC) = -s;

	}

	if (ua == true) {
		delay((7.25) * l);
	}

	else if (ua == false) {
		delay(l);
	}
}

task main()
{
	da("r",45,50,true);
	da("f",3000,50,false);
	da("l",90,50,true);
	da("f",2500,50,false);
	da("l",45,50,true);
	da("f",2000,50,false);
	da("r",90,50,true);
	da("f",2250,50,false);
	da("r",90,50,true);
	da("f",3500,50,false);
	da("l",90,50,true);
	da("f",2000,50,false);
	da("l",45,50,true);
	da("f",1000,50,false);
	da("r",90,50,true);
	da("f",3000,50,false);
}

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
		delay((8.3) * l);
	}
	
	else if (ua == false) {
		delay(l);
	}
}

task main()
{
	int i;
	
	for (i=0;i<8;i++){
		da("f",4500,50,false);
		da("r",90,50,true);
	}
}

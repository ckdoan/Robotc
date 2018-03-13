#pragma config(Sensor, S1,     linesensor,     sensorLightActive)
#pragma config(Sensor, S2,     touchsensorR,   sensorTouch)
#pragma config(Sensor, S3,     threshold,      sensorSONAR)
#pragma config(Sensor, S4,     touchsensorL,   sensorTouch)

task main()
{
	wait1Msec(5000);
	//nxtDisplayString(0, "Hello world");
	motor[motorA] = -2000;
	motor[motorC] = 2000;
	wait1Msec(450);

	//long lite;
  int touchL;
  int touchR;
  int line;
  int see;
  //bool pressedL = false;
  //bool pressedR = false;
  string sColor;
  while (true) {

  	 //lite = SensorValue(light);
     touchL = SensorValue(touchsensorL);
		 touchR = SensorValue(touchsensorR);
		 line = SensorValue(linesensor);
		 see = SensorValue(threshold);

		 //left touch sensor
		 if(touchL == 1 && line < 45){

		 //goes straight at slow speed
		   motor[motorA] = 100;
		 	 motor[motorC] = 100;
	//	 	 wait1Msec(400);

		 	 //rotates lefts
		   motor[motorA] = 70;
		 	 motor[motorC] = -50;
		// 	 wait1Msec(200);

		 	 //goes straight at slow speed
		   motor[motorA] = 100;
		 	 motor[motorC] = 100;
	//	 	 wait1Msec(300);

		 	 //rotates lefts
		   motor[motorA] = 150;
		 	 motor[motorC] = -150;
//		 	 wait1Msec(200);

		}

		//right touch sensor
		if (touchR == 1 && line < 45){
				//goes straight at slow speed
		   motor[motorA] = 100;
		 	 motor[motorC] = 100;
//		 	 wait1Msec(400);

		 	 //rotates lefts
		   motor[motorA] = -50;
		 	 motor[motorC] = 70;
	//	 	 wait1Msec(200);

		 	 //goes straight at slow speed
		   motor[motorA] = 100;
		 	 motor[motorC] = 100;
	//	 	 wait1Msec(300);

		 	 //rotates lefts
		   motor[motorA] = -150;
		 	 motor[motorC] = 150;
		// 	 wait1Msec(200);
		}


		//if it sees white stop
		if(line >= 45){
		 //goes backwards at slow speed
		  motor[motorA] = -50;
		 	motor[motorC] = -50;
		 	wait1Msec(700);

			motor[motorA] = -200;
		  motor[motorC] = 200;
		  wait1Msec(400);


/*
			motor[motorA] = 0;
		  motor[motorC] = 0;
		  wait1Msec(50);*/
		}


		//If target is within 70 cm, KILL
		if(see < 50 && line < 45){
			nxtDisplayString(0, "Seen");
			nxtDisplayString(1,"seen");
			motor[motorA] = 2000;
		  motor[motorC] = 2000;
		  wait1Msec(100);
			//speed ahead
		} /*else {
		 	nxtDisplayString(0,"no see");
			nxtDisplayString(1,"no see");
		}*/

		//If no target is within 70 cm, just keep spinning
		if(line < 45 && touchR != 1 && touchL != 1 && see>= 50) {
		 	//turn, go
			nxtDisplayString(0,"see nothing and going");
		 	motor[motorA] = 200;
		  motor[motorC] = -200;
	//	  wait1Msec(100);

//		  if(see < 50 && line < 45){
	//			nxtDisplayString(0, "Seen");
	//			nxtDisplayString(1,"seen");
	//			motor[motorA] = 2000;
	//		  motor[motorC] = 2000;
	//		  wait1Msec(100);
			//speed ahead
	//		}


		  motor[motorA] = 1000;
		  motor[motorC] = 1000;
	//	  wait1Msec(300);
		}
	}

}

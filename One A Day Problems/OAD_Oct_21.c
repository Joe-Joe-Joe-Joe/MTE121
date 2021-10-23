//a) assume the skater will always pass within 50 cm of the middle of the track

//b) the skater falls before the fourth lap
const int PASSES_UNTIL_FINAL = 3;
const int TIME_TO_MOVE_BACK = 30;
const int DIST_TO_LANE = 100;
void waitForPass();


task main()
{
	SensorType[S1] = sensorEV3_Touch;
	wait1Msec(50);
	SensorType[S3] = sensorEV3_Ultrasonic;
	wait1Msec(50);


	for (int pass = 0; pass < PASSES_UNTIL_FINAL; pass++)
	{
		waitForPass();
	}

	motor[motorA] = motor[motorD] = 100;
	while(SensorValue[S1] == 0)
	{}
	motor[motorA] = motor[motorD] = 0;

	displayString(5, "Press to reset");
	while(!getButtonPress(buttonAny))
	{}
	while(getButtonPress(buttonAny))
	{}

	clearTimer(T1);
	motor[motorA] = motor[motorD] = -25;
	while(time1[T1]/1000 < TIME_TO_MOVE_BACK)
	{}
	motor[motorA] = motor[motorD] = 0;

}

void waitForPass()
{
	while(SensorValue[S3] > DIST_TO_LANE+50)
	{}
}

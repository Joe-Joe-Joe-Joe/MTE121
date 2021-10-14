void moveDist(int motor_power, int radius, int dist);
void calibrateSensors();
//a) assume the garage door is closed
//b) ryan could have potholes in his driveway deep enough to stop the robot

task main()
{

	bool overheated = false;
	bool close_to_door = false;
	while(!overheated && !close_to_door)
	{
		clearTimer(T1);
		motor[motorB] = 1;
		resetGyro(S4);
		motor[motorA] = 10*direction;
		motor[motorD] = -10*direction;

		while(abs(getGyroDegrees(S4)) < 720 && time[T1] <= 6000)
		{}
		motor[motorA] = motor[motorB] = motor[motorD] = 0;
		if(time[T1] > 6000)
		{
			overheated = true;
		}
		else
		{
			if(SensorValue[S2] < 55)
			{
				close_to_door = true;
			}
			else
			{
				moveDist(10, 3, 15);
			}
		}
	}
}

void moveDist(int motor_power, int radius, int dist)
{
	float enc_max = dist * 360 / (2 * PI * radius);
	nMotorEncoder[motorA] = 0
	motor[motorA] = motor[motorD] = motor_power;
	while(nMotorEncoder[motorA] < enc_max)
	{}
	motor[motorA] = motor[motorD] = 0;
}

void calibrateSensors()
{
	SensorType[S1] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorType[S2] = sensorEV3_Ultrasonic;
	wait1Msec(50);
	SensorMode[S1] = modeEV3Gyro_calibration;
	wait1Msec(50);
	SensorMode[S1] = modeEV3Gyro_RateAndAngle;
}

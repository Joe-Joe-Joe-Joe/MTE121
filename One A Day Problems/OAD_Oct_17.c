//a Assume the orange button means the enter button and thr question is outdated
//b the robot could be attacked by one or more geese in the course of its operations

const int WALL_DIST = 15 + 30;
void driveToLimit(int dist);
void turnSec(int motor_pow, float turn_time);



task main()
{
	SensorType[S4] = sensorEV3_Ultrasonic;
	wait1Msec(50);

	while(!getButtonPress(buttonEnter))
	{}
	while(getButtonPress(buttonEnter))
	{}
	motor[motorB] = 1;

	driveToLimit(WALL_DIST);
	turnSec(75, 0.75);
	driveToLimit(WALL_DIST);
	turnSec(75, 0.75);
	driveToLimit(WALL_DIST);
	motor[motorB] = 0;

}

void turnSec(int motor_pow, float turn_time)
{
	clearTimer(T1);
	motor[motorA] = motor_pow;
	motor[motorD] = -motor_pow;
	while(time1[T1] / 1000 < turn_time)
	{}
	motor[motorA] = motor[motorD] = 0;
}

void driveToLimit(int dist)
{
	motor[motorA] = motor[motorB] = 50;
	while(SensorValue[S4] > dist)
	{}
	motor[motorA] = motor[motorB] = 50;
}

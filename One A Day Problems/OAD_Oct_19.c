//a does not check for deep spots within the square area

const int SIDE_LEN = 800;
const int CHECK_INTERVAL = 50;
const float PINION_RADIUS = 1.2;

float maxDepthSide(int side_len, int interval);
void turnDegrees(int degrees, int dir);
void moveDist(int motor_power, int radius, int dist);
float getDepth();

task main()
{
	SensorType[S1] = sensorEV3_Touch;
	displayString(1, "%0.2f cm deep, side 1", maxDepthSide(SIDE_LEN, CHECK_INTERVAL));
	turnDegrees(90, -1);
	displayString(2, "%0.2f cm deep, side 2", maxDepthSide(SIDE_LEN, CHECK_INTERVAL));
	turnDegrees(90, -1);
	displayString(3, "%0.2f cm deep, side 3", maxDepthSide(SIDE_LEN, CHECK_INTERVAL));
	turnDegrees(90, -1);
	displayString(4, "%0.2f cm deep, side 4", maxDepthSide(SIDE_LEN, CHECK_INTERVAL));


}

float maxDepthSide(int side_len, int interval)
{
	float max_depth = 0;
	for(int step = 0; step < side_len/interval; step++)
	{
		float depth = 0;
		moveDist(50, 2.75, interval);
		depth = getDepth();
		if(depth > max_depth) max_depth = depth;
	}
	return max_depth;
}

void turnDegrees(int degrees, int dir)
{
	//direction = 1 is clockwise, direction = -1 is CCW
	resetGyro(S4);
	motor[motorA] = 20*dir;
	motor[motorD] = -20*dir;
	while(abs(getGyroDegrees(S4)) < degrees)
	{}
	motor[motorA] = motor[motorD] = 0;
}

void moveDist(int motor_power, int radius, int dist)
{
	float enc_max = dist * 360 / (2 * PI * radius);
	nMotorEncoder[motorA] = 0;
	motor[motorA] = motor[motorD] = motor_power;
	while(nMotorEncoder[motorA] < enc_max)
	{}
	motor[motorA] = motor[motorD] = 0;
}

float getDepth()
{
	nMotorEncoder[motorB] = 0;
	motor[motorB] = 10;
	while(SensorValue[S1] == 0)
	{}
	motor[motorB] = 0;
	return nMotorEncoder[motorB] / 360 * (2 * PI * PINION_RADIUS);
}

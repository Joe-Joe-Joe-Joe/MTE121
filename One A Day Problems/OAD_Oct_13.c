void configureSensors();
void turnDegrees(int degrees);
void moveToDistLimit(int limit);
void flipScoop(int deg);
void moveToColor(TLegoColors color);
void moveEncoderDist(int dist);
const int WALL_DIST_LIMIT = 30;

//assume the red tape is 8 cm wide or less

//there could be a piece of debris
//that is too heavy for the robot,
//breaking the scoop


task main()
{
	configureSensors();
	bool hallsToSweep = true;
	int halls_swept = 0;
	int encoder_dist = 0;

	while(hallsToSweep)
	{
		halls_swept++;
		moveToColor(colorRed);
		turnDegrees(270);
		nMotorEncoder[motorA] = 0;
		moveToDistLimit(WALL_DIST_LIMIT);
		encoder_dist = nMotorEncoder[motorA];
		flipScoop(110);
		if (SensorValue[S2] == colorBlack)
		{
			hallsToSweep = false;
		}
		else
		{
			turnDegrees(180);
			moveEncoderDist(encoder_dist);
			turnDegrees(270);
			moveEncoderDist(180); //offset from red tape for next cycle
		}

	}

	displayString(5, "%d Halls Swept", halls_swept);
	wait1Msec(10000);
}

void turnDegrees(int degrees)
{
	//direction = 1 is clockwise, direction = -1 is CCW
	resetGyro(S4);
	motor[motorA] = 20;
	motor[motorD] = -20;
	while(abs(getGyroDegrees(S4)) < degrees)
	{}
	motor[motorA] = motor[motorD] = 0;
}

void moveToColor(TLegoColors color)
{
	motor[motorA] = motor[motorD] = 30;
	while(SensorValue[S2] != color)
	{}
	motor[motorA] = motor[motorD] = 0;
}

void flipScoop(int deg)
{
	motor[motorB] = 100;
	nMotorEncoder[motorB] = 0;
	while(nMotorEncoder[motorB] < deg)
	{
	}
	nMotorEncoder[motorB] = 0;
	motor[motorB] = -30;
	while(-deg < nMotorEncoder[motorB])
	{
	}
	motor[motorB] = 0;
}

void moveToDistLimit(int limit)
{
	motor[motorA] = motor[motorD] = 30;
	while(limit < SensorValue[S3])
	{}
	motor[motorA] = motor[motorD] = 0;
}

void moveEncoderDist(int dist)
{
	nMotorEncoder[motorA] = 0
	motor[motorA] = motor[motorD] = 40;
	while(nMotorEncoder[motorA] < dist)
	{}
	motor[motorA] = motor[motorD] = 0;
}

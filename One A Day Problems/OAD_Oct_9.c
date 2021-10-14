// a) assume that the robot's electronics are waterproof and its tires are skid-proof
// b) the washer could wash off Ryan's painted red line as well
void moveDist(int dist);
void turnDegrees(int degrees, int direction);
bool washCycle (int vertical);
void moveToDistLimit(int limit);
void moveToColor(TLegoColors color);
int hallCycle(int passes);
const int HALL_CYCLE_WIDTH = 100;
const int HALL_PASSES_E2 = 3;


task main()
{
	configureAllSensors();
	hallCycle(HALL_PASSES_E2);
}

void moveDist(int dist)
{
	float enc_max = dist * 360 / (2 * PI * 2.75);
	nMotorEncoder[motorA] = 0
	motor[motorA] = motor[motorD] = 40;
	while(nMotorEncoder[motorA] < enc_max)
	{}
	motor[motorA] = motor[motorD] = 0;
}
void moveToDistLimit(int limit)
{
	motor[motorA] = motor[motorD] = 30;
	while(limit < SensorValue[S3])
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

void turnDegrees(int degrees, int direction)
{
	//direction = 1 is clockwise, direction = -1 is CCW
	resetGyro(S4);
	motor[motorA] = 20*direction;
	motor[motorD] = -20*direction;
	while(abs(getGyroDegrees(S4)) < degrees)
	{}
	motor[motorA] = motor[motorD] = 0;
}

bool washCycle(int vertical)
{
	moveDist(vertical);
	turnDegrees(90, -1);
	motor[motorB] = 100;
	moveToDistLimit(40);
	motor[motorB] = 0;
	turnDegrees(180, 1);
	moveToColor(colorRed);
	turnDegrees(90, -1);

	return SensorValue[S1];
}
int hallCycle(int passes)
{
	for(int pass = 1; pass <= passes; pass++)
	{
		if(washCycle(HALL_CYCLE_WIDTH))
		{
			turnDegrees(180, 1);
			moveDist(pass*HALL_CYCLE_WIDTH);
			return pass;
		}
	}
	return 0;
}

void EncoderForward(float goStraightDistance, int initMotorPower)
{
    encoderLeft.reset();
    encoderRight.reset();
    int speedVariable = initMotorPower;
    float tempRightEncoderTicks, tempLeftEncoderTicks;
    do
    {
        tempRightEncoderTicks = abs(encoderRight.read());
        tempLeftEncoderTicks = abs(encoderLeft.read());
        if (TicksToDistance(tempRightEncoderTicks) < goStraightDistance / 2)
        {
            speedVariable = map(TicksToDistance(tempRightEncoderTicks), 0, goStraightDistance / 2, 400, initMotorPower);
        }
        else
        {
            speedVariable = map(goStraightDistance - TicksToDistance(tempRightEncoderTicks), 0, goStraightDistance / 2, 400, initMotorPower);
        }

        if (tempRightEncoderTicks > tempLeftEncoderTicks)
        {
            ForwardLeftMotor(speedVariable);
            BreakRightMotor();
        }
        else if (tempRightEncoderTicks < tempLeftEncoderTicks)
        {
            ForwardRightMotor(speedVariable);
            BreakLeftMotor();
        }
        else
        {
            ForwardLeftMotor(speedVariable);
            ForwardRightMotor(speedVariable);
        }
    } while (TicksToDistance(tempRightEncoderTicks) <= goStraightDistance);
    //LowBreak();
}

void EncoderBackward(float goStraightDistance, int initMotorPower)
{
    encoderLeft.reset();
    encoderRight.reset();
    float tempRightEncoderTicks, tempLeftEncoderTicks;
    do
    {
        tempRightEncoderTicks = abs(encoderRight.read());
        tempLeftEncoderTicks = abs(encoderLeft.read());
        if (tempRightEncoderTicks > tempLeftEncoderTicks)
        {
            BackwardLeftMotor(initMotorPower);
            BreakRightMotor();
        }
        else if (tempRightEncoderTicks < tempLeftEncoderTicks)
        {
            BackwardRightMotor(initMotorPower);
            BreakLeftMotor();
        }
        else
        {
            BackwardLeftMotor(initMotorPower);
            BackwardRightMotor(initMotorPower);
        }
    } while (TicksToDistance(tempRightEncoderTicks) <= goStraightDistance);
    LowBreak();
}

void EncoderTurnRight90(int turnRight90Ticks, int initMotorPower)
{
    encoderLeft.reset();
    encoderRight.reset();
    int speedVariable = initMotorPower;
    float tempRightEncoderTicks, tempLeftEncoderTicks;
    while (true)
    {
        tempRightEncoderTicks = abs(encoderRight.read());
        tempLeftEncoderTicks = abs(encoderLeft.read());
        if (tempLeftEncoderTicks < turnRight90Ticks / 2)
        {
            speedVariable = initMotorPower;
        }
        else
        {
            speedVariable = map(turnRight90Ticks - tempRightEncoderTicks, 0, turnRight90Ticks / 2, 300, initMotorPower);
        }

        if (tempLeftEncoderTicks > turnRight90Ticks)
        {
            BreakMotors();
            break;
        }

        if (tempRightEncoderTicks > tempLeftEncoderTicks)
        {
            ForwardLeftMotor(speedVariable);
            BreakRightMotor();
        }
        else if (tempRightEncoderTicks < leftEncoderTicks)
        {
            BackwardRightMotor(speedVariable);
            BreakLeftMotor();
        }
        else
        {
            ForwardLeftMotor(speedVariable);
            BackwardRightMotor(speedVariable);
        }
    }
}

void EncoderTurnLeft90(int turnLeft90Ticks, int initMotorPower)
{
    encoderLeft.reset();
    encoderRight.reset();
    int speedVariable = initMotorPower;
    float tempRightEncoderTicks, tempLeftEncoderTicks;
    while (true)
    {
        tempRightEncoderTicks = abs(encoderRight.read());
        tempLeftEncoderTicks = abs(encoderLeft.read());
        if (tempRightEncoderTicks < turnLeft90Ticks / 2)
        {
            speedVariable = initMotorPower;
        }
        else
        {
            speedVariable = map(turnLeft90Ticks - tempRightEncoderTicks, 0, turnLeft90Ticks / 2, 300, initMotorPower);
        }

        if (tempLeftEncoderTicks > turnLeft90Ticks)
        {
            BreakMotors();
            break;
        }

        if (tempRightEncoderTicks > tempLeftEncoderTicks)
        {
            ForwardRightMotor(speedVariable);
            BreakRightMotor();
        }
        else if (tempRightEncoderTicks < leftEncoderTicks)
        {
            BackwardLeftMotor(speedVariable);
            BreakLeftMotor();
        }
        else
        {
            ForwardRightMotor(speedVariable);
            BackwardLeftMotor(speedVariable);
        }
    }
}

void TurnRight90()
{
    EncoderTurnRight90(ENCODER_TURN_RIGHT_90_TICKS, 500);
    needAccel = true;
}

void TurnLeft90()
{
    EncoderTurnLeft90(ENCODER_TURN_LEFT_90_TICKS, 500);
    needAccel = true;
}

void TurnRight180()
{
    EncoderTurnRight90(ENCODER_TURN_RIGHT_180_TICKS, 500);
    needAccel = true;
}

void TurnLeft180()
{
    EncoderTurnLeft90(ENCODER_TURN_LEFT_180_TICKS, 500);
    needAccel = true;
}

void TurnLeftNew90(int ticksnew){
    EncoderTurnLeft90(ticksnew, 500);     //ENCODER_TURN_LEFT_90_TICKS = 1050
    needAccel = true;
}
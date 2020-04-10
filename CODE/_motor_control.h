void StopMotors();

DigitalOut motorLeft1(MOTOR_LEFT_1);
DigitalOut motorLeft2(MOTOR_LEFT_2);
DigitalOut motorRight1(MOTOR_RIGHT_1);
DigitalOut motorRight2(MOTOR_RIGHT_2);
PwmOut motorLeftPowerPin(MOTOR_LEFT_POWER_PIN);
PwmOut motorRightPowerPin(MOTOR_RIGHT_POWER_PIN);

void InitMotors()
{
    motorLeftPowerPin.period_us(100);
    motorRightPowerPin.period_us(100);
    StopMotors();
}

void StopMotors()
{
    motorLeft1.write(0);
    motorLeft2.write(0);
    motorRight1.write(0);
    motorRight2.write(0);
    motorLeftPowerPin.write(0);
    motorRightPowerPin.write(0);
}

void ForwardLeftMotor(float power)
{
    motorLeft1.write(0);
    motorLeft2.write(1);
    motorLeftPowerPin.write(power / 1000);
}

void BackwardLeftMotor(float power)
{
    motorLeft1.write(1);
    motorLeft2.write(0);
    motorLeftPowerPin.write(power / 1000);
}

void ForwardRightMotor(float power)
{
    motorRight1.write(0);
    motorRight2.write(1);
    motorRightPowerPin.write(power / 1000);
}

void BackwardRightMotor(float power)
{
    motorRight1.write(1);
    motorRight2.write(0);
    motorRightPowerPin.write(power / 1000);
}

void BreakMotors()
{
    motorLeft1 = 1;
    motorLeft2 = 1;
    motorRight1 = 1;
    motorRight2 = 1;
    motorLeftPowerPin.write(1);
    motorRightPowerPin.write(1);
}

void LowBreak()
{
    motorLeft1 = 1;
    motorLeft2 = 1;
    motorRight1 = 1;
    motorRight2 = 1;
    motorLeftPowerPin.write(0);
    motorRightPowerPin.write(0);
}

void BreakLeftMotor()
{
    motorLeft1 = 1;
    motorLeft2 = 1;
    motorLeftPowerPin.write(1);
}

void BreakRightMotor()
{
    motorRight1 = 1;
    motorRight2 = 1;
    motorRightPowerPin.write(1);
}

void RunBothMotors(float leftPower, float rightPower)
{
    if (leftPower > 0)
    {
        ForwardLeftMotor(leftPower);
    }
    else
    {
        BackwardLeftMotor(abs(leftPower));
    }
    if (rightPower > 0)
    {
        ForwardRightMotor(rightPower);
    }
    else
    {
        BackwardRightMotor(abs(rightPower));
    }
}

struct AccelCurve
{
    int speedVar = 0;
    float funcOutput;

    void Reset()
    {
        speedVar = 0;
    }

    int GetSpeed(int speedConst)
    {
        speedVar += 1;
        if (speedConst <= 550)
        {
            if (speedVar < 100)
            {
                funcOutput =
                    speedConst * (speedVar / (pow(1000.0 + pow(speedVar, 2), 0.5)));
                funcOutput = constrain(funcOutput, 200, 1000);
            }
            else
            {
                funcOutput = speedConst;
            }
        }
        else if (speedConst < 650)
        {
            if (speedVar < 200)
            {
                funcOutput =
                    speedConst * (speedVar / (pow(15000.0 + pow(speedVar, 2), 0.5)));
                funcOutput = constrain(funcOutput, 200, 1000);
            }
            else
            {
                funcOutput = speedConst;
            }
        }
        else
        {
            if (speedVar < 400)
            {
                funcOutput =
                    speedConst * (speedVar / (pow(100000.0 + pow(speedVar, 2), 0.5)));
                funcOutput = constrain(funcOutput, 200, 1000);
            }
            else
            {
                funcOutput = speedConst;
            }
        }
        return funcOutput;
    }
};

AccelCurve accelCurve;
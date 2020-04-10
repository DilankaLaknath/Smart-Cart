void InitMotors()
{
    pinMode(MOTOR_LEFT_1, OUTPUT);
    pinMode(MOTOR_LEFT_2, OUTPUT);
    pinMode(MOTOR_RIGHT_1, OUTPUT);
    pinMode(MOTOR_RIGHT_2, OUTPUT);
    pinMode(MOTOR_LEFT_POWER_PIN, OUTPUT);
    pinMode(MOTOR_RIGHT_POWER_PIN, OUTPUT);
    StopMotors();
}

void StopMotors()
{
    digitalWrite(MOTOR_LEFT_1, LOW);
    digitalWrite(MOTOR_LEFT_2, LOW);
    digitalWrite(MOTOR_RIGHT_1, LOW);
    digitalWrite(MOTOR_RIGHT_2, LOW);
    digitalWrite(MOTOR_LEFT_POWER_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_POWER_PIN, LOW);
}

void ForwardLeftMotor(float power)
{
    analogWrite(MOTOR_LEFT_POWER_PIN, (int)power);
    digitalWrite(MOTOR_LEFT_1, HIGH);
    digitalWrite(MOTOR_LEFT_2, LOW);
}

void BackwardLeftMotor(float power)
{
    analogWrite(MOTOR_LEFT_POWER_PIN, (int)power);
    digitalWrite(MOTOR_LEFT_1, LOW);
    digitalWrite(MOTOR_LEFT_2, HIGH);
}

void ForwardRightMotor(float power)
{   
    analogWrite(MOTOR_RIGHT_POWER_PIN, (int)power);
    digitalWrite(MOTOR_RIGHT_1, HIGH);
    digitalWrite(MOTOR_RIGHT_2, LOW);
}

void BackwardRightMotor(float power)
{
    analogWrite(MOTOR_RIGHT_POWER_PIN, (int)power);
    digitalWrite(MOTOR_RIGHT_1, LOW);
    digitalWrite(MOTOR_RIGHT_2, HIGH);
}

void BreakMotors()
{
    digitalWrite(MOTOR_LEFT_1, HIGH);
    digitalWrite(MOTOR_LEFT_2, HIGH);
    digitalWrite(MOTOR_RIGHT_1, HIGH);
    digitalWrite(MOTOR_RIGHT_2, HIGH);
    digitalWrite(MOTOR_LEFT_POWER_PIN, HIGH);
    digitalWrite(MOTOR_RIGHT_POWER_PIN, HIGH);
}

void LowBreak()
{
    digitalWrite(MOTOR_LEFT_1, LOW);
    digitalWrite(MOTOR_LEFT_2, LOW);
    digitalWrite(MOTOR_RIGHT_1, LOW);
    digitalWrite(MOTOR_RIGHT_2, LOW);
    digitalWrite(MOTOR_LEFT_POWER_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_POWER_PIN, LOW);
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


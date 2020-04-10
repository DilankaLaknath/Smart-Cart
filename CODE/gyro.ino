void InitMPU()
{
    pinMode(INTERRUPT_DMP_PIN, INPUT);
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000);
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif
    BeginMPU();
}

void DmpDataReady()
{
    mpuInterrupt = true;
}

void BeginMPU()
{
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000);
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif
    mpu.initialize();

    // extra line
    // mpu.setDLPFMode(0);

    // this is the code to increase the rate to 5ms speed.
    //mpu.setRate(9); // 309 in MPU6050-6Axis_MotionApps20.h was changed to work this properly

    devStatus = mpu.dmpInitialize();
    mpu.setXGyroOffset(-1184); //98
    mpu.setYGyroOffset(45); //-24
    mpu.setZGyroOffset(-77); //0
    mpu.setZAccelOffset(1297); // 1788
    mpu.setXAccelOffset(-2683);
    mpu.setYAccelOffset(2179);

    if (devStatus == 0)
    {
        mpu.setDMPEnabled(true);
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_DMP_PIN), DmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
        fifoCount = mpu.getFIFOCount();
    }
}

void TestGyroSpeed()
{
    unsigned long tempMicros = micros();
    for (int i = 0; i < 200; i++)
    {
        GetZAngle();
    }
    tempMicros = micros() - tempMicros;
    DisplayTextOLED("Time (us): " + String(tempMicros / 200));
}

void GetZAngle()
{
    if (!dmpReady)
        return;
    while (!mpuInterrupt && fifoCount < packetSize)
    {
        if (mpuInterrupt && fifoCount < packetSize)
        {
            fifoCount = mpu.getFIFOCount();
        }
    }
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();
    if ((mpuIntStatus & _BV(MPU6050_INTERRUPT_FIFO_OFLOW_BIT)) || fifoCount >= 1024)
    {
        mpu.resetFIFO();
        fifoCount = mpu.getFIFOCount();
        while (!mpuInterrupt)
        {
        }
        //Serial.println("Overflow!");
    }
    if (mpuIntStatus & _BV(MPU6050_INTERRUPT_DMP_INT_BIT))
    {
        while (fifoCount < packetSize)
            fifoCount = mpu.getFIFOCount();
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;
        DMPMath();
    }
}

void DMPMath()
{
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

    float tempZAngle = ypr[0] * 180 / M_PI;
    zAngle = (int)tempZAngle;
    if (zAngle < 0)
    {
        zAngle = 360 + zAngle;
    }
}

void AddToTargetAngle(float angle)
{
    refZAngle += angle;
    if (refZAngle > 360)
    {
        refZAngle -= 360;
    }
    else if (refZAngle < 0)
    {
        refZAngle += 360;
    }
}
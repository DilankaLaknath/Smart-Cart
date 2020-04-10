void DmpDataReady();

void InitMPU()
{
    InterruptIn dmpInterrupt(GYRO_INT_PIN);
    mpu.initialize();  
    wait_ms(200);
    devStatus = mpu.dmpInitialize();
    PrintSerial("Dmp Initialized!");

    mpu.setXGyroOffset(98);
    mpu.setYGyroOffset(-24);
    mpu.setZGyroOffset(0);
    mpu.setZAccelOffset(1788);

    if (devStatus == 0)
    {
        mpu.setDMPEnabled(true);
        dmpInterrupt.rise(&DmpDataReady);
        
        mpuIntStatus = mpu.getIntStatus();
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
        // mpu.resetFIFO();
        // fifoCount = mpu.getFIFOCount();
        PrintSerial("DMP Began");
    }
    else
    {
    }
}

void DmpDataReady()
{
    mpuInterrupt = true;
}

void DMPMath()
{
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    zAngle = (int)ypr[0] * 180 / M_PI;
    xAngle = (int)ypr[1] * 180 / M_PI;
    if (zAngle < 0)
    {
        zAngle += 360;
    }
    if (xAngle < 0)
    {
        xAngle += 360;
    }
}

void GetAngles(bool silentMode)
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
    if ((mpuIntStatus & 0x10) || fifoCount >= 1024)
    {
        mpu.resetFIFO();
        fifoCount = mpu.getFIFOCount();
        while (!mpuInterrupt)
        {
        }
    }
    if (mpuIntStatus & 0x02)
    {
        while (fifoCount < packetSize)
            fifoCount = mpu.getFIFOCount();
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;
        DMPMath();
        if (!silentMode)
        {
            printf("%d\n",(int)zAngle);
        }
    }
}
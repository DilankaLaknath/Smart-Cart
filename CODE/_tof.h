// Tof Defs
#define SENSOR_MIDDLE_ADDRESS 0x45
#define SIGNAL_RATE_LIMIT 0.9    //Higher the limit , higher the accuracy //0.8
#define MEASUREMENT_BUDGET 40000 //Higher the time , higher the accuracy //20000
#define TOF_TIMEOUT 500          //200
#define CONT_INTERVAL 40         //inter-measurement period in milliseconds determining how often the sensor takes a measurement.

void InitOneTOF(VL53L0X &tofSensor)
{
    tofSensor.init();
    wait_ms(20);
    tofSensor.setSignalRateLimit(SIGNAL_RATE_LIMIT);
    tofSensor.setMeasurementTimingBudget(MEASUREMENT_BUDGET);
    tofSensor.setTimeout(TOF_TIMEOUT);
    tofSensor.startContinuous();
    wait_ms(10);
}

void InitTOFs()
{
    wait_ms(20);
    InitOneTOF(tofMiddle);
}

float ReadOneTOF(VL53L0X &tofSensor)
{
    float tofDistance = tofSensor.readRangeContinuousMillimeters();
    return (float)(tofDistance / 10.0);
}

void ReadTOF()
{
    frontTofDistance = ReadOneTOF(tofMiddle);
}

void print_tof_distance()
{
    ReadTOF();
    pc.printf("d: %.2f\n", frontTofDistance);
    oled.clearDisplay();
    oled.setTextCursor(0, 0);
    oled.printf("d: %.2f\n", frontTofDistance);
    oled.display();
}

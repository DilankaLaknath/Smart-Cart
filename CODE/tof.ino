VL53L0X Sensor3; //Right Sensor
VL53L0X Sensor2; //Left Sensor
VL53L0X Sensor1; //Front Sensor



#define Sensor1_newAddress 42
#define Sensor2_newAddress 43
#define Sensor3_newAddress 44

#define SignalRateLimit 0.9     //Higher the limit , higher the accuracy //0.8
#define MeasurementBudget 40000 //Higher the time , higher the accuracy //20000
#define Timeout 500 //200
#define ContInterval 40 //inter-measurement period in milliseconds determining how often the sensor takes a measurement.

int right_Distance;
int left_Distance;
int front_Distance;

void InitTof()
{
    Wire.begin();
    pinMode(XSHUT_pin1, OUTPUT);
    pinMode(XSHUT_pin2, OUTPUT);
    pinMode(XSHUT_pin3, OUTPUT);

    pinMode(XSHUT_pin3, INPUT);
    delay(10);
    Sensor3.setAddress(Sensor3_newAddress);

    pinMode(XSHUT_pin2, INPUT);
    delay(10);
    Sensor2.setAddress(Sensor2_newAddress);

    pinMode(XSHUT_pin1, INPUT);
    delay(10);
    Sensor1.setAddress(Sensor1_newAddress);

    if (Sensor1.init())
    {
        Serial.println("Sensor 1 : Configured");
    }
    else
    {
        Serial.println("Sensor 1 : Configuration Failed");
    }
    if (Sensor2.init())
    {
        Serial.println("Sensor 2 : Configured");
    }
    else
    {
        Serial.println("Sensor 2 : Configuration Failed");
    }
    if (Sensor3.init())
    {
        Serial.println("Sensor 3 : Configured");
    }
    else
    {
        Serial.println("Sensor 3 : Configuration Failed");
    }

    Sensor1.setSignalRateLimit(SignalRateLimit);
    Sensor2.setSignalRateLimit(SignalRateLimit);
    Sensor3.setSignalRateLimit(SignalRateLimit);

    Sensor1.setMeasurementTimingBudget(MeasurementBudget);
    Sensor2.setMeasurementTimingBudget(MeasurementBudget);
    Sensor3.setMeasurementTimingBudget(MeasurementBudget);

    Sensor1.setTimeout(Timeout);
    Sensor2.setTimeout(Timeout);
    Sensor3.setTimeout(Timeout);

    Sensor1.startContinuous();
    Sensor2.startContinuous();
    Sensor3.startContinuous();
}

void GetDistance()
{
    front_Distance = Sensor1.readRangeContinuousMillimeters();
    float front_DistanceCM = (float)( front_Distance  / 10.0);

    left_Distance = Sensor2.readRangeContinuousMillimeters() ;
    float left_DistanceCM = (float)(left_Distance / 10.0);

    right_Distance = Sensor3.readRangeContinuousMillimeters();
    float right_DistanceCM = (float)(right_Distance / 10.0);
    
    Serial.print("front = " + String(front_DistanceCM));
    Serial.print(" ");
    Serial.print("left = " +String(left_DistanceCM));
    Serial.print(" ");
    Serial.println("right = " + String(right_DistanceCM));
    // OLED_Display("R = " + String(right_Distance) + "L = " + String(left_Distance) + "F = " + String(front_Distance));
}


#ifndef _VAR_H_
#define _VAR_H_

// STM variables
RawSerial bluetooth(PA_11, PA_12);
RawSerial pc(USBTX, USBRX);
I2C i2cVar(I2C_SDA_PIN, I2C_SCL_PIN);

// Servo controller
Adafruit_PWMServoDriver servoController(I2C_SDA_PIN, I2C_SCL_PIN);

// Timer variables
Timer i2cTimer;
Timer tempTime;

// Task variables
bool needAccel = true;

//tof variables
float frontTofDistance, leftTofDistance, rightTofDistance;

// Line follow variables
int lineMode = 0;
int preLineMode = 0;
int sumLine = 0;
bool leftJuncFound = false;
bool rightJuncFound = false;
bool contLineFound = false;
int contLineCount = 0;
int numContLineFound = 0;
int blackLineMode = true;

// line follow PID
float lineKp = 25; //20
float lineKd = 50; //40
float lineP = 0;
float lineD = 0;
float lineError;
float preLineError;
float linePIDValue;

// Encoder variables
volatile int rightEncoderTicks = 0;
volatile int leftEncoderTicks = 0;

// Tof variables
VL53L0X tofMiddle(&i2cVar, &i2cTimer); //Right Sensor

// Gyro Variables
MPU6050 mpu;
volatile bool mpuInterrupt = false;
unsigned long savedMillis;
bool gyroTurnMode = false;
int zAngle = 0;
int xAngle = 0;
int preZAngle = 0;
int preXAngle = 0;
int startAngle = 0;
unsigned long preGyroMillis = 0;

// MPU control/status vars
bool dmpReady = false; // set true if DMP init was successful
uint8_t mpuIntStatus;  // holds actual interrupt status byte from MPU
uint8_t devStatus;
uint16_t packetSize; // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;
uint8_t fifoBuffer[64];

// orientation/motion vars
Quaternion q;        // [w, x, y, z]         quaternion container
VectorInt16 aa;      // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;  // [x, y, z]
VectorInt16 aaWorld; // [x, y, z]
VectorFloat gravity; // [x, y, z]            gravity vector
float euler[3];      // [psi, theta, phi]    Euler angle container
float ypr[3];        // [yaw, pitch, roll]

#endif
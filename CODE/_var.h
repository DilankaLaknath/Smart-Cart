// Button Panel
ButtonPanel button_panel(BTN_LEFT, BTN_RIGHT, BTN_OK);
voidFuncPtr actions[] = {test_buttons,LEDBlink,get_z_angle};
char *titles[] = {
    (char *)"test buttons",
    (char *)"led blink",
    (char *)"get z angle"};

// Gyro Variables
MPU6050 mpu;
volatile bool mpuInterrupt = false;
unsigned long savedMillis;
bool gyroTurnMode = false;
float refZAngle = 0;
float zAngle = 0;
float xAngle = 0;
float preZAngle = 0;
float preXAngle = 0;
float startAngle = 0;
unsigned long preGyroMillis = 0;
// int rampState = NORMAL;

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
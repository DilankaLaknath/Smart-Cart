#ifndef _DEF_H_
#define _DEF_H_

#include "VL53L0X.h"
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "tcs3200_lib/tcs3200_lib.h"
#include "QTRSensors.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_PWMServoDriver.h"
#include <math.h>

#ifndef REP_DEF
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REP_N(i, a, b) for (int i = a; i > b; i--)
#endif

#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

#ifndef M_PI
#define M_PI 3.1415
#endif

// line follow modes
#define NO_LINE 0
#define FOLLOWING_LINE 1
#define JUNCTION_MODE 2

// Robot Properties
#define WHEEL_DIAMETER 40.0
#define TICKS_PER_ROUND_RIGHT 980
#define TICKS_PER_ROUND_LEFT 980

// Turn Encoder Ticks
#define ENCODER_TURN_RIGHT_90_TICKS 1050
#define ENCODER_TURN_LEFT_90_TICKS 1100     //1050
#define ENCODER_TURN_RIGHT_180_TICKS 2150
#define ENCODER_TURN_LEFT_180_TICKS 2150

// Servo angles
#define MAIN_ARM_SERVO_INIT_ANGLE 400
#define MAIN_ARM_SERVO_TASK_ANGLE 1080
#define MAIN_ARM_SERVO_SWORD_TASK_ANGLE 1000

#define FRONT_COLOR_SERVO_CLOSED_ANGLE 240//220
#define FRONT_COLOR_SERVO_OPEN_ANGLE 450

#define SIDE_COLOR_SERVO_INIT_ANGLE 850
#define SIDE_COLOR_SERVO_TASK_ANGLE 500

#define SWORD_SERVO_INIT_ANGLE 700//700
#define SWORD_SERVO_TASK_ANGLE 100//150

#include "__pins.h"
#include "__var.h"

float map(float x, float x1, float x2, float y1, float y2)
{
    return (x - x1) * (y2 - y1) / (x2 - x1) + y1;
}

void InitSerial()
{
    pc.baud(115200);
    pc.printf("Circuit Breakers!\n");
    bluetooth.baud(38400);
    bluetooth.printf("Circuit Breakers!\n");
}

void PrintSerial(char *message)
{
    pc.printf(message);
    pc.printf("\n");
}

void PrintBluetooth(char message)
{
    bluetooth.printf("%c", message);
}

void InitRobot();

void Hold()
{
    while (1)
    {
    }
}

void TestI2C()
{
    int ackReceived, address;
    int nDevices;

    pc.printf("Scanning...\n");

    nDevices = 0;

    for (address = 1; address < 127; address++)
    {
        i2cVar.start();
        ackReceived = i2cVar.write(address << 1); //We shift it left because mbed takes in 8 bit addreses
        i2cVar.stop();
        if (ackReceived == 1)
        {
            pc.printf("I2C device found at address 0x%X\n", (address)); //Returns 8-bit addres
            nDevices++;
        }
    }
    if (nDevices == 0)
        pc.printf("No I2C devices found\n");
    else
        pc.printf("done\n\n");

    wait_ms(1000); // wait 5 seconds for next scan
}

#endif
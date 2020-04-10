#ifndef _PINS_H
#define _PINS_H

// Gyro Pins
#define GYRO_INT_PIN PA_13

// Battery Pin
#define BATTERY_PIN PC_4

// Sword Connection Pin 
#define SWORD_CONNECT_PIN PA_0

// Servo Numbers in driver
#define MAIN_ARM_SERVO 12
#define SWORD_SERVO 15
#define FRONT_COLOR_SERVO 13
#define SIDE_COLOR_SERVO 14

// Motor Pins
#define MOTOR_LEFT_1 PC_3
#define MOTOR_LEFT_2 PC_2
#define MOTOR_LEFT_POWER_PIN PB_4
#define MOTOR_RIGHT_1 PD_2
#define MOTOR_RIGHT_2 PC_11
#define MOTOR_RIGHT_POWER_PIN PB_5

// I2C Pins
#define I2C_SDA_PIN PB_9
#define I2C_SCL_PIN PB_8

// Encoder Pins
#define ENCODER_MOTOR_RIGHT_PIN_1 PA_4
#define ENCODER_MOTOR_RIGHT_PIN_2 PA_10
#define ENCODER_MOTOR_LEFT_PIN_1 PC_0
#define ENCODER_MOTOR_LEFT_PIN_2 PC_1

// Serial Pins
#define SERIAL_TX_PIN PA_2
#define SERIAL_RX_PIN PA_3

// Buzzer Pin
#define BUZZER_PIN PB_7

// Button Panel
#define BTN_LEFT PA_6
#define BTN_OK PC_13
#define BTN_RIGHT PA_7

// Color RGB
#define R_PIN PC_8
#define G_PIN PC_6
#define B_PIN PC_5

// Color Sensor
#define COLOR_SENSOR_1 PB_6
#define COLOR_SENSOR_2 PC_7
#define COLOR_SENSOR_3 PA_9
#define COLOR_SENSOR_4 PA_14
#define COLOR_S2 PB_10
#define COLOR_S3 PA_8

#endif